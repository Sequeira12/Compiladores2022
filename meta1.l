


%X STRLIT COM1 COM2

%{
	#include <string.h>
	#include <stdbool.h>
	int linha,coluna;
	int linhaaux,colunaaux;
	bool imprime;
	char string[254];
	bool flag = false;

%}



digito					[0-9]
letra					[a-z]|[A-Z]|"_"|"$"


BOOLLIT					("true"|"false")
AND						"&&"			
ASSIGN					"="							
STAR					"*"				
COMMA					","				
DIV						"/"						
EQ						"=="				
GE						">="				
GT						">"				
LBRACE					"{"				
LE						"<="				
LPAR					"("				
LSQ						"["				
LT						"<"				
MINUS					"-"								
MOD						"%"				
NE						"!="				
NOT						"!"				
OR						"||"				
PLUS					"+"				
RBRACE					"}"				
RPAR					")"				
RSQ						"]"				
SEMICOLON				";"				
ARROW					"->"				
LSHIFT					"<<"				
RSHIFT					">>"				
XOR						"^"				
BOOL					"boolean"			
CLASS					"class"				
DOTLENGTH				".length"			
DOUBLE					"double"			
ELSE					"else"				
IF						"if"				
INT						"int"				
PRINT					"System.out.print"		
PARSEINT				"Integer.parseInt"		
PUBLIC					"public"			
RETURN					"return"			
STATIC					"static"			
STRING					"String"			
VOID					"void"				
WHILE					"while"				
RESERVED				("++"|"--"|"null"|"Integer"|"System")	
ID						({letra})({letra}|{digito})*		
STRLIT					\t\n\r\f"\\\\""\\"	

REALLIT					({parte}"."({parte}?{exp}?)?)|("."{parte}{exp}?)|({parte}{exp})
INTLIT					"0"|{digito}|({digito}({digito}|"_")*{digito})
				
parte					{digito}([{digito}|"_"]*{digito})*
exp						("e"|"E")("-"|"+")?({parte})


%%

"/*"						{BEGIN COM1;linhaaux = linha; colunaaux = coluna;coluna+=yyleng;}
<COM1><<EOF>> 					{BEGIN 0;printf("Line %d, column %d: unterminated comment\n",linhaaux,colunaaux);yyterminate();}

<COM1>"*/"					{BEGIN 0;coluna += yyleng;}
<COM1>\r\n|\n|\r 				{linha++; coluna=1;}
<COM1>.					{coluna += yyleng;}


"//"						{BEGIN COM2;linhaaux = linha; colunaaux = coluna;coluna+=yyleng;}
<COM2>.					{coluna += yyleng;}
<COM2>"\r\n"					{linha++; coluna=1;}
<COM2><<EOF>					{BEGIN 0;}






\"                                  {BEGIN STRLIT; linhaaux = linha; colunaaux = coluna; coluna+=yyleng; imprime = true;}
<STRLIT>\n|\r|(\r\n)                {BEGIN 0; printf("Line %d, column %d: unterminated string literal\n", linhaaux, colunaaux); strcpy(string,""); coluna = 1; linha+=1;}
<STRLIT>(\\n|\\f|\\r|\\t|\t|\\\\|\\\")|[^\\\r\n\"]         {strcat(string, yytext);  coluna+=yyleng;}
<STRLIT>\\[^\n\r\"]|\\|\f|\t        {printf("Line %d, column %d: invalid escape sequence (%s)\n", linhaaux, coluna, yytext); coluna+=yyleng; imprime = false; flag = false;}
<STRLIT>\"                          {if(imprime) {  printf("STRLIT(\"%s\")\n", string); flag=true;} strcpy(string,""); BEGIN 0; coluna += yyleng;}
<STRLIT><<EOF>>                     {BEGIN 0; printf("Line %d, column %d: unterminated string literal\n", linhaaux, colunaaux);strcpy(string,""); coluna = 1;}





 
{REALLIT}				{printf("REALLIT(%s)\n", yytext);flag = true;coluna+=yyleng;}

{INTLIT}				{printf("INTLIT(%s)\n", yytext);flag = false;coluna+=yyleng;}

{BOOLLIT}				{printf("BOOLLIT\n");flag = false;coluna+=yyleng;}
{AND}					{printf("AND\n");flag = false;coluna+=yyleng;}
{ASSIGN}				{printf("ASSIGN\n");flag = false;coluna+=yyleng;}				
{STAR}					{printf("STAR\n");flag = false;coluna+=yyleng;}
{COMMA}				{printf("COMMA\n");flag = false;coluna+=yyleng;}
{DIV}					{printf("DIV\n");flag = false;coluna+=yyleng;}			
{EQ}					{printf("EQ\n");flag = false;coluna+=yyleng;}
{GE}					{printf("GE\n");flag = false;coluna+=yyleng;}
{GT}					{printf("GT\n");flag = false;coluna+=yyleng;}
{LBRACE}				{printf("LBRACE\n");flag = false;coluna+=yyleng;}
{LE}					{printf("LE\n");flag = false;coluna+=yyleng;}
{LPAR}					{printf("LPAR\n");flag = false;coluna+=yyleng;}
{LSQ}					{printf("LSQ\n");flag = false;coluna+=yyleng;}
{LT}					{printf("LT\n");flag = false;coluna+=yyleng;}
{MINUS}			      {printf("MINUS\n");flag=false;coluna+=yyleng;}				
{MOD}					{printf("MOD\n");flag = false;coluna+=yyleng;}
{NE}					{printf("NE\n");flag = false;coluna+=yyleng;}
{NOT}					{printf("NOT\n");flag = false;coluna+=yyleng;}
{OR}					{printf("OR\n");flag = false;coluna+=yyleng;}
{PLUS}					{printf("PLUS\n");flag = false;coluna+=yyleng;}
{RBRACE}				{printf("RBRACE\n");flag = true;coluna+=yyleng;}
{RPAR}					{printf("RPAR\n");flag = true;coluna+=yyleng;}
{RSQ}					{printf("RSQ\n");flag = true;coluna+=yyleng;}
{SEMICOLON}				{printf("SEMICOLON\n");flag = false;coluna+=yyleng;}
{ARROW}				{printf("ARROW\n");flag = false;coluna+=yyleng;}
{LSHIFT}				{printf("LSHIFT\n");flag = false;coluna+=yyleng;}
{RSHIFT}				{printf("RSHIFT\n");flag = false;coluna+=yyleng;}
{XOR}					{printf("XOR\n");flag = false;coluna+=yyleng;}
{BOOL}					{printf("BOOL\n");flag = false;coluna+=yyleng;}
{CLASS}				{printf("CLASS\n");flag = false;coluna+=yyleng;}
{DOTLENGTH}				{printf("DOTLENGTH\n");flag = false;coluna+=yyleng;}
{DOUBLE}				{printf("DOUBLE\n");flag = false;coluna+=yyleng;}
{ELSE}					{printf("ELSE\n");flag = false;coluna+=yyleng;}
{IF}					{printf("IF\n");flag = false;coluna+=yyleng;}
{INT}					{printf("INT\n");flag = false;coluna+=yyleng;}
{PRINT}				{printf("PRINT\n");flag = false;coluna+=yyleng;}
{PARSEINT}				{printf("PARSEINT\n");flag = false;coluna+=yyleng;}
{PUBLIC}				{printf("PUBLIC\n");flag = false;coluna+=yyleng;}
{RETURN}				{printf("RETURN\n");flag = true;coluna+=yyleng;}
{STATIC}				{printf("STATIC\n");flag = false;coluna+=yyleng;}
{STRING}				{printf("STRING\n");flag = false;coluna+=yyleng;}
{VOID}					{printf("VOID\n");flag = false;coluna+=yyleng;}
{WHILE}				{printf("WHILE\n");flag = false;coluna+=yyleng;}
{RESERVED}				{printf("RESERVED\n");flag = false;coluna+=yyleng;}
{ID}					{printf("ID(%s)\n",yytext);flag = true;coluna+=yyleng;}
{STRLIT}				{printf("STRLIT\n");flag = false;coluna+=yyleng;}


" " 					{coluna+= yyleng;}
\t 					{coluna+= yyleng;}
\r\n|\n|\r				{if(flag == true){printf("SEMICOLON\n");flag = false;}linha++; coluna=1; }
.                   			{printf("Line %d, column %d: illegal character (%s)\n", linha, coluna, yytext); coluna += yyleng;}
<<EOF>>             			{if(flag==true) printf("SEMICOLON\n"); yyterminate();}







%%

int main(){
	linha=1,coluna=1; 
	yylex(); 
	return 0;
}

int yywrap() {
	return 1;
}
