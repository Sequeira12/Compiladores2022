/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "jucompiler.y"

	#include <string.h>
	#include <stdbool.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "functions.h"
	

	no aux=NULL;
	no auxi2=NULL;
	bool flagErro = true;

	no raiz;
    int yylex(void);
    void yyerror (char *s);
    int yyparse(void);
	


#line 91 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    AND = 258,                     /* AND  */
    ASSIGN = 259,                  /* ASSIGN  */
    STAR = 260,                    /* STAR  */
    COMMA = 261,                   /* COMMA  */
    DIV = 262,                     /* DIV  */
    EQ = 263,                      /* EQ  */
    GE = 264,                      /* GE  */
    GT = 265,                      /* GT  */
    LBRACE = 266,                  /* LBRACE  */
    LE = 267,                      /* LE  */
    LPAR = 268,                    /* LPAR  */
    LSQ = 269,                     /* LSQ  */
    LT = 270,                      /* LT  */
    MINUS = 271,                   /* MINUS  */
    MOD = 272,                     /* MOD  */
    NE = 273,                      /* NE  */
    NOT = 274,                     /* NOT  */
    OR = 275,                      /* OR  */
    PLUS = 276,                    /* PLUS  */
    RBRACE = 277,                  /* RBRACE  */
    RPAR = 278,                    /* RPAR  */
    RSQ = 279,                     /* RSQ  */
    SEMICOLON = 280,               /* SEMICOLON  */
    ARROW = 281,                   /* ARROW  */
    LSHIFT = 282,                  /* LSHIFT  */
    RSHIFT = 283,                  /* RSHIFT  */
    XOR = 284,                     /* XOR  */
    CLASS = 285,                   /* CLASS  */
    DOTLENGTH = 286,               /* DOTLENGTH  */
    ELSE = 287,                    /* ELSE  */
    IF = 288,                      /* IF  */
    PRINT = 289,                   /* PRINT  */
    PARSEINT = 290,                /* PARSEINT  */
    PUBLIC = 291,                  /* PUBLIC  */
    RETURN = 292,                  /* RETURN  */
    STATIC = 293,                  /* STATIC  */
    STRING = 294,                  /* STRING  */
    VOID = 295,                    /* VOID  */
    WHILE = 296,                   /* WHILE  */
    INT = 297,                     /* INT  */
    DOUBLE = 298,                  /* DOUBLE  */
    BOOL = 299,                    /* BOOL  */
    RESERVED = 300,                /* RESERVED  */
    ID = 301,                      /* ID  */
    INTLIT = 302,                  /* INTLIT  */
    REALLIT = 303,                 /* REALLIT  */
    BOOLLIT = 304,                 /* BOOLLIT  */
    STRLIT = 305                   /* STRLIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define AND 258
#define ASSIGN 259
#define STAR 260
#define COMMA 261
#define DIV 262
#define EQ 263
#define GE 264
#define GT 265
#define LBRACE 266
#define LE 267
#define LPAR 268
#define LSQ 269
#define LT 270
#define MINUS 271
#define MOD 272
#define NE 273
#define NOT 274
#define OR 275
#define PLUS 276
#define RBRACE 277
#define RPAR 278
#define RSQ 279
#define SEMICOLON 280
#define ARROW 281
#define LSHIFT 282
#define RSHIFT 283
#define XOR 284
#define CLASS 285
#define DOTLENGTH 286
#define ELSE 287
#define IF 288
#define PRINT 289
#define PARSEINT 290
#define PUBLIC 291
#define RETURN 292
#define STATIC 293
#define STRING 294
#define VOID 295
#define WHILE 296
#define INT 297
#define DOUBLE 298
#define BOOL 299
#define RESERVED 300
#define ID 301
#define INTLIT 302
#define REALLIT 303
#define BOOLLIT 304
#define STRLIT 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "jucompiler.y"

    char* id;
    struct node *no;

#line 249 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AND = 3,                        /* AND  */
  YYSYMBOL_ASSIGN = 4,                     /* ASSIGN  */
  YYSYMBOL_STAR = 5,                       /* STAR  */
  YYSYMBOL_COMMA = 6,                      /* COMMA  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_EQ = 8,                         /* EQ  */
  YYSYMBOL_GE = 9,                         /* GE  */
  YYSYMBOL_GT = 10,                        /* GT  */
  YYSYMBOL_LBRACE = 11,                    /* LBRACE  */
  YYSYMBOL_LE = 12,                        /* LE  */
  YYSYMBOL_LPAR = 13,                      /* LPAR  */
  YYSYMBOL_LSQ = 14,                       /* LSQ  */
  YYSYMBOL_LT = 15,                        /* LT  */
  YYSYMBOL_MINUS = 16,                     /* MINUS  */
  YYSYMBOL_MOD = 17,                       /* MOD  */
  YYSYMBOL_NE = 18,                        /* NE  */
  YYSYMBOL_NOT = 19,                       /* NOT  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_PLUS = 21,                      /* PLUS  */
  YYSYMBOL_RBRACE = 22,                    /* RBRACE  */
  YYSYMBOL_RPAR = 23,                      /* RPAR  */
  YYSYMBOL_RSQ = 24,                       /* RSQ  */
  YYSYMBOL_SEMICOLON = 25,                 /* SEMICOLON  */
  YYSYMBOL_ARROW = 26,                     /* ARROW  */
  YYSYMBOL_LSHIFT = 27,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 28,                    /* RSHIFT  */
  YYSYMBOL_XOR = 29,                       /* XOR  */
  YYSYMBOL_CLASS = 30,                     /* CLASS  */
  YYSYMBOL_DOTLENGTH = 31,                 /* DOTLENGTH  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_PRINT = 34,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 35,                  /* PARSEINT  */
  YYSYMBOL_PUBLIC = 36,                    /* PUBLIC  */
  YYSYMBOL_RETURN = 37,                    /* RETURN  */
  YYSYMBOL_STATIC = 38,                    /* STATIC  */
  YYSYMBOL_STRING = 39,                    /* STRING  */
  YYSYMBOL_VOID = 40,                      /* VOID  */
  YYSYMBOL_WHILE = 41,                     /* WHILE  */
  YYSYMBOL_INT = 42,                       /* INT  */
  YYSYMBOL_DOUBLE = 43,                    /* DOUBLE  */
  YYSYMBOL_BOOL = 44,                      /* BOOL  */
  YYSYMBOL_RESERVED = 45,                  /* RESERVED  */
  YYSYMBOL_ID = 46,                        /* ID  */
  YYSYMBOL_INTLIT = 47,                    /* INTLIT  */
  YYSYMBOL_REALLIT = 48,                   /* REALLIT  */
  YYSYMBOL_BOOLLIT = 49,                   /* BOOLLIT  */
  YYSYMBOL_STRLIT = 50,                    /* STRLIT  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_Program = 52,                   /* Program  */
  YYSYMBOL_declaration = 53,               /* declaration  */
  YYSYMBOL_MethodDecl = 54,                /* MethodDecl  */
  YYSYMBOL_FieldDecl = 55,                 /* FieldDecl  */
  YYSYMBOL_FindDeclSec = 56,               /* FindDeclSec  */
  YYSYMBOL_Type = 57,                      /* Type  */
  YYSYMBOL_MethodHeader = 58,              /* MethodHeader  */
  YYSYMBOL_MethodHeaderSec = 59,           /* MethodHeaderSec  */
  YYSYMBOL_FormalParams = 60,              /* FormalParams  */
  YYSYMBOL_FormalParamsSec = 61,           /* FormalParamsSec  */
  YYSYMBOL_MethodBody = 62,                /* MethodBody  */
  YYSYMBOL_MethodBodySec = 63,             /* MethodBodySec  */
  YYSYMBOL_VarDecl = 64,                   /* VarDecl  */
  YYSYMBOL_VarDeclSec = 65,                /* VarDeclSec  */
  YYSYMBOL_Statement = 66,                 /* Statement  */
  YYSYMBOL_StatementSec = 67,              /* StatementSec  */
  YYSYMBOL_StatementThird = 68,            /* StatementThird  */
  YYSYMBOL_StatementPrint = 69,            /* StatementPrint  */
  YYSYMBOL_MethodInvocation = 70,          /* MethodInvocation  */
  YYSYMBOL_MethodInvocationSec = 71,       /* MethodInvocationSec  */
  YYSYMBOL_MethodInvocationThird = 72,     /* MethodInvocationThird  */
  YYSYMBOL_Assignment = 73,                /* Assignment  */
  YYSYMBOL_ParseArgs = 74,                 /* ParseArgs  */
  YYSYMBOL_Expr = 75,                      /* Expr  */
  YYSYMBOL_Expr1 = 76,                     /* Expr1  */
  YYSYMBOL_Expr2 = 77,                     /* Expr2  */
  YYSYMBOL_ExprLit = 78                    /* ExprLit  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   409

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    66,    67,    68,    69,    72,    78,    95,
      98,   101,   104,   105,   106,   109,   117,   128,   129,   132,
     138,   145,   150,   153,   159,   165,   168,   172,   190,   191,
     195,   201,   213,   237,   248,   249,   251,   252,   255,   260,
     266,   270,   271,   272,   273,   276,   277,   281,   285,   290,
     291,   295,   299,   302,   308,   312,   317,   318,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   348,   349,   352,   353,   354
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AND", "ASSIGN",
  "STAR", "COMMA", "DIV", "EQ", "GE", "GT", "LBRACE", "LE", "LPAR", "LSQ",
  "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS", "RBRACE", "RPAR", "RSQ",
  "SEMICOLON", "ARROW", "LSHIFT", "RSHIFT", "XOR", "CLASS", "DOTLENGTH",
  "ELSE", "IF", "PRINT", "PARSEINT", "PUBLIC", "RETURN", "STATIC",
  "STRING", "VOID", "WHILE", "INT", "DOUBLE", "BOOL", "RESERVED", "ID",
  "INTLIT", "REALLIT", "BOOLLIT", "STRLIT", "$accept", "Program",
  "declaration", "MethodDecl", "FieldDecl", "FindDeclSec", "Type",
  "MethodHeader", "MethodHeaderSec", "FormalParams", "FormalParamsSec",
  "MethodBody", "MethodBodySec", "VarDecl", "VarDeclSec", "Statement",
  "StatementSec", "StatementThird", "StatementPrint", "MethodInvocation",
  "MethodInvocationSec", "MethodInvocationThird", "Assignment",
  "ParseArgs", "Expr", "Expr1", "Expr2", "ExprLit", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-41)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-51)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,   -40,    12,     4,   -41,    73,     6,    73,    40,    11,
      73,    73,   -41,   -41,    15,   -41,   -41,   -41,    -7,   -41,
     -41,   -41,     7,    54,    83,    34,    27,   -41,   122,    51,
     122,    76,    78,   134,    94,    98,    99,   216,   102,     1,
      70,   109,    27,    27,   101,   -41,   -41,   -41,   105,    87,
     111,   -41,   118,   113,   -41,   -41,   134,   115,   223,   178,
       2,   141,   233,   233,   233,   -41,    41,   -41,   -41,   -41,
     -41,   -41,   -41,   116,   280,   -41,   -41,   223,   223,   104,
     137,   -41,   -41,   -41,   -41,   123,   143,   -41,   -41,   -41,
     -41,   -41,   117,   -41,   132,   -41,   135,   149,   147,   150,
      -5,   -41,   -41,   -41,   -41,   -41,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   151,   -41,   154,   155,   173,   138,   156,   139,
      33,   -41,   171,   158,   -41,   223,   -41,   -41,   332,   -41,
     -41,   381,   193,   193,   193,   193,    39,   -41,   381,   307,
      39,    97,    97,   357,   171,   -41,   -41,   223,   -41,   137,
     -41,   -41,   140,   160,   -41,   169,   -41,   173,   -41,   143,
     171,   172,   -41,   -41,   -41,   -41
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     9,     5,     0,     2,     3,     4,     0,    13,
      14,    12,     0,     0,     0,    11,     0,     7,    18,     0,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    43,    44,     0,     0,
       0,    17,    11,     0,     8,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,    80,    85,    86,    87,
      83,    56,    84,     0,    57,    79,    82,     0,     0,     0,
      28,    23,    25,    24,    36,     0,    22,    16,    10,    15,
      39,    30,     0,    46,     0,    45,     0,     0,     0,     0,
      80,    75,    76,    74,    81,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,     0,    52,     0,     0,     0,
       0,    19,     0,     0,    55,     0,    78,    77,    63,    60,
      61,    68,    69,    70,    71,    72,    59,    62,    73,    64,
      58,    66,    67,    65,     0,    48,    47,     0,    49,    28,
      27,    20,     0,    31,    37,     0,    33,    52,    29,    22,
       0,     0,    51,    21,    32,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -41,   -41,    56,   -41,   -41,   159,    -1,   -41,   177,   -41,
      32,   -41,     8,   -41,    43,   -32,   162,   -41,   -41,   -26,
     -41,    36,   -24,   -22,   -36,   -27,   -41,   -41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    11,    31,    40,    23,    50,    51,
     131,    27,    41,    42,   128,    43,    57,    44,    94,    70,
     125,   158,    71,    72,    73,    74,    75,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    56,    46,    96,    47,    78,     3,    45,    79,    46,
       1,    47,     4,    22,    79,     5,    45,    45,    46,    46,
      47,    47,    92,    95,    56,    99,   104,    49,    32,    49,
      45,    12,    46,    15,    47,   101,   102,   103,    33,    24,
      29,   122,   123,   126,   107,    78,   108,    30,    97,   -26,
      82,    83,   -41,    25,    79,    18,   115,    19,    20,    21,
      34,    35,    36,    13,    37,    26,    16,    17,    38,    19,
      20,    21,   104,    39,     6,    19,    20,    21,    14,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -6,    28,    52,     7,   165,
     163,    54,   107,    55,   108,   124,    45,    58,    46,     8,
      47,    59,    60,   114,   115,    77,    80,    61,   118,    85,
      62,   167,   166,    63,    29,    64,    84,   -50,    45,   162,
      46,    81,    47,    86,    87,    32,    89,    91,   174,    36,
     132,   105,    98,   127,    45,    33,    46,   129,    47,   130,
      66,    67,    68,    69,    61,   133,   -40,    62,   134,   -41,
      63,    48,    64,   135,    19,    20,    21,    34,    35,    36,
     136,    37,    32,   137,   154,    38,    36,   155,   156,   157,
      39,   160,    33,   164,   159,   161,   169,    66,    67,    68,
      69,    61,   170,   171,    62,   175,   -41,    63,   107,    64,
     108,   173,   168,   172,    34,    35,    36,    53,    37,   114,
     115,    88,    38,    36,   118,     0,     0,    39,    90,     0,
     119,   120,     0,     0,    66,    67,    68,    69,    93,    61,
       0,     0,    62,     0,     0,    63,    61,    64,     0,    62,
       0,    65,    63,     0,    64,     0,    61,     0,     0,    62,
       0,    36,    63,     0,    64,     0,     0,     0,    36,     0,
       0,     0,    66,    67,    68,    69,     0,     0,    36,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,   100,
      67,    68,    69,   106,     0,   107,     0,   108,   109,   110,
     111,     0,   112,     0,     0,   113,   114,   115,   116,     0,
     117,   118,     0,     0,     0,     0,     0,   119,   120,   121,
     106,     0,   107,     0,   108,   109,   110,   111,     0,   112,
       0,     0,   113,   114,   115,   116,     0,     0,   118,     0,
       0,     0,     0,     0,   119,   120,   121,   107,     0,   108,
     109,   110,   111,     0,   112,     0,     0,   113,   114,   115,
     116,     0,     0,   118,     0,     0,     0,     0,     0,   119,
     120,   121,   107,     0,   108,   109,   110,   111,     0,   112,
       0,     0,   113,   114,   115,   116,     0,     0,   118,     0,
       0,     0,     0,     0,   119,   120,   107,     0,   108,     0,
     110,   111,     0,   112,     0,     0,   113,   114,   115,     0,
       0,     0,   118,     0,     0,     0,     0,     0,   119,   120
};

static const yytype_int16 yycheck[] =
{
      26,    33,    26,     1,    26,     4,    46,    33,    13,    33,
      30,    33,     0,    14,    13,    11,    42,    43,    42,    43,
      42,    43,    58,    59,    56,    61,    31,    28,     1,    30,
      56,    25,    56,    22,    56,    62,    63,    64,    11,    46,
       6,    77,    78,    79,     5,     4,     7,    13,    46,    22,
      42,    43,    25,    46,    13,    40,    17,    42,    43,    44,
      33,    34,    35,     7,    37,    11,    10,    11,    41,    42,
      43,    44,    31,    46,     1,    42,    43,    44,    38,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    22,    13,    46,    25,   135,
     132,    25,     5,    25,     7,     1,   132,    13,   132,    36,
     132,    13,    13,    16,    17,    13,    46,    13,    21,    14,
      16,   157,   154,    19,     6,    21,    25,    23,   154,   130,
     154,    22,   154,    46,    23,     1,    23,    22,   170,    35,
      23,    25,     1,     6,   170,    11,   170,    24,   170,     6,
      46,    47,    48,    49,    13,    23,    22,    16,    23,    25,
      19,    39,    21,    14,    42,    43,    44,    33,    34,    35,
      23,    37,     1,    23,    23,    41,    35,    23,    23,     6,
      46,    25,    11,    25,    46,    46,    46,    46,    47,    48,
      49,    13,    32,    24,    16,    23,    25,    19,     5,    21,
       7,   169,   159,   167,    33,    34,    35,    30,    37,    16,
      17,    52,    41,    35,    21,    -1,    -1,    46,    56,    -1,
      27,    28,    -1,    -1,    46,    47,    48,    49,    50,    13,
      -1,    -1,    16,    -1,    -1,    19,    13,    21,    -1,    16,
      -1,    25,    19,    -1,    21,    -1,    13,    -1,    -1,    16,
      -1,    35,    19,    -1,    21,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    35,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,     3,    -1,     5,    -1,     7,     8,     9,
      10,    -1,    12,    -1,    -1,    15,    16,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
       3,    -1,     5,    -1,     7,     8,     9,    10,    -1,    12,
      -1,    -1,    15,    16,    17,    18,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,     5,    -1,     7,
       8,     9,    10,    -1,    12,    -1,    -1,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,     5,    -1,     7,     8,     9,    10,    -1,    12,
      -1,    -1,    15,    16,    17,    18,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    27,    28,     5,    -1,     7,    -1,
       9,    10,    -1,    12,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    52,    46,     0,    11,     1,    25,    36,    53,
      54,    55,    25,    53,    38,    22,    53,    53,    40,    42,
      43,    44,    57,    58,    46,    46,    11,    62,    13,     6,
      13,    56,     1,    11,    33,    34,    35,    37,    41,    46,
      57,    63,    64,    66,    68,    70,    73,    74,    39,    57,
      59,    60,    46,    59,    25,    25,    66,    67,    13,    13,
      13,    13,    16,    19,    21,    25,    46,    47,    48,    49,
      70,    73,    74,    75,    76,    77,    78,    13,     4,    13,
      46,    22,    63,    63,    25,    14,    46,    23,    56,    23,
      67,    22,    75,    50,    69,    75,     1,    46,     1,    75,
      46,    76,    76,    76,    31,    25,     3,     5,     7,     8,
       9,    10,    12,    15,    16,    17,    18,    20,    21,    27,
      28,    29,    75,    75,     1,    71,    75,     6,    65,    24,
       6,    61,    23,    23,    23,    14,    23,    23,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    23,    23,    23,     6,    72,    46,
      25,    46,    57,    66,    25,    75,    66,    75,    65,    46,
      32,    24,    72,    61,    66,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    62,    63,    63,    63,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      67,    68,    68,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    74,    74,    75,    75,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    78,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     6,     2,
       3,     0,     1,     1,     1,     5,     5,     1,     0,     3,
       4,     4,     0,     3,     2,     2,     0,     4,     0,     3,
       3,     5,     7,     5,     2,     3,     2,     5,     2,     2,
       0,     0,     1,     1,     1,     1,     1,     4,     4,     2,
       0,     3,     0,     3,     7,     4,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     3,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: CLASS ID LBRACE declaration RBRACE  */
#line 57 "jucompiler.y"
                                                                                                        {raiz = CriaNo(no_raiz,"","Program");
																		aux = CriaNo(no_ids,(yyvsp[-3].id),"Id");
																		AdicionaNo(raiz,aux);
																		AdicionaIrmao(aux,(yyvsp[-1].no));
																		(yyval.no) = raiz;		
																		}
#line 1472 "y.tab.c"
    break;

  case 3: /* declaration: MethodDecl declaration  */
#line 66 "jucompiler.y"
                                                                                                                        {(yyval.no) = (yyvsp[-1].no);AdicionaIrmao((yyval.no),(yyvsp[0].no));}
#line 1478 "y.tab.c"
    break;

  case 4: /* declaration: FieldDecl declaration  */
#line 67 "jucompiler.y"
                                                                                                                        {(yyval.no) = (yyvsp[-1].no);AdicionaIrmao((yyval.no),(yyvsp[0].no));}
#line 1484 "y.tab.c"
    break;

  case 5: /* declaration: SEMICOLON declaration  */
#line 68 "jucompiler.y"
                                                                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1490 "y.tab.c"
    break;

  case 6: /* declaration: %empty  */
#line 69 "jucompiler.y"
                                                                                                                                        {(yyval.no) = NULL;}
#line 1496 "y.tab.c"
    break;

  case 7: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 72 "jucompiler.y"
                                                                                                        {(yyval.no) = CriaNo(no_metodos,"","MethodDecl");
																			AdicionaNo((yyval.no),(yyvsp[-1].no));
																			AdicionaIrmao((yyvsp[-1].no),(yyvsp[0].no));}
#line 1504 "y.tab.c"
    break;

  case 8: /* FieldDecl: PUBLIC STATIC Type ID FindDeclSec SEMICOLON  */
#line 78 "jucompiler.y"
                                                                                        {(yyval.no) = CriaNo(no_var,"","FieldDecl");
																	AdicionaNo((yyval.no),(yyvsp[-3].no));
																	AdicionaIrmao((yyvsp[-3].no),CriaNo(no_ids,(yyvsp[-2].id),"Id"));

																	if ( (yyvsp[-1].no) != NULL ) {
																		aux = (yyvsp[-1].no);
																		while(aux != NULL){
																			no aux1 = CriaNo(no_var,"","FieldDecl");
																			no aux2 = CriaNo((yyvsp[-3].no)->tipo,(yyvsp[-3].no)->valor,(yyvsp[-3].no)->s_type);
																			AdicionaNo(aux1,aux2);
																			AdicionaIrmao(aux2,CriaNo(no_ids,aux->valor,"Id"));
																			AdicionaIrmao((yyval.no),aux1);
																			aux = aux->irmao;
																		}		
																		free(aux);
																	}
																	}
#line 1526 "y.tab.c"
    break;

  case 9: /* FieldDecl: error SEMICOLON  */
#line 95 "jucompiler.y"
                                                                                                                                {(yyval.no) = NULL;flagErro = false;}
#line 1532 "y.tab.c"
    break;

  case 10: /* FindDeclSec: COMMA ID FindDeclSec  */
#line 98 "jucompiler.y"
                                                                                                                {(yyval.no) = CriaNo(no_ids,(yyvsp[-1].id),"Id");
																	AdicionaIrmao((yyval.no),(yyvsp[0].no));
																	}
#line 1540 "y.tab.c"
    break;

  case 11: /* FindDeclSec: %empty  */
#line 101 "jucompiler.y"
                                                                                                                {(yyval.no) = NULL;}
#line 1546 "y.tab.c"
    break;

  case 12: /* Type: BOOL  */
#line 104 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_terminais,"","Bool");}
#line 1552 "y.tab.c"
    break;

  case 13: /* Type: INT  */
#line 105 "jucompiler.y"
                                                                                                                                        {(yyval.no) = CriaNo(no_terminais,"","Int");}
#line 1558 "y.tab.c"
    break;

  case 14: /* Type: DOUBLE  */
#line 106 "jucompiler.y"
                                                                                                                                {(yyval.no) = CriaNo(no_terminais,"","Double");}
#line 1564 "y.tab.c"
    break;

  case 15: /* MethodHeader: Type ID LPAR MethodHeaderSec RPAR  */
#line 109 "jucompiler.y"
                                                                                        {(yyval.no) = CriaNo(no_metodos,"","MethodHeader");
																	AdicionaNo((yyval.no),(yyvsp[-4].no));
																	AdicionaIrmao((yyvsp[-4].no),CriaNo(no_ids,(yyvsp[-3].id),"Id"));
																	aux = CriaNo(no_metodos,"","MethodParams");
																	AdicionaIrmao((yyvsp[-4].no),aux);
																	AdicionaNo(aux,(yyvsp[-1].no));
																	}
#line 1576 "y.tab.c"
    break;

  case 16: /* MethodHeader: VOID ID LPAR MethodHeaderSec RPAR  */
#line 117 "jucompiler.y"
                                                                                                        {(yyval.no) = CriaNo(no_metodos,"","MethodHeader");
																	aux = CriaNo(no_terminais,"","Void");
																	AdicionaNo((yyval.no),aux);
																	AdicionaIrmao(aux,CriaNo(no_ids,(yyvsp[-3].id),"Id"));
																	auxi2 = CriaNo(no_metodos,"","MethodParams");
																	AdicionaIrmao(aux,auxi2);
																	AdicionaNo(auxi2,(yyvsp[-1].no));
																	}
#line 1589 "y.tab.c"
    break;

  case 17: /* MethodHeaderSec: FormalParams  */
#line 128 "jucompiler.y"
                                                                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1595 "y.tab.c"
    break;

  case 18: /* MethodHeaderSec: %empty  */
#line 129 "jucompiler.y"
                                                                                                                                {(yyval.no) = NULL;}
#line 1601 "y.tab.c"
    break;

  case 19: /* FormalParams: Type ID FormalParamsSec  */
#line 132 "jucompiler.y"
                                                                                                {(yyval.no) = CriaNo(no_metodos,"","ParamDecl");
																	AdicionaNo((yyval.no),(yyvsp[-2].no));
																	aux=CriaNo(no_ids,(yyvsp[-1].id),"Id");
																	AdicionaIrmao((yyvsp[-2].no),aux);
																	AdicionaIrmao((yyval.no),(yyvsp[0].no));}
#line 1611 "y.tab.c"
    break;

  case 20: /* FormalParams: STRING LSQ RSQ ID  */
#line 138 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_metodos,"","ParamDecl");
																	aux = CriaNo(no_metodos,"","StringArray");
																	AdicionaNo((yyval.no),aux);
																	AdicionaIrmao(aux,CriaNo(no_ids,(yyvsp[0].id),"Id"));}
#line 1620 "y.tab.c"
    break;

  case 21: /* FormalParamsSec: COMMA Type ID FormalParamsSec  */
#line 145 "jucompiler.y"
                                                                                                        {(yyval.no) = CriaNo(no_metodos,"","ParamDecl");
																	aux=CriaNo(no_ids,(yyvsp[-1].id),"Id");
																	AdicionaNo((yyval.no),(yyvsp[-2].no));
																	AdicionaIrmao((yyvsp[-2].no),aux);
																	AdicionaIrmao((yyval.no),(yyvsp[0].no));}
#line 1630 "y.tab.c"
    break;

  case 22: /* FormalParamsSec: %empty  */
#line 150 "jucompiler.y"
                                                                                                                                {(yyval.no) = NULL;}
#line 1636 "y.tab.c"
    break;

  case 23: /* MethodBody: LBRACE MethodBodySec RBRACE  */
#line 153 "jucompiler.y"
                                                                                                        {(yyval.no) = CriaNo(no_metodos,"","MethodBody");
																	AdicionaNo((yyval.no),(yyvsp[-1].no));
																	}
#line 1644 "y.tab.c"
    break;

  case 24: /* MethodBodySec: Statement MethodBodySec  */
#line 159 "jucompiler.y"
                                                                                                                {if((yyvsp[-1].no) != NULL){
																		(yyval.no) = (yyvsp[-1].no); 
																		AdicionaIrmao((yyval.no),(yyvsp[0].no));
																	}else{
																		(yyval.no)=(yyvsp[0].no);}
																	}
#line 1655 "y.tab.c"
    break;

  case 25: /* MethodBodySec: VarDecl MethodBodySec  */
#line 165 "jucompiler.y"
                                                                                                                {(yyval.no) = (yyvsp[-1].no);
																	AdicionaIrmao((yyval.no),(yyvsp[0].no));
																	}
#line 1663 "y.tab.c"
    break;

  case 26: /* MethodBodySec: %empty  */
#line 168 "jucompiler.y"
                                                                                                                                {(yyval.no) = NULL;}
#line 1669 "y.tab.c"
    break;

  case 27: /* VarDecl: Type ID VarDeclSec SEMICOLON  */
#line 172 "jucompiler.y"
                                                                                                {(yyval.no) = CriaNo(no_metodos,"","VarDecl");
																	AdicionaNo((yyval.no),(yyvsp[-3].no));
																	AdicionaIrmao((yyvsp[-3].no),CriaNo(no_ids,(yyvsp[-2].id),"Id"));
																	if ((yyvsp[-1].no) != NULL){
																		aux = (yyvsp[-1].no);
																		while(aux != NULL){
																			no aux1 = CriaNo(no_metodos,"","VarDecl");
																			no aux2 = CriaNo((yyvsp[-3].no)->tipo,(yyvsp[-3].no)->valor,(yyvsp[-3].no)->s_type);
																			AdicionaNo(aux1,aux2);
																			AdicionaIrmao(aux2,CriaNo(no_ids,aux->valor,"Id"));
																			AdicionaIrmao((yyval.no),aux1);
																			aux = aux->irmao;
																		}	
																		free(aux);
																															
																	}}
#line 1690 "y.tab.c"
    break;

  case 28: /* VarDeclSec: %empty  */
#line 190 "jucompiler.y"
                                                                                                                        {(yyval.no) = NULL;}
#line 1696 "y.tab.c"
    break;

  case 29: /* VarDeclSec: COMMA ID VarDeclSec  */
#line 191 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_ids,(yyvsp[-1].id),"Id");
																	AdicionaIrmao((yyval.no),(yyvsp[0].no));}
#line 1703 "y.tab.c"
    break;

  case 30: /* Statement: LBRACE StatementSec RBRACE  */
#line 195 "jucompiler.y"
                                                                                                        {if(conta_irmaos((yyvsp[-1].no))>1){
																		aux = CriaNo(no_statements,"","Block");
																		(yyval.no)=aux;
																		AdicionaNo(aux,(yyvsp[-1].no));
																	}else{(yyval.no)=(yyvsp[-1].no);}
																															}
#line 1714 "y.tab.c"
    break;

  case 31: /* Statement: IF LPAR Expr RPAR Statement  */
#line 201 "jucompiler.y"
                                                                                        {(yyval.no) = CriaNo(no_statements,"","If");
																	AdicionaNo((yyval.no),(yyvsp[-2].no));
																	aux=CriaNo(no_statements,"","Block");
																	if(conta_irmaos((yyvsp[0].no)) == 1 && (yyvsp[0].no) != NULL){
																		AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));
																		AdicionaIrmao((yyvsp[0].no),aux);
																		}else{
																			AdicionaIrmao((yyvsp[-2].no),aux);
																			AdicionaNo(aux,(yyvsp[0].no));
																			AdicionaIrmao(aux,CriaNo(no_statements,"","Block"));
																		}
																	}
#line 1731 "y.tab.c"
    break;

  case 32: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 213 "jucompiler.y"
                                                                                                {(yyval.no) = CriaNo(no_statements,"","If");
																	AdicionaNo((yyval.no),(yyvsp[-4].no)); 
																	aux = CriaNo(no_statements,"","Block");
																	if (conta_irmaos((yyvsp[-2].no)) == 1 && (yyvsp[-2].no) != NULL) {
																		AdicionaIrmao((yyvsp[-4].no), (yyvsp[-2].no));
																		if (conta_irmaos((yyvsp[0].no)) == 1 && (yyvsp[0].no) != NULL) {
																			AdicionaIrmao((yyvsp[-2].no), (yyvsp[0].no));
																		}else {
																			AdicionaIrmao((yyvsp[-2].no), aux);
																			AdicionaNo(aux, (yyvsp[0].no));}
																	}else {
																		AdicionaIrmao((yyvsp[-4].no), aux);
																		AdicionaNo(aux, (yyvsp[-2].no));
																		if (conta_irmaos((yyvsp[0].no)) == 1 && (yyvsp[0].no) != NULL) {
																			AdicionaIrmao(aux, (yyvsp[0].no));
																		}else {
																			auxi2 = CriaNo(no_statements,"","Block");
																			AdicionaIrmao(aux, auxi2);
																			AdicionaNo(auxi2, (yyvsp[0].no));
																		}
																	}
															}
#line 1758 "y.tab.c"
    break;

  case 33: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 237 "jucompiler.y"
                                                                                                        {(yyval.no) = CriaNo(no_statements,"","While");
																	AdicionaNo((yyval.no),(yyvsp[-2].no));
																	if(conta_irmaos((yyvsp[0].no)) == 1 && (yyvsp[0].no) != NULL){
																		AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));
																	}else{
																		aux = CriaNo(no_statements,"","Block");
																		AdicionaIrmao((yyvsp[-2].no),aux);
																		AdicionaNo(aux,(yyvsp[0].no));
																	}
																	}
#line 1773 "y.tab.c"
    break;

  case 34: /* Statement: RETURN SEMICOLON  */
#line 248 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_statements,"","Return");}
#line 1779 "y.tab.c"
    break;

  case 35: /* Statement: RETURN Expr SEMICOLON  */
#line 249 "jucompiler.y"
                                                                                                                {(yyval.no) = CriaNo(no_statements,"","Return");
																	AdicionaNo((yyval.no),(yyvsp[-1].no));}
#line 1786 "y.tab.c"
    break;

  case 36: /* Statement: StatementThird SEMICOLON  */
#line 251 "jucompiler.y"
                                                                                                                {(yyval.no) = (yyvsp[-1].no);}
#line 1792 "y.tab.c"
    break;

  case 37: /* Statement: PRINT LPAR StatementPrint RPAR SEMICOLON  */
#line 252 "jucompiler.y"
                                                                                                {(yyval.no) = CriaNo(no_statements,"","Print");
																	AdicionaNo((yyval.no),(yyvsp[-2].no));
																	}
#line 1800 "y.tab.c"
    break;

  case 38: /* Statement: error SEMICOLON  */
#line 255 "jucompiler.y"
                                                                                                                        {(yyval.no)=NULL;flagErro=false;}
#line 1806 "y.tab.c"
    break;

  case 39: /* StatementSec: Statement StatementSec  */
#line 260 "jucompiler.y"
                                                                                                                {if((yyvsp[-1].no) != NULL){
																		(yyval.no)=(yyvsp[-1].no);
																		AdicionaIrmao((yyval.no),(yyvsp[0].no));
																	}else{
																		(yyval.no)=(yyvsp[0].no);}
			}
#line 1817 "y.tab.c"
    break;

  case 40: /* StatementSec: %empty  */
#line 266 "jucompiler.y"
                                                                                                                        {(yyval.no) = NULL;}
#line 1823 "y.tab.c"
    break;

  case 41: /* StatementThird: %empty  */
#line 270 "jucompiler.y"
                                                                                                                {(yyval.no) = NULL;}
#line 1829 "y.tab.c"
    break;

  case 42: /* StatementThird: MethodInvocation  */
#line 271 "jucompiler.y"
                                                                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1835 "y.tab.c"
    break;

  case 43: /* StatementThird: Assignment  */
#line 272 "jucompiler.y"
                                                                                                                                {(yyval.no) = (yyvsp[0].no);}
#line 1841 "y.tab.c"
    break;

  case 44: /* StatementThird: ParseArgs  */
#line 273 "jucompiler.y"
                                                                                                                                {(yyval.no) = (yyvsp[0].no);}
#line 1847 "y.tab.c"
    break;

  case 45: /* StatementPrint: Expr  */
#line 276 "jucompiler.y"
                                                                                                                {(yyval.no) = (yyvsp[0].no);}
#line 1853 "y.tab.c"
    break;

  case 46: /* StatementPrint: STRLIT  */
#line 277 "jucompiler.y"
                                                                                                                                {(yyval.no) = CriaNo(no_terminais,(yyvsp[0].id),"StrLit");}
#line 1859 "y.tab.c"
    break;

  case 47: /* MethodInvocation: ID LPAR MethodInvocationSec RPAR  */
#line 281 "jucompiler.y"
                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Call");
																	aux = CriaNo(no_ids,(yyvsp[-3].id),"Id");
																	AdicionaNo((yyval.no),aux);
																	AdicionaIrmao(aux,(yyvsp[-1].no));}
#line 1868 "y.tab.c"
    break;

  case 48: /* MethodInvocation: ID LPAR error RPAR  */
#line 285 "jucompiler.y"
                                                                                                                {(yyval.no) = NULL;
															flagErro = false;}
#line 1875 "y.tab.c"
    break;

  case 49: /* MethodInvocationSec: Expr MethodInvocationThird  */
#line 290 "jucompiler.y"
                                                                                                                {(yyval.no) = (yyvsp[-1].no);AdicionaIrmao((yyval.no),(yyvsp[0].no));}
#line 1881 "y.tab.c"
    break;

  case 50: /* MethodInvocationSec: %empty  */
#line 291 "jucompiler.y"
                                                                                                                                {(yyval.no) = NULL;}
#line 1887 "y.tab.c"
    break;

  case 51: /* MethodInvocationThird: COMMA Expr MethodInvocationThird  */
#line 295 "jucompiler.y"
                                                                                {if((yyvsp[-1].no)!=NULL){
																		(yyval.no)=(yyvsp[-1].no);
																		AdicionaIrmao((yyval.no),(yyvsp[0].no));
																	}else{(yyval.no)=(yyvsp[-1].no);}}
#line 1896 "y.tab.c"
    break;

  case 52: /* MethodInvocationThird: %empty  */
#line 299 "jucompiler.y"
                                                                                                                        {(yyval.no) = NULL;}
#line 1902 "y.tab.c"
    break;

  case 53: /* Assignment: ID ASSIGN Expr  */
#line 302 "jucompiler.y"
                                                                                                                {(yyval.no) = CriaNo(no_operadores,"","Assign");
																	aux = CriaNo(no_ids,(yyvsp[-2].id),"Id");
																	AdicionaNo((yyval.no),aux);
																	AdicionaIrmao(aux,(yyvsp[0].no));}
#line 1911 "y.tab.c"
    break;

  case 54: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 308 "jucompiler.y"
                                                                                                {(yyval.no) = CriaNo(no_operadores,"","ParseArgs");
																	aux = CriaNo(no_ids,(yyvsp[-4].id),"Id");
																	AdicionaNo((yyval.no),aux);
																	AdicionaIrmao(aux,(yyvsp[-2].no));}
#line 1920 "y.tab.c"
    break;

  case 55: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 312 "jucompiler.y"
                                                                                                                                                                                {(yyval.no) = NULL;flagErro=false;}
#line 1926 "y.tab.c"
    break;

  case 56: /* Expr: Assignment  */
#line 317 "jucompiler.y"
                                                                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1932 "y.tab.c"
    break;

  case 57: /* Expr: Expr1  */
#line 318 "jucompiler.y"
                                                                                                                                {(yyval.no) = (yyvsp[0].no);}
#line 1938 "y.tab.c"
    break;

  case 58: /* Expr1: Expr1 PLUS Expr1  */
#line 322 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Add");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1944 "y.tab.c"
    break;

  case 59: /* Expr1: Expr1 MINUS Expr1  */
#line 323 "jucompiler.y"
                                                                                                                                {(yyval.no) = CriaNo(no_operadores,"","Sub");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1950 "y.tab.c"
    break;

  case 60: /* Expr1: Expr1 STAR Expr1  */
#line 324 "jucompiler.y"
                                                                                                                                {(yyval.no) = CriaNo(no_operadores,"","Mul");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1956 "y.tab.c"
    break;

  case 61: /* Expr1: Expr1 DIV Expr1  */
#line 325 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Div");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1962 "y.tab.c"
    break;

  case 62: /* Expr1: Expr1 MOD Expr1  */
#line 326 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Mod");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1968 "y.tab.c"
    break;

  case 63: /* Expr1: Expr1 AND Expr1  */
#line 327 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","And");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1974 "y.tab.c"
    break;

  case 64: /* Expr1: Expr1 OR Expr1  */
#line 328 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Or");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1980 "y.tab.c"
    break;

  case 65: /* Expr1: Expr1 XOR Expr1  */
#line 329 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Xor");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1986 "y.tab.c"
    break;

  case 66: /* Expr1: Expr1 LSHIFT Expr1  */
#line 330 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Lshift");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1992 "y.tab.c"
    break;

  case 67: /* Expr1: Expr1 RSHIFT Expr1  */
#line 331 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Rshift");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1998 "y.tab.c"
    break;

  case 68: /* Expr1: Expr1 EQ Expr1  */
#line 332 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Eq");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 2004 "y.tab.c"
    break;

  case 69: /* Expr1: Expr1 GE Expr1  */
#line 333 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Ge");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 2010 "y.tab.c"
    break;

  case 70: /* Expr1: Expr1 GT Expr1  */
#line 334 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Gt");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 2016 "y.tab.c"
    break;

  case 71: /* Expr1: Expr1 LE Expr1  */
#line 335 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Le");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 2022 "y.tab.c"
    break;

  case 72: /* Expr1: Expr1 LT Expr1  */
#line 336 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Lt");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 2028 "y.tab.c"
    break;

  case 73: /* Expr1: Expr1 NE Expr1  */
#line 337 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Ne");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 2034 "y.tab.c"
    break;

  case 74: /* Expr1: PLUS Expr1  */
#line 338 "jucompiler.y"
                                                                                                                {(yyval.no) = CriaNo(no_operadores,"","Plus");AdicionaNo((yyval.no),(yyvsp[0].no));}
#line 2040 "y.tab.c"
    break;

  case 75: /* Expr1: MINUS Expr1  */
#line 339 "jucompiler.y"
                                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Minus");AdicionaNo((yyval.no),(yyvsp[0].no));}
#line 2046 "y.tab.c"
    break;

  case 76: /* Expr1: NOT Expr1  */
#line 340 "jucompiler.y"
                                                                {(yyval.no) = CriaNo(no_operadores,"","Not");AdicionaNo((yyval.no),(yyvsp[0].no));}
#line 2052 "y.tab.c"
    break;

  case 77: /* Expr1: LPAR Expr RPAR  */
#line 341 "jucompiler.y"
                                                                                                                        {(yyval.no) = (yyvsp[-1].no);}
#line 2058 "y.tab.c"
    break;

  case 78: /* Expr1: LPAR error RPAR  */
#line 342 "jucompiler.y"
                                                                                                                        {(yyval.no) = NULL;flagErro = false;}
#line 2064 "y.tab.c"
    break;

  case 79: /* Expr1: Expr2  */
#line 343 "jucompiler.y"
                                                                                                                                {(yyval.no) = (yyvsp[0].no);}
#line 2070 "y.tab.c"
    break;

  case 80: /* Expr1: ID  */
#line 344 "jucompiler.y"
                                                                                                                                        {(yyval.no) = CriaNo(no_ids,(yyvsp[0].id),"Id");}
#line 2076 "y.tab.c"
    break;

  case 81: /* Expr1: ID DOTLENGTH  */
#line 345 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(no_operadores,"","Length");AdicionaNo((yyval.no),CriaNo(no_ids,(yyvsp[-1].id),"Id"));}
#line 2082 "y.tab.c"
    break;

  case 82: /* Expr1: ExprLit  */
#line 346 "jucompiler.y"
                                                                                                                                {(yyval.no)=(yyvsp[0].no);}
#line 2088 "y.tab.c"
    break;

  case 83: /* Expr2: MethodInvocation  */
#line 348 "jucompiler.y"
                                                                                                {(yyval.no) = (yyvsp[0].no);}
#line 2094 "y.tab.c"
    break;

  case 84: /* Expr2: ParseArgs  */
#line 349 "jucompiler.y"
                                                                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2100 "y.tab.c"
    break;

  case 85: /* ExprLit: INTLIT  */
#line 352 "jucompiler.y"
                                                                                                                {(yyval.no) = CriaNo(no_operadores,(yyvsp[0].id),"DecLit");}
#line 2106 "y.tab.c"
    break;

  case 86: /* ExprLit: REALLIT  */
#line 353 "jucompiler.y"
                                                                                                                                {(yyval.no) = CriaNo(no_operadores,(yyvsp[0].id),"RealLit");}
#line 2112 "y.tab.c"
    break;

  case 87: /* ExprLit: BOOLLIT  */
#line 354 "jucompiler.y"
                                                                                                                                {(yyval.no) = CriaNo(no_operadores,(yyvsp[0].id),"BoolLit");}
#line 2118 "y.tab.c"
    break;


#line 2122 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 357 "jucompiler.y"






