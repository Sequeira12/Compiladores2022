
digito		[0-9]
letra		[a-z]|[A-Z]|"_"|"$"


%%


"0"|{digito}|({digito}({digito}|"_")*{digito})	{printf("INTLIT(%s)\n", yytext);}

("true"|"false")		{printf("BOOLLIT\n");}
"&&"				{printf("AND\n");}
"="				{printf("ASSIGN\n");}				
"*"				{printf("STAR\n");}
","				{printf("COMMA\n");}
"/"				{printf("DIV\n");}			
"=="				{printf("EQ\n");}
">="				{printf("GE\n");}
">"				{printf("GT\n");}
"{"				{printf("LBRACE\n");}
"<="				{printf("LE\n");}
"("				{printf("LPAR\n");}
"["				{printf("LSQ\n");}
"<"				{printf("LT\n");}
"-"				{printf("MINUS\n");}				
"%"				{printf("MOD\n");}
"!="				{printf("NE\n");}
"!"				{printf("NOT\n");}
"||"				{printf("OR\n");}
"+"				{printf("PLUS\n");}
"}"				{printf("RBRACE\n");}
")"				{printf("RPAR\n");}
"]"				{printf("RSQ\n");}
";"				{printf("SEMICOLON\n");}
"->"				{printf("ARROW\n");}
"<<"				{printf("LSHIFT\n");}
">>"				{printf("RSHIFT\n");}
"^"				{printf("XOR\n");}
"boolean"			{printf("BOOL\n");}
"class"				{printf("CLASS\n");}
".length"			{printf("DOTLENGTH\n");}
"double"			{printf("double\n");}
"else"				{printf("ELSE\n");}
"if"				{printf("IF\n");}
"int"				{printf("INT\n");}
"System.out.print"		{printf("PRINT\n");}
"Integer.parseInt"		{printf("PARSEINT\n");}
"public"			{printf("PUBLIC\n");}
"return"			{printf("RETURN\n");}
"static"			{printf("STATIC\n");}
"String"			{printf("STRING\n");}
"void"				{printf("VOID\n");}
"while"				{printf("WHILE\n");}
("++"|"--"|"null"|"Integer"|"System")	{printf("RESERVED\n");}
({letra})({letra}|{digito})*		{printf("ID(%s)\n",yytext);}

\t\n\r\f"\\\\""\\"		{printf("STRLIT\n");}
\n\r|\r\n			;
.				;



%%

int main(){
yylex(); 
return 0;
}

int yywrap() {
return 1;
}
