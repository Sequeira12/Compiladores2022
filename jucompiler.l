


%X STRLIT COM1 COM2

%{
	#include <string.h>
	#include <stdbool.h>
	int linha,coluna;
	int linhaaux,colunaaux;
	bool flag = false;
	bool imprime;
	char string[254];

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
RESERVED				("++"|"--"|"null"|"Integer"|"System"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"catch"|"char"|"const"|"default"|"do"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile"|"continue")	
ID						({letra})({letra}|{digito})*		
STRLIT					\t\n\r\f"\\\\""\\"	

REALLIT					({parte}"."({parte}?{exp}?)?)|("."{parte}{exp}?)|({parte}{exp})
INTLIT					"0"|[1-9]|([1-9]({digito}|"_")*{digito})
				
parte					{digito}([{digito}|"_"]*{digito})*
exp						("e"|"E")("-"|"+")?({parte})


%%

"/*"					{BEGIN COM1;linhaaux = linha; colunaaux = coluna;coluna+=yyleng;}
<COM1><<EOF>> 			{BEGIN 0;printf("Line %d, col %d: unterminated comment\n",linhaaux,colunaaux);yyterminate();}

<COM1>"*/"				{BEGIN 0;coluna += yyleng;}
<COM1>\r\n|\n|\r 		{linha++; coluna=1;}
<COM1>.					{coluna += yyleng;}


"//"					{BEGIN COM2;linhaaux = linha; colunaaux = coluna;coluna+=yyleng;}
<COM2>\n|\r|\r\n	{BEGIN 0; linha++; coluna=1;}
<COM2>.					{coluna += yyleng;}







\"                                 						{BEGIN STRLIT; linhaaux = linha; colunaaux = coluna; coluna+=yyleng; imprime = true;}
<STRLIT>\n|\r|\r\n               						{BEGIN 0; printf("Line %d, col %d: unterminated string literal\n", linhaaux, colunaaux); strcpy(string,""); coluna = 1; linha++;}
<STRLIT>(\\n|\\f|\\r|\\t|\t|\\\\|\\\")|[^\\\r\n\"]      {strcat(string, yytext);  coluna+=yyleng;}
<STRLIT>\\[^\n\r\"]|\\|\f|\t        					{printf("Line %d, col %d: invalid escape sequence (%s)\n", linhaaux, coluna, yytext); coluna+=yyleng; imprime = false;}
<STRLIT>\"                         						{if(imprime) {  printf("STRLIT(\"%s\")\n", string);} strcpy(string,""); BEGIN 0; coluna += yyleng;}
<STRLIT><<EOF>>                     					{BEGIN 0; printf("Line %d, col %d: unterminated string literal\n", linhaaux, colunaaux);strcpy(string,""); coluna = 1;}





 
{REALLIT}				{if(flag)printf("REALLIT(%s)\n", yytext);coluna+=yyleng;}

{INTLIT}				{if(flag)printf("INTLIT(%s)\n", yytext);coluna+=yyleng;}

{BOOLLIT}				{if(flag)printf("BOOLLIT(%s)\n", yytext);coluna+=yyleng;}
{AND}					{if(flag)printf("AND\n");coluna+=yyleng;}
{ASSIGN}				{if(flag)printf("ASSIGN\n");coluna+=yyleng;}				
{STAR}					{if(flag)printf("STAR\n");coluna+=yyleng;}
{COMMA}					{if(flag)printf("COMMA\n");coluna+=yyleng;}
{DIV}					{if(flag)printf("DIV\n");coluna+=yyleng;}			
{EQ}					{if(flag)printf("EQ\n");coluna+=yyleng;}
{GE}					{if(flag)printf("GE\n");coluna+=yyleng;}
{GT}					{if(flag)printf("GT\n");coluna+=yyleng;}
{LBRACE}				{if(flag)printf("LBRACE\n");coluna+=yyleng;}
{LE}					{if(flag)printf("LE\n");coluna+=yyleng;}
{LPAR}					{if(flag)printf("LPAR\n");coluna+=yyleng;}
{LSQ}					{if(flag)printf("LSQ\n");coluna+=yyleng;}
{LT}					{if(flag)printf("LT\n");coluna+=yyleng;}
{MINUS}			      	{if(flag)printf("MINUS\n");coluna+=yyleng;}				
{MOD}					{if(flag)printf("MOD\n");coluna+=yyleng;}
{NE}					{if(flag)printf("NE\n");coluna+=yyleng;}
{NOT}					{if(flag)printf("NOT\n");coluna+=yyleng;}
{OR}					{if(flag)printf("OR\n");coluna+=yyleng;}
{PLUS}					{if(flag)printf("PLUS\n");coluna+=yyleng;}
{RBRACE}				{if(flag)printf("RBRACE\n");coluna+=yyleng;}
{RPAR}					{if(flag)printf("RPAR\n");coluna+=yyleng;}
{RSQ}					{if(flag)printf("RSQ\n");coluna+=yyleng;}
{SEMICOLON}				{if(flag)printf("SEMICOLON\n");coluna+=yyleng;}
{ARROW}					{if(flag)printf("ARROW\n");coluna+=yyleng;}
{LSHIFT}				{if(flag)printf("LSHIFT\n");coluna+=yyleng;}
{RSHIFT}				{if(flag)printf("RSHIFT\n");coluna+=yyleng;}
{XOR}					{if(flag)printf("XOR\n");coluna+=yyleng;}
{BOOL}					{if(flag)printf("BOOL\n");coluna+=yyleng;}
{CLASS}					{if(flag)printf("CLASS\n");coluna+=yyleng;}
{DOTLENGTH}				{if(flag)printf("DOTLENGTH\n");coluna+=yyleng;}
{DOUBLE}				{if(flag)printf("DOUBLE\n");coluna+=yyleng;}
{ELSE}					{if(flag)printf("ELSE\n");coluna+=yyleng;}
{IF}					{if(flag)printf("IF\n");coluna+=yyleng;}
{INT}					{if(flag)printf("INT\n");coluna+=yyleng;}
{PRINT}					{if(flag)printf("PRINT\n");coluna+=yyleng;}
{PARSEINT}				{if(flag)printf("PARSEINT\n");coluna+=yyleng;}
{PUBLIC}				{if(flag)printf("PUBLIC\n");coluna+=yyleng;}
{RETURN}				{if(flag)printf("RETURN\n");coluna+=yyleng;}
{STATIC}				{if(flag)printf("STATIC\n");coluna+=yyleng;}
{STRING}				{if(flag)printf("STRING\n");coluna+=yyleng;}
{VOID}					{if(flag)printf("VOID\n");coluna+=yyleng;}
{WHILE}					{if(flag)printf("WHILE\n");coluna+=yyleng;}
{RESERVED}				{if(flag)printf("RESERVED(%s)\n",yytext);coluna+=yyleng;}
{ID}					{if(flag)printf("ID(%s)\n",yytext);coluna+=yyleng;}
{STRLIT}				{if(flag)printf("STRLIT\n");coluna+=yyleng;}


" " 							{coluna+= yyleng;}
"\t"							{coluna+= yyleng;}
"\f" 							{coluna+= yyleng;}
\r\n|\n|\r				    {linha++; coluna=1;}
.                   			{printf("Line %d, col %d: illegal character (%s)\n", linha, coluna, yytext); coluna += yyleng;}


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
