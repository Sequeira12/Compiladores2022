


              



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


%token <char>  INTLIT REALLIT ID RESERVED BOOLIT

%type <N_no> Program declaration MethodDecl  FieldDecl FieldDeclSec Type MethodHeader MethodHeaderSec FormalParams FormalParamsSec MethodBody MethodBodySec VarDecl VarDeclSec Statement  StatementThird MethodInvocation MethodInvocationSec MethodInvocationThird Assignment ParseArgs Expr


%%

Program:
	CLASS ID LBRACE declaration RBRACE					// Program
	;
	
declaration:
	MethodDecl declaration							
	|FieldDecl declaration
	|SEMICOLON declaration
	| /*NULL*/								{$$=NULL};
	;


MethodDecl:
	PUBLIC STATIC MethodHeader MethodBody
;
FieldDecl:
	PUBLIC STATIC Type ID FieldDeclSec SEMICOLON
	;
FieldDeclSec:
	COMMA ID
	| /*NULL*/								{$$=NULL};
	;	
Type:
	 BOOL
	| INT
	| DOUBLE 
	;

MethodHeader:
	Type ID LPAR MethodHeaderSec RPAR
	| VOID ID LPAR MethodHeaderSec RPAR
	;
MethodHeaderSec:
	FormalParams
	| /*NULL*/								{$$=NULL};
	;
FormalParams:
	Type ID FormalParamsSec
	|STRING LSQ RSQ ID
	;
FormalParamsSec:
	COMMA Type ID
	| /*NULL*/								{$$=NULL};
	;
			
MethodBody:
	LBRACE MethodBodySec RBRACE
	;
MethodBodySec:
	Statement
	|VarDecl
	| /*NULL*/								{$$=NULL};
	;
	
VarDecl:
	Type ID VarDeclSec SEMICOLON
	;
VarDeclSec:
	COMMA ID						
	| /*NULL*/								{$$=NULL};
	;
	
Statement:
	LBRACE Statement RBRACE
	|IF LPAR Expr RPAR Statement
	|IF LPAR Expr RPAR Statement ELSE Statement
	|WHILE LPAR Expr RPAR Statement
	|RETURN Expr SEMICOLON
	|RETURN SEMICOLON
	|StatementThird SEMICOLON
	|PRINT LPAR Expr RPAR SEMICOLON
	|PRINT LPAR STRLIT RPAR SEMICOLON
	|/*NULL*/								{$$=NULL;}
	;


StatementThird:
	MethodInvocation
	|Assignment
	|ParseArgs
	|/*NULL*/								{$$=NULL;}
	;


MethodInvocation:
	ID LPAR MethodInvocationSec RPAR		
;
MethodInvocationSec:
	Expr MethodInvocationThird
	| /*NULL*/								{$$=NULL};
	;
MethodInvocationThird:
	COMMA Expr MethodInvocationThird
	| /*NULL*/								{$$=NULL};
	;
	

Assignment:
	 ID ASSIGN Expr
	 ;


ParseArgs:
	 PARSEINT LPAR ID LSQ Expr RSQ RPAR
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
	| PLUS Expr			{printf("PLUS\n");}
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
int main(int argc, char *argv[]){
	linha=1,coluna=1; 
	
	
	if (argc > 1) {
		if (strcmp(argv[1],"-l") == 0) {
			flag = 1;
		}
		else if(strcmp(argv[1],"-e1") == 0) {
			flag = 0;
		}
	}
	else if (argc == 1){
		flag = 0;
	}
	yylex(); 
	return 0;
}

int yywrap() {
	return 1;
}
