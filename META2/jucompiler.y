%{
	#include <string.h>
	#include <stdbool.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "functions.h"
	
	int linha,coluna;
	int linhaaux,colunaaux;
	no aux=NULL;
	no auxi2=NULL;
	bool flagErro = true;
	bool imprime;
	char string[254];
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

%type <no> Program declaration MethodDecl FieldDecl FindDeclSec Type MethodHeader MethodHeaderSec FormalParams FormalParamsSec MethodBody MethodBodySec VarDecl VarDeclSec Statement StatementSec  StatementThird StatementPrint MethodInvocation MethodInvocationSec MethodInvocationThird Assignment ParseArgs  Expr  

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
Program:	CLASS ID LBRACE declaration RBRACE							{raiz = CriaNo(no_raiz,"","Program");
																		aux = CriaNo(no_ids,$2,"Id");
																		AdicionaNo(raiz,aux);
																		AdicionaIrmao(aux,$4);
																		$$ = raiz;		
																		if(flagErro == true)								
																			Arvore($$,0);
																		}
		;

declaration: 
				MethodDecl declaration									{$$ = $1;AdicionaIrmao($$,$2);}			
			|	FieldDecl declaration									{$$ = $1;AdicionaIrmao($$,$2);}					
			|	SEMICOLON declaration									{$$ = $2;}			
			|	/* null */												{$$ = NULL;}		
			;

MethodDecl:	PUBLIC STATIC MethodHeader MethodBody							{$$ = CriaNo(no_metodos,"","MethodDecl");
																			AdicionaNo($$,$3);
																			AdicionaIrmao($3,$4);}		
																
		;

FieldDecl:	PUBLIC STATIC Type ID FindDeclSec SEMICOLON				{$$ = CriaNo(no_var,"","FieldDecl");
																	AdicionaNo($$,$3);
																	AdicionaIrmao($3,CriaNo(no_ids,$4,"Id"));

																	if ( $5 != NULL ) {
																		aux = $5;
																		while(aux != NULL){
																			no aux1 = CriaNo(no_var,"","FieldDecl");
																			no aux2 = CriaNo($3->tipo,$3->valor,$3->s_type);
																			AdicionaNo(aux1,aux2);
																			AdicionaIrmao(aux2,CriaNo(no_ids,aux->valor,"Id"));
																			AdicionaIrmao($$,aux1);
																			aux = aux->irmao;
																		}		
																		free(aux);
																	}
																	}
			| error SEMICOLON											{$$ = NULL;flagErro = false;}
;
FindDeclSec:
			COMMA ID FindDeclSec									{$$ = CriaNo(no_ids,$2,"Id");
																	AdicionaIrmao($$,$3);
																	}	
			|/* null */										{$$ = NULL;}	
		;

Type:	BOOL														{$$ = CriaNo(no_terminais,"","Bool");}	
	|	INT															{$$ = CriaNo(no_terminais,"","Int");}
	|	DOUBLE														{$$ = CriaNo(no_terminais,"","Double");}
	;

MethodHeader:	Type ID LPAR MethodHeaderSec RPAR					{$$ = CriaNo(no_metodos,"","MethodHeader");
																	AdicionaNo($$,$1);
																	AdicionaIrmao($1,CriaNo(no_ids,$2,"Id"));
																	aux = CriaNo(no_metodos,"","MethodParams");
																	AdicionaIrmao($1,aux);
																	AdicionaNo(aux,$4);
																	}		
																															
			|	VOID ID LPAR MethodHeaderSec RPAR					{$$ = CriaNo(no_metodos,"","MethodHeader");
																	aux = CriaNo(no_terminais,"","Void");
																	AdicionaNo($$,aux);
																	AdicionaIrmao(aux,CriaNo(no_ids,$2,"Id"));
																	auxi2 = CriaNo(no_metodos,"","MethodParams");
																	AdicionaIrmao(aux,auxi2);
																	AdicionaNo(auxi2,$4);
																	}	
			;

MethodHeaderSec:	
				FormalParams										{$$ = $1;}
			|/* null */												{$$ = NULL;}																						
			;

FormalParams:	Type ID FormalParamsSec								{$$ = CriaNo(no_metodos,"","ParamDecl");
																	AdicionaNo($$,$1);
																	aux=CriaNo(no_ids,$2,"Id");
																	AdicionaIrmao($1,aux);
																	AdicionaIrmao($$,$3);}		
																																		
			|	STRING LSQ RSQ ID									{$$ = CriaNo(no_metodos,"","ParamDecl");
																	aux = CriaNo(no_metodos,"","StringArray");
																	AdicionaNo($$,aux);
																	AdicionaIrmao(aux,CriaNo(no_ids,$4,"Id"));}	
			;

FormalParamsSec:				
				COMMA Type ID FormalParamsSec 						{$$ = CriaNo(no_metodos,"","ParamDecl");
																	aux=CriaNo(no_ids,$3,"Id");
																	AdicionaNo($$,$2);
																	AdicionaIrmao($2,aux);
																	AdicionaIrmao($$,$4);}		
			|/* null */												{$$ = NULL;}							
			;

MethodBody:	LBRACE MethodBodySec RBRACE								{$$ = CriaNo(no_metodos,"","MethodBody");
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
			|	/* nulL */											{$$ = NULL;}											
			;

//NOT FINISHED
VarDecl:	Type ID VarDeclSec SEMICOLON							{$$ = CriaNo(no_metodos,"","VarDecl");
																	AdicionaNo($$,$1);
																	AdicionaIrmao($1,CriaNo(no_ids,$2,"Id"));
																	if ($3 != NULL){
																		aux = $3;
																		while(aux != NULL){
																			no aux1 = CriaNo(no_metodos,"","VarDecl");
																			no aux2 = CriaNo($1->tipo,$1->valor,$1->s_type);
																			AdicionaNo(aux1,aux2);
																			AdicionaIrmao(aux2,CriaNo(no_ids,aux->valor,"Id"));
																			AdicionaIrmao($$,aux1);
																			aux = aux->irmao;
																		}	
																		free(aux);
																															
																	}}
		;

VarDeclSec:	/* null */												{$$ = NULL;}					
		|	COMMA ID VarDeclSec										{$$ = CriaNo(no_ids,$2,"Id");
																	AdicionaIrmao($$,$3);}		
		;

Statement:	LBRACE StatementSec RBRACE								{if(conta_irmaos($2)>1){
																		aux = CriaNo(no_statements,"","Block");
																		$$=aux;
																		AdicionaNo(aux,$2);
																	}else{$$=$2;}
																															}	
		|	IF LPAR Expr RPAR Statement %prec  ELSE       			{$$ = CriaNo(no_statements,"","If");
																	AdicionaNo($$,$3);
																	aux=CriaNo(no_statements,"","Block");
																	if(conta_irmaos($5) == 1 && $5 != NULL){
																		AdicionaIrmao($3,$5);
																		AdicionaIrmao($5,aux);
																		}else{
																			AdicionaIrmao($3,aux);
																			AdicionaNo(aux,$5);
																			AdicionaIrmao(aux,CriaNo(no_statements,"","Block"));
																		}
																	}		
		|	IF LPAR Expr RPAR Statement ELSE Statement				{$$ = CriaNo(no_statements,"","If");
																	AdicionaNo($$,$3); 
																	aux = CriaNo(no_statements,"","Block");
																	if (conta_irmaos($5) == 1 && $5 != NULL) {
																		AdicionaIrmao($3, $5);
																		if (conta_irmaos($7) == 1 && $7 != NULL) {
																			AdicionaIrmao($5, $7);
																		}else {
																			AdicionaIrmao($5, aux);
																			AdicionaNo(aux, $7);}
																	}else {
																		AdicionaIrmao($3, aux);
																		AdicionaNo(aux, $5);
																		if (conta_irmaos($7) == 1 && $7 != NULL) {
																			AdicionaIrmao(aux, $7);
																		}else {
																			auxi2 = CriaNo(no_statements,"","Block");
																			AdicionaIrmao(aux, auxi2);
																			AdicionaNo(auxi2, $7);
																		}
																	}
															}


		|	WHILE LPAR Expr RPAR Statement							{$$ = CriaNo(no_statements,"","While");
																	AdicionaNo($$,$3);
																	if(conta_irmaos($5) == 1 && $5 != NULL){
																		AdicionaIrmao($3,$5);
																	}else{
																		aux = CriaNo(no_statements,"","Block");
																		AdicionaIrmao($3,aux);
																		AdicionaNo(aux,$5);
																	}
																	}

		|	RETURN SEMICOLON										{$$ = CriaNo(no_statements,"","Return");}			
		|	RETURN Expr SEMICOLON									{$$ = CriaNo(no_statements,"","Return");
																	AdicionaNo($$,$2);}			
		|	StatementThird SEMICOLON								{$$ = $1;}		
		|	PRINT LPAR StatementPrint RPAR SEMICOLON				{$$ = CriaNo(no_statements,"","Print");
																	AdicionaNo($$,$3);
																	}	
		| error SEMICOLON 											{$$=NULL;flagErro=false;}
																	
		
		;
StatementSec:	
			Statement StatementSec									{if($1 != NULL){
																		$$=$1;
																		AdicionaIrmao($$,$2);
																	}else{
																		$$=$2;}
			}			
			| /* null */											{$$ = NULL;}		
		;


StatementThird:	/* null */											{$$ = NULL;}
		|	MethodInvocation										{$$ = $1;}
		|	Assignment												{$$ = $1;}
		|	ParseArgs												{$$ = $1;}
		;

StatementPrint:	Expr												{$$ = $1;}
			|	STRLIT												{$$ = CriaNo(no_terminais,$1,"StrLit");}			
			;


MethodInvocation:	ID LPAR MethodInvocationSec RPAR  				{$$ = CriaNo(no_operadores,"","Call");
																	aux = CriaNo(no_ids,$1,"Id");
																	AdicionaNo($$,aux);
																	AdicionaIrmao(aux,$3);}					
			|	ID LPAR error RPAR								{$$ = NULL;
															flagErro = false;}
				;

MethodInvocationSec:
					Expr MethodInvocationThird						{$$ = $1;AdicionaIrmao($$,$2);}
					|/* null */										{$$ = NULL;}		
				;

																	//verificar se é NULL ou não
MethodInvocationThird:		COMMA Expr MethodInvocationThird		{if($2!=NULL){
																		$$=$2;
																		AdicionaIrmao($$,$3);
																	}else{$$=$2;}}
				| /* null */										{$$ = NULL;}		
					;

Assignment:	ID ASSIGN Expr											{$$ = CriaNo(no_operadores,"","Assign");
																	aux = CriaNo(no_ids,$1,"Id");
																	AdicionaNo($$,aux);
																	AdicionaIrmao(aux,$3);}
		;

ParseArgs:	PARSEINT LPAR ID LSQ Expr RSQ RPAR						{$$ = CriaNo(no_operadores,"","ParseArgs");
																	aux = CriaNo(no_ids,$3,"Id");
																	AdicionaNo($$,aux);
																	AdicionaIrmao(aux,$5);}					
		|	PARSEINT LPAR error RPAR																{$$ = NULL;flagErro=false;}	
			;

Expr:	Expr PLUS Expr											   	{$$ = CriaNo(no_operadores,"","Add");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr MINUS Expr										{$$ = CriaNo(no_operadores,"","Sub");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr STAR Expr										{$$ = CriaNo(no_operadores,"","Mul");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr DIV Expr										{$$ = CriaNo(no_operadores,"","Div");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr MOD Expr										{$$ = CriaNo(no_operadores,"","Mod");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr AND Expr										{$$ = CriaNo(no_operadores,"","And");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr OR Expr										{$$ = CriaNo(no_operadores,"","Or");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr XOR Expr										{$$ = CriaNo(no_operadores,"","Xor");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr LSHIFT Expr									{$$ = CriaNo(no_operadores,"","Lshift");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr RSHIFT Expr									{$$ = CriaNo(no_operadores,"","Rshift");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}
			|	Expr EQ Expr										{$$ = CriaNo(no_operadores,"","Eq");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}		
			|	Expr GE Expr										{$$ = CriaNo(no_operadores,"","Ge");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}		
			|	Expr GT Expr										{$$ = CriaNo(no_operadores,"","Gt");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}	
			|	Expr LE Expr										{$$ = CriaNo(no_operadores,"","Le");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}	
			|	Expr LT Expr										{$$ = CriaNo(no_operadores,"","Lt");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}	
			|	Expr NE Expr										{$$ = CriaNo(no_operadores,"","Ne");AdicionaNo($$,$1);AdicionaIrmao($1,$3);}	
			|	PLUS Expr                       					{$$ = CriaNo(no_operadores,"","Plus");AdicionaNo($$,$2);}	
			|	MINUS Expr 											{$$ = CriaNo(no_operadores,"","Minus");AdicionaNo($$,$2);}	
			|	NOT Expr											{$$ = CriaNo(no_operadores,"","Not");AdicionaNo($$,$2);}
			|	MethodInvocation									{$$ = $1;}
			|	ParseArgs											{$$ = $1;}
			|	LPAR error RPAR										{$$ = NULL;flagErro = false;}	
			|	ID													{$$ = CriaNo(no_ids,$1,"Id");}
			|	ID DOTLENGTH										{$$ = CriaNo(no_operadores,"","Length");AdicionaNo($$,CriaNo(no_ids,$1,"Id"));}
			|INTLIT													{$$ = CriaNo(no_operadores,$1,"DecLit");}
			|	REALLIT												{$$ = CriaNo(no_operadores,$1,"RealLit");}
			|	BOOLLIT												{$$ = CriaNo(no_operadores,$1,"BoolLit");}		
	;



%%





