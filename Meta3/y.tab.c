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
#line 4 "jucompiler.y"

	#include <string.h>
	#include <stdbool.h>
	#include <stdio.h>
	#include "structures.h"
	#include "functions.h"
	#include "y.tab.h"
	no aux=NULL;
	no auxi2=NULL;
	bool flagErro = true;
	no raiz;
    int yylex(void);
    void yyerror (char *s);
    int yyparse(void);
	extern id_info id;

	char *auxx[3];
	


#line 92 "y.tab.c"

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
#line 25 "jucompiler.y"

    char* id[3];
    struct node *no;
	struct id_info *id_i;	

#line 251 "y.tab.c"

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
  YYSYMBOL_CmId = 56,                      /* CmId  */
  YYSYMBOL_Type = 57,                      /* Type  */
  YYSYMBOL_MethodHeader = 58,              /* MethodHeader  */
  YYSYMBOL_FormalParams = 59,              /* FormalParams  */
  YYSYMBOL_FormalParamsSec = 60,           /* FormalParamsSec  */
  YYSYMBOL_MethodBody = 61,                /* MethodBody  */
  YYSYMBOL_MethodBodySec = 62,             /* MethodBodySec  */
  YYSYMBOL_VarDecl = 63,                   /* VarDecl  */
  YYSYMBOL_Statement = 64,                 /* Statement  */
  YYSYMBOL_ExprReturn = 65,                /* ExprReturn  */
  YYSYMBOL_StatementSec = 66,              /* StatementSec  */
  YYSYMBOL_StatementPrint = 67,            /* StatementPrint  */
  YYSYMBOL_MethodInvocation = 68,          /* MethodInvocation  */
  YYSYMBOL_MethodInvocationSec = 69,       /* MethodInvocationSec  */
  YYSYMBOL_MethodInvocationThird = 70,     /* MethodInvocationThird  */
  YYSYMBOL_Assignment = 71,                /* Assignment  */
  YYSYMBOL_ParseArgs = 72,                 /* ParseArgs  */
  YYSYMBOL_Expr = 73,                      /* Expr  */
  YYSYMBOL_Expr1 = 74,                     /* Expr1  */
  YYSYMBOL_Expr2 = 75                      /* Expr2  */
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
#define YYLAST   377

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

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
       0,    63,    63,    70,    74,    75,    76,    77,    80,    86,
     103,   106,   109,   112,   113,   114,   117,   125,   135,   141,
     145,   149,   154,   157,   163,   169,   172,   175,   193,   200,
     212,   236,   248,   251,   252,   253,   254,   255,   258,   263,
     264,   268,   274,   279,   280,   284,   288,   292,   293,   297,
     301,   304,   310,   314,   319,   320,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354
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
  "declaration", "MethodDecl", "FieldDecl", "CmId", "Type", "MethodHeader",
  "FormalParams", "FormalParamsSec", "MethodBody", "MethodBodySec",
  "VarDecl", "Statement", "ExprReturn", "StatementSec", "StatementPrint",
  "MethodInvocation", "MethodInvocationSec", "MethodInvocationThird",
  "Assignment", "ParseArgs", "Expr", "Expr1", "Expr2", YY_NULLPTR
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

#define YYTABLE_NINF (-49)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -22,   -40,    28,    27,   -41,    25,    16,    25,     5,    29,
      25,    25,   -41,   -41,   126,    15,   -41,   -41,    10,   -41,
     -41,   -41,    21,    63,   -41,    65,    49,   114,   -41,    80,
      38,    80,    70,    72,   139,   -41,    75,    87,    89,   170,
      93,    64,    58,    88,   114,   114,    95,   103,   105,   100,
      86,   119,   112,   121,   -41,   -41,   139,    94,   170,   146,
       2,    44,   185,   185,   185,     1,   -41,   -41,   -41,   138,
     -41,   -41,   -41,   -41,   232,   -41,   170,   170,    23,   112,
     -41,   -41,   -41,   -41,   -41,   -41,   122,   165,   -41,   -41,
     -41,   -41,   -41,   152,   -41,   159,   -41,   161,   176,   174,
     177,    -1,   -41,   -41,   -41,   -41,   -41,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   179,   -41,   180,   184,   193,   183,   163,
     110,   -41,    48,   186,   -41,   170,   -41,   -41,   284,   -41,
     -41,   333,    59,    59,    59,    59,    91,   -41,   333,   259,
      91,    96,    96,   309,    48,   -41,   -41,   170,   -41,   -41,
     -41,   164,   181,   -41,   188,   -41,   193,   165,    48,   191,
     -41,   -41,   -41,   -41
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,    10,     6,     0,     0,     4,     5,     0,    14,
      15,    13,     0,     0,     3,     0,    12,     0,     8,    20,
       0,    20,     0,     0,     0,    36,     0,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     9,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    82,    83,    84,     0,
      76,    54,    77,    40,    55,    72,     0,     0,     0,    12,
      23,    25,    24,    33,    34,    35,     0,    22,    17,    11,
      16,    41,    28,     0,    44,     0,    43,     0,     0,     0,
       0,    80,    75,    73,    74,    81,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,    50,     0,     0,
       0,    18,     0,     0,    53,     0,    79,    78,    61,    58,
      59,    66,    67,    68,    69,    70,    57,    60,    71,    62,
      56,    64,    65,    63,     0,    46,    45,     0,    47,    27,
      19,     0,    29,    37,     0,    31,    50,    22,     0,     0,
      49,    21,    30,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -41,   -41,   127,   -41,   -41,   -39,    -4,   -41,   190,    55,
     -41,   143,   -41,   -33,   -41,   167,   -41,   -27,   -41,    60,
     -25,   -23,   -24,   255,   115
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    11,    32,    42,    23,    51,   131,
      28,    43,    44,    45,    69,    57,    95,    70,   126,   158,
      71,    72,    73,    74,    75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    56,    47,    97,    48,    77,     3,    46,     1,    47,
      22,    48,    78,    89,    78,    -2,    24,    46,    46,    47,
      47,    48,    48,    56,   125,    50,     6,    50,     4,    46,
     105,    47,   105,    48,    93,    96,    61,   100,     5,    62,
     128,    12,    63,    14,    64,    99,   -48,    -7,    98,    33,
       7,    15,   123,   124,   127,    30,    25,    61,    38,    34,
      62,     8,    31,    63,   108,    64,   109,    26,    77,    65,
      66,    67,    68,    35,    27,   115,   116,    78,    29,    38,
     119,    36,    37,    38,    52,    39,   120,   121,    58,    40,
      65,    66,    67,    68,    41,    54,   108,    55,   109,   162,
      59,   108,    60,   109,    79,    46,    76,    47,   116,    48,
      80,   164,   115,   116,    86,    33,    92,   119,    30,    49,
      83,   165,    19,    20,    21,    34,   161,    46,    84,    47,
      85,    48,    87,   166,    13,   172,   -26,    16,    17,    35,
      33,    46,    88,    47,    90,    48,   129,    36,    37,    38,
      34,    39,    19,    20,    21,    40,    19,    20,    21,    61,
      41,   -42,    62,   106,    35,    63,    18,    64,    19,    20,
      21,   130,    36,    37,    38,   132,    39,   102,   103,   104,
      40,    38,   133,    61,   134,    41,    62,    81,    82,    63,
     135,    64,    65,    66,    67,    68,    94,   136,    61,   157,
     137,    62,   154,   155,    63,    38,    64,   156,   159,   160,
     167,   163,   169,   168,   173,     0,    65,    66,    67,    68,
      38,    53,   171,    91,     0,     0,   170,     0,     0,     0,
       0,   101,    66,    67,    68,   107,     0,   108,     0,   109,
     110,   111,   112,     0,   113,     0,     0,   114,   115,   116,
     117,     0,   118,   119,     0,     0,     0,     0,     0,   120,
     121,   122,   107,     0,   108,     0,   109,   110,   111,   112,
       0,   113,     0,     0,   114,   115,   116,   117,     0,     0,
     119,     0,     0,     0,     0,     0,   120,   121,   122,   108,
       0,   109,   110,   111,   112,     0,   113,     0,     0,   114,
     115,   116,   117,     0,     0,   119,     0,     0,     0,     0,
       0,   120,   121,   122,   108,     0,   109,   110,   111,   112,
       0,   113,     0,     0,   114,   115,   116,   117,     0,     0,
     119,     0,     0,     0,     0,     0,   120,   121,   108,     0,
     109,     0,   111,   112,     0,   113,     0,     0,   114,   115,
     116,     0,     0,     0,   119,     0,     0,     0,     0,     0,
     120,   121,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153
};

static const yytype_int16 yycheck[] =
{
      27,    34,    27,     1,    27,     4,    46,    34,    30,    34,
      14,    34,    13,    52,    13,     0,     1,    44,    45,    44,
      45,    44,    45,    56,     1,    29,     1,    31,     0,    56,
      31,    56,    31,    56,    58,    59,    13,    61,    11,    16,
      79,    25,    19,    38,    21,     1,    23,    22,    46,     1,
      25,    22,    76,    77,    78,     6,    46,    13,    35,    11,
      16,    36,    13,    19,     5,    21,     7,    46,     4,    46,
      47,    48,    49,    25,    11,    16,    17,    13,    13,    35,
      21,    33,    34,    35,    46,    37,    27,    28,    13,    41,
      46,    47,    48,    49,    46,    25,     5,    25,     7,   132,
      13,     5,    13,     7,    46,   132,    13,   132,    17,   132,
      22,   135,    16,    17,    14,     1,    22,    21,     6,    39,
      25,   154,    42,    43,    44,    11,   130,   154,    25,   154,
      25,   154,    46,   157,     7,   168,    22,    10,    11,    25,
       1,   168,    23,   168,    23,   168,    24,    33,    34,    35,
      11,    37,    42,    43,    44,    41,    42,    43,    44,    13,
      46,    22,    16,    25,    25,    19,    40,    21,    42,    43,
      44,     6,    33,    34,    35,    23,    37,    62,    63,    64,
      41,    35,    23,    13,    23,    46,    16,    44,    45,    19,
      14,    21,    46,    47,    48,    49,    50,    23,    13,     6,
      23,    16,    23,    23,    19,    35,    21,    23,    25,    46,
      46,    25,    24,    32,    23,    -1,    46,    47,    48,    49,
      35,    31,   167,    56,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,     3,    -1,     5,    -1,     7,
       8,     9,    10,    -1,    12,    -1,    -1,    15,    16,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,     3,    -1,     5,    -1,     7,     8,     9,    10,
      -1,    12,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,     5,
      -1,     7,     8,     9,    10,    -1,    12,    -1,    -1,    15,
      16,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,     5,    -1,     7,     8,     9,    10,
      -1,    12,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    27,    28,     5,    -1,
       7,    -1,     9,    10,    -1,    12,    -1,    -1,    15,    16,
      17,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      27,    28,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    52,    46,     0,    11,     1,    25,    36,    53,
      54,    55,    25,    53,    38,    22,    53,    53,    40,    42,
      43,    44,    57,    58,     1,    46,    46,    11,    61,    13,
       6,    13,    56,     1,    11,    25,    33,    34,    35,    37,
      41,    46,    57,    62,    63,    64,    68,    71,    72,    39,
      57,    59,    46,    59,    25,    25,    64,    66,    13,    13,
      13,    13,    16,    19,    21,    46,    47,    48,    49,    65,
      68,    71,    72,    73,    74,    75,    13,     4,    13,    46,
      22,    62,    62,    25,    25,    25,    14,    46,    23,    56,
      23,    66,    22,    73,    50,    67,    73,     1,    46,     1,
      73,    46,    75,    75,    75,    31,    25,     3,     5,     7,
       8,     9,    10,    12,    15,    16,    17,    18,    20,    21,
      27,    28,    29,    73,    73,     1,    69,    73,    56,    24,
       6,    60,    23,    23,    23,    14,    23,    23,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    23,    23,    23,     6,    70,    25,
      46,    57,    64,    25,    73,    64,    73,    46,    32,    24,
      70,    60,    64,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    53,    53,    54,    55,
      55,    56,    56,    57,    57,    57,    58,    58,    59,    59,
      59,    60,    60,    61,    62,    62,    62,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    72,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     6,     2,     2,     2,     0,     4,     6,
       2,     3,     0,     1,     1,     1,     5,     5,     3,     4,
       0,     4,     0,     3,     2,     2,     0,     4,     3,     5,
       7,     5,     3,     2,     2,     2,     1,     5,     2,     0,
       1,     2,     0,     1,     1,     4,     4,     2,     0,     3,
       0,     3,     7,     4,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     2,     2,     2,     1,     1,     3,     3,
       1,     2,     1,     1,     1
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
#line 63 "jucompiler.y"
                                                                                                {raiz = CriaNo(NULL,"","Program");
																	aux = CriaNo((yyvsp[-3].id),NULL,"Id");
																	AdicionaNo(raiz,aux);
																	AdicionaIrmao(aux,(yyvsp[-1].no));
																	(yyval.no) = raiz;		
																	}
#line 1464 "y.tab.c"
    break;

  case 3: /* Program: CLASS ID LBRACE declaration RBRACE error  */
#line 70 "jucompiler.y"
                                                                                                {(yyval.no) = NULL;flagErro = false;}
#line 1470 "y.tab.c"
    break;

  case 4: /* declaration: MethodDecl declaration  */
#line 74 "jucompiler.y"
                                                                                                                {(yyval.no) = (yyvsp[-1].no);AdicionaIrmao((yyval.no),(yyvsp[0].no));}
#line 1476 "y.tab.c"
    break;

  case 5: /* declaration: FieldDecl declaration  */
#line 75 "jucompiler.y"
                                                                                                                {(yyval.no) = (yyvsp[-1].no);AdicionaIrmao((yyval.no),(yyvsp[0].no));}
#line 1482 "y.tab.c"
    break;

  case 6: /* declaration: SEMICOLON declaration  */
#line 76 "jucompiler.y"
                                                                                                                {(yyval.no) = (yyvsp[0].no);}
#line 1488 "y.tab.c"
    break;

  case 7: /* declaration: %empty  */
#line 77 "jucompiler.y"
                                                                                                                                {(yyval.no) = NULL;}
#line 1494 "y.tab.c"
    break;

  case 8: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 80 "jucompiler.y"
                                                                                        {(yyval.no) = CriaNo(NULL,"","MethodDecl");
																	AdicionaNo((yyval.no),(yyvsp[-1].no));
																	AdicionaIrmao((yyvsp[-1].no),(yyvsp[0].no));}
#line 1502 "y.tab.c"
    break;

  case 9: /* FieldDecl: PUBLIC STATIC Type ID CmId SEMICOLON  */
#line 86 "jucompiler.y"
                                                                                {(yyval.no) = CriaNo(NULL,"","FieldDecl");
																	AdicionaNo((yyval.no),(yyvsp[-3].no));
																	AdicionaIrmao((yyvsp[-3].no),CriaNo((yyvsp[-2].id),NULL,"Id"));

																	if ( (yyvsp[-1].no) != NULL ) {
																		aux = (yyvsp[-1].no);
																		while(aux != NULL){
																			no aux1 = CriaNo(NULL,"","FieldDecl");
																			no aux2 = CriaNo(NULL,(yyvsp[-3].no)->valor,(yyvsp[-3].no)->s_type);
																			AdicionaNo(aux1,aux2);
																			AdicionaIrmao(aux2,CriaNo(NULL,aux->valor,"Id"));
																			AdicionaIrmao((yyval.no),aux1);
																			aux = aux->irmao;
																		}		
																		free(aux);
																	}
																	}
#line 1524 "y.tab.c"
    break;

  case 10: /* FieldDecl: error SEMICOLON  */
#line 103 "jucompiler.y"
                                                                                                                                {(yyval.no) = NULL;flagErro = false;}
#line 1530 "y.tab.c"
    break;

  case 11: /* CmId: COMMA ID CmId  */
#line 106 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),NULL,"Id");
																		AdicionaIrmao((yyval.no),(yyvsp[0].no));
																	}
#line 1538 "y.tab.c"
    break;

  case 12: /* CmId: %empty  */
#line 109 "jucompiler.y"
                                                                                                                                {(yyval.no) = NULL;}
#line 1544 "y.tab.c"
    break;

  case 13: /* Type: BOOL  */
#line 112 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(NULL,"","Bool");}
#line 1550 "y.tab.c"
    break;

  case 14: /* Type: INT  */
#line 113 "jucompiler.y"
                                                                                                                                        {(yyval.no) = CriaNo(NULL,"","Int");}
#line 1556 "y.tab.c"
    break;

  case 15: /* Type: DOUBLE  */
#line 114 "jucompiler.y"
                                                                                                                                {(yyval.no) = CriaNo(NULL,"","Double");}
#line 1562 "y.tab.c"
    break;

  case 16: /* MethodHeader: Type ID LPAR FormalParams RPAR  */
#line 117 "jucompiler.y"
                                                                                        {(yyval.no) = CriaNo(NULL,"","MethodHeader");
																	AdicionaNo((yyval.no),(yyvsp[-4].no));
																	AdicionaIrmao((yyvsp[-4].no),CriaNo((yyvsp[-3].id),NULL,"Id"));
																	aux = CriaNo(NULL,"","MethodParams");
																	AdicionaIrmao((yyvsp[-4].no),aux);
																	AdicionaNo(aux,(yyvsp[-1].no));
																	}
#line 1574 "y.tab.c"
    break;

  case 17: /* MethodHeader: VOID ID LPAR FormalParams RPAR  */
#line 125 "jucompiler.y"
                                                                                                        {(yyval.no) = CriaNo(NULL,"","MethodHeader");
																	aux = CriaNo(NULL,"","Void");
																	AdicionaNo((yyval.no),aux);
																	AdicionaIrmao(aux,CriaNo((yyvsp[-3].id),NULL,"Id"));
																	auxi2 = CriaNo(NULL,"","MethodParams");
																	AdicionaIrmao(aux,auxi2);
																	AdicionaNo(auxi2,(yyvsp[-1].no));
																	}
#line 1587 "y.tab.c"
    break;

  case 18: /* FormalParams: Type ID FormalParamsSec  */
#line 135 "jucompiler.y"
                                                                                                {(yyval.no) = CriaNo(NULL,"","ParamDecl");
																	AdicionaNo((yyval.no),(yyvsp[-2].no));
																	aux=CriaNo((yyvsp[-1].id),NULL,"Id");
																	AdicionaIrmao((yyvsp[-2].no),aux);
																	AdicionaIrmao((yyval.no),(yyvsp[0].no));}
#line 1597 "y.tab.c"
    break;

  case 19: /* FormalParams: STRING LSQ RSQ ID  */
#line 141 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(NULL,"","ParamDecl");
																	aux = CriaNo(NULL,"","StringArray");
																	AdicionaNo((yyval.no),aux);
																	AdicionaIrmao(aux,CriaNo((yyvsp[0].id),NULL,"Id"));}
#line 1606 "y.tab.c"
    break;

  case 20: /* FormalParams: %empty  */
#line 145 "jucompiler.y"
                                                                                                                                {(yyval.no) = NULL;}
#line 1612 "y.tab.c"
    break;

  case 21: /* FormalParamsSec: COMMA Type ID FormalParamsSec  */
#line 149 "jucompiler.y"
                                                                                                        {(yyval.no) = CriaNo(NULL,"","ParamDecl");
																	aux=CriaNo((yyvsp[-1].id),NULL,"Id");
																	AdicionaNo((yyval.no),(yyvsp[-2].no));
																	AdicionaIrmao((yyvsp[-2].no),aux);
																	AdicionaIrmao((yyval.no),(yyvsp[0].no));}
#line 1622 "y.tab.c"
    break;

  case 22: /* FormalParamsSec: %empty  */
#line 154 "jucompiler.y"
                                                                                                                                {(yyval.no) = NULL;}
#line 1628 "y.tab.c"
    break;

  case 23: /* MethodBody: LBRACE MethodBodySec RBRACE  */
#line 157 "jucompiler.y"
                                                                                                        {(yyval.no) = CriaNo(NULL,"","MethodBody");
																	AdicionaNo((yyval.no),(yyvsp[-1].no));
																	}
#line 1636 "y.tab.c"
    break;

  case 24: /* MethodBodySec: Statement MethodBodySec  */
#line 163 "jucompiler.y"
                                                                                                                {if((yyvsp[-1].no) != NULL){
																		(yyval.no) = (yyvsp[-1].no); 
																		AdicionaIrmao((yyval.no),(yyvsp[0].no));
																	}else{
																		(yyval.no)=(yyvsp[0].no);}
																	}
#line 1647 "y.tab.c"
    break;

  case 25: /* MethodBodySec: VarDecl MethodBodySec  */
#line 169 "jucompiler.y"
                                                                                                                {(yyval.no) = (yyvsp[-1].no);
																	AdicionaIrmao((yyval.no),(yyvsp[0].no));
																	}
#line 1655 "y.tab.c"
    break;

  case 26: /* MethodBodySec: %empty  */
#line 172 "jucompiler.y"
                                                                                                                                {(yyval.no) = NULL;}
#line 1661 "y.tab.c"
    break;

  case 27: /* VarDecl: Type ID CmId SEMICOLON  */
#line 175 "jucompiler.y"
                                                                                        {(yyval.no) = CriaNo(NULL,"","VarDecl");
																	AdicionaNo((yyval.no),(yyvsp[-3].no));
																	AdicionaIrmao((yyvsp[-3].no),CriaNo((yyvsp[-2].id),NULL,"Id"));
																	if ((yyvsp[-1].no)){
																		aux = (yyvsp[-1].no);
																		while(aux != NULL){
																			no aux1 = CriaNo(NULL,"","VarDecl");
																			no aux2 = CriaNo(NULL,(yyvsp[-3].no)->valor,(yyvsp[-3].no)->s_type);
																			AdicionaNo(aux1,aux2);
																			AdicionaIrmao(aux2,CriaNo(NULL,aux->valor,"Id"));
																			AdicionaIrmao((yyval.no),aux1);
																			aux = aux->irmao;
																		}	
																		free(aux);
																															
																	}}
#line 1682 "y.tab.c"
    break;

  case 28: /* Statement: LBRACE StatementSec RBRACE  */
#line 193 "jucompiler.y"
                                                                                                        {if(conta_irmaos((yyvsp[-1].no))>1){
																		aux = CriaNo(NULL,"","Block");
																		(yyval.no)=aux;
																		AdicionaNo(aux,(yyvsp[-1].no));
																	}else{(yyval.no)=(yyvsp[-1].no);}
																	}
#line 1693 "y.tab.c"
    break;

  case 29: /* Statement: IF LPAR Expr RPAR Statement  */
#line 200 "jucompiler.y"
                                                                                        {(yyval.no) = CriaNo(NULL,"","If");
																	AdicionaNo((yyval.no),(yyvsp[-2].no));
																	aux=CriaNo(NULL,"","Block");
																	if(conta_irmaos((yyvsp[0].no)) == 1 && (yyvsp[0].no)){
																		AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));
																		AdicionaIrmao((yyvsp[0].no),aux);
																		}else{
																			AdicionaIrmao((yyvsp[-2].no),aux);
																			AdicionaNo(aux,(yyvsp[0].no));
																			AdicionaIrmao(aux,CriaNo(NULL,"","Block"));
																		}
																	}
#line 1710 "y.tab.c"
    break;

  case 30: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 212 "jucompiler.y"
                                                                                                {(yyval.no) = CriaNo(NULL,"","If");
																	AdicionaNo((yyval.no),(yyvsp[-4].no)); 
																	aux = CriaNo(NULL,"","Block");
																	if (conta_irmaos((yyvsp[-2].no)) == 1 && (yyvsp[-2].no)) {
																		AdicionaIrmao((yyvsp[-4].no), (yyvsp[-2].no));
																		if (conta_irmaos((yyvsp[0].no)) == 1 && (yyvsp[0].no)) {
																			AdicionaIrmao((yyvsp[-2].no), (yyvsp[0].no));
																		}else {
																			AdicionaIrmao((yyvsp[-2].no), aux);
																			AdicionaNo(aux, (yyvsp[0].no));}
																	}else {
																		AdicionaIrmao((yyvsp[-4].no), aux);
																		AdicionaNo(aux, (yyvsp[-2].no));
																		if (conta_irmaos((yyvsp[0].no)) == 1 && (yyvsp[0].no)) {
																			AdicionaIrmao(aux, (yyvsp[0].no));
																		}else {
																			auxi2 = CriaNo(NULL,"","Block");
																			AdicionaIrmao(aux, auxi2);
																			AdicionaNo(auxi2, (yyvsp[0].no));
																		}
																	}
																	}
#line 1737 "y.tab.c"
    break;

  case 31: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 236 "jucompiler.y"
                                                                                                        {(yyval.no) = CriaNo(NULL,"","While");
																	AdicionaNo((yyval.no),(yyvsp[-2].no));
																	if(conta_irmaos((yyvsp[0].no)) == 1 && (yyvsp[0].no)){
																		AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));
																	}else{
																		aux = CriaNo(NULL,"","Block");
																		AdicionaIrmao((yyvsp[-2].no),aux);
																		AdicionaNo(aux,(yyvsp[0].no));
																		}
																	}
#line 1752 "y.tab.c"
    break;

  case 32: /* Statement: RETURN ExprReturn SEMICOLON  */
#line 248 "jucompiler.y"
                                                                                                                {(yyval.no) = CriaNo(NULL,"","Return");
																	AdicionaNo((yyval.no),(yyvsp[-1].no));}
#line 1759 "y.tab.c"
    break;

  case 33: /* Statement: MethodInvocation SEMICOLON  */
#line 251 "jucompiler.y"
                                                                                                                {(yyval.no) = (yyvsp[-1].no);}
#line 1765 "y.tab.c"
    break;

  case 34: /* Statement: Assignment SEMICOLON  */
#line 252 "jucompiler.y"
                                                                                                                        {(yyval.no) = (yyvsp[-1].no);}
#line 1771 "y.tab.c"
    break;

  case 35: /* Statement: ParseArgs SEMICOLON  */
#line 253 "jucompiler.y"
                                                                                                                        {(yyval.no) = (yyvsp[-1].no);}
#line 1777 "y.tab.c"
    break;

  case 36: /* Statement: SEMICOLON  */
#line 254 "jucompiler.y"
                                                                                                                                {(yyval.no) = NULL;}
#line 1783 "y.tab.c"
    break;

  case 37: /* Statement: PRINT LPAR StatementPrint RPAR SEMICOLON  */
#line 255 "jucompiler.y"
                                                                                                {(yyval.no) = CriaNo(NULL,"","Print");
																	AdicionaNo((yyval.no),(yyvsp[-2].no));
																	}
#line 1791 "y.tab.c"
    break;

  case 38: /* Statement: error SEMICOLON  */
#line 258 "jucompiler.y"
                                                                                                                        {(yyval.no)=NULL;flagErro=false;}
#line 1797 "y.tab.c"
    break;

  case 39: /* ExprReturn: %empty  */
#line 263 "jucompiler.y"
                {(yyval.no)=NULL;}
#line 1803 "y.tab.c"
    break;

  case 40: /* ExprReturn: Expr  */
#line 264 "jucompiler.y"
                                {(yyval.no)=(yyvsp[0].no);}
#line 1809 "y.tab.c"
    break;

  case 41: /* StatementSec: Statement StatementSec  */
#line 268 "jucompiler.y"
                                                                                                                {if((yyvsp[-1].no)){
																		(yyval.no)=(yyvsp[-1].no);
																		AdicionaIrmao((yyval.no),(yyvsp[0].no));
																	}else{
																		(yyval.no)=(yyvsp[0].no);}
			}
#line 1820 "y.tab.c"
    break;

  case 42: /* StatementSec: %empty  */
#line 274 "jucompiler.y"
                                                                                                                        {(yyval.no) = NULL;}
#line 1826 "y.tab.c"
    break;

  case 43: /* StatementPrint: Expr  */
#line 279 "jucompiler.y"
                                                                                                                {(yyval.no) = (yyvsp[0].no);}
#line 1832 "y.tab.c"
    break;

  case 44: /* StatementPrint: STRLIT  */
#line 280 "jucompiler.y"
                                                                                                                                {(yyval.no) = CriaNo((yyvsp[0].id),NULL,"StrLit");}
#line 1838 "y.tab.c"
    break;

  case 45: /* MethodInvocation: ID LPAR MethodInvocationSec RPAR  */
#line 284 "jucompiler.y"
                                                                                        {(yyval.no) = CriaNo(NULL,"","Call");
																	aux = CriaNo((yyvsp[-3].id),NULL,"Id");
																	AdicionaNo((yyval.no),aux);
																	AdicionaIrmao(aux,(yyvsp[-1].no));}
#line 1847 "y.tab.c"
    break;

  case 46: /* MethodInvocation: ID LPAR error RPAR  */
#line 288 "jucompiler.y"
                                                                                                                        {(yyval.no) = NULL;flagErro = false;}
#line 1853 "y.tab.c"
    break;

  case 47: /* MethodInvocationSec: Expr MethodInvocationThird  */
#line 292 "jucompiler.y"
                                                                                                                {(yyval.no) = (yyvsp[-1].no);AdicionaIrmao((yyval.no),(yyvsp[0].no));}
#line 1859 "y.tab.c"
    break;

  case 48: /* MethodInvocationSec: %empty  */
#line 293 "jucompiler.y"
                                                                                                                                {(yyval.no) = NULL;}
#line 1865 "y.tab.c"
    break;

  case 49: /* MethodInvocationThird: COMMA Expr MethodInvocationThird  */
#line 297 "jucompiler.y"
                                                                                {if((yyvsp[-1].no)){
																		(yyval.no)=(yyvsp[-1].no);
																		AdicionaIrmao((yyval.no),(yyvsp[0].no));
																	}else{(yyval.no)=(yyvsp[-1].no);}}
#line 1874 "y.tab.c"
    break;

  case 50: /* MethodInvocationThird: %empty  */
#line 301 "jucompiler.y"
                                                                                                                        {(yyval.no) = NULL;}
#line 1880 "y.tab.c"
    break;

  case 51: /* Assignment: ID ASSIGN Expr  */
#line 304 "jucompiler.y"
                                                                                                                {(yyval.no) = CriaNo((yyvsp[-1].id),"","Assign");
																	aux = CriaNo((yyvsp[-2].id),NULL,"Id");
																	AdicionaNo((yyval.no),aux);
																	AdicionaIrmao(aux,(yyvsp[0].no));}
#line 1889 "y.tab.c"
    break;

  case 52: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 310 "jucompiler.y"
                                                                                                {(yyval.no) = CriaNo(NULL,"","ParseArgs");
																	aux = CriaNo((yyvsp[-4].id),NULL,"Id");
																	AdicionaNo((yyval.no),aux);
																	AdicionaIrmao(aux,(yyvsp[-2].no));}
#line 1898 "y.tab.c"
    break;

  case 53: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 314 "jucompiler.y"
                                                                                                                {(yyval.no) = NULL;flagErro=false;}
#line 1904 "y.tab.c"
    break;

  case 54: /* Expr: Assignment  */
#line 319 "jucompiler.y"
                                                                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1910 "y.tab.c"
    break;

  case 55: /* Expr: Expr1  */
#line 320 "jucompiler.y"
                                                                                                                                {(yyval.no) = (yyvsp[0].no);}
#line 1916 "y.tab.c"
    break;

  case 56: /* Expr1: Expr1 PLUS Expr1  */
#line 324 "jucompiler.y"
                                                                                                                {(yyval.no) = CriaNo((yyvsp[-1].id),"","Add");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1922 "y.tab.c"
    break;

  case 57: /* Expr1: Expr1 MINUS Expr1  */
#line 325 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),"","Sub");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1928 "y.tab.c"
    break;

  case 58: /* Expr1: Expr1 STAR Expr1  */
#line 326 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),"","Mul");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1934 "y.tab.c"
    break;

  case 59: /* Expr1: Expr1 DIV Expr1  */
#line 327 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),"","Div");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1940 "y.tab.c"
    break;

  case 60: /* Expr1: Expr1 MOD Expr1  */
#line 328 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),"","Mod");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1946 "y.tab.c"
    break;

  case 61: /* Expr1: Expr1 AND Expr1  */
#line 329 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),"","And");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1952 "y.tab.c"
    break;

  case 62: /* Expr1: Expr1 OR Expr1  */
#line 330 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),"","Or");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1958 "y.tab.c"
    break;

  case 63: /* Expr1: Expr1 XOR Expr1  */
#line 331 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),"","Xor");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1964 "y.tab.c"
    break;

  case 64: /* Expr1: Expr1 LSHIFT Expr1  */
#line 332 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),"","Lshift");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1970 "y.tab.c"
    break;

  case 65: /* Expr1: Expr1 RSHIFT Expr1  */
#line 333 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),"","Rshift");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1976 "y.tab.c"
    break;

  case 66: /* Expr1: Expr1 EQ Expr1  */
#line 334 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),"","Eq");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1982 "y.tab.c"
    break;

  case 67: /* Expr1: Expr1 GE Expr1  */
#line 335 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),"","Ge");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1988 "y.tab.c"
    break;

  case 68: /* Expr1: Expr1 GT Expr1  */
#line 336 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),"","Gt");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 1994 "y.tab.c"
    break;

  case 69: /* Expr1: Expr1 LE Expr1  */
#line 337 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),"","Le");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 2000 "y.tab.c"
    break;

  case 70: /* Expr1: Expr1 LT Expr1  */
#line 338 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),"","Lt");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 2006 "y.tab.c"
    break;

  case 71: /* Expr1: Expr1 NE Expr1  */
#line 339 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo((yyvsp[-1].id),"","Ne");AdicionaNo((yyval.no),(yyvsp[-2].no));AdicionaIrmao((yyvsp[-2].no),(yyvsp[0].no));}
#line 2012 "y.tab.c"
    break;

  case 72: /* Expr1: Expr2  */
#line 340 "jucompiler.y"
                                                                                                                                {(yyval.no) = (yyvsp[0].no);}
#line 2018 "y.tab.c"
    break;

  case 73: /* Expr2: NOT Expr2  */
#line 343 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(NULL,"","Not");AdicionaNo((yyval.no),(yyvsp[0].no));}
#line 2024 "y.tab.c"
    break;

  case 74: /* Expr2: PLUS Expr2  */
#line 344 "jucompiler.y"
                                                                                                        {(yyval.no) = CriaNo(NULL,"","Plus");AdicionaNo((yyval.no),(yyvsp[0].no));}
#line 2030 "y.tab.c"
    break;

  case 75: /* Expr2: MINUS Expr2  */
#line 345 "jucompiler.y"
                                                                                                                                {(yyval.no) = CriaNo(NULL,"","Minus");AdicionaNo((yyval.no),(yyvsp[0].no));}
#line 2036 "y.tab.c"
    break;

  case 76: /* Expr2: MethodInvocation  */
#line 346 "jucompiler.y"
                                                                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2042 "y.tab.c"
    break;

  case 77: /* Expr2: ParseArgs  */
#line 347 "jucompiler.y"
                                                                                                                                {(yyval.no) = (yyvsp[0].no);}
#line 2048 "y.tab.c"
    break;

  case 78: /* Expr2: LPAR Expr RPAR  */
#line 348 "jucompiler.y"
                                                                                                                    {(yyval.no) = (yyvsp[-1].no);}
#line 2054 "y.tab.c"
    break;

  case 79: /* Expr2: LPAR error RPAR  */
#line 349 "jucompiler.y"
                                                                                                                        {(yyval.no) = NULL;flagErro = false;}
#line 2060 "y.tab.c"
    break;

  case 80: /* Expr2: ID  */
#line 350 "jucompiler.y"
                                                                                                                                        {(yyval.no) = CriaNo((yyvsp[0].id),NULL,"Id");}
#line 2066 "y.tab.c"
    break;

  case 81: /* Expr2: ID DOTLENGTH  */
#line 351 "jucompiler.y"
                                                                                                                        {(yyval.no) = CriaNo(NULL,"","Length");AdicionaNo((yyval.no),CriaNo((yyvsp[-1].id),NULL,"Id"));}
#line 2072 "y.tab.c"
    break;

  case 82: /* Expr2: INTLIT  */
#line 352 "jucompiler.y"
                                                                                                                                {(yyval.no) = CriaNo((yyvsp[0].id),NULL,"DecLit");}
#line 2078 "y.tab.c"
    break;

  case 83: /* Expr2: REALLIT  */
#line 353 "jucompiler.y"
                                                                                                                                {(yyval.no) = CriaNo((yyvsp[0].id),NULL,"RealLit");}
#line 2084 "y.tab.c"
    break;

  case 84: /* Expr2: BOOLLIT  */
#line 354 "jucompiler.y"
                                                                                                                                {(yyval.no) = CriaNo((yyvsp[0].id),NULL,"BoolLit");}
#line 2090 "y.tab.c"
    break;


#line 2094 "y.tab.c"

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






