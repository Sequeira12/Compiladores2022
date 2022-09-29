
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
{REALLIT}				{printf("REALLIT(%s)\n", yytext);}

{INTLIT}				{printf("INTLIT(%s)\n", yytext);}

{BOOLLIT}				{printf("BOOLLIT\n");}
{AND}					{printf("AND\n");}
{ASSIGN}				{printf("ASSIGN\n");}				
{STAR}					{printf("STAR\n");}
{COMMA}					{printf("COMMA\n");}
{DIV}					{printf("DIV\n");}			
{EQ}					{printf("EQ\n");}
{GE}					{printf("GE\n");}
{GT}					{printf("GT\n");}
{LBRACE}				{printf("LBRACE\n");}
{LE}					{printf("LE\n");}
{LPAR}					{printf("LPAR\n");}
{LSQ}					{printf("LSQ\n");}
{LT}					{printf("LT\n");}
{MINUS}					{printf("MINUS\n");}				
{MOD}					{printf("MOD\n");}
{NE}					{printf("NE\n");}
{NOT}					{printf("NOT\n");}
{OR}					{printf("OR\n");}
{PLUS}					{printf("PLUS\n");}
{RBRACE}				{printf("RBRACE\n");}
{RPAR}					{printf("RPAR\n");}
{RSQ}					{printf("RSQ\n");}
{SEMICOLON}				{printf("SEMICOLON\n");}
{ARROW}					{printf("ARROW\n");}
{LSHIFT}				{printf("LSHIFT\n");}
{RSHIFT}				{printf("RSHIFT\n");}
{XOR}					{printf("XOR\n");}
{BOOL}					{printf("BOOL\n");}
{CLASS}					{printf("CLASS\n");}
{DOTLENGTH}				{printf("DOTLENGTH\n");}
{DOUBLE}				{printf("DOUBLE\n");}
{ELSE}					{printf("ELSE\n");}
{IF}					{printf("IF\n");}
{INT}					{printf("INT\n");}
{PRINT}					{printf("PRINT\n");}
{PARSEINT}				{printf("PARSEINT\n");}
{PUBLIC}				{printf("PUBLIC\n");}
{RETURN}				{printf("RETURN\n");}
{STATIC}				{printf("STATIC\n");}
{STRING}				{printf("STRING\n");}
{VOID}					{printf("VOID\n");}
{WHILE}					{printf("WHILE\n");}
{RESERVED}				{printf("RESERVED\n");}
{ID}					{printf("ID(%s)\n",yytext);}
{STRLIT}				{printf("STRLIT\n");}

\n\r|\r\n				;
.						;


%%

int main(){
yylex(); 
return 0;
}

int yywrap() {
return 1;
}
