%{
	#include <string.h>
	#include <stdbool.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "functions.h"
	

	no aux=NULL;
	no auxi2=NULL;
	bool flagErro = true;

	no raiz;
    int yylex(void);
    void yyerror (char *s);
    int yyparse(void);
	

%}

%union{
    char* id;
    struct node *no;
};





%token AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR CLASS DOTLENGTH ELSE IF PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE INT DOUBLE BOOL RESERVED

%token <id> ID
%token <id> INTLIT
%token <id> REALLIT
%token <id> BOOLLIT
%token <id> STRLIT

%type <no> Expr1 Expr2  Program declaration MethodDecl FieldDecl FindDeclSec Type MethodHeader FormalParams FormalParamsSec MethodBody MethodBodySec VarDecl VarDeclSec Statement StatementSec StatementPrint MethodInvocation MethodInvocationSec MethodInvocationThird Assignment ParseArgs  Expr  ExprReturn

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

																	// Criação do no principal, Program
Program:	CLASS ID LBRACE declaration RBRACE						{raiz = CriaNo("","Program");
																	aux = CriaNo($2,"Id");
																	AdicionaNo(raiz,aux);
																	AdicionaIrmao(aux,$4);
																	$$ = raiz;		
																	}
		
			|CLASS ID LBRACE declaration RBRACE	error				{$$ = NULL;flagErro = false;}
		;

declaration: 
			MethodDecl declaration									{$$ = $1;AdicionaIrmao($$,$2);}			
		|	FieldDecl declaration									{$$ = $1;AdicionaIrmao($$,$2);}					
		|	SEMICOLON declaration									{$$ = $2;}			
		|	/* null */												{$$ = NULL;}		
			;

MethodDecl:	PUBLIC STATIC MethodHeader MethodBody					{$$ = CriaNo("","MethodDecl");
																	AdicionaNo($$,$3);
																	AdicionaIrmao($3,$4);}		
																
		;

FieldDecl:	PUBLIC STATIC Type ID FindDeclSec SEMICOLON				{$$ = CriaNo("","FieldDecl");
																	AdicionaNo($$,$3);
																	AdicionaIrmao($3,CriaNo($4,"Id"));

																	if ( $5 != NULL ) {
																		aux = $5;
																		while(aux != NULL){
																			no aux1 = CriaNo("","FieldDecl");
																			no aux2 = CriaNo($3->valor,$3->s_type);
																			AdicionaNo(aux1,aux2);
																			AdicionaIrmao(aux2,CriaNo(aux->valor,"Id"));
																			AdicionaIrmao($$,aux1);
																			aux = aux->irmao;
																		}		
																		free(aux);
																	}
																	}
			| error SEMICOLON											{$$ = NULL;flagErro = false;}
;
FindDeclSec:
			COMMA ID FindDeclSec									{$$ = CriaNo($2,"Id");
																	AdicionaIrmao($$,$3);
																	}	
			|/* null */												{$$ = NULL;}	
		;

Type:	BOOL														{$$ = CriaNo("","Bool");}	
	|	INT															{$$ = CriaNo("","Int");}
	|	DOUBLE														{$$ = CriaNo("","Double");}
	;

MethodHeader:	Type ID LPAR FormalParams RPAR					{$$ = CriaNo("","MethodHeader");
																	AdicionaNo($$,$1);
																	AdicionaIrmao($1,CriaNo($2,"Id"));
																	aux = CriaNo("","MethodParams");
																	AdicionaIrmao($1,aux);
																	AdicionaNo(aux,$4);
																	}		
																															
			|	VOID ID LPAR FormalParams RPAR					{$$ = CriaNo("","MethodHeader");
																	aux = CriaNo("","Void");
																	AdicionaNo($$,aux);
																	AdicionaIrmao(aux,CriaNo($2,"Id"));
																	auxi2 = CriaNo("","MethodParams");
																	AdicionaIrmao(aux,auxi2);
																	AdicionaNo(auxi2,$4);
																	}	
			;

FormalParams:	Type ID FormalParamsSec								{$$ = CriaNo("","ParamDecl");
																	AdicionaNo($$,$1);
																	aux=CriaNo($2,"Id");
																	AdicionaIrmao($1,aux);
																	AdicionaIrmao($$,$3);}		
																																		
			|	STRING LSQ RSQ ID									{$$ = CriaNo("","ParamDecl");
																	aux = CriaNo("","StringArray");
																	AdicionaNo($$,aux);
																	AdicionaIrmao(aux,CriaNo($4,"Id"));}	
			|/* null */												{$$ = NULL;}
			;

FormalParamsSec:				
				COMMA Type ID FormalParamsSec 						{$$ = CriaNo("","ParamDecl");
																	aux=CriaNo($3,"Id");
																	AdicionaNo($$,$2);
																	AdicionaIrmao($2,aux);
																	AdicionaIrmao($$,$4);}		
			|/* null */												{$$ = NULL;}							
			;

MethodBody:	LBRACE MethodBodySec RBRACE								{$$ = CriaNo("","MethodBody");
																	AdicionaNo($$,$2);
																	}						
		;

MethodBodySec: 	
				Statement MethodBodySec								{if($1 != NULL){
																		$$ = $1; 
																		AdicionaIrmao($$,$2);
																	}else{
																		$$=$2;}
																	}		
			|	VarDecl MethodBodySec								{$$ = $1;
																	AdicionaIrmao($$,$2);
																	}	
			|	/* null */											{$$ = NULL;}											
			;

VarDecl:	Type ID VarDeclSec SEMICOLON							{$$ = CriaNo("","VarDecl");
																	AdicionaNo($$,$1);
																	AdicionaIrmao($1,CriaNo($2,"Id"));
																	if ($3){
																		aux = $3;
																		while(aux != NULL){
																			no aux1 = CriaNo("","VarDecl");
																			no aux2 = CriaNo($1->valor,$1->s_type);
																			AdicionaNo(aux1,aux2);
																			AdicionaIrmao(aux2,CriaNo(aux->valor,"Id"));
																			AdicionaIrmao($$,aux1);
																			aux = aux->irmao;
																		}	
																		free(aux);
																															
																	}}
		;

VarDeclSec:	/* null */												{$$ = NULL;}					
		|	COMMA ID VarDeclSec										{$$ = CriaNo($2,"Id");
																	AdicionaIrmao($$,$3);}		
		;

Statement:	LBRACE StatementSec RBRACE								{if(conta_irmaos($2)>1){
																		aux = CriaNo("","Block");
																		$$=aux;
																		AdicionaNo(aux,$2);
																	}else{$$=$2;}
																															}	
		|	IF LPAR Expr RPAR Statement %prec  ELSE       			{$$ = CriaNo("","If");
																	AdicionaNo($$,$3);
																	aux=CriaNo("","Block");
																	if(conta_irmaos($5) == 1 && $5){
																		AdicionaIrmao($3,$5);
																		AdicionaIrmao($5,aux);
																		}else{
																			AdicionaIrmao($3,aux);
																			AdicionaNo(aux,$5);
																			AdicionaIrmao(aux,CriaNo("","Block"));
																		}
																	}		
		|	IF LPAR Expr RPAR Statement ELSE Statement				{$$ = CriaNo("","If");
																	AdicionaNo($$,$3); 
																	aux = CriaNo("","Block");
																	if (conta_irmaos($5) == 1 && $5) {
																		AdicionaIrmao($3, $5);
																		if (conta_irmaos($7) == 1 && $7) {
																			AdicionaIrmao($5, $7);
																		}else {
																			AdicionaIrmao($5, aux);
																			AdicionaNo(aux, $7);}
																	}else {
																		AdicionaIrmao($3, aux);
																		AdicionaNo(aux, $5);
																		if (conta_irmaos($7) == 1 && $7) {
																			AdicionaIrmao(aux, $7);
																		}else {
																			auxi2 = CriaNo("","Block");
																			AdicionaIrmao(aux, auxi2);
																			AdicionaNo(auxi2, $7);
																		}
																	}
																	}


		|	WHILE LPAR Expr RPAR Statement							{$$ = CriaNo("","While");
																	AdicionaNo($$,$3);
																	if(conta_irmaos($5) == 1 && $5){
																		AdicionaIrmao($3,$5);
																	}else{
																		aux = CriaNo("","Block");
																		AdicionaIrmao($3,aux);
																		AdicionaNo(aux,$5);
																		}
																	}

	
		|	RETURN ExprReturn SEMICOLON								{$$ = CriaNo("","Return");
																	AdicionaNo($$,$2);}			
		
		|	MethodInvocation SEMICOLON								{$$ = $1;}
		|	Assignment	SEMICOLON									{$$ = $1;}
		|	ParseArgs SEMICOLON										{$$ = $1;}	
		|	SEMICOLON												{$$ = NULL;}
		|	PRINT LPAR StatementPrint RPAR SEMICOLON				{$$ = CriaNo("","Print");
																	AdicionaNo($$,$3);
																	}	
		| error SEMICOLON 											{$$=NULL;flagErro=false;}
																	
		
		;
		
ExprReturn:	{$$=NULL;}
	| Expr 	 		{$$=$1;}

;		
StatementSec:	
			Statement StatementSec									{if($1){
																		$$=$1;
																		AdicionaIrmao($$,$2);
																	}else{
																		$$=$2;}
			}			
			| /* null */											{$$ = NULL;}		
		;



StatementPrint:	Expr												{$$ = $1;}
			|	STRLIT												{$$ = CriaNo($1,"StrLit");}			
			;


MethodInvocation:	ID LPAR MethodInvocationSec RPAR  				{$$ = CriaNo("","Call");
																	aux = CriaNo($1,"Id");
																	AdicionaNo($$,aux);
																	AdicionaIrmao(aux,$3);}					
			|	ID LPAR error RPAR									{$$ = NULL;flagErro = false;}
				;

MethodInvocationSec:
					Expr MethodInvocationThird						{$$ = $1;AdicionaIrmao($$,$2);}
					|/* null */										{$$ = NULL;}		
				;

																	//verificar se é NULL ou não
MethodInvocationThird:		COMMA Expr MethodInvocationThird		{if($2){
																		$$=$2;
																		AdicionaIrmao($$,$3);
																	}else{$$=$2;}}
				| /* null */										{$$ = NULL;}		
					;

Assignment:	ID ASSIGN Expr											{$$ = CriaNo("","Assign");
																	aux = CriaNo($1,"Id");
																	AdicionaNo($$,aux);
																	AdicionaIrmao(aux,$3);}
		;

ParseArgs:	PARSEINT LPAR ID LSQ Expr RSQ RPAR						{$$ = CriaNo("","ParseArgs");
																	aux = CriaNo($3,"Id");
																	AdicionaNo($$,aux);
																	AdicionaIrmao(aux,$5);}					
		|	PARSEINT LPAR error RPAR								{$$ = NULL;flagErro=false;}	
			;



Expr: Assignment													{$$ = $1;}
	| Expr1															{$$ = $1;}
	;


Expr1:	Expr1 PLUS Expr1											{$$ = CriaNo("","Add");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 MINUS Expr1									{$$ = CriaNo("","Sub");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 STAR Expr1									{$$ = CriaNo("","Mul");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 DIV Expr1										{$$ = CriaNo("","Div");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 MOD Expr1										{$$ = CriaNo("","Mod");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 AND Expr1										{$$ = CriaNo("","And");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 OR Expr1										{$$ = CriaNo("","Or");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 XOR Expr1										{$$ = CriaNo("","Xor");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 LSHIFT Expr1									{$$ = CriaNo("","Lshift");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 RSHIFT Expr1									{$$ = CriaNo("","Rshift");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 EQ Expr1										{$$ = CriaNo("","Eq");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}		
			|	Expr1 GE Expr1										{$$ = CriaNo("","Ge");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}		
			|	Expr1 GT Expr1										{$$ = CriaNo("","Gt");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}	
			|	Expr1 LE Expr1										{$$ = CriaNo("","Le");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}	
			|	Expr1 LT Expr1										{$$ = CriaNo("","Lt");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}	
			|	Expr1 NE Expr1										{$$ = CriaNo("","Ne");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}	
			|	Expr2												{$$ = $1;}
			;

Expr2:  NOT Expr2													{$$ = CriaNo("","Not");AdicionaNo($$,$2);}
		|	PLUS Expr2                    							{$$ = CriaNo("","Plus");AdicionaNo($$,$2);}	
		|	MINUS Expr2												{$$ = CriaNo("","Minus");AdicionaNo($$,$2);}
		|	MethodInvocation										{$$ = $1;}
		|	ParseArgs												{$$ = $1;}
		|	LPAR Expr RPAR										    {$$ = $2;}
		|	LPAR error RPAR											{$$ = NULL;flagErro = false;}
		|	ID														{$$ = CriaNo($1,"Id");}
		|	ID DOTLENGTH											{$$ = CriaNo("","Length");AdicionaNo($$,CriaNo($1,"Id"));}
		|	INTLIT													{$$ = CriaNo($1,"DecLit");}
		|	REALLIT													{$$ = CriaNo($1,"RealLit");}
		|	BOOLLIT													{$$ = CriaNo($1,"BoolLit");}		
	
		;
%%





