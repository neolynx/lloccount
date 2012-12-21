#ifndef _STATS_
#define _STATS_

#include <stddef.h>
#include <map>

class Stats
{
  public:
    Stats( ) { count = 0; name = NULL; category = Cat_Misc; }
    Stats( const char *n ) { count = 0; name = n; category = Cat_Misc;}
    static void Init( std::map<int, Stats> &stats );
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

void Stats::Init( std::map<int, Stats> &stats )
{
  stats[CXCursor_UnexposedDecl]                      = "Unexposed  Declaration";

  stats[CXCursor_StructDecl]                         = "struct";
  stats[CXCursor_StructDecl].category                = Cat_Declaration;
  stats[CXCursor_UnionDecl]                          = "union";
  stats[CXCursor_UnionDecl].category                 = Cat_Declaration;
  stats[CXCursor_ClassDecl]                          = "class";
  stats[CXCursor_ClassDecl].category                 = Cat_Declaration;
  stats[CXCursor_EnumDecl]                           = "enum";
  stats[CXCursor_EnumDecl].category                  = Cat_Declaration;

  stats[CXCursor_IfStmt]                             = "if";
  stats[CXCursor_IfStmt].category                    = Cat_Condition;
  stats[CXCursor_SwitchStmt]                         = "switch";
  stats[CXCursor_SwitchStmt].category                = Cat_Condition;
  stats[CXCursor_WhileStmt]                          = "while";
  stats[CXCursor_WhileStmt].category                 = Cat_Loop;
  stats[CXCursor_DoStmt]                             = "do";
  stats[CXCursor_DoStmt].category                    = Cat_Loop;
  stats[CXCursor_ForStmt]                            = "for";
  stats[CXCursor_ForStmt].category                   = Cat_Loop;

  stats[CXCursor_GotoStmt]                           = "goto";
  stats[CXCursor_BreakStmt]                          = "break";
  stats[CXCursor_ReturnStmt]                         = "return";

  stats[CXCursor_InclusionDirective]                 = "include";
  stats[CXCursor_CallExpr]                           = "function call";
  stats[CXCursor_CallExpr].category                  = Cat_Call;
  stats[CXCursor_FunctionDecl]                       = "functions";
  stats[CXCursor_FunctionDecl].category              = Cat_Function;
  stats[CXCursor_VarDecl]                            = "variable";
  stats[CXCursor_ParmDecl]                           = "parameter";

  stats[CXCursor_FieldDecl]                          = "Field Declaration";
  stats[CXCursor_EnumConstantDecl]                   = "EnumConstant Declaration";
  stats[CXCursor_ObjCInterfaceDecl]                  = "ObjCInterface Declaration";
  stats[CXCursor_ObjCCategoryDecl]                   = "ObjCCategory Declaration";
  stats[CXCursor_ObjCProtocolDecl]                   = "ObjCProtocol Declaration";
  stats[CXCursor_ObjCPropertyDecl]                   = "ObjCProperty Declaration";
  stats[CXCursor_ObjCIvarDecl]                       = "ObjCIvar Declaration";
  stats[CXCursor_ObjCInstanceMethodDecl]             = "ObjCInstanceMethod Declaration";
  stats[CXCursor_ObjCClassMethodDecl]                = "ObjCClassMethod Declaration";
  stats[CXCursor_ObjCImplementationDecl]             = "ObjCImplementation Declaration";
  stats[CXCursor_ObjCCategoryImplDecl]               = "ObjCCategoryImpl Declaration";
  stats[CXCursor_TypedefDecl]                        = "Typedef Declaration";
  stats[CXCursor_CXXMethod]                          = "CXXMethod";
  stats[CXCursor_Namespace]                          = "Namespace";
  stats[CXCursor_LinkageSpec]                        = "LinkageSpec";
  stats[CXCursor_Constructor]                        = "Constructor";
  stats[CXCursor_Destructor]                         = "Destructor";
  stats[CXCursor_ConversionFunction]                 = "ConversionFunction";
  stats[CXCursor_TemplateTypeParameter]              = "TemplateTypeParameter";
  stats[CXCursor_NonTypeTemplateParameter]           = "NonTypeTemplateParameter";
  stats[CXCursor_TemplateTemplateParameter]          = "TemplateTemplateParameter";
  stats[CXCursor_FunctionTemplate]                   = "FunctionTemplate";
  stats[CXCursor_ClassTemplate]                      = "ClassTemplate";
  stats[CXCursor_ClassTemplatePartialSpecialization] = "ClassTemplatePartialSpecialization";
  stats[CXCursor_NamespaceAlias]                     = "NamespaceAlias";
  stats[CXCursor_UsingDirective]                     = "UsingDirective";
  stats[CXCursor_UsingDeclaration]                   = "UsingDeclaration";
  stats[CXCursor_TypeAliasDecl]                      = "TypeAlias Declaration";
  stats[CXCursor_ObjCSynthesizeDecl]                 = "ObjCSynthesize Declaration";
  stats[CXCursor_ObjCDynamicDecl]                    = "ObjCDynamic Declaration";
  stats[CXCursor_CXXAccessSpecifier]                 = "CXXAccessSpecifier";
  stats[CXCursor_FirstRef]                           = "FirstRef";
  stats[CXCursor_ObjCSuperClassRef]                  = "ObjCSuperClassRef";
  stats[CXCursor_ObjCProtocolRef]                    = "ObjCProtocolRef";
  stats[CXCursor_ObjCClassRef]                       = "ObjCClassRef";
  stats[CXCursor_TypeRef]                            = "TypeRef";
  stats[CXCursor_CXXBaseSpecifier]                   = "CXXBaseSpecifier";
  stats[CXCursor_TemplateRef]                        = "TemplateRef";
  stats[CXCursor_NamespaceRef]                       = "NamespaceRef";
  stats[CXCursor_MemberRef]                          = "MemberRef";
  stats[CXCursor_LabelRef]                           = "LabelRef";
  stats[CXCursor_OverloadedDeclRef]                  = "OverloadedDeclRef";
  stats[CXCursor_FirstInvalid]                       = "FirstInvalid";
  stats[CXCursor_InvalidFile]                        = "InvalidFile";
  stats[CXCursor_NoDeclFound]                        = "NoDeclFound";
  stats[CXCursor_NotImplemented]                     = "NotImplemented";
  stats[CXCursor_InvalidCode]                        = "InvalidCode";
  stats[CXCursor_FirstExpr]                          = "FirstExpr";
  stats[CXCursor_UnexposedExpr]                      = "UnexposedExpr";
  stats[CXCursor_DeclRefExpr]                        = "DeclRefExpr";
  stats[CXCursor_MemberRefExpr]                      = "MemberRefExpr";
  stats[CXCursor_ObjCMessageExpr]                    = "ObjCMessageExpr";
  stats[CXCursor_BlockExpr]                          = "BlockExpr";
  stats[CXCursor_IntegerLiteral]                     = "IntegerLiteral";
  stats[CXCursor_FloatingLiteral]                    = "FloatingLiteral";
  stats[CXCursor_ImaginaryLiteral]                   = "ImaginaryLiteral";
  stats[CXCursor_StringLiteral]                      = "StringLiteral";
  stats[CXCursor_CharacterLiteral]                   = "CharacterLiteral";
  stats[CXCursor_ParenExpr]                          = "ParenExpr";
  stats[CXCursor_UnaryOperator]                      = "UnaryOperator";
  stats[CXCursor_ArraySubscriptExpr]                 = "ArraySubscriptExpr";
  stats[CXCursor_BinaryOperator]                     = "BinaryOperator";
  stats[CXCursor_CompoundAssignOperator]             = "CompoundAssignOperator";
  stats[CXCursor_ConditionalOperator]                = "ConditionalOperator";
  stats[CXCursor_CStyleCastExpr]                     = "CStyleCastExpr";
  stats[CXCursor_CompoundLiteralExpr]                = "CompoundLiteralExpr";
  stats[CXCursor_InitListExpr]                       = "InitListExpr";
  stats[CXCursor_AddrLabelExpr]                      = "AddrLabelExpr";
  stats[CXCursor_StmtExpr]                           = "StmtExpr";
  stats[CXCursor_GenericSelectionExpr]               = "GenericSelectionExpr";
  stats[CXCursor_GNUNullExpr]                        = "GNUNullExpr";
  stats[CXCursor_CXXStaticCastExpr]                  = "CXXStaticCastExpr";
  stats[CXCursor_CXXDynamicCastExpr]                 = "CXXDynamicCastExpr";
  stats[CXCursor_CXXReinterpretCastExpr]             = "CXXReinterpretCastExpr";
  stats[CXCursor_CXXConstCastExpr]                   = "CXXConstCastExpr";
  stats[CXCursor_CXXFunctionalCastExpr]              = "CXXFunctionalCastExpr";
  stats[CXCursor_CXXTypeidExpr]                      = "CXXTypeidExpr";
  stats[CXCursor_CXXBoolLiteralExpr]                 = "CXXBoolLiteralExpr";
  stats[CXCursor_CXXNullPtrLiteralExpr]              = "CXXNullPtrLiteralExpr";
  stats[CXCursor_CXXThisExpr]                        = "CXXThisExpr";
  stats[CXCursor_CXXThrowExpr]                       = "CXXThrowExpr";
  stats[CXCursor_CXXNewExpr]                         = "CXXNewExpr";
  stats[CXCursor_CXXDeleteExpr]                      = "CXXDeleteExpr";
  stats[CXCursor_UnaryExpr]                          = "UnaryExpr";
  stats[CXCursor_ObjCStringLiteral]                  = "ObjCStringLiteral";
  stats[CXCursor_ObjCEncodeExpr]                     = "ObjCEncodeExpr";
  stats[CXCursor_ObjCSelectorExpr]                   = "ObjCSelectorExpr";
  stats[CXCursor_ObjCProtocolExpr]                   = "ObjCProtocolExpr";
  stats[CXCursor_ObjCBridgedCastExpr]                = "ObjCBridgedCastExpr";
  stats[CXCursor_PackExpansionExpr]                  = "PackExpansionExpr";
  stats[CXCursor_SizeOfPackExpr]                     = "SizeOfPackExpr";
  stats[CXCursor_FirstStmt]                          = "FirstStmt";
  stats[CXCursor_UnexposedStmt]                      = "UnexposedStmt";
  stats[CXCursor_LabelStmt]                          = "LabelStmt";
  stats[CXCursor_CompoundStmt]                       = "CompoundStmt";
  stats[CXCursor_CaseStmt]                           = "CaseStmt";
  stats[CXCursor_DefaultStmt]                        = "DefaultStmt";
  stats[CXCursor_IndirectGotoStmt]                   = "IndirectGotoStmt";
  stats[CXCursor_ContinueStmt]                       = "ContinueStmt";
  stats[CXCursor_AsmStmt]                            = "AsmStmt";
  stats[CXCursor_ObjCAtTryStmt]                      = "ObjCAtTryStmt";
  stats[CXCursor_ObjCAtCatchStmt]                    = "ObjCAtCatchStmt";
  stats[CXCursor_ObjCAtFinallyStmt]                  = "ObjCAtFinallyStmt";
  stats[CXCursor_ObjCAtThrowStmt]                    = "ObjCAtThrowStmt";
  stats[CXCursor_ObjCAtSynchronizedStmt]             = "ObjCAtSynchronizedStmt";
  stats[CXCursor_ObjCAutoreleasePoolStmt]            = "ObjCAutoreleasePoolStmt";
  stats[CXCursor_ObjCForCollectionStmt]              = "ObjCForCollectionStmt";
  stats[CXCursor_CXXCatchStmt]                       = "CXXCatchStmt";
  stats[CXCursor_CXXTryStmt]                         = "CXXTryStmt";
  stats[CXCursor_CXXForRangeStmt]                    = "CXXForRangeStmt";
  stats[CXCursor_SEHTryStmt]                         = "SEHTryStmt";
  stats[CXCursor_SEHExceptStmt]                      = "SEHExceptStmt";
  stats[CXCursor_SEHFinallyStmt]                     = "SEHFinallyStmt";
  stats[CXCursor_NullStmt]                           = "NullStmt";
  stats[CXCursor_DeclStmt]                           = "DeclStmt";
  stats[CXCursor_TranslationUnit]                    = "TranslationUnit";
  stats[CXCursor_FirstAttr]                          = "FirstAttr";
  stats[CXCursor_UnexposedAttr]                      = "UnexposedAttr";
  stats[CXCursor_IBActionAttr]                       = "IBActionAttr";
  stats[CXCursor_IBOutletAttr]                       = "IBOutletAttr";
  stats[CXCursor_IBOutletCollectionAttr]             = "IBOutletCollectionAttr";
  stats[CXCursor_CXXFinalAttr]                       = "CXXFinalAttr";
  stats[CXCursor_CXXOverrideAttr]                    = "CXXOverrideAttr";
  stats[CXCursor_AnnotateAttr]                       = "AnnotateAttr";
  stats[CXCursor_PreprocessingDirective]             = "PreprocessingDirective";
  stats[CXCursor_MacroDefinition]                    = "MacroDefinition";
  stats[CXCursor_MacroExpansion]                     = "MacroExpansion";

  stats[Cat_Misc]                                    = "Misc";
  stats[Cat_Declaration]                             = "Declarations";
  stats[Cat_Statement]                               = "Statements";
  stats[Cat_Loop]                                    = "Loops";
  stats[Cat_Condition]                               = "Conditions";
  stats[Cat_Function]                                = "Functions";
  stats[Cat_Call]                                    = "Calls";
}

#endif

