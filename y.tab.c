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
#line 1 "string-compiler.y"

/* Include standard C libraries needed for input/output, string manipulation, and character functions. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>    // For character functions like toupper, tolower, and isspace

/* Define a maximum number of variables that can be stored. */
#define MAX_VARS 100

/* Declare the external variable for line numbers, used in error messages. */
extern int yylineno;

/* Define a structure to represent a variable, which has a name and a value. */
struct var {
    char* name;   /* Variable name */
    char* value;  /* Variable value */
};

/* Declare an array to act as a simple symbol table for storing variables. */
struct var vars[MAX_VARS];
int var_count = 0;  /* Keep track of the number of variables stored */

/* Function prototypes for managing variables and handling errors. */
char* get_var_value(char* name);
void set_var_value(char* name, char* value);

/* Function prototypes for lexer and error reporting. */
int yylex(void);
void yyerror(const char *s);

#line 103 "y.tab.c"

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
    ID = 258,                      /* ID  */
    STRING_LITERAL = 259,          /* STRING_LITERAL  */
    NUMBER = 260,                  /* NUMBER  */
    LENGTH = 261,                  /* LENGTH  */
    REVERSE = 262,                 /* REVERSE  */
    SUBSTRING = 263,               /* SUBSTRING  */
    PALINDROME = 264,              /* PALINDROME  */
    TOUPPER = 265,                 /* TOUPPER  */
    TOLOWER = 266,                 /* TOLOWER  */
    PADLEFT = 267,                 /* PADLEFT  */
    PADRIGHT = 268,                /* PADRIGHT  */
    TRIM = 269,                    /* TRIM  */
    FIND = 270                     /* FIND  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define STRING_LITERAL 259
#define NUMBER 260
#define LENGTH 261
#define REVERSE 262
#define SUBSTRING 263
#define PALINDROME 264
#define TOUPPER 265
#define TOLOWER 266
#define PADLEFT 267
#define PADRIGHT 268
#define TRIM 269
#define FIND 270

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "string-compiler.y"

    char* sval;  /* For string values */
    int ival;    /* For integer values */

#line 191 "y.tab.c"

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
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_STRING_LITERAL = 4,             /* STRING_LITERAL  */
  YYSYMBOL_NUMBER = 5,                     /* NUMBER  */
  YYSYMBOL_LENGTH = 6,                     /* LENGTH  */
  YYSYMBOL_REVERSE = 7,                    /* REVERSE  */
  YYSYMBOL_SUBSTRING = 8,                  /* SUBSTRING  */
  YYSYMBOL_PALINDROME = 9,                 /* PALINDROME  */
  YYSYMBOL_TOUPPER = 10,                   /* TOUPPER  */
  YYSYMBOL_TOLOWER = 11,                   /* TOLOWER  */
  YYSYMBOL_PADLEFT = 12,                   /* PADLEFT  */
  YYSYMBOL_PADRIGHT = 13,                  /* PADRIGHT  */
  YYSYMBOL_TRIM = 14,                      /* TRIM  */
  YYSYMBOL_FIND = 15,                      /* FIND  */
  YYSYMBOL_16_ = 16,                       /* ';'  */
  YYSYMBOL_17_ = 17,                       /* '='  */
  YYSYMBOL_18_ = 18,                       /* '+'  */
  YYSYMBOL_19_ = 19,                       /* '('  */
  YYSYMBOL_20_ = 20,                       /* ')'  */
  YYSYMBOL_21_ = 21,                       /* ','  */
  YYSYMBOL_YYACCEPT = 22,                  /* $accept  */
  YYSYMBOL_program = 23,                   /* program  */
  YYSYMBOL_statement = 24,                 /* statement  */
  YYSYMBOL_assignment = 25,                /* assignment  */
  YYSYMBOL_expr = 26,                      /* expr  */
  YYSYMBOL_term = 27,                      /* term  */
  YYSYMBOL_function_call = 28              /* function_call  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   75

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  22
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  20
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  69

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   270


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
      19,    20,     2,    18,    21,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    16,
       2,    17,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    52,    52,    53,    58,    63,    74,    84,    89,    98,
     109,   114,   121,   132,   149,   165,   175,   185,   214,   243,
     260
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "STRING_LITERAL",
  "NUMBER", "LENGTH", "REVERSE", "SUBSTRING", "PALINDROME", "TOUPPER",
  "TOLOWER", "PADLEFT", "PADRIGHT", "TRIM", "FIND", "';'", "'='", "'+'",
  "'('", "')'", "','", "$accept", "program", "statement", "assignment",
  "expr", "term", "function_call", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-24)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -24,    23,   -24,    -5,   -24,     9,     7,   -24,   -24,   -24,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      10,   -24,   -24,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,    18,    21,     6,    22,    25,    26,
      11,    12,    29,    16,   -24,   -24,   -24,    56,   -24,   -24,
     -24,    57,    58,   -24,     7,    14,    43,    44,    30,    61,
      63,    64,   -24,    49,    50,    51,   -24,   -24,   -24
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     1,     0,     2,     0,     0,     4,     9,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     7,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,    11,    12,     0,    14,    15,
      16,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,    20,     0,     0,     0,    13,    17,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -24,   -24,   -24,   -24,   -23,    42,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     4,     5,    20,    21,    22
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       8,     9,     6,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     2,    33,     7,     3,    47,    33,    33,
      33,    58,    51,    52,    33,    59,    33,    54,    45,    33,
      33,    46,    48,    33,    33,    49,    50,    33,    33,    53,
      62,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    55,    56,    57,    60,    61,    63,    64,    65,    66,
      67,    68,     0,     0,     0,    44
};

static const yytype_int8 yycheck[] =
{
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       3,     4,    17,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,    18,    16,     3,    21,    18,    18,
      18,    54,    21,    21,    18,    21,    18,    21,    20,    18,
      18,    20,    20,    18,    18,    20,    20,    18,    18,    20,
      20,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,     5,     5,     5,    21,    21,     5,     4,     4,    20,
      20,    20,    -1,    -1,    -1,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,     0,     3,    24,    25,    17,    16,     3,     4,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      26,    27,    28,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    18,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    27,    20,    20,    21,    20,    20,
      20,    21,    21,    20,    21,     5,     5,     5,    26,    21,
      21,    21,    20,     5,     4,     4,    20,    20,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    22,    23,    23,    24,    25,    26,    26,    27,    27,
      27,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     3,     3,     1,     1,     1,
       1,     4,     4,     8,     4,     4,     4,     8,     8,     4,
       6
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
  case 5: /* assignment: ID '=' expr  */
#line 63 "string-compiler.y"
                   {
        /* Store the variable and its value in the symbol table. */
        set_var_value((yyvsp[-2].sval), (yyvsp[0].sval));
        /* Free the memory allocated for the variable name and value. */
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 1233 "y.tab.c"
    break;

  case 6: /* expr: expr '+' term  */
#line 74 "string-compiler.y"
                     {
        /* Concatenate the two strings. */
        char* tmp = malloc(strlen((yyvsp[-2].sval)) + strlen((yyvsp[0].sval)) + 1);
        strcpy(tmp, (yyvsp[-2].sval));
        strcat(tmp, (yyvsp[0].sval));
        (yyval.sval) = tmp;  /* Set the result as the value of the expression */
        /* Free the memory allocated for the operands. */
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 1248 "y.tab.c"
    break;

  case 7: /* expr: term  */
#line 84 "string-compiler.y"
                    { (yyval.sval) = (yyvsp[0].sval); }
#line 1254 "y.tab.c"
    break;

  case 8: /* term: STRING_LITERAL  */
#line 89 "string-compiler.y"
                       {
        /* Remove the surrounding quotes from the string literal. */
        char* str = strdup((yyvsp[0].sval));
        str[strlen(str)-1] = '\0';       /* Remove the ending quote */
        (yyval.sval) = strdup(&str[1]);            /* Remove the starting quote */
        /* Free the temporary strings. */
        free(str);
        free((yyvsp[0].sval));
    }
#line 1268 "y.tab.c"
    break;

  case 9: /* term: ID  */
#line 98 "string-compiler.y"
                       {
        /* Retrieve the value of the variable from the symbol table. */
        char* val = get_var_value((yyvsp[0].sval));
        if (val) {
            (yyval.sval) = strdup(val);  /* Set the variable's value as the term's value */
        } else {
            yyerror("Undefined variable");  /* Report an error if the variable is not found */
            (yyval.sval) = strdup("");  /* Set an empty string to prevent crashes */
        }
        free((yyvsp[0].sval));  /* Free the memory allocated for the variable name */
    }
#line 1284 "y.tab.c"
    break;

  case 10: /* term: function_call  */
#line 109 "string-compiler.y"
                       { (yyval.sval) = (yyvsp[0].sval); }
#line 1290 "y.tab.c"
    break;

  case 11: /* function_call: LENGTH '(' expr ')'  */
#line 114 "string-compiler.y"
                           {
        /* Calculate the length of the string and convert it to a string. */
        char buffer[20];
        sprintf(buffer, "%d", (int)strlen((yyvsp[-1].sval)));
        (yyval.sval) = strdup(buffer);  /* Set the length as the function's result */
        free((yyvsp[-1].sval));             /* Free the memory allocated for the argument */
    }
#line 1302 "y.tab.c"
    break;

  case 12: /* function_call: REVERSE '(' expr ')'  */
#line 121 "string-compiler.y"
                            {
        /* Reverse the input string. */
        int len = strlen((yyvsp[-1].sval));
        char* reversed = malloc(len +1);
        for(int i=0; i<len; i++){
            reversed[i] = (yyvsp[-1].sval)[len - i -1];  /* Copy characters from the end to the start */
        }
        reversed[len] = '\0';  /* Null-terminate the reversed string */
        (yyval.sval) = reversed;         /* Set the reversed string as the function's result */
        free((yyvsp[-1].sval));              /* Free the memory allocated for the argument */
    }
#line 1318 "y.tab.c"
    break;

  case 13: /* function_call: SUBSTRING '(' expr ',' NUMBER ',' NUMBER ')'  */
#line 132 "string-compiler.y"
                                                   {
        /* Extract a substring from the input string between 'start' and 'end' indices. */
        int start = (yyvsp[-3].ival);  /* Starting index */
        int end = (yyvsp[-1].ival);    /* Ending index */
        int len_str = strlen((yyvsp[-5].sval));
        int len = end - start;
        if(len<0 || start<0 || end>len_str){
            yyerror("Invalid substring indices");  /* Report an error if indices are invalid */
            (yyval.sval) = strdup("");  /* Set an empty string to prevent crashes */
        } else {
            char* substr = malloc(len +1);
            strncpy(substr, (yyvsp[-5].sval) + start, len);  /* Copy the substring */
            substr[len] = '\0';                /* Null-terminate the substring */
            (yyval.sval) = substr;  /* Set the substring as the function's result */
        }
        free((yyvsp[-5].sval));  /* Free the memory allocated for the input string */
    }
#line 1340 "y.tab.c"
    break;

  case 14: /* function_call: PALINDROME '(' expr ')'  */
#line 149 "string-compiler.y"
                              {
        /* Check if the input string is a palindrome. */
        int len = strlen((yyvsp[-1].sval));
        int is_palindrome = 1;  /* Flag to indicate if it's a palindrome */
        for(int i=0; i<len/2; i++){
            if((yyvsp[-1].sval)[i] != (yyvsp[-1].sval)[len - i -1]){
                is_palindrome = 0;  /* Set flag to 0 if characters don't match */
                break;
            }
        }
        if(is_palindrome)
            (yyval.sval) = strdup("true");   /* Set result to "true" */
        else
            (yyval.sval) = strdup("false");  /* Set result to "false" */
        free((yyvsp[-1].sval));  /* Free the memory allocated for the input string */
    }
#line 1361 "y.tab.c"
    break;

  case 15: /* function_call: TOUPPER '(' expr ')'  */
#line 165 "string-compiler.y"
                           {
        /* Convert the input string to uppercase. */
        int len = strlen((yyvsp[-1].sval));
        char* upper_str = strdup((yyvsp[-1].sval));
        for(int i = 0; i < len; i++) {
            upper_str[i] = toupper((unsigned char)upper_str[i]);
        }
        (yyval.sval) = upper_str;  /* Set the uppercase string as the function's result */
        free((yyvsp[-1].sval));        /* Free the memory allocated for the input string */
    }
#line 1376 "y.tab.c"
    break;

  case 16: /* function_call: TOLOWER '(' expr ')'  */
#line 175 "string-compiler.y"
                           {
        /* Convert the input string to lowercase. */
        int len = strlen((yyvsp[-1].sval));
        char* lower_str = strdup((yyvsp[-1].sval));
        for(int i = 0; i < len; i++) {
            lower_str[i] = tolower((unsigned char)lower_str[i]);
        }
        (yyval.sval) = lower_str;  /* Set the lowercase string as the function's result */
        free((yyvsp[-1].sval));        /* Free the memory allocated for the input string */
    }
#line 1391 "y.tab.c"
    break;

  case 17: /* function_call: PADLEFT '(' expr ',' NUMBER ',' STRING_LITERAL ')'  */
#line 185 "string-compiler.y"
                                                         {
        /* Pad the input string on the left with a character to reach the total length. */
        int total_length = (yyvsp[-3].ival);  /* Desired total length */
        /* Process the pad character string literal */
        char* pad_str = strdup((yyvsp[-1].sval));
        pad_str[strlen(pad_str)-1] = '\0';  /* Remove ending quote */
        char* pad_content = &pad_str[1];    /* Remove starting quote */
        char pad_char;
        if (strlen(pad_content) >= 1) {
            pad_char = pad_content[0];     /* Use the first character */
        } else {
            yyerror("Pad character must not be empty");
            pad_char = ' ';  /* Default to space */
        }
        int str_len = strlen((yyvsp[-5].sval));
        if(total_length <= str_len) {
            (yyval.sval) = strdup((yyvsp[-5].sval));  /* Return the original string */
        } else {
            int pad_len = total_length - str_len;
            char* padded_str = malloc(total_length + 1);
            memset(padded_str, pad_char, pad_len);       /* Fill with pad_char */
            strcpy(padded_str + pad_len, (yyvsp[-5].sval));            /* Copy the original string */
            padded_str[total_length] = '\0';             /* Null-terminate */
            (yyval.sval) = padded_str;
        }
        free(pad_str);
        free((yyvsp[-5].sval));
        free((yyvsp[-1].sval));
    }
#line 1425 "y.tab.c"
    break;

  case 18: /* function_call: PADRIGHT '(' expr ',' NUMBER ',' STRING_LITERAL ')'  */
#line 214 "string-compiler.y"
                                                          {
        /* Pad the input string on the right with a character to reach the total length. */
        int total_length = (yyvsp[-3].ival);  /* Desired total length */
        /* Process the pad character string literal */
        char* pad_str = strdup((yyvsp[-1].sval));
        pad_str[strlen(pad_str)-1] = '\0';  /* Remove ending quote */
        char* pad_content = &pad_str[1];    /* Remove starting quote */
        char pad_char;
        if (strlen(pad_content) >= 1) {
            pad_char = pad_content[0];     /* Use the first character */
        } else {
            yyerror("Pad character must not be empty");
            pad_char = ' ';  /* Default to space */
        }
        int str_len = strlen((yyvsp[-5].sval));
        if(total_length <= str_len) {
            (yyval.sval) = strdup((yyvsp[-5].sval));  /* Return the original string */
        } else {
            int pad_len = total_length - str_len;
            char* padded_str = malloc(total_length + 1);
            strcpy(padded_str, (yyvsp[-5].sval));                        /* Copy the original string */
            memset(padded_str + str_len, pad_char, pad_len); /* Fill with pad_char */
            padded_str[total_length] = '\0';               /* Null-terminate */
            (yyval.sval) = padded_str;
        }
        free(pad_str);
        free((yyvsp[-5].sval));
        free((yyvsp[-1].sval));
    }
#line 1459 "y.tab.c"
    break;

  case 19: /* function_call: TRIM '(' expr ')'  */
#line 243 "string-compiler.y"
                        {
        /* Trim leading and trailing whitespace from the input string. */
        char* trimmed_str = strdup((yyvsp[-1].sval));
        char* start = trimmed_str;
        char* end = trimmed_str + strlen(trimmed_str) - 1;

        /* Trim leading whitespace */
        while(isspace((unsigned char)*start)) start++;

        /* Trim trailing whitespace */
        while(end >= start && isspace((unsigned char)*end)) end--;
        *(end + 1) = '\0';  /* Null-terminate after the last non-space character */

        (yyval.sval) = strdup(start);  /* Set the trimmed string as the function's result */
        free(trimmed_str);   /* Free the temporary string */
        free((yyvsp[-1].sval));            /* Free the memory allocated for the input string */
    }
#line 1481 "y.tab.c"
    break;

  case 20: /* function_call: FIND '(' expr ',' expr ')'  */
#line 260 "string-compiler.y"
                                 {
        /* Find the index of the substring within the input string. */
        char* haystack = (yyvsp[-3].sval);  /* The string to search in */
        char* needle = (yyvsp[-1].sval);    /* The substring to find */
        char* pos = strstr(haystack, needle);  /* Find the substring */
        if(pos) {
            int index = pos - haystack;  /* Calculate the index */
            char buffer[20];
            sprintf(buffer, "%d", index);
            (yyval.sval) = strdup(buffer);  /* Set the index as the function's result */
        } else {
            (yyval.sval) = strdup("-1");  /* Return -1 if the substring is not found */
        }
        free((yyvsp[-3].sval));  /* Free the memory allocated for the haystack string */
        free((yyvsp[-1].sval));  /* Free the memory allocated for the needle string */
    }
#line 1502 "y.tab.c"
    break;


#line 1506 "y.tab.c"

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

#line 279 "string-compiler.y"


/* Function to retrieve the value of a variable from the symbol table. */
char* get_var_value(char* name) {
    for(int i=0; i<var_count; i++){
        if(strcmp(vars[i].name, name) == 0){
            return vars[i].value;  /* Return the value if the name matches */
        }
    }
    return NULL;  /* Return NULL if the variable is not found */
}

/* Function to set the value of a variable in the symbol table. */
void set_var_value(char* name, char* value) {
    for(int i=0; i<var_count; i++){
        if(strcmp(vars[i].name, name) == 0){
            /* Update the value if the variable already exists. */
            free(vars[i].value);  /* Free the old value */
            vars[i].value = strdup(value);  /* Store the new value */
            return;
        }
    }
    if(var_count < MAX_VARS){
        /* Add a new variable if there is space in the symbol table. */
        vars[var_count].name = strdup(name);
        vars[var_count].value = strdup(value);
        var_count++;
    } else {
        yyerror("Variable limit reached");  /* Report an error if the table is full */
    }
}

/* Function to report parsing errors with line numbers. */
void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}

/* The main function initializes the line number and starts the parsing process. */
int main(void){
    yylineno = 1;  /* Initialize the line number */
    yyparse();     /* Start parsing the input */
    /* After parsing, print all variables and their values. */
    printf("Variables:\n");
    for(int i=0; i<var_count; i++){
        printf("%s = %s\n", vars[i].name, vars[i].value);
        /* Free the memory allocated for variable names and values. */
        free(vars[i].name);
        free(vars[i].value);
    }
    return 0;  /* Exit the program */
}
