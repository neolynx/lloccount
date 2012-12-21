/*
 * Logical Lines Of Code Counter
 *
 * Run with:
 * ./lloccount file.cc [clang args...]
 */

// TODO:
// - getopt
// - categories
// - multiple files
// - summary

#include <clang-c/Index.h>
#include <cstdlib>
#include <iostream>
#include <string>

#include "stats.h"

std::map<int, Stats> stats;

void printDecl( CXCursor c )
{
  CXString n       = clang_getCursorSpelling( c );
  const char *name = clang_getCString( n );
  CXString t       = clang_getDeclObjCTypeEncoding( c );
  const char *type = clang_getCString( t );
  clang_disposeString( n );
  clang_disposeString( t );
}


std::string getFileName(CXCursor cursor)
{
  CXFile file;
  clang_getSpellingLocation(clang_getCursorLocation(cursor), &file, 0, 0, 0);
  CXString fileStr = clang_getFileName(file);
  const char *t = clang_getCString(fileStr);
  std::string fileName;
  if( t )
    fileName = t;
  clang_disposeString(fileStr);
  return fileName;
}

const char *filename;

CXChildVisitResult statsVisitor( CXCursor cursor, CXCursor parent, CXClientData client_data )
{
  CXSourceRange range = clang_getCursorExtent( cursor );
  std::string file = getFileName( cursor );

  //FIXME: verify kind exists in stats
  if( file == filename )
  {
    stats[cursor.kind].count++;
    stats[stats[cursor.kind].category].count++;
  }
  //std::cout << file << std::endl;
  //printDecl( c );
  return CXChildVisit_Recurse;
}

int main(int argc, char** argv)
{
  Stats::Init( stats );

  if (argc < 2) {
    std::cout << argv[0] << " file.cc"
      << std::endl;
    return 1;
  }
  filename = argv[1];

  CXIndex idx = clang_createIndex(1, 0);
  if (!idx) {
    std::cerr << "createIndex failed" << std::endl;
    return 2;
  }

  CXTranslationUnit u = clang_parseTranslationUnit(idx, filename, argv + 2,
      argc - 2, 0, 0,
      CXTranslationUnit_PrecompiledPreamble
      | CXTranslationUnit_CXXPrecompiledPreamble |
      CXTranslationUnit_DetailedPreprocessingRecord
      );

  if (!u) {
    std::cerr << "parseTranslationUnit failed" << std::endl;
    return 2;
  }

  clang_reparseTranslationUnit(u, 0, 0, 0);

  clang_visitChildren( clang_getTranslationUnitCursor( u ), statsVisitor, NULL );

  for( size_t i = 0; i < stats.size( ); i++ )
  {
    if (stats[i].name == NULL || stats[i].count == 0 )
      continue;
    std::cout << stats[i].name << ": " << stats[i].count << std::endl;
  }

  return 0;
}
