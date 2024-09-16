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
#line 2 "misc/bisonFile.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern char* yytext;

#include "../inc/instruction.hpp"
#include "../inc/directive.hpp" 

void yyerror(const char *s);

#line 86 "misc/bison.cpp"

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

#include "bison.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COMMA = 3,                      /* COMMA  */
  YYSYMBOL_LEFT_BRACKET = 4,               /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 5,              /* RIGHT_BRACKET  */
  YYSYMBOL_GLOBAL = 6,                     /* GLOBAL  */
  YYSYMBOL_EXTERN = 7,                     /* EXTERN  */
  YYSYMBOL_SECTION = 8,                    /* SECTION  */
  YYSYMBOL_WORD = 9,                       /* WORD  */
  YYSYMBOL_SKIP = 10,                      /* SKIP  */
  YYSYMBOL_END = 11,                       /* END  */
  YYSYMBOL_HALT = 12,                      /* HALT  */
  YYSYMBOL_INT = 13,                       /* INT  */
  YYSYMBOL_IRET = 14,                      /* IRET  */
  YYSYMBOL_CALL = 15,                      /* CALL  */
  YYSYMBOL_RET = 16,                       /* RET  */
  YYSYMBOL_JMP = 17,                       /* JMP  */
  YYSYMBOL_BEQ = 18,                       /* BEQ  */
  YYSYMBOL_BNE = 19,                       /* BNE  */
  YYSYMBOL_BGT = 20,                       /* BGT  */
  YYSYMBOL_PUSH = 21,                      /* PUSH  */
  YYSYMBOL_POP = 22,                       /* POP  */
  YYSYMBOL_XCHG = 23,                      /* XCHG  */
  YYSYMBOL_ADD = 24,                       /* ADD  */
  YYSYMBOL_SUB = 25,                       /* SUB  */
  YYSYMBOL_MUL = 26,                       /* MUL  */
  YYSYMBOL_DIV = 27,                       /* DIV  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_XOR = 31,                       /* XOR  */
  YYSYMBOL_SHL = 32,                       /* SHL  */
  YYSYMBOL_SHR = 33,                       /* SHR  */
  YYSYMBOL_LD = 34,                        /* LD  */
  YYSYMBOL_ST = 35,                        /* ST  */
  YYSYMBOL_CSRRD = 36,                     /* CSRRD  */
  YYSYMBOL_CSRWR = 37,                     /* CSRWR  */
  YYSYMBOL_LABEL = 38,                     /* LABEL  */
  YYSYMBOL_IDENT = 39,                     /* IDENT  */
  YYSYMBOL_DOLARIDENT = 40,                /* DOLARIDENT  */
  YYSYMBOL_INTEGER = 41,                   /* INTEGER  */
  YYSYMBOL_DOLARINTEGER = 42,              /* DOLARINTEGER  */
  YYSYMBOL_REGISTER = 43,                  /* REGISTER  */
  YYSYMBOL_STATUS = 44,                    /* STATUS  */
  YYSYMBOL_HANDLER = 45,                   /* HANDLER  */
  YYSYMBOL_CAUSE = 46,                     /* CAUSE  */
  YYSYMBOL_PLUS = 47,                      /* PLUS  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_statements = 50,                /* statements  */
  YYSYMBOL_statement = 51,                 /* statement  */
  YYSYMBOL_directive = 52,                 /* directive  */
  YYSYMBOL_list_of_symbols = 53,           /* list_of_symbols  */
  YYSYMBOL_list_of_literals_or_symbols = 54, /* list_of_literals_or_symbols  */
  YYSYMBOL_literal_or_symbol = 55,         /* literal_or_symbol  */
  YYSYMBOL_instruction = 56,               /* instruction  */
  YYSYMBOL_csr = 57                        /* csr  */
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
#define YYFINAL  78
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    79,    80,    83,    84,    85,    88,    89,
      90,    91,    92,    93,    96,    97,   105,   109,   118,   121,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   167,   168,
     169
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
  "\"end of file\"", "error", "\"invalid token\"", "COMMA",
  "LEFT_BRACKET", "RIGHT_BRACKET", "GLOBAL", "EXTERN", "SECTION", "WORD",
  "SKIP", "END", "HALT", "INT", "IRET", "CALL", "RET", "JMP", "BEQ", "BNE",
  "BGT", "PUSH", "POP", "XCHG", "ADD", "SUB", "MUL", "DIV", "NOT", "AND",
  "OR", "XOR", "SHL", "SHR", "LD", "ST", "CSRRD", "CSRWR", "LABEL",
  "IDENT", "DOLARIDENT", "INTEGER", "DOLARINTEGER", "REGISTER", "STATUS",
  "HANDLER", "CAUSE", "PLUS", "$accept", "program", "statements",
  "statement", "directive", "list_of_symbols",
  "list_of_literals_or_symbols", "literal_or_symbol", "instruction", "csr", YY_NULLPTR
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

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      66,   -31,   -31,   -29,   -32,   -28,   -41,   -41,   -41,   -41,
     -32,   -41,   -32,   -26,   -25,   -24,   -23,   -22,   -21,   -20,
     -19,   -18,   -17,   -16,   -15,   -14,   -13,   -12,   -11,     7,
      -9,   -40,    -8,   -41,    14,    66,   -41,   -41,   -41,   -41,
       9,     9,   -41,   -41,   -41,    30,   -41,   -41,   -41,   -41,
      33,    34,    35,   -41,   -41,    36,    37,    38,    39,    41,
     -41,    53,    54,    55,    56,    57,    18,    59,    60,    61,
      62,    63,    64,   -41,   -41,   -41,    65,    67,   -41,   -41,
      68,   -32,    26,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    -4,    84,    85,    86,    87,
      88,    12,    89,   -40,   -41,   -41,   102,   103,   105,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   106,
      92,   -41,   -41,   -41,   -41,   -41,    91,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -32,   -32,   -32,    93,    10,    -2,
     -41,   -41,   -41,   -41,   107,   -41,    94,    95,   132,   -41,
     -41
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    13,    20,    21,    22,
       0,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     2,     3,     5,     6,    14,
       8,     9,    10,    19,    18,    11,    16,    12,    23,    25,
       0,     0,     0,    29,    30,     0,     0,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,     0,     0,     1,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,    17,     0,     0,     0,    31,
      32,    33,    34,    35,    37,    38,    39,    40,    41,     0,
       0,    47,    45,    46,    44,    48,     0,    54,    52,    53,
      51,    55,    42,    43,     0,     0,     0,     0,     0,     0,
      26,    27,    28,    49,     0,    56,     0,     0,     0,    50,
      57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -41,   104,   -41,   109,   -41,   -10,   -41,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    34,    35,    36,    37,    40,    45,    46,    38,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      48,   119,    49,   145,    73,    74,    75,    43,    39,    44,
      42,    66,    80,    47,    78,   144,   126,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    81,    72,    77,    82,    83,    84,    85,
      86,    87,    88,   120,    89,   146,    67,    68,    69,    70,
      71,   127,   128,   129,   130,   131,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   106,
     103,   105,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,   134,   135,   104,   136,   137,
     147,    41,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   140,   141,   142,   121,   122,   123,
     124,   125,   132,   138,   139,   148,   143,   150,   149,    79,
       0,     0,     0,   133
};

static const yytype_int16 yycheck[] =
{
      10,     5,    12,     5,    44,    45,    46,    39,    39,    41,
      39,     4,     3,    41,     0,     5,     4,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,     3,    43,    43,     3,     3,     3,     3,
       3,     3,     3,    47,     3,    47,    39,    40,    41,    42,
      43,    39,    40,    41,    42,    43,     3,     3,     3,     3,
       3,    43,     3,     3,     3,     3,     3,     3,     3,    43,
       3,    81,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,     3,     3,    39,     3,     3,
       3,     2,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,   134,   135,   136,    43,    43,    43,
      43,    43,    43,    41,    43,    41,    43,     5,    43,    35,
      -1,    -1,    -1,   103
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    49,    50,    51,    52,    56,    39,
      53,    53,    39,    39,    41,    54,    55,    41,    55,    55,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,     4,    39,    40,    41,
      42,    43,    43,    44,    45,    46,    57,    43,     0,    51,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,    43,     3,     3,     3,     3,
       3,     3,     3,     3,    39,    55,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,     5,
      47,    43,    43,    43,    43,    43,     4,    39,    40,    41,
      42,    43,    43,    57,     3,     3,     3,     3,    41,    43,
      55,    55,    55,    43,     5,     5,    47,     3,    41,    43,
       5
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    52,    52,
      52,    52,    52,    52,    53,    53,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     2,     2,
       2,     2,     2,     1,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     2,     1,     2,     6,     6,     6,     2,
       2,     4,     4,     4,     4,     4,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       8,     4,     4,     4,     4,     4,     6,     8,     1,     1,
       1
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
  case 7: /* statement: LABEL  */
#line 85 "misc/bisonFile.y"
             { Assembler::getInstance().handleLabel((yyvsp[0].stringValue)); free((yyvsp[0].stringValue));}
#line 1219 "misc/bison.cpp"
    break;

  case 8: /* directive: GLOBAL list_of_symbols  */
#line 88 "misc/bisonFile.y"
                           { Directive::global((yyvsp[0].stringValue)); free((yyvsp[0].stringValue)); }
#line 1225 "misc/bison.cpp"
    break;

  case 9: /* directive: EXTERN list_of_symbols  */
#line 89 "misc/bisonFile.y"
                             { Directive::_extern((yyvsp[0].stringValue)); free((yyvsp[0].stringValue));}
#line 1231 "misc/bison.cpp"
    break;

  case 10: /* directive: SECTION IDENT  */
#line 90 "misc/bisonFile.y"
                    { Directive::section((yyvsp[0].stringValue)); free((yyvsp[0].stringValue)); }
#line 1237 "misc/bison.cpp"
    break;

  case 11: /* directive: WORD list_of_literals_or_symbols  */
#line 91 "misc/bisonFile.y"
                                       { Directive::word((yyvsp[0].stringValue)); }
#line 1243 "misc/bison.cpp"
    break;

  case 12: /* directive: SKIP INTEGER  */
#line 92 "misc/bisonFile.y"
                   { Directive::skip((yyvsp[0].integerValue)); }
#line 1249 "misc/bison.cpp"
    break;

  case 13: /* directive: END  */
#line 93 "misc/bisonFile.y"
          { Directive::end(); YYACCEPT;}
#line 1255 "misc/bison.cpp"
    break;

  case 14: /* list_of_symbols: IDENT  */
#line 96 "misc/bisonFile.y"
          { (yyval.stringValue)=strdup((yyvsp[0].stringValue)); free((yyvsp[0].stringValue));}
#line 1261 "misc/bison.cpp"
    break;

  case 15: /* list_of_symbols: list_of_symbols COMMA IDENT  */
#line 97 "misc/bisonFile.y"
                                  { 
        (yyval.stringValue)=(char*)malloc(strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))+2);
        sprintf((yyval.stringValue), "%s %s", (yyvsp[-2].stringValue), (yyvsp[0].stringValue));
        free((yyvsp[-2].stringValue));
        free((yyvsp[0].stringValue));
        }
#line 1272 "misc/bison.cpp"
    break;

  case 16: /* list_of_literals_or_symbols: literal_or_symbol  */
#line 105 "misc/bisonFile.y"
                      { 
        (yyval.stringValue) = strdup((yyvsp[0].stringValue));
        free((yyvsp[0].stringValue));
    }
#line 1281 "misc/bison.cpp"
    break;

  case 17: /* list_of_literals_or_symbols: list_of_literals_or_symbols COMMA literal_or_symbol  */
#line 109 "misc/bisonFile.y"
                                                          { 
        (yyval.stringValue) = (char*)malloc(strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue)) + 2);
        sprintf((yyval.stringValue), "%s %s", (yyvsp[-2].stringValue), (yyvsp[0].stringValue));
        free((yyvsp[-2].stringValue));
        free((yyvsp[0].stringValue));
    }
#line 1292 "misc/bison.cpp"
    break;

  case 18: /* literal_or_symbol: INTEGER  */
#line 118 "misc/bisonFile.y"
            { (yyval.stringValue)=(char*)malloc(12);
        sprintf((yyval.stringValue), "%u", (yyvsp[0].integerValue)); 
    }
#line 1300 "misc/bison.cpp"
    break;

  case 19: /* literal_or_symbol: IDENT  */
#line 121 "misc/bisonFile.y"
            { (yyval.stringValue) = strdup((yyvsp[0].stringValue)); free((yyvsp[0].stringValue)); }
#line 1306 "misc/bison.cpp"
    break;

  case 20: /* instruction: HALT  */
#line 125 "misc/bisonFile.y"
         { Instruction::halt();}
#line 1312 "misc/bison.cpp"
    break;

  case 21: /* instruction: INT  */
#line 126 "misc/bisonFile.y"
          { Instruction::interrupt();}
#line 1318 "misc/bison.cpp"
    break;

  case 22: /* instruction: IRET  */
#line 127 "misc/bisonFile.y"
           { Instruction::iret();}
#line 1324 "misc/bison.cpp"
    break;

  case 23: /* instruction: CALL literal_or_symbol  */
#line 128 "misc/bisonFile.y"
                             { Instruction::call((yyvsp[0].stringValue)); free((yyvsp[0].stringValue));}
#line 1330 "misc/bison.cpp"
    break;

  case 24: /* instruction: RET  */
#line 129 "misc/bisonFile.y"
          {  Instruction::ret(); }
#line 1336 "misc/bison.cpp"
    break;

  case 25: /* instruction: JMP literal_or_symbol  */
#line 130 "misc/bisonFile.y"
                            { Instruction::jmp((yyvsp[0].stringValue)); free((yyvsp[0].stringValue));}
#line 1342 "misc/bison.cpp"
    break;

  case 26: /* instruction: BEQ REGISTER COMMA REGISTER COMMA literal_or_symbol  */
#line 131 "misc/bisonFile.y"
                                                          { Instruction::beq((yyvsp[-4].integerValue), (yyvsp[-2].integerValue), (yyvsp[0].stringValue)); free((yyvsp[0].stringValue));}
#line 1348 "misc/bison.cpp"
    break;

  case 27: /* instruction: BNE REGISTER COMMA REGISTER COMMA literal_or_symbol  */
#line 132 "misc/bisonFile.y"
                                                          { Instruction::bne((yyvsp[-4].integerValue), (yyvsp[-2].integerValue), (yyvsp[0].stringValue)); free((yyvsp[0].stringValue));}
#line 1354 "misc/bison.cpp"
    break;

  case 28: /* instruction: BGT REGISTER COMMA REGISTER COMMA literal_or_symbol  */
#line 133 "misc/bisonFile.y"
                                                          { Instruction::bgt((yyvsp[-4].integerValue), (yyvsp[-2].integerValue), (yyvsp[0].stringValue)); free((yyvsp[0].stringValue));}
#line 1360 "misc/bison.cpp"
    break;

  case 29: /* instruction: PUSH REGISTER  */
#line 134 "misc/bisonFile.y"
                   { Instruction::push((yyvsp[0].integerValue)); }
#line 1366 "misc/bison.cpp"
    break;

  case 30: /* instruction: POP REGISTER  */
#line 135 "misc/bisonFile.y"
                  { Instruction::pop((yyvsp[0].integerValue)); }
#line 1372 "misc/bison.cpp"
    break;

  case 31: /* instruction: XCHG REGISTER COMMA REGISTER  */
#line 136 "misc/bisonFile.y"
                                   { Instruction::xchg((yyvsp[-2].integerValue), (yyvsp[0].integerValue));}
#line 1378 "misc/bison.cpp"
    break;

  case 32: /* instruction: ADD REGISTER COMMA REGISTER  */
#line 137 "misc/bisonFile.y"
                                  {  Instruction::add((yyvsp[0].integerValue), (yyvsp[-2].integerValue)); }
#line 1384 "misc/bison.cpp"
    break;

  case 33: /* instruction: SUB REGISTER COMMA REGISTER  */
#line 138 "misc/bisonFile.y"
                                  {  Instruction::sub((yyvsp[0].integerValue), (yyvsp[-2].integerValue));}
#line 1390 "misc/bison.cpp"
    break;

  case 34: /* instruction: MUL REGISTER COMMA REGISTER  */
#line 139 "misc/bisonFile.y"
                                  {  Instruction::mul((yyvsp[0].integerValue), (yyvsp[-2].integerValue));}
#line 1396 "misc/bison.cpp"
    break;

  case 35: /* instruction: DIV REGISTER COMMA REGISTER  */
#line 140 "misc/bisonFile.y"
                                  { Instruction::div((yyvsp[0].integerValue), (yyvsp[-2].integerValue));}
#line 1402 "misc/bison.cpp"
    break;

  case 36: /* instruction: NOT REGISTER  */
#line 141 "misc/bisonFile.y"
                  {  Instruction::_not((yyvsp[0].integerValue)); }
#line 1408 "misc/bison.cpp"
    break;

  case 37: /* instruction: AND REGISTER COMMA REGISTER  */
#line 142 "misc/bisonFile.y"
                                  {  Instruction::_and((yyvsp[0].integerValue), (yyvsp[-2].integerValue));}
#line 1414 "misc/bison.cpp"
    break;

  case 38: /* instruction: OR REGISTER COMMA REGISTER  */
#line 143 "misc/bisonFile.y"
                                 { Instruction::_or((yyvsp[0].integerValue), (yyvsp[-2].integerValue));}
#line 1420 "misc/bison.cpp"
    break;

  case 39: /* instruction: XOR REGISTER COMMA REGISTER  */
#line 144 "misc/bisonFile.y"
                                  { Instruction::_xor((yyvsp[0].integerValue), (yyvsp[-2].integerValue));}
#line 1426 "misc/bison.cpp"
    break;

  case 40: /* instruction: SHL REGISTER COMMA REGISTER  */
#line 145 "misc/bisonFile.y"
                                  { Instruction::shl((yyvsp[0].integerValue), (yyvsp[-2].integerValue));}
#line 1432 "misc/bison.cpp"
    break;

  case 41: /* instruction: SHR REGISTER COMMA REGISTER  */
#line 146 "misc/bisonFile.y"
                                  { Instruction::shr((yyvsp[0].integerValue), (yyvsp[-2].integerValue));}
#line 1438 "misc/bison.cpp"
    break;

  case 42: /* instruction: CSRRD csr COMMA REGISTER  */
#line 147 "misc/bisonFile.y"
                               {  Instruction::csrrd((yyvsp[-2].integerValue), (yyvsp[0].integerValue)); }
#line 1444 "misc/bison.cpp"
    break;

  case 43: /* instruction: CSRWR REGISTER COMMA csr  */
#line 148 "misc/bisonFile.y"
                               {Instruction::csrrw((yyvsp[-2].integerValue), (yyvsp[0].integerValue)); }
#line 1450 "misc/bison.cpp"
    break;

  case 44: /* instruction: LD DOLARINTEGER COMMA REGISTER  */
#line 149 "misc/bisonFile.y"
                                     { Instruction::load_imm_literal((yyvsp[-2].integerValue), (yyvsp[0].integerValue));}
#line 1456 "misc/bison.cpp"
    break;

  case 45: /* instruction: LD DOLARIDENT COMMA REGISTER  */
#line 150 "misc/bisonFile.y"
                                   { Instruction::load_imm_symbol((yyvsp[-2].stringValue), (yyvsp[0].integerValue)); free((yyvsp[-2].stringValue));}
#line 1462 "misc/bison.cpp"
    break;

  case 46: /* instruction: LD INTEGER COMMA REGISTER  */
#line 151 "misc/bisonFile.y"
                                {  Instruction::load_literal((yyvsp[-2].integerValue), (yyvsp[0].integerValue));}
#line 1468 "misc/bison.cpp"
    break;

  case 47: /* instruction: LD IDENT COMMA REGISTER  */
#line 152 "misc/bisonFile.y"
                              { Instruction::load_symbol((yyvsp[-2].stringValue), (yyvsp[0].integerValue)); free((yyvsp[-2].stringValue));}
#line 1474 "misc/bison.cpp"
    break;

  case 48: /* instruction: LD REGISTER COMMA REGISTER  */
#line 153 "misc/bisonFile.y"
                                 {  Instruction::load_regdir((yyvsp[-2].integerValue), (yyvsp[0].integerValue));}
#line 1480 "misc/bison.cpp"
    break;

  case 49: /* instruction: LD LEFT_BRACKET REGISTER RIGHT_BRACKET COMMA REGISTER  */
#line 154 "misc/bisonFile.y"
                                                            {  Instruction::load_reg_ind((yyvsp[-3].integerValue), (yyvsp[0].integerValue));}
#line 1486 "misc/bison.cpp"
    break;

  case 50: /* instruction: LD LEFT_BRACKET REGISTER PLUS INTEGER RIGHT_BRACKET COMMA REGISTER  */
#line 155 "misc/bisonFile.y"
                                                                         {  Instruction::load_reg_ind_offset((yyvsp[-3].integerValue), (yyvsp[-5].integerValue), (yyvsp[0].integerValue));}
#line 1492 "misc/bison.cpp"
    break;

  case 51: /* instruction: ST REGISTER COMMA DOLARINTEGER  */
#line 156 "misc/bisonFile.y"
                                     {printf("Parsing err: Tried st to literal "); exit(1); }
#line 1498 "misc/bison.cpp"
    break;

  case 52: /* instruction: ST REGISTER COMMA DOLARIDENT  */
#line 157 "misc/bisonFile.y"
                                   {printf("Parsing err: Tried immediate adressing with st"); free((yyvsp[0].stringValue)); exit(1); }
#line 1504 "misc/bison.cpp"
    break;

  case 53: /* instruction: ST REGISTER COMMA INTEGER  */
#line 158 "misc/bisonFile.y"
                                { Instruction::store_literal((yyvsp[-2].integerValue), (yyvsp[0].integerValue));}
#line 1510 "misc/bison.cpp"
    break;

  case 54: /* instruction: ST REGISTER COMMA IDENT  */
#line 159 "misc/bisonFile.y"
                              { Instruction::store_symbol((yyvsp[-2].integerValue), (yyvsp[0].stringValue)); free((yyvsp[0].stringValue));}
#line 1516 "misc/bison.cpp"
    break;

  case 55: /* instruction: ST REGISTER COMMA REGISTER  */
#line 160 "misc/bisonFile.y"
                                 { Instruction::load_regdir((yyvsp[-2].integerValue), (yyvsp[0].integerValue));}
#line 1522 "misc/bison.cpp"
    break;

  case 56: /* instruction: ST REGISTER COMMA LEFT_BRACKET REGISTER RIGHT_BRACKET  */
#line 161 "misc/bisonFile.y"
                                                            {Instruction::store_regind((yyvsp[-4].integerValue), (yyvsp[-1].integerValue));}
#line 1528 "misc/bison.cpp"
    break;

  case 57: /* instruction: ST REGISTER COMMA LEFT_BRACKET REGISTER PLUS INTEGER RIGHT_BRACKET  */
#line 162 "misc/bisonFile.y"
                                                                         {Instruction::store_regind_offs((yyvsp[-1].integerValue), (yyvsp[-6].integerValue), (yyvsp[-3].integerValue)); }
#line 1534 "misc/bison.cpp"
    break;

  case 58: /* csr: STATUS  */
#line 167 "misc/bisonFile.y"
           { (yyval.integerValue)=0;}
#line 1540 "misc/bison.cpp"
    break;

  case 59: /* csr: HANDLER  */
#line 168 "misc/bisonFile.y"
              { (yyval.integerValue)=1;}
#line 1546 "misc/bison.cpp"
    break;

  case 60: /* csr: CAUSE  */
#line 169 "misc/bisonFile.y"
            { (yyval.integerValue)=2;}
#line 1552 "misc/bison.cpp"
    break;


#line 1556 "misc/bison.cpp"

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

#line 172 "misc/bisonFile.y"


void yyerror(const char *s) {
  printf("Parsing error: %s\n", s);
  exit(1);
}
