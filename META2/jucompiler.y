%{
	#include <string.h>
	#include <stdbool.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "functions.h"
	
	int linha,coluna;
	int linhaaux,colunaaux;
	node* aux=NULL;
	node* auxi2=NULL;
	
	bool imprime;
	char string[254];
	
	node* program=NULL;
    int yylex(void);
   	void yyerror (char *s);
    int yyparse(void);
	

%}

%union{
    char* id;
    struct node *N_no;
};





%token AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR CLASS DOTLENGTH ELSE IF PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE INT DOUBLE BOOL RESERVED

%token <id> ID
%token <id> INTLIT
%token <id> REALLIT
%token <id> BOOLLIT
%token <id> STRLIT

%type <N_no> Program declaration MethodDecl FieldDecl FindDeclSec Type MethodHeader MethodHeaderSec FormalParams FormalParamsSec MethodBody MethodBodySec VarDecl VarDeclSec Statement StatementSec  StatementThird StatementPrint MethodInvocation MethodInvocationSec MethodInvocationThird Assignment ParseArgs  Expr  

%right ASSIGN
%left OR
%left AND
%left XOR
%left EQ NE
%left GE GT LE LT
%left LSHIFT RSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%left LPAR RPAR LSQ RSQ

%right ELSE

%%

Program:	CLASS ID LBRACE declaration RBRACE									{program = NovoNo("Program");AdicionaFilho($$,NovoID("Id",$2));AdicionaFilho($$,$4);}		
		;

declaration: 
				MethodDecl declaration																{$$ = $1;AdicionaIrmao($$,$2);}			
			|	FieldDecl declaration																	{$$ = $1;AdicionaIrmao($$,$2);}					
			|	SEMICOLON declaration																	{$$ = $2;}			
			|	/* null */																						{$$ = NULL;}		
			;

MethodDecl:	PUBLIC STATIC MethodHeader MethodBody							{$$ = NovoNo("MethodDecl");AdicionaFilho($$,$3);AdicionaFilho($$,$4);}		
																
		;

FieldDecl:	PUBLIC STATIC Type ID FindDeclSec SEMICOLON				{$$ = NovoNo("FieldDecl");AdicionaFilho($$,$3);AdicionaFilho($$,NovoID("Id",$4));}		
	
;
FindDeclSec:
			COMMA ID FindDeclSec																		{$$ = NovoID("Id",$2);AdicionaIrmao($$,$3);}	
			|/* null */										{$$ = NULL;}	
		;

Type:	BOOL																										{$$ = NovoNo("Bool");}	
	|	INT																												{$$ = NovoNo("Int");}
	|	DOUBLE																										{$$ = NovoNo("Double");}
	;

MethodHeader:	Type ID LPAR MethodHeaderSec RPAR								{$$ = NovoNo("MethodHeader");AdicionaFilho($$,$1);AdicionaFilho($$,NovoID("Id",$2));
aux = NovoNo("MethodParams");AdicionaIrmao($1,aux);AdicionaFilho(aux,$4);}	
	
			|	VOID ID LPAR MethodHeaderSec RPAR											{$$ = NovoNo("MethodHeader");aux = NovoNo("Void");AdicionaFilho($$,aux);AdicionaIrmao(aux,NovoID("Id",$2));auxi2 = NovoNo("MethodParams");AdicionaIrmao(aux,auxi2);AdicionaFilho(auxi2,$4);}	
			
			;

MethodHeaderSec:	
				FormalParams																					{$$ = $1;}
			|/* null */																							{$$ = NULL;}																						
			;

FormalParams:	Type ID FormalParamsSec													{$$ = NovoNo("ParamDecl");AdicionaFilho($$,$1);aux=NovoID("Id",$2);AdicionaIrmao($1,aux);AdicionaIrmao($$,$3);}					
			|	STRING LSQ RSQ ID																			{$$ = NovoNo("ParamDecl");aux = NovoNo("StringArray");AdicionaFilho($$,aux);AdicionaIrmao(aux,NovoID("Id",$4));}	
			;

FormalParamsSec:				
				COMMA Type ID FormalParamsSec 												{$$ = NovoNo("ParamDecl");aux=NovoID("Id",$3);AdicionaFilho($$,$2);AdicionaIrmao($$,aux);AdicionaIrmao($$,$4);}		
			|/* null */																							{$$ = NULL;}							
			;

MethodBody:	LBRACE MethodBodySec RBRACE												{$$ = NovoNo("MethodBody");AdicionaFilho($$,$2);}						
		;

MethodBodySec: 	
				Statement MethodBodySec																{if($1 != NULL){
				$$ = $1; AdicionaIrmao($$,$2);}else{$$=$2;}}		
			|	VarDecl MethodBodySec																	{$$ = $1;AdicionaIrmao($$,$2);}	
			|	/* nulL */																						{$$ = NULL;}											
			;

//NOT FINISHED
VarDecl:	Type ID VarDeclSec SEMICOLON												{$$ = NovoNo("VarDecl");AdicionaFilho($$,$1);AdicionaFilho($$,NovoID("Id",$2));}						
		;

VarDeclSec:	/* null */																				{$$ = NULL;}					
		|	COMMA ID VarDeclSec																			{$$ = NovoID("Id",$2);AdicionaIrmao($$,$3);}		
		;

Statement:	LBRACE StatementSec RBRACE												{if(conta_irmaos($2)>1){aux = NovoNo("Block");$$=aux;AdicionaFilho(aux,$2);}else{$$=$2;}}	
		|	IF LPAR Expr RPAR Statement         										{$$ = NovoNo("If");AdicionaFilho($$,$3);aux=NovoNo("Block");
																											if(conta_irmaos($5) == 1 && $5 != NULL){																																	
																																	
																																	AdicionaIrmao($3,$5);AdicionaIrmao($5,aux);}																				else{AdicionaIrmao($3,aux);AdicionaFilho(aux,$5);
																																				AdicionaIrmao(aux,aux);}}	
		
		|	IF LPAR Expr RPAR Statement ELSE Statement							{$$ = NovoNo("If");AdicionaFilho($$,$3); aux = NovoNo("Block");if (conta_irmaos($5) == 1 && $5 != NULL) {AdicionaIrmao($3, $5);if (conta_irmaos($7) == 1 && $7 != NULL) {AdicionaIrmao($5, $7);}else {AdicionaIrmao($5, aux);AdicionaFilho(aux, $7);}}else {AdicionaIrmao($3, aux);AdicionaFilho(aux, $5);if (conta_irmaos($7) == 1 && $7 != NULL) {AdicionaIrmao(aux, $7);
}else {auxi2 = NovoNo("Block");AdicionaIrmao(aux, auxi2);AdicionaFilho(auxi2, $7);}}}
		|	WHILE LPAR Expr RPAR Statement													{$$ = NovoNo("While");AdicionaFilho($$,$3);if(conta_irmaos($5) == 1 && $5 != NULL){AdicionaIrmao($3,$5);}else{aux = NovoNo("Block");AdicionaIrmao($3,aux);AdicionaFilho(aux,$5);}}			
		|	RETURN SEMICOLON																				{$$ = NovoNo("Return");}			
		|	RETURN Expr SEMICOLON																		{$$ = NovoNo("Return");AdicionaFilho($$,$2);}			
		|	StatementThird SEMICOLON																{$$ = $1;}		
		|	PRINT LPAR StatementPrint RPAR SEMICOLON								{$$ = NovoNo("Print");AdicionaFilho($$,$3);}	
																	
		
		;
StatementSec:	
			Statement StatementSec																	{if($1 != NULL){$$=$1;AdicionaIrmao($$,$2);}else{$$=$2;};}			
			| /* null */																						{$$ = NULL;}		
		;


StatementThird:	/* null */																		{$$ = NULL;}
		|	MethodInvocation																				{$$ = $1;}
		|	Assignment																							{$$ = $1;}
		|	ParseArgs																								{$$ = $1;}
		;

StatementPrint:	Expr																					{$$ = $1;}
			|	STRLIT																								{$$ = NULL;}			
			;


//COLOCAR ERRO AQUI TBM
MethodInvocation:	ID LPAR MethodInvocationSec RPAR  					{$$ = NovoNo("Call");AdicionaFilho($$,NovoID("Id",$1));AdicionaFilho($$,$3);}					
				
				;

MethodInvocationSec:
					Expr MethodInvocationThird													{$$ = $1;AdicionaIrmao($$,$2);}
					|/* null */																					{$$ = NULL;}		
				;


MethodInvocationThird:		COMMA Expr MethodInvocationThird		{if($2!=NULL){$$=$2;AdicionaIrmao($$,$3);}else{$$=$2;}}
				| /* null */																					{$$ = NULL;}		
					;

Assignment:	ID ASSIGN Expr																		{$$ = NovoNo("Assign");AdicionaFilho($$,NovoID("Id",$1));AdicionaFilho($$,$3);}
		;

ParseArgs:	PARSEINT LPAR ID LSQ Expr RSQ RPAR							{$$ = NovoNo("ParseArgs");AdicionaFilho($$,NovoID("Id",$3));AdicionaFilho($$,$5);}					
		|	PARSEINT LPAR error RPAR																{$$ = NULL;}	//COLOCAR O ERRO
			;

Expr:	Expr PLUS Expr											   	{$$ = NovoNo("Add");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}
			|	Expr MINUS Expr												{$$ = NovoNo("Sub");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}
			|	Expr STAR Expr												{$$ = NovoNo("Mul");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}
			|	Expr DIV Expr													{$$ = NovoNo("Div");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}
			|	Expr MOD Expr													{$$ = NovoNo("Mod");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}
			|	Expr AND Expr													{$$ = NovoNo("And");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}
			|	Expr OR Expr													{$$ = NovoNo("Or");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}
			|	Expr XOR Expr													{$$ = NovoNo("Xor");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}
			|	Expr LSHIFT Expr											{$$ = NovoNo("Lshift");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}
			|	Expr RSHIFT Expr											{$$ = NovoNo("Rshift");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}
			|	Expr EQ Expr													{$$ = NovoNo("Eq");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}		
			|	Expr GE Expr													{$$ = NovoNo("Ge");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}		
			|	Expr GT Expr													{$$ = NovoNo("Gt");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}	
			|	Expr LE Expr													{$$ = NovoNo("Le");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}	
			|	Expr LT Expr													{$$ = NovoNo("Lt");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}	
			|	Expr NE Expr													{$$ = NovoNo("Ne");AdicionaFilho($$,$1);AdicionaFilho($$,$3);}	
			|	PLUS Expr                       			{$$ = NovoNo("Plus");AdicionaFilho($$,$2);}	
			|	MINUS Expr 														{$$ = NovoNo("Minus");AdicionaFilho($$,$2);}	
			|	NOT Expr															{$$ = NovoNo("Not");AdicionaFilho($$,$2);}
			|	MethodInvocation											{$$ = $1;}
			|	ParseArgs															{$$ = $1;}
			|	LPAR error RPAR												{$$ = NULL;}	//COLOCAR O ERRO criar flag
			|	ID																		{$$ = NovoID("Id",$1);printf("IDDD");}
			|	ID DOTLENGTH													{$$ = NovoNo("Length");}
			|INTLIT																	{$$ = NovoID("IntLit",$1);}
			|	REALLIT																{$$ = NovoID("RealLit",$1);}
			|	BOOLLIT																{$$ = NovoID("BoolLit",$1);}		
	;



%%


void yyerror( char  *s){
	fprintf(stderr,"%s\n",s);
}
