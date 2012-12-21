#include <clang-c/Index.h>
#include <cstdlib>
#include <iostream>
#include <sys/stat.h>

/*
 * Compile with:
 * g++ complete.cc -o complete -lclang -L/usr/lib/llvm
 * Run with:
 * LIBCLANG_TIMING=1 ./complete file.cc line column [clang args...]
 */

void printDecl( CXCursor c )
{
  CXString n       = clang_getCursorSpelling( c );
  const char *name = clang_getCString( n );
  CXString t       = clang_getDeclObjCTypeEncoding( c );
  const char *type = clang_getCString( t );
  clang_disposeString( n );
  clang_disposeString( t );
}

#include "stats.cc"
std::map<int, Stats> stats;

#include <string>
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

const char *getTokenName( int token )
{
  switch( token )
  {
    case CXToken_Punctuation: return "Punctuation";
    case CXToken_Keyword: return "Keyword";
    case CXToken_Identifier: return "Identifier";
    case CXToken_Literal: return "Literal";
    case CXToken_Comment: return "Comment";
  }
  return NULL;
}

int main(int argc, char** argv)
{
  Stats::Init( stats );

  if (argc < 2) {
    std::cout << argv[0] << " file.cc"
      << std::endl;
    return 1;
  }

  CXIndex idx = clang_createIndex(1, 0);
  if (!idx) {
    std::cerr << "createIndex failed" << std::endl;
    return 2;
  }

  CXTranslationUnit u = clang_parseTranslationUnit(idx, argv[1], argv + 2,
      argc - 2, 0, 0,
      clang_defaultEditingTranslationUnitOptions() | CXTranslationUnit_DetailedPreprocessingRecord
      );

  if (!u) {
    std::cerr << "parseTranslationUnit failed" << std::endl;
    return 2;
  }

  struct stat st;
  stat( argv[1], &st );

  CXFile file = clang_getFile( u, argv[1] );
  CXSourceRange range = clang_getRange( clang_getLocationForOffset( u, file, 0),
      clang_getLocationForOffset( u, file, st.st_size ));

  CXToken *tokens = NULL;
  unsigned int n = 0;
  CXCursor *cursors = NULL;

  clang_tokenize( u, range, &tokens, &n );
  cursors = (CXCursor *) malloc( n * sizeof( CXCursor ));
  clang_annotateTokens( u, tokens, n, cursors );

  for( int i = 0 ; i < n ; i++ )
  {
    //printf( "found %s: %s\n", getTokenName( clang_getTokenKind( tokens[i] )), stats[ cursors[i].kind ].name );
    //CXSourceRange tkrange = clang_getTokenExtent( u, tokens[i] );
    switch( clang_getTokenKind( tokens[i] ))
    {
      case CXToken_Keyword:
        stats[ cursors[i].kind ].count++;
        break;
      case CXToken_Punctuation:
      case CXToken_Identifier:
      case CXToken_Literal:
      case CXToken_Comment:
        break;
    }
    //clang_getSpellingLocation(  clang_getRangeStart( tkrange ), NULL, clang_getRangeStart( range ), &range.start.col, NULL );
    //clang_getSpellingLocation( clang_getRangeEnd( tkrange ), NULL, &range.end.line, &range.end.col, NULL );

  }


  //clang_reparseTranslationUnit(u, 0, 0, 0);

  //clang_visitChildrenWithBlock( clang_getTranslationUnitCursor( u ),
  //^ enum CXChildVisitResult( CXCursor c, CXCursor parent )
  //{
  //CXSourceRange range = clang_getCursorExtent(c);
  //std::string file = getFileName( c );

  //if( file == argv[1] )
  //stats[c.kind].count++;
  ////std::cout << file << std::endl;
  ////printDecl( c );
  //return CXChildVisit_Recurse; //CXChildVisit_Continue;
  //} );

  for (size_t ii = 0; ii < stats.size( ); ii++)
  {
    if (stats[ii].name == NULL || stats[ii].count == 0 )
      continue;
    //std::cout << stats[ii].name << ": " << stats[ii].count << std::endl;
    printf( "%s: %d\n", stats[ii].name, stats[ii].count );
  }

  return 0;
}
