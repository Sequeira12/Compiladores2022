


%X STRLIT COM1 COM2

%{
	#include <string.h>
	#include <stdbool.h>
	int linha,coluna;
	int linhaaux,colunaaux;
	bool flag = false;
	bool flag_yacc = false;
	bool imprime;
	char string[254];

%}



digito						[0-9]
letra						[a-z]|[A-Z]|"_"|"$"


BOOLLIT						("true"|"false")
AND						"&&"			
ASSIGN						"="							
STAR						"*"				
COMMA						","				
DIV						"/"						
EQ						"=="				
GE						">="				
GT						">"				
LBRACE						"{"				
LE						"<="				
LPAR						"("				
LSQ						"["				
LT						"<"				
MINUS						"-"								
MOD						"%"				
NE						"!="				
NOT						"!"				
OR						"||"				
PLUS						"+"				
RBRACE						"}"				
RPAR						")"				
RSQ						"]"				
SEMICOLON					";"				
ARROW						"->"				
LSHIFT						"<<"				
RSHIFT						">>"				
XOR						"^"				
BOOL						"boolean"			
CLASS						"class"				
DOTLENGTH					".length"			
DOUBLE						"double"			
ELSE						"else"				
IF						"if"				
INT						"int"				
PRINT						"System.out.print"		
PARSEINT					"Integer.parseInt"		
PUBLIC						"public"			
RETURN						"return"			
STATIC						"static"			
STRING						"String"			
VOID						"void"				
WHILE						"while"				
RESERVED					("++"|"--"|"null"|"Integer"|"System"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"catch"|"char"|"const"|"default"|"do"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile"|"continue")	
ID						({letra})({letra}|{digito})*		
STRLIT						\t\n\r\f"\\\\""\\"	

REALLIT						({parte}"."({parte}?{exp}?)?)|("."{parte}{exp}?)|({parte}{exp})
INTLIT						"0"|[1-9]|([1-9]({digito}|"_")*{digito})
				
parte						{digito}([{digito}|"_"]*{digito})*
exp						("e"|"E")("-"|"+")?({parte})


%%

"/*"						{BEGIN COM1;linhaaux = linha; colunaaux = coluna;coluna+=yyleng;}
<COM1><<EOF>> 					{BEGIN 0;printf("Line %d, col %d: unterminated comment\n",linhaaux,colunaaux);yyterminate();}

<COM1>"*/"					{BEGIN 0;coluna += yyleng;}
<COM1>\r\n|\n|\r 				{linha++; coluna=1;}
<COM1>.						{coluna += yyleng;}


"//"						{BEGIN COM2;linhaaux = linha; colunaaux = coluna;coluna+=yyleng;}
<COM2>\n|\r|\r\n				{BEGIN 0; linha++; coluna=1;}
<COM2>.						{coluna += yyleng;}







\"                                 						{BEGIN STRLIT; linhaaux = linha; colunaaux = coluna; coluna+=yyleng; imprime = true;}
<STRLIT>\n|\r|\r\n               						{printf("Line %d, col %d: unterminated string literal\n", linhaaux, colunaaux); strcpy(string,""); coluna = 1; linha++;BEGIN 0; }
<STRLIT>(\\n|\\f|\\r|\\t|\t|\\\\|\\\")|[^\\\r\n\"]      			{strcat(string, yytext);  coluna+=yyleng;}
<STRLIT>\\[^\n\r\"]|\\|\f|\t        						{printf("Line %d, col %d: invalid escape sequence (%s)\n", linhaaux, coluna, yytext); coluna+=yyleng; imprime = false;}
<STRLIT>\"                         						{if(imprime && flag) {  printf("STRLIT(\"%s\")\n", string);}if(flag_yacc)return STRLIT; strcpy(string,""); BEGIN 0; coluna += yyleng;}
<STRLIT><<EOF>>                     						{printf("Line %d, col %d: unterminated string literal\n", linhaaux, colunaaux);strcpy(string,""); coluna = 1;BEGIN 0; }





 
{REALLIT}				{if(flag)printf("REALLIT(%s)\n", yytext);coluna+=yyleng;if(flag_yacc)return REALLIT;}
{INTLIT}				{if(flag)printf("INTLIT(%s)\n", yytext);coluna+=yyleng;if(flag_yacc)return INTLIT;}
{BOOLLIT}				{if(flag)printf("BOOLLIT(%s)\n", yytext);coluna+=yyleng;if(flag_yacc)return BOOLIT;}
{AND}					{if(flag)printf("AND\n");coluna+=yyleng;if(flag_yacc)return AND;}
{ASSIGN}				{if(flag)printf("ASSIGN\n");coluna+=yyleng;if(flag_yacc)return ASSIGN;}				
{STAR}					{if(flag)printf("STAR\n");coluna+=yyleng;if(flag_yacc)return STAR;}
{COMMA}					{if(flag)printf("COMMA\n");coluna+=yyleng;if(flag_yacc)return COMMA;}
{DIV}					{if(flag)printf("DIV\n");coluna+=yyleng;if(flag_yacc)return DIV;}			
{EQ}					{if(flag)printf("EQ\n");coluna+=yyleng;if(flag_yacc)return EQ;}
{GE}					{if(flag)printf("GE\n");coluna+=yyleng;if(flag_yacc)return GE;}
{GT}					{if(flag)printf("GT\n");coluna+=yyleng;if(flag_yacc)return GT;}
{LBRACE}				{if(flag)printf("LBRACE\n");coluna+=yyleng;if(flag_yacc)return LBRACE;}
{LE}					{if(flag)printf("LE\n");coluna+=yyleng;if(flag_yacc)return LE;}
{LPAR}					{if(flag)printf("LPAR\n");coluna+=yyleng;if(flag_yacc)return LPAR;}
{LSQ}					{if(flag)printf("LSQ\n");coluna+=yyleng;if(flag_yacc)return LSQ;}
{LT}					{if(flag)printf("LT\n");coluna+=yyleng;if(flag_yacc)return LT;}
{MINUS}			      {if(flag)printf("MINUS\n");coluna+=yyleng;if(flag_yacc)return MINUS;}				
{MOD}					{if(flag)printf("MOD\n");coluna+=yyleng;if(flag_yacc)return MOD;}
{NE}					{if(flag)printf("NE\n");coluna+=yyleng;if(flag_yacc)return NE;}
{NOT}					{if(flag)printf("NOT\n");coluna+=yyleng;if(flag_yacc)return NOT;}
{OR}					{if(flag)printf("OR\n");coluna+=yyleng;if(flag_yacc)return OR;}}
{PLUS}					{if(flag)printf("PLUS\n");coluna+=yyleng;if(flag_yacc)return PLUS;}
{RBRACE}				{if(flag)printf("RBRACE\n");coluna+=yyleng;if(flag_yacc)return RBRACE;}
{RPAR}					{if(flag)printf("RPAR\n");coluna+=yyleng;if(flag_yacc)return RPAR;}
{RSQ}					{if(flag)printf("RSQ\n");coluna+=yyleng;if(flag_yacc)return RSQ;}
{SEMICOLON}				{if(flag)printf("SEMICOLON\n");coluna+=yyleng;if(flag_yacc)return SEMICOLON;}
{ARROW}				{if(flag)printf("ARROW\n");coluna+=yyleng;if(flag_yacc)return ARROW;}
{LSHIFT}				{if(flag)printf("LSHIFT\n");coluna+=yyleng;if(flag_yacc)return LSHIFT;}
{RSHIFT}				{if(flag)printf("RSHIFT\n");coluna+=yyleng;if(flag_yacc)return RSHIFT;}
{XOR}					{if(flag)printf("XOR\n");coluna+=yyleng;if(flag_yacc)return XOR;}
{BOOL}					{if(flag)printf("BOOL\n");coluna+=yyleng;if(flag_yacc)return BOOL;}
{CLASS}				{if(flag)printf("CLASS\n");coluna+=yyleng;if(flag_yacc)return CLASS;}
{DOTLENGTH}				{if(flag)printf("DOTLENGTH\n");coluna+=yyleng;if(flag_yacc)return DOTLENGTH;}
{DOUBLE}				{if(flag)printf("DOUBLE\n");coluna+=yyleng;if(flag_yacc)return DOUBLE;}
{ELSE}					{if(flag)printf("ELSE\n");coluna+=yyleng;if(flag_yacc)return ELSE;}
{IF}					{if(flag)printf("IF\n");coluna+=yyleng;if(flag_yacc)return IF;}
{INT}					{if(flag)printf("INT\n");coluna+=yyleng;if(flag_yacc)return INT;}
{PRINT}					{if(flag)printf("PRINT\n");coluna+=yyleng;if(flag_yacc)return PRINT;}
{PARSEINT}				{if(flag)printf("PARSEINT\n");coluna+=yyleng;if(flag_yacc)return PARSEINT;}
{PUBLIC}				{if(flag)printf("PUBLIC\n");coluna+=yyleng;if(flag_yacc)return PUBLIC;}
{RETURN}				{if(flag)printf("RETURN\n");coluna+=yyleng;if(flag_yacc)return RETURN;}
{STATIC}				{if(flag)printf("STATIC\n");coluna+=yyleng;if(flag_yacc)return STATIC;}
{STRING}				{if(flag)printf("STRING\n");coluna+=yyleng;if(flag_yacc)return STRING;}
{VOID}					{if(flag)printf("VOID\n");coluna+=yyleng;if(flag_yacc)return VOID;}
{WHILE}					{if(flag)printf("WHILE\n");coluna+=yyleng;if(flag_yacc)return WHILE;}
{RESERVED}				{if(flag)printf("RESERVED(%s)\n",yytext);coluna+=yyleng;if(flag_yacc)return RESERVED;}
{ID}					{if(flag)printf("ID(%s)\n",yytext);coluna+=yyleng;if(flag_yacc)return ID;}
{STRLIT}				{if(flag)printf("STRLIT\n");coluna+=yyleng;if(flag_yacc)return STRLIT;}


" " 					{coluna+= yyleng;}
"\t"					{coluna+= yyleng;}
"\f" 					{coluna+= yyleng;}
\r\n|\n|\r				{linha++; coluna=1;}
.                   			{printf("Line %d, col %d: illegal character (%s)\n", linha, coluna, yytext); coluna += yyleng;}


%%
%%

int main(int argc, char *argv[]){
	linha=1,coluna=1; 
	
	
	if (argc > 1) {
		if (strcmp(argv[1],"-l") == 0) {
			flag = 1;
		}
		else if(strcmp(argv[1],"-e1") == 0) {
			flag = 0;
		}else if(strcmp(argv[1],"-t") == 0){
			flag_yacc = 1;
		
	}
	else if (argc == 1){
		flag = 0;
		flag_yacc = 0;
	}
	}
	yylex(); 
	return 0;

}

int yywrap() {
	return 1;
}
