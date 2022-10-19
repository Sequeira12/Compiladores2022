/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NE = 258,
    NOT = 259,
    AND = 260,
    OR = 261,
    RBRACE = 262,
    LBRACE = 263,
    RPAR = 264,
    RSQ = 265,
    PARSEINT = 266,
    RETURN = 267,
    ELSE = 268,
    IF = 269,
    LSQ = 270,
    LPAR = 271,
    LE = 272,
    GE = 273,
    GT = 274,
    EQ = 275,
    LT = 276,
    PLUS = 277,
    MINUS = 278,
    DIV = 279,
    STAR = 280,
    ASSIGN = 281,
    COMMA = 282,
    SEMICOLON = 283,
    INT = 284,
    STRING = 285,
    WHILE = 286,
    DOTLENGTH = 287,
    STATIC = 288,
    DOUBLE = 289,
    PUBLIC = 290,
    CLASS = 291,
    VOID = 292,
    MOD = 293,
    XOR = 294,
    RSHIFT = 295,
    LSHIFT = 296,
    STRLIT = 297,
    BOOL = 298,
    PRINT = 299,
    INTLIT = 300,
    REALLIT = 301,
    ID = 302,
    RESERVED = 303,
    BOOLIT = 304
  };
#endif
/* Tokens.  */
#define NE 258
#define NOT 259
#define AND 260
#define OR 261
#define RBRACE 262
#define LBRACE 263
#define RPAR 264
#define RSQ 265
#define PARSEINT 266
#define RETURN 267
#define ELSE 268
#define IF 269
#define LSQ 270
#define LPAR 271
#define LE 272
#define GE 273
#define GT 274
#define EQ 275
#define LT 276
#define PLUS 277
#define MINUS 278
#define DIV 279
#define STAR 280
#define ASSIGN 281
#define COMMA 282
#define SEMICOLON 283
#define INT 284
#define STRING 285
#define WHILE 286
#define DOTLENGTH 287
#define STATIC 288
#define DOUBLE 289
#define PUBLIC 290
#define CLASS 291
#define VOID 292
#define MOD 293
#define XOR 294
#define RSHIFT 295
#define LSHIFT 296
#define STRLIT 297
#define BOOL 298
#define PRINT 299
#define INTLIT 300
#define REALLIT 301
#define ID 302
#define RESERVED 303
#define BOOLIT 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "jucompiler.y"

    char* lit;
    struct node *N_no;

#line 160 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
