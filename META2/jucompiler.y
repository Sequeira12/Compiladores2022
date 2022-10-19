


              



%{
	#include <string.h>
	#include <stdbool.h>
	int linha,coluna;
	int linhaaux,colunaaux;
	bool flag = false;
	bool imprime;
	char string[254];

%}

%union{
    char* lit;
    struct node *N_no;
};




%token	 NE NOT AND OR RBRACE LBRACE RPAR RSQ PARSEINT RETURN ELSE IF LSQ LPAR LE GE GT EQ LT PLUS MINUS DIV STAR ASSIGN COMMA SEMICOLON INT STRING WHILE DOTLENGTH STATIC DOUBLE PUBLIC CLASS VOID MOD XOR RSHIFT LSHIFT STRLIT BOOL PRINT 


%token <lit>  INTLIT REALLIT ID RESERVED BOOLIT
/*  
Da linha 35 à 45 foi copy com o grupo do ano passado mas nao resolve, falta mais cenas

*/
%left COMMA SEMICOLON
%right ASSIGN
%left OR 
%left AND
%left LT LE GT GE EQ NE
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%left LPAR RPAR LSQ RSQ
%nonassoc IF
%nonassoc ELSE

%type <N_no> Program declaration MethodDecl  FieldDecl FieldDeclSec Type MethodHeader MethodHeaderSec FormalParams FormalParamsSec MethodBody MethodBodySec VarDecl VarDeclSec Statement  StatementThird MethodInvocation MethodInvocationSec MethodInvocationThird Assignment ParseArgs Expr


%%

Program:
	CLASS ID LBRACE declaration RBRACE					{$$=NULL;}	// Program
	;
	
declaration:
	MethodDecl declaration							{$$=NULL;}			
	|FieldDecl declaration							{$$=NULL;}	
	|SEMICOLON declaration							{$$=NULL;}	
	| /*NULL*/								{$$=NULL;}
	;


MethodDecl:
	PUBLIC STATIC MethodHeader MethodBody					{$$=NULL;}	
;
FieldDecl:
	PUBLIC STATIC Type ID FieldDeclSec SEMICOLON				{$$=NULL;}	
	;
FieldDeclSec:
	COMMA ID								{$$=NULL;}	
	| /*NULL*/								{$$=NULL};
	;	
Type:
	 BOOL									{$$=NULL;}	
	| INT									{$$=NULL;}	
	| DOUBLE 								{$$=NULL;}	
	;

MethodHeader:
	Type ID LPAR MethodHeaderSec RPAR					{$$=NULL;}	
	| VOID ID LPAR MethodHeaderSec RPAR					{$$=NULL;}	
	;		
MethodHeaderSec:
	FormalParams								{$$=NULL;}	
	| /*NULL*/								{$$=NULL};
	;
FormalParams:
	Type ID FormalParamsSec						{$$=NULL;}	
	|STRING LSQ RSQ ID							{$$=NULL;}	
	;
FormalParamsSec:
	COMMA Type ID								{$$=NULL;}	
	| /*NULL*/								{$$=NULL};
	;
			
MethodBody:
	LBRACE MethodBodySec RBRACE						{$$=NULL;}	
	;
MethodBodySec:
	Statement								{$$=NULL;}	
	|VarDecl								{$$=NULL;}	
	| /*NULL*/								{$$=NULL};
	;
	
VarDecl:
	Type ID VarDeclSec SEMICOLON						{$$=NULL;}	
	;
VarDeclSec:
	COMMA ID								{$$=NULL;}	
	| /*NULL*/								{$$=NULL};
	;
	
Statement:
	StatementThird SEMICOLON						{$$=NULL;}	
	|IF LPAR Expr RPAR Statement						{$$=NULL;}	
	|IF LPAR Expr RPAR Statement ELSE Statement				{$$=NULL;}	
	|WHILE LPAR Expr RPAR Statement					{$$=NULL;}	
	|RETURN Expr SEMICOLON							{$$=NULL;}	
	|RETURN SEMICOLON							{$$=NULL;}
	|LBRACE Statement RBRACE						{$$=NULL;}	
	|PRINT LPAR Expr RPAR SEMICOLON					{$$=NULL;}	
	|PRINT LPAR STRLIT RPAR SEMICOLON					{$$=NULL;}	
	|/*NULL*/								{$$=NULL;}
	;


StatementThird:
	MethodInvocation							{$$=NULL;}	
	|Assignment								{$$=NULL;}	
	|ParseArgs								{$$=NULL;}	
	|/*NULL*/								{$$=NULL;}
	;


MethodInvocation:	
	ID LPAR MethodInvocationSec RPAR					{$$=NULL;}	
;
MethodInvocationSec:
	Expr MethodInvocationThird						{$$=NULL;}	
	| /*NULL*/								{$$=NULL};
	;
MethodInvocationThird:
	COMMA Expr MethodInvocationThird					{$$=NULL;}	
	| /*NULL*/								{$$=NULL};
	;
	

Assignment:
	 ID ASSIGN Expr							{$$=NULL;}	
	 ;


ParseArgs:
	 PARSEINT LPAR ID LSQ Expr RSQ RPAR					{$$=NULL;}	
	 ;
	 
	 


Expr:
	  Expr PLUS Expr		{printf("add\n");}
	| Expr MINUS Expr		{printf("sub\n");}
	| Expr STAR Expr		{printf("STar\n");}
	| Expr DIV Expr		{printf("Div\n");}
	| Expr MOD Expr		{printf("Mod\n");}
	| Expr AND Expr		{printf("And\n");}
	| Expr OR Expr			{printf("OR\n");}
	| Expr XOR Expr		{printf("XOR\n");}
	| Expr LSHIFT Expr		{printf("Lshift\n");}
	| Expr RSHIFT Expr		{printf("Rshift\n");}
	| Expr EQ Expr			{printf("Eq\n");}
	| Expr GE Expr			{printf("Ge\n");}
	| Expr GT Expr			{printf("Gt\n");}
	| Expr LE Expr			{printf("LE\n");}
	| Expr LT Expr			{printf("Lt\n");}
	| Expr NE Expr			{printf("Ne\n");}
	| MINUS Expr			{printf("Minus\n");}
	| NOT Expr			{printf("NOT\n");}
	| PLUS Expr 			{printf("PLUS\n");}
	| LPAR Expr RPAR 		{printf("");}
	| MethodInvocation 		{printf("Method");}
	| Assignment 			{printf("Assignment\n");}
	| ParseArgs			{printf("Parse\n");}
	| ID 				{printf("ID\n");}
	| ID DOTLENGTH			{printf("ID DOTLENGTH\n");}
	| INTLIT 			{printf("intlit\n");}				
	| REALLIT 			{printf("Reallit\n");}		
	| BOOLIT			{printf("Bool\n");}

	;
	
	


%%

