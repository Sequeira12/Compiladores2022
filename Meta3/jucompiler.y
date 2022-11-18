 //Rui Santos 2020225542
 //Bruno Sequeira 2020235721

%{
	#include <string.h>
	#include <stdbool.h>
	#include <stdio.h>
	#include "structures.h"
	#include "functions.h"
	#include "y.tab.h"
	no aux=NULL;
	no auxi2=NULL;
	bool flagErro = true;
	no raiz;
    int yylex(void);
    void yyerror (char *s);
    int yyparse(void);
	extern id_info id;

	char *auxx[3];
	

%}

%union{
    char* id[3];
    struct node *no;
	struct id_info *id_i;	
};





%token <id> AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR CLASS DOTLENGTH ELSE IF PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE INT DOUBLE BOOL RESERVED

%token <id> ID
%token <id> INTLIT
%token <id> REALLIT
%token <id> BOOLLIT
%token <id> STRLIT

%type <no> Expr1 Expr2  Program declaration MethodDecl FieldDecl CmId Type MethodHeader FormalParams FormalParamsSec MethodBody MethodBodySec VarDecl Statement StatementSec StatementPrint MethodInvocation MethodInvocationSec MethodInvocationThird Assignment ParseArgs  Expr  ExprReturn

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
Program:	CLASS ID LBRACE declaration RBRACE						{raiz = CriaNo(NULL,"","Program");
																	aux = CriaNo($2,NULL,"Id");
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

MethodDecl:	PUBLIC STATIC MethodHeader MethodBody					{$$ = CriaNo(NULL,"","MethodDecl");
																	AdicionaNo($$,$3);
																	AdicionaIrmao($3,$4);}		
																
		;

FieldDecl:	PUBLIC STATIC Type ID CmId SEMICOLON				{$$ = CriaNo(NULL,"","FieldDecl");
																	AdicionaNo($$,$3);
																	AdicionaIrmao($3,CriaNo($4,NULL,"Id"));

																	if ( $5 != NULL ) {
																		aux = $5;
																		while(aux != NULL){
																			no aux1 = CriaNo(NULL,"","FieldDecl");
																			no aux2 = CriaNo(NULL,$3->valor,$3->s_type);
																			AdicionaNo(aux1,aux2);
																			AdicionaIrmao(aux2,CriaNo(NULL,aux->valor,"Id"));
																			AdicionaIrmao($$,aux1);
																			aux = aux->irmao;
																		}		
																		free(aux);
																	}
																	}
			| error SEMICOLON											{$$ = NULL;flagErro = false;}
;
CmId:
			COMMA ID CmId											{$$ = CriaNo($2,NULL,"Id");
																		AdicionaIrmao($$,$3);
																	}	
			|/* null */												{$$ = NULL;}	
		;

Type:	BOOL														{$$ = CriaNo(NULL,"","Bool");}	
	|	INT															{$$ = CriaNo(NULL,"","Int");}
	|	DOUBLE														{$$ = CriaNo(NULL,"","Double");}
	;

MethodHeader:	Type ID LPAR FormalParams RPAR						{$$ = CriaNo(NULL,"","MethodHeader");
																	AdicionaNo($$,$1);
																	AdicionaIrmao($1,CriaNo($2,NULL,"Id"));
																	aux = CriaNo(NULL,"","MethodParams");
																	AdicionaIrmao($1,aux);
																	AdicionaNo(aux,$4);
																	}		
																															
			|	VOID ID LPAR FormalParams RPAR						{$$ = CriaNo(NULL,"","MethodHeader");
																	aux = CriaNo(NULL,"","Void");
																	AdicionaNo($$,aux);
																	AdicionaIrmao(aux,CriaNo($2,NULL,"Id"));
																	auxi2 = CriaNo(NULL,"","MethodParams");
																	AdicionaIrmao(aux,auxi2);
																	AdicionaNo(auxi2,$4);
																	}	
			;

FormalParams:	Type ID FormalParamsSec								{$$ = CriaNo(NULL,"","ParamDecl");
																	AdicionaNo($$,$1);
																	aux=CriaNo($2,NULL,"Id");
																	AdicionaIrmao($1,aux);
																	AdicionaIrmao($$,$3);}		
																																		
			|	STRING LSQ RSQ ID									{$$ = CriaNo(NULL,"","ParamDecl");
																	aux = CriaNo(NULL,"","StringArray");
																	AdicionaNo($$,aux);
																	AdicionaIrmao(aux,CriaNo($4,NULL,"Id"));}	
			|/* null */												{$$ = NULL;}
			;

FormalParamsSec:				
				COMMA Type ID FormalParamsSec 						{$$ = CriaNo(NULL,"","ParamDecl");
																	aux=CriaNo($3,NULL,"Id");
																	AdicionaNo($$,$2);
																	AdicionaIrmao($2,aux);
																	AdicionaIrmao($$,$4);}		
			|/* null */												{$$ = NULL;}							
			;

MethodBody:	LBRACE MethodBodySec RBRACE								{$$ = CriaNo(NULL,"","MethodBody");
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

VarDecl:	Type ID CmId SEMICOLON							{$$ = CriaNo(NULL,"","VarDecl");
																	AdicionaNo($$,$1);
																	AdicionaIrmao($1,CriaNo($2,NULL,"Id"));
																	if ($3){
																		aux = $3;
																		while(aux != NULL){
																			no aux1 = CriaNo(NULL,"","VarDecl");
																			no aux2 = CriaNo(NULL,$1->valor,$1->s_type);
																			AdicionaNo(aux1,aux2);
																			AdicionaIrmao(aux2,CriaNo(NULL,aux->valor,"Id"));
																			AdicionaIrmao($$,aux1);
																			aux = aux->irmao;
																		}	
																		free(aux);
																															
																	}}
		;

Statement:	LBRACE StatementSec RBRACE								{if(conta_irmaos($2)>1){
																		aux = CriaNo(NULL,"","Block");
																		$$=aux;
																		AdicionaNo(aux,$2);
																	}else{$$=$2;}
																	}	

		|	IF LPAR Expr RPAR Statement %prec  ELSE       			{$$ = CriaNo(NULL,"","If");
																	AdicionaNo($$,$3);
																	aux=CriaNo(NULL,"","Block");
																	if(conta_irmaos($5) == 1 && $5){
																		AdicionaIrmao($3,$5);
																		AdicionaIrmao($5,aux);
																		}else{
																			AdicionaIrmao($3,aux);
																			AdicionaNo(aux,$5);
																			AdicionaIrmao(aux,CriaNo(NULL,"","Block"));
																		}
																	}		
		|	IF LPAR Expr RPAR Statement ELSE Statement				{$$ = CriaNo(NULL,"","If");
																	AdicionaNo($$,$3); 
																	aux = CriaNo(NULL,"","Block");
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
																			auxi2 = CriaNo(NULL,"","Block");
																			AdicionaIrmao(aux, auxi2);
																			AdicionaNo(auxi2, $7);
																		}
																	}
																	}


		|	WHILE LPAR Expr RPAR Statement							{$$ = CriaNo(NULL,"","While");
																	AdicionaNo($$,$3);
																	if(conta_irmaos($5) == 1 && $5){
																		AdicionaIrmao($3,$5);
																	}else{
																		aux = CriaNo(NULL,"","Block");
																		AdicionaIrmao($3,aux);
																		AdicionaNo(aux,$5);
																		}
																	}

	
		|	RETURN ExprReturn SEMICOLON								{$$ = CriaNo(NULL,"","Return");
																	AdicionaNo($$,$2);}			
		
		|	MethodInvocation SEMICOLON								{$$ = $1;}
		|	Assignment	SEMICOLON									{$$ = $1;}
		|	ParseArgs SEMICOLON										{$$ = $1;}	
		|	SEMICOLON												{$$ = NULL;}
		|	PRINT LPAR StatementPrint RPAR SEMICOLON				{$$ = CriaNo(NULL,"","Print");
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
			|	STRLIT												{$$ = CriaNo($1,NULL,"StrLit");}			
			;


MethodInvocation:	ID LPAR MethodInvocationSec RPAR  				{$$ = CriaNo(NULL,"","Call");
																	aux = CriaNo($1,NULL,"Id");
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

Assignment:	ID ASSIGN Expr											{$$ = CriaNo(NULL,"","Assign");
																	aux = CriaNo($1,NULL,"Id");
																	AdicionaNo($$,aux);
																	AdicionaIrmao(aux,$3);}
		;

ParseArgs:	PARSEINT LPAR ID LSQ Expr RSQ RPAR						{$$ = CriaNo(NULL,"","ParseArgs");
																	aux = CriaNo($3,NULL,"Id");
																	AdicionaNo($$,aux);
																	AdicionaIrmao(aux,$5);}					
		|	PARSEINT LPAR error RPAR								{$$ = NULL;flagErro=false;}	
			;



Expr: Assignment													{$$ = $1;}
	| Expr1															{$$ = $1;}
	;


Expr1:	Expr1 PLUS Expr1											{$$ = CriaNo(NULL,"","Add");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 MINUS Expr1									{$$ = CriaNo(NULL,"","Sub");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 STAR Expr1									{$$ = CriaNo(NULL,"","Mul");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 DIV Expr1										{$$ = CriaNo(NULL,"","Div");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 MOD Expr1										{$$ = CriaNo(NULL,"","Mod");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 AND Expr1										{$$ = CriaNo(NULL,"","And");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 OR Expr1										{$$ = CriaNo(NULL,"","Or");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 XOR Expr1										{$$ = CriaNo(NULL,"","Xor");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 LSHIFT Expr1									{$$ = CriaNo(NULL,"","Lshift");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 RSHIFT Expr1									{$$ = CriaNo(NULL,"","Rshift");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr1 EQ Expr1										{$$ = CriaNo(NULL,"","Eq");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}		
			|	Expr1 GE Expr1										{$$ = CriaNo(NULL,"","Ge");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}		
			|	Expr1 GT Expr1										{$$ = CriaNo(NULL,"","Gt");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}	
			|	Expr1 LE Expr1										{$$ = CriaNo(NULL,"","Le");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}	
			|	Expr1 LT Expr1										{$$ = CriaNo(NULL,"","Lt");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}	
			|	Expr1 NE Expr1										{$$ = CriaNo(NULL,"","Ne");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}	
			|	Expr2												{$$ = $1;}
			;

Expr2:  NOT Expr2													{$$ = CriaNo(NULL,"","Not");AdicionaNo($$,$2);}
		|	PLUS Expr2                    							{$$ = CriaNo(NULL,"","Plus");AdicionaNo($$,$2);}	
		|	MINUS Expr2												{$$ = CriaNo(NULL,"","Minus");AdicionaNo($$,$2);}
		|	MethodInvocation										{$$ = $1;}
		|	ParseArgs												{$$ = $1;}
		|	LPAR Expr RPAR										    {$$ = $2;}
		|	LPAR error RPAR											{$$ = NULL;flagErro = false;}
		|	ID														{$$ = CriaNo($1,NULL,"Id");}
		|	ID DOTLENGTH											{$$ = CriaNo(NULL,"","Length");AdicionaNo($$,CriaNo($1,NULL,"Id"));}
		|	INTLIT													{$$ = CriaNo($1,NULL,"DecLit");}
		|	REALLIT													{$$ = CriaNo($1,NULL,"RealLit");}
		|	BOOLLIT													{$$ = CriaNo($1,NULL,"BoolLit");}		
	
		;
%%





