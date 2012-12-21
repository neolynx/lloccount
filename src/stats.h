#ifndef _STATS_
#define _STATS_

#include <stddef.h>
#include <map>

class Stats
{
  public:
    Stats( ) { count = 0; name = NULL; category = Cat_Misc; }
    Stats( const char *n ) { count = 0; name = n; category = Cat_Misc;}
    static void Init( std::map<int, Stats *> &stats );
    int count;
    const char *name;
    enum Category
    {
      Cat_Misc = 1000,
      Cat_Declaration,
      Cat_Statement,
      Cat_Loop,
      Cat_Condition,
      Cat_Call,
      Cat_Function,
    } category;
};

void Stats::Init( std::map<int, Stats *> &stats )
{
  stats[CXCursor_UnexposedDecl]                      = new Stats( "Unexposed  Declaration" );

  stats[CXCursor_StructDecl]                         = new Stats( "struct" );
  stats[CXCursor_StructDecl]->category               = Cat_Declaration;
  stats[CXCursor_UnionDecl]                          = new Stats( "union" );
  stats[CXCursor_UnionDecl]->category                = Cat_Declaration;
  stats[CXCursor_ClassDecl]                          = new Stats( "class" );
  stats[CXCursor_ClassDecl]->category                = Cat_Declaration;
  stats[CXCursor_EnumDecl]                           = new Stats( "enum" );
  stats[CXCursor_EnumDecl]->category                 = Cat_Declaration;

  stats[CXCursor_IfStmt]                             = new Stats( "if" );
  stats[CXCursor_IfStmt]->category                   = Cat_Condition;
  stats[CXCursor_SwitchStmt]                         = new Stats( "switch" );
  stats[CXCursor_SwitchStmt]->category               = Cat_Condition;
  stats[CXCursor_WhileStmt]                          = new Stats( "while" );
  stats[CXCursor_WhileStmt]->category                = Cat_Loop;
  stats[CXCursor_DoStmt]                             = new Stats( "do" );
  stats[CXCursor_DoStmt]->category                   = Cat_Loop;
  stats[CXCursor_ForStmt]                            = new Stats( "for" );
  stats[CXCursor_ForStmt]->category                  = Cat_Loop;

  stats[CXCursor_GotoStmt]                           = new Stats( "goto" );
  stats[CXCursor_GotoStmt]->category                 = Cat_Statement;
  stats[CXCursor_BreakStmt]                          = new Stats( "break" );
  stats[CXCursor_BreakStmt]->category                = Cat_Statement;
  stats[CXCursor_ReturnStmt]                         = new Stats( "return" );
  stats[CXCursor_ReturnStmt]->category               = Cat_Statement;

  stats[CXCursor_InclusionDirective]                 = new Stats( "include" );
  stats[CXCursor_InclusionDirective]->category       = Cat_Statement;
  stats[CXCursor_CallExpr]                           = new Stats( "function call" );
  stats[CXCursor_CallExpr]->category                 = Cat_Call;
  stats[CXCursor_FunctionDecl]                       = new Stats( "functions" );
  stats[CXCursor_FunctionDecl]->category             = Cat_Function;
  stats[CXCursor_VarDecl]                            = new Stats( "variable" );
  stats[CXCursor_VarDecl]->category                  = Cat_Statement;
  stats[CXCursor_ParmDecl]                           = new Stats( "parameter" );

  stats[CXCursor_FieldDecl]                          = new Stats( "Field Declaration" );
  stats[CXCursor_EnumConstantDecl]                   = new Stats( "EnumConstant Declaration" );
  stats[CXCursor_ObjCInterfaceDecl]                  = new Stats( "ObjCInterface Declaration" );
  stats[CXCursor_ObjCCategoryDecl]                   = new Stats( "ObjCCategory Declaration" );
  stats[CXCursor_ObjCProtocolDecl]                   = new Stats( "ObjCProtocol Declaration" );
  stats[CXCursor_ObjCPropertyDecl]                   = new Stats( "ObjCProperty Declaration" );
  stats[CXCursor_ObjCIvarDecl]                       = new Stats( "ObjCIvar Declaration" );
  stats[CXCursor_ObjCInstanceMethodDecl]             = new Stats( "ObjCInstanceMethod Declaration" );
  stats[CXCursor_ObjCClassMethodDecl]                = new Stats( "ObjCClassMethod Declaration" );
  stats[CXCursor_ObjCImplementationDecl]             = new Stats( "ObjCImplementation Declaration" );
  stats[CXCursor_ObjCCategoryImplDecl]               = new Stats( "ObjCCategoryImpl Declaration" );
  stats[CXCursor_TypedefDecl]                        = new Stats( "Typedef Declaration" );
  stats[CXCursor_CXXMethod]                          = new Stats( "CXXMethod" );
  stats[CXCursor_Namespace]                          = new Stats( "Namespace" );
  stats[CXCursor_LinkageSpec]                        = new Stats( "LinkageSpec" );
  stats[CXCursor_Constructor]                        = new Stats( "Constructor" );
  stats[CXCursor_Destructor]                         = new Stats( "Destructor" );
  stats[CXCursor_ConversionFunction]                 = new Stats( "ConversionFunction" );
  stats[CXCursor_TemplateTypeParameter]              = new Stats( "TemplateTypeParameter" );
  stats[CXCursor_NonTypeTemplateParameter]           = new Stats( "NonTypeTemplateParameter" );
  stats[CXCursor_TemplateTemplateParameter]          = new Stats( "TemplateTemplateParameter" );
  stats[CXCursor_FunctionTemplate]                   = new Stats( "FunctionTemplate" );
  stats[CXCursor_ClassTemplate]                      = new Stats( "ClassTemplate" );
  stats[CXCursor_ClassTemplatePartialSpecialization] = new Stats( "ClassTemplatePartialSpecialization" );
  stats[CXCursor_NamespaceAlias]                     = new Stats( "NamespaceAlias" );
  stats[CXCursor_UsingDirective]                     = new Stats( "UsingDirective" );
  stats[CXCursor_UsingDeclaration]                   = new Stats( "UsingDeclaration" );
  stats[CXCursor_TypeAliasDecl]                      = new Stats( "TypeAlias Declaration" );
  stats[CXCursor_ObjCSynthesizeDecl]                 = new Stats( "ObjCSynthesize Declaration" );
  stats[CXCursor_ObjCDynamicDecl]                    = new Stats( "ObjCDynamic Declaration" );
  stats[CXCursor_CXXAccessSpecifier]                 = new Stats( "CXXAccessSpecifier" );
  stats[CXCursor_FirstRef]                           = new Stats( "FirstRef" );
  stats[CXCursor_ObjCSuperClassRef]                  = new Stats( "ObjCSuperClassRef" );
  stats[CXCursor_ObjCProtocolRef]                    = new Stats( "ObjCProtocolRef" );
  stats[CXCursor_ObjCClassRef]                       = new Stats( "ObjCClassRef" );
  stats[CXCursor_TypeRef]                            = new Stats( "TypeRef" );
  stats[CXCursor_CXXBaseSpecifier]                   = new Stats( "CXXBaseSpecifier" );
  stats[CXCursor_TemplateRef]                        = new Stats( "TemplateRef" );
  stats[CXCursor_NamespaceRef]                       = new Stats( "NamespaceRef" );
  stats[CXCursor_MemberRef]                          = new Stats( "MemberRef" );
  stats[CXCursor_LabelRef]                           = new Stats( "LabelRef" );
  stats[CXCursor_OverloadedDeclRef]                  = new Stats( "OverloadedDeclRef" );
  stats[CXCursor_FirstInvalid]                       = new Stats( "FirstInvalid" );
  stats[CXCursor_InvalidFile]                        = new Stats( "InvalidFile" );
  stats[CXCursor_NoDeclFound]                        = new Stats( "NoDeclFound" );
  stats[CXCursor_NotImplemented]                     = new Stats( "NotImplemented" );
  stats[CXCursor_InvalidCode]                        = new Stats( "InvalidCode" );
  stats[CXCursor_FirstExpr]                          = new Stats( "FirstExpr" );
  stats[CXCursor_UnexposedExpr]                      = new Stats( "UnexposedExpr" );
  stats[CXCursor_DeclRefExpr]                        = new Stats( "DeclRefExpr" );
  stats[CXCursor_MemberRefExpr]                      = new Stats( "MemberRefExpr" );
  stats[CXCursor_ObjCMessageExpr]                    = new Stats( "ObjCMessageExpr" );
  stats[CXCursor_BlockExpr]                          = new Stats( "BlockExpr" );
  stats[CXCursor_IntegerLiteral]                     = new Stats( "IntegerLiteral" );
  stats[CXCursor_FloatingLiteral]                    = new Stats( "FloatingLiteral" );
  stats[CXCursor_ImaginaryLiteral]                   = new Stats( "ImaginaryLiteral" );
  stats[CXCursor_StringLiteral]                      = new Stats( "StringLiteral" );
  stats[CXCursor_CharacterLiteral]                   = new Stats( "CharacterLiteral" );
  stats[CXCursor_ParenExpr]                          = new Stats( "ParenExpr" );
  stats[CXCursor_UnaryOperator]                      = new Stats( "UnaryOperator" );
  stats[CXCursor_ArraySubscriptExpr]                 = new Stats( "ArraySubscriptExpr" );
  stats[CXCursor_BinaryOperator]                     = new Stats( "BinaryOperator" );
  stats[CXCursor_CompoundAssignOperator]             = new Stats( "CompoundAssignOperator" );
  stats[CXCursor_ConditionalOperator]                = new Stats( "ConditionalOperator" );
  stats[CXCursor_CStyleCastExpr]                     = new Stats( "CStyleCastExpr" );
  stats[CXCursor_CompoundLiteralExpr]                = new Stats( "CompoundLiteralExpr" );
  stats[CXCursor_InitListExpr]                       = new Stats( "InitListExpr" );
  stats[CXCursor_AddrLabelExpr]                      = new Stats( "AddrLabelExpr" );
  stats[CXCursor_StmtExpr]                           = new Stats( "StmtExpr" );
  stats[CXCursor_GenericSelectionExpr]               = new Stats( "GenericSelectionExpr" );
  stats[CXCursor_GNUNullExpr]                        = new Stats( "GNUNullExpr" );
  stats[CXCursor_CXXStaticCastExpr]                  = new Stats( "CXXStaticCastExpr" );
  stats[CXCursor_CXXDynamicCastExpr]                 = new Stats( "CXXDynamicCastExpr" );
  stats[CXCursor_CXXReinterpretCastExpr]             = new Stats( "CXXReinterpretCastExpr" );
  stats[CXCursor_CXXConstCastExpr]                   = new Stats( "CXXConstCastExpr" );
  stats[CXCursor_CXXFunctionalCastExpr]              = new Stats( "CXXFunctionalCastExpr" );
  stats[CXCursor_CXXTypeidExpr]                      = new Stats( "CXXTypeidExpr" );
  stats[CXCursor_CXXBoolLiteralExpr]                 = new Stats( "CXXBoolLiteralExpr" );
  stats[CXCursor_CXXNullPtrLiteralExpr]              = new Stats( "CXXNullPtrLiteralExpr" );
  stats[CXCursor_CXXThisExpr]                        = new Stats( "CXXThisExpr" );
  stats[CXCursor_CXXThrowExpr]                       = new Stats( "CXXThrowExpr" );
  stats[CXCursor_CXXNewExpr]                         = new Stats( "CXXNewExpr" );
  stats[CXCursor_CXXDeleteExpr]                      = new Stats( "CXXDeleteExpr" );
  stats[CXCursor_UnaryExpr]                          = new Stats( "UnaryExpr" );
  stats[CXCursor_ObjCStringLiteral]                  = new Stats( "ObjCStringLiteral" );
  stats[CXCursor_ObjCEncodeExpr]                     = new Stats( "ObjCEncodeExpr" );
  stats[CXCursor_ObjCSelectorExpr]                   = new Stats( "ObjCSelectorExpr" );
  stats[CXCursor_ObjCProtocolExpr]                   = new Stats( "ObjCProtocolExpr" );
  stats[CXCursor_ObjCBridgedCastExpr]                = new Stats( "ObjCBridgedCastExpr" );
  stats[CXCursor_PackExpansionExpr]                  = new Stats( "PackExpansionExpr" );
  stats[CXCursor_SizeOfPackExpr]                     = new Stats( "SizeOfPackExpr" );
  stats[CXCursor_FirstStmt]                          = new Stats( "FirstStmt" );
  stats[CXCursor_UnexposedStmt]                      = new Stats( "UnexposedStmt" );
  stats[CXCursor_LabelStmt]                          = new Stats( "LabelStmt" );
  stats[CXCursor_CompoundStmt]                       = new Stats( "CompoundStmt" );
  stats[CXCursor_CaseStmt]                           = new Stats( "CaseStmt" );
  stats[CXCursor_DefaultStmt]                        = new Stats( "DefaultStmt" );
  stats[CXCursor_IndirectGotoStmt]                   = new Stats( "IndirectGotoStmt" );
  stats[CXCursor_ContinueStmt]                       = new Stats( "ContinueStmt" );
  stats[CXCursor_AsmStmt]                            = new Stats( "AsmStmt" );
  stats[CXCursor_ObjCAtTryStmt]                      = new Stats( "ObjCAtTryStmt" );
  stats[CXCursor_ObjCAtCatchStmt]                    = new Stats( "ObjCAtCatchStmt" );
  stats[CXCursor_ObjCAtFinallyStmt]                  = new Stats( "ObjCAtFinallyStmt" );
  stats[CXCursor_ObjCAtThrowStmt]                    = new Stats( "ObjCAtThrowStmt" );
  stats[CXCursor_ObjCAtSynchronizedStmt]             = new Stats( "ObjCAtSynchronizedStmt" );
  stats[CXCursor_ObjCAutoreleasePoolStmt]            = new Stats( "ObjCAutoreleasePoolStmt" );
  stats[CXCursor_ObjCForCollectionStmt]              = new Stats( "ObjCForCollectionStmt" );
  stats[CXCursor_CXXCatchStmt]                       = new Stats( "CXXCatchStmt" );
  stats[CXCursor_CXXTryStmt]                         = new Stats( "CXXTryStmt" );
  stats[CXCursor_CXXForRangeStmt]                    = new Stats( "CXXForRangeStmt" );
  stats[CXCursor_SEHTryStmt]                         = new Stats( "SEHTryStmt" );
  stats[CXCursor_SEHExceptStmt]                      = new Stats( "SEHExceptStmt" );
  stats[CXCursor_SEHFinallyStmt]                     = new Stats( "SEHFinallyStmt" );
  stats[CXCursor_NullStmt]                           = new Stats( "NullStmt" );
  stats[CXCursor_DeclStmt]                           = new Stats( "DeclStmt" );
  stats[CXCursor_TranslationUnit]                    = new Stats( "TranslationUnit" );
  stats[CXCursor_FirstAttr]                          = new Stats( "FirstAttr" );
  stats[CXCursor_UnexposedAttr]                      = new Stats( "UnexposedAttr" );
  stats[CXCursor_IBActionAttr]                       = new Stats( "IBActionAttr" );
  stats[CXCursor_IBOutletAttr]                       = new Stats( "IBOutletAttr" );
  stats[CXCursor_IBOutletCollectionAttr]             = new Stats( "IBOutletCollectionAttr" );
  stats[CXCursor_CXXFinalAttr]                       = new Stats( "CXXFinalAttr" );
  stats[CXCursor_CXXOverrideAttr]                    = new Stats( "CXXOverrideAttr" );
  stats[CXCursor_AnnotateAttr]                       = new Stats( "AnnotateAttr" );
  stats[CXCursor_PreprocessingDirective]             = new Stats( "PreprocessingDirective" );
  stats[CXCursor_MacroDefinition]                    = new Stats( "MacroDefinition" );
  stats[CXCursor_MacroExpansion]                     = new Stats( "MacroExpansion" );

  stats[Cat_Misc]                                    = new Stats( "Misc" );
  stats[Cat_Declaration]                             = new Stats( "Declarations" );
  stats[Cat_Statement]                               = new Stats( "Statements" );
  stats[Cat_Loop]                                    = new Stats( "Loops" );
  stats[Cat_Condition]                               = new Stats( "Conditions" );
  stats[Cat_Function]                                = new Stats( "Functions" );
  stats[Cat_Call]                                    = new Stats( "Calls" );
}

#endif

