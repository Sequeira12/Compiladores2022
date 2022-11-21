 //Rui Santos 2020225542
 //Bruno Sequeira 2020235721


%X STRLLIT COM1 COM2

%{
	#include <string.h>
	#include <stdbool.h>
	int linha,coluna;
	int linhaaux,colunaaux;
	bool flag = true;
	bool flagYacc = false;
	bool imprime;
	char string[254];
	
	#include "y.tab.h"
	#include "semantics.h"
	int yylex(void);
	void yyerror (char *s);
	int yyparse(void);
	extern no raiz;
	extern int flagErro;
	int parse = 1;
	char auxxx[100];
	int isstring=0;
%}



digito						[0-9]
letra						[a-z]|[A-Z]|"_"|"$"


BOOLLIT						("true"|"false")
AND							"&&"			
ASSIGN						"="							
STAR						"*"				
COMMA						","				
DIV							"/"						
EQ							"=="				
GE							">="				
GT							">"				
LBRACE						"{"				
LE							"<="				
LPAR						"("				
LSQ							"["				
LT							"<"				
MINUS						"-"								
MOD							"%"				
NE							"!="				
NOT							"!"				
OR							"||"				
PLUS						"+"				
RBRACE						"}"				
RPAR						")"				
RSQ							"]"				
SEMICOLON					";"				
ARROW						"->"				
LSHIFT						"<<"				
RSHIFT						">>"				
XOR							"^"				
BOOL						"boolean"			
CLASS						"class"				
DOTLENGTH					".length"			
DOUBLE						"double"			
ELSE						"else"				
IF							"if"				
INT							"int"				
PRINT						"System.out.print"		
PARSEINT					"Integer.parseInt"		
PUBLIC						"public"			
RETURN						"return"			
STATIC						"static"			
STRING						"String"			
VOID						"void"				
WHILE						"while"				
RESERVED					("++"|"--"|"null"|"Integer"|"System"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"catch"|"char"|"const"|"default"|"do"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile"|"continue")	
ID							({letra})({letra}|{digito})*		
STRLIT						\t\n\r\f"\\\\""\\"	
REALLIT						({parte}"."({parte}?{exp}?)?)|("."{parte}{exp}?)|({parte}{exp})
INTLIT						"0"|[1-9]|([1-9]({digito}|"_")*{digito})
parte						{digito}([{digito}|"_"]*{digito})*
exp							("e"|"E")("-"|"+")?({parte})





%%


"/*"							{BEGIN COM1;linhaaux = linha; colunaaux = coluna;coluna+=yyleng;}

<COM1>"*/"						{BEGIN 0;coluna += yyleng;}
<COM1>\r\n|\n|\r 				{linha++; coluna=1;}
<COM1>.							{coluna += yyleng;}
<COM1><<EOF>> 					{BEGIN 0;printf("Line %d, col %d: unterminated comment\n",linhaaux,colunaaux);yyterminate();}

"//"							{BEGIN COM2;coluna+=yyleng;}
<COM2>\n|\r|\r\n				{BEGIN 0; linha++; coluna=1;}
<COM2>.							{coluna += yyleng;}







\"                                 							{BEGIN STRLLIT;string[0]=0;strcat(string, yytext);linhaaux = linha; colunaaux = coluna; coluna+=yyleng; imprime = true;}
<STRLLIT>\n|\r|\r\n               							{BEGIN 0; string[0] = 0;printf("Line %d, col %d: unterminated string literal\n", linhaaux, colunaaux); coluna = 1; linha++;}
<STRLLIT>(\\n|\\f|\\r|\\t|\t|\\\\|\\\")|[^\\\r\n\"]      	{coluna+=yyleng;strcat(string, yytext);  }
<STRLLIT>\\[^\n\r\"]|\\|\f|\t        						{strcat(string,yytext);printf("Line %d, col %d: invalid escape sequence (%s)\n",linhaaux, coluna, yytext); coluna+=yyleng; imprime = false;}
<STRLLIT>\"                         						{BEGIN 0;strcat(string, yytext);if(imprime && flag) {printf("STRLIT(%s)\n", string);}coluna+=yyleng;if(flagYacc && imprime){yylval.id[0] = strdup(string); yytext = string;sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx);return STRLIT;}}
<STRLLIT><<EOF>>                     						{printf("Line %d, col %d: unterminated string literal\n", linhaaux, colunaaux);strcpy(string,""); coluna = 1;isstring=0;BEGIN 0; }





 
{REALLIT}				{if(flag){printf("REALLIT(%s)\n", yytext);}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return REALLIT;}}
{INTLIT}				{if(flag){printf("INTLIT(%s)\n", yytext);}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return INTLIT;}}
{BOOLLIT}				{if(flag){printf("BOOLLIT(%s)\n", yytext);}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return BOOLLIT;}}
{AND}					{if(flag){printf("AND\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return AND;}}
{ASSIGN}				{if(flag){printf("ASSIGN\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return ASSIGN;}}				
{STAR}					{if(flag){printf("STAR\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return STAR;}}
{COMMA}					{if(flag){printf("COMMA\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return COMMA;}}
{DIV}					{if(flag){printf("DIV\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return DIV;}}			
{EQ}					{if(flag){printf("EQ\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return EQ;}}
{GE}					{if(flag){printf("GE\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return GE;}}
{GT}					{if(flag){printf("GT\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return GT;}}
{LBRACE}				{if(flag){printf("LBRACE\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return LBRACE;}}
{LE}					{if(flag){printf("LE\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return LE;}}
{LPAR}					{if(flag){printf("LPAR\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng+1);yylval.id[2]=strdup(auxxx); return LPAR;}}
{LSQ}					{if(flag){printf("LSQ\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return LSQ;}}
{LT}					{if(flag){printf("LT\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return LT;}}
{MINUS}			        {if(flag){printf("MINUS\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return MINUS;}}				
{MOD}					{if(flag){printf("MOD\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return MOD;}}
{NE}					{if(flag){printf("NE\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return NE;}}
{NOT}					{if(flag){printf("NOT\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return NOT;}}
{OR}					{if(flag){printf("OR\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return OR;}}
{PLUS}					{if(flag){printf("PLUS\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return PLUS;}}
{RBRACE}				{if(flag){printf("RBRACE\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return RBRACE;}}
{RPAR}					{if(flag){printf("RPAR\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return RPAR;}}
{RSQ}					{if(flag){printf("RSQ\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return RSQ;}}
{SEMICOLON}				{if(flag){printf("SEMICOLON\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return SEMICOLON;}}
{ARROW}					{if(flag){printf("ARROW\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return ARROW;}}
{LSHIFT}				{if(flag){printf("LSHIFT\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return LSHIFT;}}
{RSHIFT}				{if(flag){printf("RSHIFT\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return RSHIFT;}}
{XOR}					{if(flag){printf("XOR\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return XOR;}}
{BOOL}					{if(flag){printf("BOOL\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return BOOL;}}
{CLASS}					{if(flag){printf("CLASS\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return CLASS;}}
{DOTLENGTH}				{if(flag){printf("DOTLENGTH\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return DOTLENGTH;}}
{DOUBLE}				{if(flag){printf("DOUBLE\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return DOUBLE;}}
{ELSE}					{if(flag){printf("ELSE\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return ELSE;}}
{IF}					{if(flag){printf("IF\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return IF;}}
{INT}					{if(flag){printf("INT\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return INT;}}
{PRINT}					{if(flag){printf("PRINT\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return PRINT;}}
{PARSEINT}				{if(flag){printf("PARSEINT\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return PARSEINT;}}
{PUBLIC}				{if(flag){printf("PUBLIC\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return PUBLIC;}}
{RETURN}				{if(flag){printf("RETURN\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return RETURN;}}
{STATIC}				{if(flag){printf("STATIC\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return STATIC;}}
{STRING}				{if(flag){printf("STRING\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return STRING;}}
{VOID}					{if(flag){printf("VOID\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return VOID;}}
{WHILE}					{if(flag){printf("WHILE\n");}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return WHILE;}}
{RESERVED}				{if(flag){printf("RESERVED(%s)\n",yytext);}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx); return RESERVED;}}
{ID}					{if(flag){printf("ID(%s)\n",yytext);}coluna+=yyleng;if(flagYacc){yylval.id[0] = strdup(yytext);sprintf(auxxx,"%d", linha);yylval.id[1]=strdup(auxxx);sprintf(auxxx,"%d", coluna-yyleng);yylval.id[2]=strdup(auxxx);return ID;}}



" " 							{coluna+= yyleng;}
\t								{coluna+= yyleng;}
\f 								{coluna+= yyleng;}
\r\n|\n|\r						{linha++; coluna=1;}
.                   			{printf("Line %d, col %d: illegal character (%s)\n", linha, coluna, yytext); coluna += yyleng;}

%%



int main(int argc, char *argv[]){
	linha=1,coluna=1; 
	
	
	if (argc > 1) {
		if (strcmp(argv[1],"-l") == 0) {
			flag = 1;
			yylex();
		}
		else if (strcmp(argv[1], "-e1") == 0) {
			flag = 0;
			while (yylex() != 0) {
				;
			}
		}else if(strcmp(argv[1],"-t") == 0){
			flagYacc = true;
			flag = false;
			yyparse();
			if(flagErro == true){								
				Arvore(raiz,0,0);
			}
	      }
		else if(strcmp(argv[1],"-e2") == 0) {
			flag = 0;
			flagYacc = true;
			yyparse();
			yylex();
		}
		else if(strcmp(argv[1],"-s") == 0){
			flagYacc = true;
			flag = false;
			yyparse();
			if(flagErro == true){
				verifica(raiz);
				check_ast(raiz);
				imprime_tabela();							
				Arvore(raiz,0,1);
			}
	      }

    }else{
      
			flag = 0;
			flagYacc = true;
			yyparse();
			yylex();
    }
	return 0;
	
}
void yyerror(char *s) { 
	printf ("Line %d, col %d: %s: %s\n", linha, (int)(coluna-strlen(yytext)), s, yytext);
}


int yywrap() {
	return 1;
}
