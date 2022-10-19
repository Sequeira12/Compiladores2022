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

Program:	CLASS ID LBRACE declaration RBRACE									{$$ = NULL;}		
		;

declaration: 
				MethodDecl declaration																{$$ = NULL;}			
			|	FieldDecl declaration																	{$$ = NULL;}					
			|	SEMICOLON declaration																	{$$ = NULL;}			
			|	/* null */																						{$$ = NULL;}		
			;

MethodDecl:	PUBLIC STATIC MethodHeader MethodBody							{$$ = NULL;}		
																
		;

FieldDecl:	PUBLIC STATIC Type ID FindDeclSec SEMICOLON				{$$ = NULL;}		
	
;
FindDeclSec:
			COMMA ID FindDeclSec																		{$$ = NULL;}	
			|/* null */										{$$ = NULL;}	
		;

Type:	BOOL																										{$$ = NULL;}	
	|	INT																												{$$ = NULL;}
	|	DOUBLE																										{$$ = NULL;}
	;

MethodHeader:	Type ID LPAR MethodHeaderSec RPAR								{$$ = NULL;}		
			|	VOID ID LPAR MethodHeaderSec RPAR											{$$ = NULL;}	
			;

MethodHeaderSec:	
				FormalParams																					{$$ = $1;}
			|/* null */																							{$$ = NULL;}																						
			;

FormalParams:	Type ID FormalParamsSec													{$$ = NULL;}					
			|	STRING LSQ RSQ ID																			{$$ = NULL;}	
			;

FormalParamsSec:				
				COMMA Type ID FormalParamsSec 												{$$ = NULL;}		
			|/* null */																							{$$ = NULL;}							
			;

MethodBody:	LBRACE MethodBodySec RBRACE												{$$ = NULL;}						
		;

MethodBodySec: 	
				Statement MethodBodySec																{$$ = NULL;}		
			|	VarDecl MethodBodySec																	{$$ = NULL;}	
			|	/* nulL */																						{$$ = NULL;}											
			;

VarDecl:	Type ID VarDeclSec SEMICOLON												{$$ = NULL;}						
		;

VarDeclSec:	/* null */																				{$$ = NULL;}					
		|	COMMA ID VarDeclSec																			{$$ = NULL;}		
		;

Statement:	LBRACE StatementSec RBRACE												{$$ = NULL;}	
		|	IF LPAR Expr RPAR Statement         										{$$ = NULL;}		
		|	IF LPAR Expr RPAR Statement ELSE Statement							{$$ = NULL;}	
		|	WHILE LPAR Expr RPAR Statement													{$$ = NULL;}			
		|	RETURN SEMICOLON																				{$$ = NULL;}			
		|	RETURN Expr SEMICOLON																		{$$ = NULL;}			
		|	StatementThird SEMICOLON																{$$ = NULL;}		
		|	PRINT LPAR StatementPrint RPAR SEMICOLON								{$$ = NULL;}	
																	
		
		;
StatementSec:	
			Statement StatementSec																	{$$ = NULL;}			
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

MethodInvocation:	ID LPAR MethodInvocationSec RPAR  					{$$ = NULL;}					
				
				;

MethodInvocationSec:
					Expr MethodInvocationThird													{$$ = $1;}
					|/* null */																					{$$ = NULL;}		
				;

MethodInvocationThird:		COMMA Expr MethodInvocationThird		{$$ = NULL;}
				| /* null */																					{$$ = NULL;}		
					;

Assignment:	ID ASSIGN Expr																		{$$ = NULL;}
		;

ParseArgs:	PARSEINT LPAR ID LSQ Expr RSQ RPAR								{$$ = NULL;}					
		|	PARSEINT LPAR error RPAR																{$$ = NULL;}
			;

Expr:	Expr PLUS Expr											   	{$$ = NULL;}
			|	Expr MINUS Expr												{$$ = NULL;}
			|	Expr STAR Expr												{$$ = NULL;}
			|	Expr DIV Expr													{$$ = NULL;}
			|	Expr MOD Expr													{$$ = NULL;}
			|	Expr AND Expr													{$$ = NULL;}
			|	Expr OR Expr													{$$ = NULL;}
			|	Expr XOR Expr													{$$ = NULL;}
			|	Expr LSHIFT Expr											{$$ = NULL;}
			|	Expr RSHIFT Expr											{$$ = NULL;}
			|	Expr EQ Expr													{$$ = NULL;}		
			|	Expr GE Expr													{$$ = NULL;}		
			|	Expr GT Expr													{$$ = NULL;}	
			|	Expr LE Expr													{$$ = NULL;}	
			|	Expr LT Expr													{$$ = NULL;}	
			|	Expr NE Expr													{$$ = NULL;}	
			|	PLUS Expr                       			{$$ = NULL;}	
			|	MINUS Expr 														{$$ = NULL;}	
			|	NOT Expr															{$$ = NULL;}
			|	MethodInvocation											{$$ = $1;}
			|	ParseArgs															{$$ = $1;}
			|	LPAR error RPAR												{$$ = NULL;}
			|	ID																		{$$ = NULL;}
			|	ID DOTLENGTH													{$$ = NULL;}
			|INTLIT																	{$$ = NULL;}
			|	REALLIT																{$$ = NULL;}
			|	BOOLLIT																{$$ = NULL;}		
	;



%%
