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
#line 7 "parse.y"

int yylex();
void yyerror(char *s);

#line 76 "parse.tab.c"

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

#include "parse.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENT = 3,                      /* IDENT  */
  YYSYMBOL_CHARLIT = 4,                    /* CHARLIT  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_NUMBER = 6,                     /* NUMBER  */
  YYSYMBOL_INDSEL = 7,                     /* INDSEL  */
  YYSYMBOL_LOGAND = 8,                     /* LOGAND  */
  YYSYMBOL_LOGOR = 9,                      /* LOGOR  */
  YYSYMBOL_SHL = 10,                       /* SHL  */
  YYSYMBOL_SHR = 11,                       /* SHR  */
  YYSYMBOL_LTEQ = 12,                      /* LTEQ  */
  YYSYMBOL_GTEQ = 13,                      /* GTEQ  */
  YYSYMBOL_EQEQ = 14,                      /* EQEQ  */
  YYSYMBOL_NOTEQ = 15,                     /* NOTEQ  */
  YYSYMBOL_PLUSPLUS = 16,                  /* PLUSPLUS  */
  YYSYMBOL_MINUSMINUS = 17,                /* MINUSMINUS  */
  YYSYMBOL_TIMESEQ = 18,                   /* TIMESEQ  */
  YYSYMBOL_DIVEQ = 19,                     /* DIVEQ  */
  YYSYMBOL_MODEQ = 20,                     /* MODEQ  */
  YYSYMBOL_PLUSEQ = 21,                    /* PLUSEQ  */
  YYSYMBOL_MINUSEQ = 22,                   /* MINUSEQ  */
  YYSYMBOL_SHLEQ = 23,                     /* SHLEQ  */
  YYSYMBOL_SHREQ = 24,                     /* SHREQ  */
  YYSYMBOL_ANDEQ = 25,                     /* ANDEQ  */
  YYSYMBOL_OREQ = 26,                      /* OREQ  */
  YYSYMBOL_XOREQ = 27,                     /* XOREQ  */
  YYSYMBOL_SIZEOF = 28,                    /* SIZEOF  */
  YYSYMBOL_ELLIPSIS = 29,                  /* ELLIPSIS  */
  YYSYMBOL_AUTO = 30,                      /* AUTO  */
  YYSYMBOL_BREAK = 31,                     /* BREAK  */
  YYSYMBOL_CASE = 32,                      /* CASE  */
  YYSYMBOL_CHAR = 33,                      /* CHAR  */
  YYSYMBOL_CONST = 34,                     /* CONST  */
  YYSYMBOL_CONTINUE = 35,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 36,                   /* DEFAULT  */
  YYSYMBOL_DO = 37,                        /* DO  */
  YYSYMBOL_DOUBLE = 38,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 39,                      /* ELSE  */
  YYSYMBOL_ENUM = 40,                      /* ENUM  */
  YYSYMBOL_EXTERN = 41,                    /* EXTERN  */
  YYSYMBOL_FLOAT = 42,                     /* FLOAT  */
  YYSYMBOL_FOR = 43,                       /* FOR  */
  YYSYMBOL_GOTO = 44,                      /* GOTO  */
  YYSYMBOL_IF = 45,                        /* IF  */
  YYSYMBOL_INLINE = 46,                    /* INLINE  */
  YYSYMBOL_INT = 47,                       /* INT  */
  YYSYMBOL_LONG = 48,                      /* LONG  */
  YYSYMBOL_REGISTER = 49,                  /* REGISTER  */
  YYSYMBOL_RESTRICT = 50,                  /* RESTRICT  */
  YYSYMBOL_RETURN = 51,                    /* RETURN  */
  YYSYMBOL_SHORT = 52,                     /* SHORT  */
  YYSYMBOL_SIGNED = 53,                    /* SIGNED  */
  YYSYMBOL_STATIC = 54,                    /* STATIC  */
  YYSYMBOL_STRUCT = 55,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 56,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 57,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 58,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 59,                  /* UNSIGNED  */
  YYSYMBOL_VOID = 60,                      /* VOID  */
  YYSYMBOL_VOLATILE = 61,                  /* VOLATILE  */
  YYSYMBOL_WHILE = 62,                     /* WHILE  */
  YYSYMBOL__BOOL = 63,                     /* _BOOL  */
  YYSYMBOL__COMPLEX = 64,                  /* _COMPLEX  */
  YYSYMBOL__IMAGINARY = 65,                /* _IMAGINARY  */
  YYSYMBOL_TOKEOF = 66,                    /* TOKEOF  */
  YYSYMBOL_67_ = 67,                       /* ','  */
  YYSYMBOL_68_ = 68,                       /* '='  */
  YYSYMBOL_69_ = 69,                       /* '?'  */
  YYSYMBOL_70_ = 70,                       /* ":"  */
  YYSYMBOL_71_ = 71,                       /* '|'  */
  YYSYMBOL_72_ = 72,                       /* '^'  */
  YYSYMBOL_73_ = 73,                       /* '&'  */
  YYSYMBOL_74_ = 74,                       /* '<'  */
  YYSYMBOL_75_ = 75,                       /* '>'  */
  YYSYMBOL_76_ = 76,                       /* '+'  */
  YYSYMBOL_77_ = 77,                       /* '-'  */
  YYSYMBOL_78_ = 78,                       /* '*'  */
  YYSYMBOL_79_ = 79,                       /* '/'  */
  YYSYMBOL_80_ = 80,                       /* '%'  */
  YYSYMBOL_81_ = 81,                       /* '!'  */
  YYSYMBOL_82_ = 82,                       /* '~'  */
  YYSYMBOL_83_ = 83,                       /* '('  */
  YYSYMBOL_84_ = 84,                       /* ')'  */
  YYSYMBOL_85_ = 85,                       /* '['  */
  YYSYMBOL_86_ = 86,                       /* ']'  */
  YYSYMBOL_87_ = 87,                       /* ';'  */
  YYSYMBOL_88_ = 88,                       /* '.'  */
  YYSYMBOL_89___ = 89,                     /* '_'  */
  YYSYMBOL_90_ = 90,                       /* ':'  */
  YYSYMBOL_91_ = 91,                       /* '{'  */
  YYSYMBOL_92_ = 92,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 93,                  /* $accept  */
  YYSYMBOL_start = 94,                     /* start  */
  YYSYMBOL_statement = 95,                 /* statement  */
  YYSYMBOL_expression = 96,                /* expression  */
  YYSYMBOL_primary_expression = 97,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 98,        /* postfix_expression  */
  YYSYMBOL_function_call = 99,             /* function_call  */
  YYSYMBOL_argument_expression_list = 100, /* argument_expression_list  */
  YYSYMBOL_unary_operator = 101,           /* unary_operator  */
  YYSYMBOL_cast_expression = 102,          /* cast_expression  */
  YYSYMBOL_unary_expression = 103,         /* unary_expression  */
  YYSYMBOL_multiplicative_expression = 104, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 105,      /* additive_expression  */
  YYSYMBOL_shift_expression = 106,         /* shift_expression  */
  YYSYMBOL_relational_expression = 107,    /* relational_expression  */
  YYSYMBOL_equality_expression = 108,      /* equality_expression  */
  YYSYMBOL_AND_expression = 109,           /* AND_expression  */
  YYSYMBOL_exclusive_OR_expression = 110,  /* exclusive_OR_expression  */
  YYSYMBOL_inclusive_OR_expression = 111,  /* inclusive_OR_expression  */
  YYSYMBOL_logical_AND_expression = 112,   /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 113,    /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 114,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 115,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 116,      /* assignment_operator  */
  YYSYMBOL_type_specifier = 117,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 118, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 119,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 120,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 121,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 122, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 123,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 124,        /* struct_declarator  */
  YYSYMBOL_type_qualifier = 125,           /* type_qualifier  */
  YYSYMBOL_declarator = 126,               /* declarator  */
  YYSYMBOL_direct_declarator = 127,        /* direct_declarator  */
  YYSYMBOL_pointer = 128,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 129,      /* type_qualifier_list  */
  YYSYMBOL_type_name = 130,                /* type_name  */
  YYSYMBOL_abstract_declarator = 131,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 132 /* direct_abstract_declarator  */
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
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   578

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   322


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
       2,     2,     2,    81,     2,     2,     2,    80,    73,     2,
      83,    84,    78,    76,    67,    77,    88,    79,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    90,    87,
      74,    68,    75,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    85,     2,    86,    72,    89,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    91,    71,    92,    82,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    70
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    84,    84,    85,    88,    90,    91,    94,    96,    98,
     104,   106,   109,   110,   114,   115,   118,   123,   124,   129,
     130,   133,   137,   167,   168,   169,   170,   171,   172,   175,
     176,   179,   180,   184,   188,   189,   190,   193,   194,   195,
     196,   199,   200,   201,   204,   205,   206,   209,   210,   211,
     212,   213,   216,   217,   218,   221,   222,   225,   226,   229,
     230,   233,   234,   237,   238,   241,   242,   245,   246,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   315,   316,   317,
     320,   321,   324,   325,   328,   332,   333,   334,   335,   338,
     339,   342,   345,   346,   347,   352,   353,   356,   357,   358,
     359,   360,   361,   362,   365,   368,   369,   370,   371,   374,
     375,   378,   379,   400,   401,   402,   405,   406,   408,   409,
     410,   411,   414
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENT", "CHARLIT",
  "STRING", "NUMBER", "INDSEL", "LOGAND", "LOGOR", "SHL", "SHR", "LTEQ",
  "GTEQ", "EQEQ", "NOTEQ", "PLUSPLUS", "MINUSMINUS", "TIMESEQ", "DIVEQ",
  "MODEQ", "PLUSEQ", "MINUSEQ", "SHLEQ", "SHREQ", "ANDEQ", "OREQ", "XOREQ",
  "SIZEOF", "ELLIPSIS", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO", "IF", "INLINE", "INT", "LONG", "REGISTER", "RESTRICT",
  "RETURN", "SHORT", "SIGNED", "STATIC", "STRUCT", "SWITCH", "TYPEDEF",
  "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE", "_BOOL", "_COMPLEX",
  "_IMAGINARY", "TOKEOF", "','", "'='", "'?'", "\":\"", "'|'", "'^'",
  "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'",
  "'('", "')'", "'['", "']'", "';'", "'.'", "'_'", "':'", "'{'", "'}'",
  "$accept", "start", "statement", "expression", "primary_expression",
  "postfix_expression", "function_call", "argument_expression_list",
  "unary_operator", "cast_expression", "unary_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "AND_expression",
  "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "type_specifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "type_qualifier", "declarator", "direct_declarator",
  "pointer", "type_qualifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-139)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     333,  -139,  -139,  -139,  -139,   373,   373,   391,  -139,  -139,
    -139,  -139,  -139,  -139,   171,    47,  -139,   -55,  -139,     6,
    -139,   333,  -139,   510,     5,   -47,    33,    44,   121,   -36,
     -14,    -6,    62,    19,  -139,  -139,   333,  -139,  -139,   171,
    -139,  -139,  -139,  -139,  -139,  -139,    74,  -139,    26,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,    23,   131,  -139,
       7,    56,   131,    54,  -139,  -139,   333,  -139,    83,  -139,
    -139,    76,   333,    98,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,    64,  -139,  -139,
      93,  -139,  -139,  -139,    55,   131,   -23,    48,   -17,   -52,
    -139,    14,  -139,   333,  -139,  -139,  -139,    43,  -139,   -46,
    -139,  -139,  -139,  -139,  -139,     5,     5,   -47,   -47,    33,
      33,    33,    33,    44,    44,   121,   -36,   -14,    -6,    62,
     -49,  -139,  -139,   131,   428,  -139,    68,  -139,  -139,   -23,
    -139,    72,    75,  -139,    14,    79,   417,  -139,   333,  -139,
    -139,   333,   463,  -139,  -139,   131,  -139,  -139,  -139,  -139,
    -139,    81,    86,  -139,  -139,  -139,    17,  -139,  -139,  -139,
      17,   -33,  -139,  -139,    30,    13,    96,    17,  -139,   101,
     211,    30,  -139,  -139,  -139,   -15,   107,   252,   292,  -139,
     333,   110,   111,   112,   115,  -139,  -139,  -139,  -139
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     9,    10,     8,     0,     0,     0,    23,    25,
      26,    24,    28,    27,     0,     0,     2,     0,    12,    31,
      14,     0,    37,    29,    41,    44,    47,    52,    55,    57,
      59,    61,    63,    65,    67,     5,     0,    32,    33,     0,
      35,    81,   112,    90,    89,    84,    85,   113,    82,    92,
     100,   101,    93,    80,   114,    94,    95,     0,   105,    96,
       0,   131,   107,     0,     1,     3,     0,     4,     0,    17,
      18,     0,     0,     0,    34,    29,    70,    71,    72,    73,
      74,    75,    76,    77,    79,    78,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    86,
      87,    83,    11,   106,    98,     0,   125,     0,     0,   133,
     132,   134,   108,     0,     6,    16,    20,     0,    21,     0,
      15,    68,    38,    39,    40,    42,    43,    45,    46,    50,
      51,    48,    49,    53,    54,    56,    58,    60,    62,    64,
       0,    36,    88,     0,     0,   102,     0,   129,   127,   126,
     141,     0,     0,   137,   135,     0,     0,    30,     0,    19,
      13,     0,     0,    97,   103,     0,   130,   128,   136,   139,
     142,    24,     0,    22,    66,    99,     0,   140,   138,   117,
       0,     0,   109,   111,   115,     0,     0,     0,   104,     0,
       0,   116,   118,   110,   124,     0,     0,     0,     0,   119,
       0,    24,     0,     0,     0,   123,   120,   121,   122
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,   167,     2,  -139,  -139,  -139,  -139,  -139,   -12,
       0,    51,    57,   145,    71,   102,   100,   103,   108,   106,
    -139,    49,   -63,  -139,  -139,  -139,  -139,    69,  -124,   -13,
    -139,    28,   -91,    46,    38,   -57,  -138,   198,   129,   119
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    15,    16,    57,    18,    19,    20,   127,    21,    22,
      75,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    87,    58,    59,    60,   154,   155,   156,
     191,   192,    62,   193,   194,   195,   159,    63,   120,   121
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      23,    61,    17,   124,   119,    37,    38,    40,   128,    74,
     114,    42,    66,    68,    23,    23,   189,    17,    66,    42,
     189,    66,    69,    70,   131,   157,    61,    47,   105,    91,
     174,   117,    67,   118,   197,    47,    23,   101,    54,    23,
     170,   171,    92,    93,    94,   113,    54,    64,   174,   122,
       1,     2,     3,     4,   198,   116,    95,    96,   102,   158,
     119,   162,   207,     5,     6,   103,    23,   208,   176,   163,
     104,    23,    23,   111,   129,     7,   132,   133,   134,     1,
       2,     3,     4,    88,    89,    90,   125,    23,   106,    71,
      66,    72,     5,     6,    73,   116,   190,   165,   115,   166,
     190,   130,   177,   182,     7,   183,    23,   112,   150,   157,
     168,   167,   108,   199,   157,   200,   176,   176,    97,    98,
       8,   109,   110,     9,    10,    11,   116,   169,    12,    13,
      14,   117,   160,   118,   116,    99,   100,   206,   123,   117,
     152,   118,   135,   136,   212,   213,   153,   214,   151,     8,
     137,   138,     9,    10,    11,   175,   178,    12,    13,    14,
     126,   179,   186,   180,    41,    42,    23,   187,    23,    43,
     143,   144,   188,    44,     1,     2,     3,     4,    45,    46,
     202,    47,    65,    48,    49,   204,    50,     5,     6,    51,
      52,    53,    54,   209,    55,    56,   215,   216,   217,     7,
      23,   218,   146,   145,    41,    42,   147,    23,    23,    43,
      23,   149,   148,    44,     1,     2,     3,     4,    45,    46,
     184,    47,   172,    48,    49,   203,    50,     5,     6,    51,
      52,    53,    54,   201,    55,    56,   196,   107,   164,     7,
     139,   140,   141,   142,     8,    42,   161,     9,    10,    11,
       0,     0,    12,    13,    14,     1,     2,     3,     4,     0,
       0,    47,     0,     0,     0,   205,     0,     0,     5,     6,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       7,     0,     0,     0,     8,     0,    42,     9,    10,    11,
       0,     0,    12,    13,    14,     1,     2,     3,     4,     0,
       0,     0,    47,     0,     0,     0,   210,     0,     5,     6,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       7,     0,     0,     0,     0,     8,    42,     0,     9,    10,
     211,     0,     0,    12,    13,    14,     1,     2,     3,     4,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     5,
       6,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     8,     0,     0,     9,    10,
      11,     0,     0,    12,    13,    14,     1,     2,     3,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     0,     0,     0,     1,     2,     3,     4,     0,     0,
       0,     7,     0,     0,     0,     0,     8,     5,     6,     9,
      10,    11,     0,     0,    12,    13,    14,     0,     0,     7,
       1,     2,     3,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     9,
      10,    11,     0,     0,    12,    13,    36,     0,     0,     0,
       0,    41,    42,     0,     8,     0,    43,     9,    10,    11,
      44,     0,    12,    13,    39,    45,    46,     0,    47,     0,
      48,    49,     0,    50,     0,     0,    51,    52,    53,    54,
       8,    55,    56,     9,    10,   181,    41,    42,    12,    13,
      14,    43,     0,     0,     0,    44,     0,     0,     0,     0,
      45,    46,     0,    47,     0,    48,    49,     0,    50,     0,
     173,    51,    52,    53,    54,     0,    55,    56,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   185,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86
};

static const yytype_int16 yycheck[] =
{
       0,    14,     0,    66,    61,     5,     6,     7,    71,    21,
       3,    34,    67,     7,    14,    15,     3,    15,    67,    34,
       3,    67,    16,    17,    87,   116,    39,    50,     9,    76,
     154,    83,    87,    85,    67,    50,    36,    73,    61,    39,
      86,    90,    89,    10,    11,    58,    61,     0,   172,    62,
       3,     4,     5,     6,    87,    78,    12,    13,    72,   116,
     117,    78,   200,    16,    17,    71,    66,   205,   159,    86,
       8,    71,    72,    47,    72,    28,    88,    89,    90,     3,
       4,     5,     6,    78,    79,    80,     3,    87,    69,    83,
      67,    85,    16,    17,    88,    78,    83,    83,    91,    85,
      83,     3,   159,   166,    28,   168,   106,    84,   106,   200,
      67,   123,    38,    83,   205,    85,   207,   208,    74,    75,
      73,    47,    48,    76,    77,    78,    78,    84,    81,    82,
      83,    83,    84,    85,    78,    14,    15,   200,    84,    83,
      47,    85,    91,    92,   207,   208,    91,   210,    84,    73,
      93,    94,    76,    77,    78,    87,    84,    81,    82,    83,
      84,    86,   175,    84,    33,    34,   166,    86,   168,    38,
      99,   100,    86,    42,     3,     4,     5,     6,    47,    48,
      84,    50,    15,    52,    53,    84,    55,    16,    17,    58,
      59,    60,    61,    86,    63,    64,    86,    86,    86,    28,
     200,    86,   102,   101,    33,    34,   103,   207,   208,    38,
     210,   105,   104,    42,     3,     4,     5,     6,    47,    48,
     171,    50,   153,    52,    53,   197,    55,    16,    17,    58,
      59,    60,    61,   195,    63,    64,   190,    39,   119,    28,
      95,    96,    97,    98,    73,    34,   117,    76,    77,    78,
      -1,    -1,    81,    82,    83,     3,     4,     5,     6,    -1,
      -1,    50,    -1,    -1,    -1,    54,    -1,    -1,    16,    17,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    73,    -1,    34,    76,    77,    78,
      -1,    -1,    81,    82,    83,     3,     4,     5,     6,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    54,    -1,    16,    17,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    73,    34,    -1,    76,    77,
      78,    -1,    -1,    81,    82,    83,     3,     4,     5,     6,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    73,    -1,    -1,    76,    77,
      78,    -1,    -1,    81,    82,    83,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    73,    16,    17,    76,
      77,    78,    -1,    -1,    81,    82,    83,    -1,    -1,    28,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    73,    -1,    -1,    76,
      77,    78,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,
      -1,    33,    34,    -1,    73,    -1,    38,    76,    77,    78,
      42,    -1,    81,    82,    83,    47,    48,    -1,    50,    -1,
      52,    53,    -1,    55,    -1,    -1,    58,    59,    60,    61,
      73,    63,    64,    76,    77,    78,    33,    34,    81,    82,
      83,    38,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      47,    48,    -1,    50,    -1,    52,    53,    -1,    55,    -1,
      92,    58,    59,    60,    61,    -1,    63,    64,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    16,    17,    28,    73,    76,
      77,    78,    81,    82,    83,    94,    95,    96,    97,    98,
      99,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    83,   103,   103,    83,
     103,    33,    34,    38,    42,    47,    48,    50,    52,    53,
      55,    58,    59,    60,    61,    63,    64,    96,   117,   118,
     119,   122,   125,   130,     0,    95,    67,    87,     7,    16,
      17,    83,    85,    88,   102,   103,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    68,   116,    78,    79,
      80,    76,    89,    10,    11,    12,    13,    74,    75,    14,
      15,    73,    72,    71,     8,     9,    69,   130,    38,    47,
      48,    47,    84,   122,     3,    91,    78,    83,    85,   128,
     131,   132,   122,    84,   115,     3,    84,   100,   115,    96,
       3,   115,   102,   102,   102,   104,   104,   105,   105,   106,
     106,   106,   106,   107,   107,   108,   109,   110,   111,   112,
      96,    84,    47,    91,   120,   121,   122,   125,   128,   129,
      84,   131,    78,    86,   132,    83,    85,   102,    67,    84,
      86,    90,   120,    92,   121,    87,   125,   128,    84,    86,
      84,    78,   115,   115,   114,    92,   122,    86,    86,     3,
      83,   123,   124,   126,   127,   128,   126,    67,    87,    83,
      85,   127,    84,   124,    84,    54,   115,   129,   129,    86,
      54,    78,   115,   115,   115,    86,    86,    86,    86
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    94,    95,    96,    96,    97,    97,    97,
      97,    97,    98,    98,    98,    98,    98,    98,    98,    99,
      99,   100,   100,   101,   101,   101,   101,   101,   101,   102,
     102,   103,   103,   103,   103,   103,   103,   104,   104,   104,
     104,   105,   105,   105,   106,   106,   106,   107,   107,   107,
     107,   107,   108,   108,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   118,   118,   118,
     119,   119,   120,   120,   121,   122,   122,   122,   122,   123,
     123,   124,   125,   125,   125,   126,   126,   127,   127,   127,
     127,   127,   127,   127,   127,   128,   128,   128,   128,   129,
     129,   130,   130,   131,   131,   131,   132,   132,   132,   132,
     132,   132,   132
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     3,     1,     1,     1,
       1,     3,     1,     4,     1,     3,     3,     2,     2,     4,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     2,     2,     2,     2,     4,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     2,     2,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     4,     2,     5,
       1,     1,     1,     2,     5,     1,     2,     1,     2,     1,
       3,     1,     1,     1,     1,     1,     2,     1,     3,     4,
       5,     6,     6,     5,     3,     1,     2,     2,     3,     1,
       2,     1,     2,     1,     1,     2,     3,     2,     4,     3,
       4,     2,     3
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
  case 4: /* statement: expression ';'  */
#line 88 "parse.y"
                          {printAST((yyvsp[-1].astnode_p), 0);}
#line 1437 "parse.tab.c"
    break;

  case 5: /* expression: assignment_expression  */
#line 90 "parse.y"
                                  {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1443 "parse.tab.c"
    break;

  case 6: /* expression: expression ',' assignment_expression  */
#line 91 "parse.y"
                                           {(yyval.astnode_p) = new_astnode_binop(',', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1449 "parse.tab.c"
    break;

  case 7: /* primary_expression: IDENT  */
#line 94 "parse.y"
                          {(yyval.astnode_p) = new_astnode_ident(IDENT_NODE, (yyvsp[0].stringInfo).string_literal); 
    }
#line 1456 "parse.tab.c"
    break;

  case 8: /* primary_expression: NUMBER  */
#line 96 "parse.y"
             {(yyval.astnode_p) = new_astnode_num(NUMBER_NODE, (yyvsp[0].numInfo));
    }
#line 1463 "parse.tab.c"
    break;

  case 9: /* primary_expression: CHARLIT  */
#line 98 "parse.y"
              { 
                struct numinfo *temp = (struct numinfo*) malloc(sizeof (struct numinfo));
                temp->meta = UNSIGNED_INT;
                temp->value.int_val = (yyvsp[0].char_literal);
                (yyval.astnode_p) = new_astnode_num(NUMBER_NODE, *temp); 
    }
#line 1474 "parse.tab.c"
    break;

  case 10: /* primary_expression: STRING  */
#line 104 "parse.y"
             {(yyval.astnode_p) = new_astnode_string(STRING_NODE, (yyvsp[0].stringInfo).string_literal);
    }
#line 1481 "parse.tab.c"
    break;

  case 11: /* primary_expression: '(' expression ')'  */
#line 106 "parse.y"
                       {(yyval.astnode_p) = (yyvsp[-1].astnode_p);}
#line 1487 "parse.tab.c"
    break;

  case 12: /* postfix_expression: primary_expression  */
#line 109 "parse.y"
                                       {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1493 "parse.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 110 "parse.y"
                                           { // E1[E2] is identical to (*((E1)+(E2))) 
                                            union astnode *astnode_temp = new_astnode_binop('+', (yyvsp[-3].astnode_p), (yyvsp[-1].astnode_p));
                                            (yyval.astnode_p) = new_astnode_unop('*', astnode_temp);                           
    }
#line 1502 "parse.tab.c"
    break;

  case 14: /* postfix_expression: function_call  */
#line 114 "parse.y"
                    {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1508 "parse.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression '.' IDENT  */
#line 115 "parse.y"
                                   {union astnode *astnode_ident = new_astnode_ident(IDENT_NODE, (yyvsp[0].stringInfo).string_literal);
                                    (yyval.astnode_p) = new_astnode_binop('.', (yyvsp[-2].astnode_p), astnode_ident); 
    }
#line 1516 "parse.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression INDSEL IDENT  */
#line 118 "parse.y"
                                      { // E1->E2 is identical to (*E1).E2
                                      union astnode *astnode_temp = new_astnode_unop('*', (yyvsp[-2].astnode_p));
                                      union astnode *astnode_ident = new_astnode_ident(IDENT_NODE, (yyvsp[0].stringInfo).string_literal);
                                      (yyval.astnode_p) = new_astnode_binop('.', astnode_temp, astnode_ident);
    }
#line 1526 "parse.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression PLUSPLUS  */
#line 123 "parse.y"
                                  {(yyval.astnode_p) = new_astnode_unop(PLUSPLUS, (yyvsp[-1].astnode_p));}
#line 1532 "parse.tab.c"
    break;

  case 18: /* postfix_expression: postfix_expression MINUSMINUS  */
#line 124 "parse.y"
                                    {(yyval.astnode_p) = new_astnode_unop(MINUSMINUS, (yyvsp[-1].astnode_p));}
#line 1538 "parse.tab.c"
    break;

  case 19: /* function_call: postfix_expression '(' argument_expression_list ')'  */
#line 129 "parse.y"
                                                                     {(yyval.astnode_p) = new_astnode_func((yyvsp[-3].astnode_p), (yyvsp[-1].astnode_p));}
#line 1544 "parse.tab.c"
    break;

  case 20: /* function_call: postfix_expression '(' ')'  */
#line 130 "parse.y"
                                 {(yyval.astnode_p) = new_astnode_func((yyvsp[-2].astnode_p), NULL);}
#line 1550 "parse.tab.c"
    break;

  case 21: /* argument_expression_list: assignment_expression  */
#line 133 "parse.y"
                                                {
                                                union astnode *head = new_astnode_arg((yyvsp[0].astnode_p));
                                                (yyval.astnode_p) = init_list(head);
                                                }
#line 1559 "parse.tab.c"
    break;

  case 22: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 137 "parse.y"
                                                         {(yyval.astnode_p) = append_arg((yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1565 "parse.tab.c"
    break;

  case 23: /* unary_operator: '&'  */
#line 167 "parse.y"
                    {(yyval.operator) = '&';}
#line 1571 "parse.tab.c"
    break;

  case 24: /* unary_operator: '*'  */
#line 168 "parse.y"
          {(yyval.operator) = '*';}
#line 1577 "parse.tab.c"
    break;

  case 25: /* unary_operator: '+'  */
#line 169 "parse.y"
          {(yyval.operator) = '+';}
#line 1583 "parse.tab.c"
    break;

  case 26: /* unary_operator: '-'  */
#line 170 "parse.y"
          {(yyval.operator) = '-';}
#line 1589 "parse.tab.c"
    break;

  case 27: /* unary_operator: '~'  */
#line 171 "parse.y"
          {(yyval.operator) = '~';}
#line 1595 "parse.tab.c"
    break;

  case 28: /* unary_operator: '!'  */
#line 172 "parse.y"
          {(yyval.operator) = '!';}
#line 1601 "parse.tab.c"
    break;

  case 29: /* cast_expression: unary_expression  */
#line 175 "parse.y"
                                  {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1607 "parse.tab.c"
    break;

  case 30: /* cast_expression: '(' type_name ')' cast_expression  */
#line 176 "parse.y"
                                        {(yyval.astnode_p) = new_astnode_binop('\0', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1613 "parse.tab.c"
    break;

  case 31: /* unary_expression: postfix_expression  */
#line 179 "parse.y"
                                     {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1619 "parse.tab.c"
    break;

  case 32: /* unary_expression: PLUSPLUS unary_expression  */
#line 180 "parse.y"
                                { 
                                union astnode* one = astnode_one();
                                (yyval.astnode_p) = new_astnode_binop(PLUSEQ, (yyvsp[0].astnode_p), one);
    }
#line 1628 "parse.tab.c"
    break;

  case 33: /* unary_expression: MINUSMINUS unary_expression  */
#line 184 "parse.y"
                                  { 
                                union astnode* one = astnode_one();
                                (yyval.astnode_p) = new_astnode_binop(MINUSEQ, (yyvsp[0].astnode_p), one);
    }
#line 1637 "parse.tab.c"
    break;

  case 34: /* unary_expression: unary_operator cast_expression  */
#line 188 "parse.y"
                                     {(yyval.astnode_p) = new_astnode_unop((yyvsp[-1].operator), (yyvsp[0].astnode_p));}
#line 1643 "parse.tab.c"
    break;

  case 35: /* unary_expression: SIZEOF unary_expression  */
#line 189 "parse.y"
                              {(yyval.astnode_p) = new_astnode_unop(SIZEOF, (yyvsp[0].astnode_p));}
#line 1649 "parse.tab.c"
    break;

  case 36: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 190 "parse.y"
                               {(yyval.astnode_p) = new_astnode_unop(SIZEOF, (yyvsp[-1].astnode_p));}
#line 1655 "parse.tab.c"
    break;

  case 37: /* multiplicative_expression: cast_expression  */
#line 193 "parse.y"
                                           {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1661 "parse.tab.c"
    break;

  case 38: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 194 "parse.y"
                                                    {(yyval.astnode_p) = new_astnode_binop('*', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1667 "parse.tab.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 195 "parse.y"
                                                    {(yyval.astnode_p) = new_astnode_binop('/', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1673 "parse.tab.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 196 "parse.y"
                                                    {(yyval.astnode_p) = new_astnode_binop('%', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1679 "parse.tab.c"
    break;

  case 41: /* additive_expression: multiplicative_expression  */
#line 199 "parse.y"
                                               {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1685 "parse.tab.c"
    break;

  case 42: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 200 "parse.y"
                                                        {(yyval.astnode_p) = new_astnode_binop('+', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1691 "parse.tab.c"
    break;

  case 43: /* additive_expression: additive_expression '_' multiplicative_expression  */
#line 201 "parse.y"
                                                        {(yyval.astnode_p) = new_astnode_binop('-', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1697 "parse.tab.c"
    break;

  case 44: /* shift_expression: additive_expression  */
#line 204 "parse.y"
                                      {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1703 "parse.tab.c"
    break;

  case 45: /* shift_expression: shift_expression SHL additive_expression  */
#line 205 "parse.y"
                                               {(yyval.astnode_p) = new_astnode_binop(SHL, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1709 "parse.tab.c"
    break;

  case 46: /* shift_expression: shift_expression SHR additive_expression  */
#line 206 "parse.y"
                                               {(yyval.astnode_p) = new_astnode_binop(SHR, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1715 "parse.tab.c"
    break;

  case 47: /* relational_expression: shift_expression  */
#line 209 "parse.y"
                                        {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1721 "parse.tab.c"
    break;

  case 48: /* relational_expression: relational_expression '<' shift_expression  */
#line 210 "parse.y"
                                                 {(yyval.astnode_p) = new_astnode_binop('<', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1727 "parse.tab.c"
    break;

  case 49: /* relational_expression: relational_expression '>' shift_expression  */
#line 211 "parse.y"
                                                 {(yyval.astnode_p) = new_astnode_binop('>', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1733 "parse.tab.c"
    break;

  case 50: /* relational_expression: relational_expression LTEQ shift_expression  */
#line 212 "parse.y"
                                                  {(yyval.astnode_p) = new_astnode_binop(LTEQ, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1739 "parse.tab.c"
    break;

  case 51: /* relational_expression: relational_expression GTEQ shift_expression  */
#line 213 "parse.y"
                                                  {(yyval.astnode_p) = new_astnode_binop(GTEQ, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1745 "parse.tab.c"
    break;

  case 52: /* equality_expression: relational_expression  */
#line 216 "parse.y"
                                           {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1751 "parse.tab.c"
    break;

  case 53: /* equality_expression: equality_expression EQEQ relational_expression  */
#line 217 "parse.y"
                                                     {(yyval.astnode_p) = new_astnode_binop(EQEQ, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1757 "parse.tab.c"
    break;

  case 54: /* equality_expression: equality_expression NOTEQ relational_expression  */
#line 218 "parse.y"
                                                      {(yyval.astnode_p) = new_astnode_binop(NOTEQ, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1763 "parse.tab.c"
    break;

  case 55: /* AND_expression: equality_expression  */
#line 221 "parse.y"
                                    {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1769 "parse.tab.c"
    break;

  case 56: /* AND_expression: AND_expression '&' equality_expression  */
#line 222 "parse.y"
                                             {(yyval.astnode_p) = new_astnode_binop('&', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1775 "parse.tab.c"
    break;

  case 57: /* exclusive_OR_expression: AND_expression  */
#line 225 "parse.y"
                                        {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1781 "parse.tab.c"
    break;

  case 58: /* exclusive_OR_expression: exclusive_OR_expression '^' AND_expression  */
#line 226 "parse.y"
                                                 {(yyval.astnode_p) = new_astnode_binop('^', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1787 "parse.tab.c"
    break;

  case 59: /* inclusive_OR_expression: exclusive_OR_expression  */
#line 229 "parse.y"
                                                 {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1793 "parse.tab.c"
    break;

  case 60: /* inclusive_OR_expression: inclusive_OR_expression '|' exclusive_OR_expression  */
#line 230 "parse.y"
                                                          {(yyval.astnode_p) = new_astnode_binop('|', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1799 "parse.tab.c"
    break;

  case 61: /* logical_AND_expression: inclusive_OR_expression  */
#line 233 "parse.y"
                                                {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1805 "parse.tab.c"
    break;

  case 62: /* logical_AND_expression: logical_AND_expression LOGAND inclusive_OR_expression  */
#line 234 "parse.y"
                                                            {(yyval.astnode_p) = new_astnode_binop(LOGAND, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1811 "parse.tab.c"
    break;

  case 63: /* logical_OR_expression: logical_AND_expression  */
#line 237 "parse.y"
                                              {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1817 "parse.tab.c"
    break;

  case 64: /* logical_OR_expression: logical_OR_expression LOGOR logical_AND_expression  */
#line 238 "parse.y"
                                                         {(yyval.astnode_p) = new_astnode_binop(LOGOR, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1823 "parse.tab.c"
    break;

  case 65: /* conditional_expression: logical_OR_expression  */
#line 241 "parse.y"
                                              {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1829 "parse.tab.c"
    break;

  case 66: /* conditional_expression: logical_OR_expression '?' expression ':' conditional_expression  */
#line 242 "parse.y"
                                                                      {(yyval.astnode_p) = new_astnode_ternop('?', ':', (yyvsp[-4].astnode_p), (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1835 "parse.tab.c"
    break;

  case 67: /* assignment_expression: conditional_expression  */
#line 245 "parse.y"
                                              {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1841 "parse.tab.c"
    break;

  case 68: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 246 "parse.y"
                                                                 {(yyval.astnode_p) = new_astnode_binop((yyvsp[-1].operator), (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1847 "parse.tab.c"
    break;

  case 69: /* assignment_operator: '='  */
#line 249 "parse.y"
                         {(yyval.operator) = '=';}
#line 1853 "parse.tab.c"
    break;

  case 70: /* assignment_operator: TIMESEQ  */
#line 250 "parse.y"
              {(yyval.operator) = TIMESEQ;}
#line 1859 "parse.tab.c"
    break;

  case 71: /* assignment_operator: DIVEQ  */
#line 251 "parse.y"
            {(yyval.operator) = DIVEQ;}
#line 1865 "parse.tab.c"
    break;

  case 72: /* assignment_operator: MODEQ  */
#line 252 "parse.y"
            {(yyval.operator) = MODEQ;}
#line 1871 "parse.tab.c"
    break;

  case 73: /* assignment_operator: PLUSEQ  */
#line 253 "parse.y"
             {(yyval.operator) = PLUSEQ;}
#line 1877 "parse.tab.c"
    break;

  case 74: /* assignment_operator: MINUSEQ  */
#line 254 "parse.y"
              {(yyval.operator) = MINUSEQ;}
#line 1883 "parse.tab.c"
    break;

  case 75: /* assignment_operator: SHLEQ  */
#line 255 "parse.y"
            {(yyval.operator) = SHLEQ;}
#line 1889 "parse.tab.c"
    break;

  case 76: /* assignment_operator: SHREQ  */
#line 256 "parse.y"
            {(yyval.operator) = SHREQ;}
#line 1895 "parse.tab.c"
    break;

  case 77: /* assignment_operator: ANDEQ  */
#line 257 "parse.y"
            {(yyval.operator) = ANDEQ;}
#line 1901 "parse.tab.c"
    break;

  case 78: /* assignment_operator: XOREQ  */
#line 258 "parse.y"
            {(yyval.operator) = XOREQ;}
#line 1907 "parse.tab.c"
    break;

  case 79: /* assignment_operator: OREQ  */
#line 259 "parse.y"
           {(yyval.operator) = OREQ;}
#line 1913 "parse.tab.c"
    break;


#line 1917 "parse.tab.c"

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

#line 442 "parse.y"


void printIndents(int indent){
    for (int i = 0; i < indent; i++){
        printf("\t");
    }
}

void printBinop(int operator){
    if(operator == '=') {
        printf("ASSIGNMENT\n"); 
    } else if(operator >= 263 && operator <= 264){
        printf("LOGICAL OP ");
    } else if(operator >= 265 && operator <= 266){
        printf("BINARY OP ");
    } else if(operator >= 267 && operator <= 270){
        printf("COMPARISON OP ");
    } else if(operator >= 271 && operator <= 282){
        printf("ASSIGNMENT COMPOUND (");
    } 
    switch(operator){
        case LTEQ:
            printf("<");
            break;
        case GTEQ:
            printf(">");
            break;
        case EQEQ:
            printf("=");
            break;
        case NOTEQ:
            printf("!");
            break;
        case LOGAND:
            printf("&&\n");
            break;
        case LOGOR:
            printf("||\n");
            break;
        case SHL:
            printf("<<\n");
            break;
        case SHR:
            printf(">>\n");
            break;
        case TIMESEQ:
            printf("*");
            break;
        case DIVEQ:
            printf("/");
            break;
        case MODEQ:
            printf("%%");
            break;
        case PLUSEQ:
            printf("+");
            break;
        case MINUSEQ:
            printf("-");
            break;
        case SHLEQ:
            printf("<<");
            break;
        case SHREQ:
            printf(">>");
            break;
        case ANDEQ:
            printf("&");
            break;
        case OREQ:
            printf("|");
            break;
        case XOREQ:
            printf("^");
            break;
    }

    if(operator >= 267 && operator <= 270){
        printf("=\n");
    } else if(operator >= 271 && operator <= 282){
        printf(")\n");
    }
}

void printNum(struct numinfo numInfo){
    switch(numInfo.meta) {
            case(UNSIGNED_INT):
            case(SIGNED_INT):
                printf("int)");
                printf("%lld\n", numInfo.value.int_val);
                break;
            case(UNSIGNED_LONG):
            case(SIGNED_LONG):
                printf("long)");
                printf("%lld\n", numInfo.value.int_val);
                break;
            case(UNSIGNED_LONGLONG):
            case(SIGNED_LONGLONG):
                printf("long long)");
                printf("%lld\n", numInfo.value.int_val);
                break;
            case(DOUBLE_NUM):
                printf("double)");
                if (numInfo.value.float_val >= 10) {
                    printf("%.2Le\n", numInfo.value.float_val);
                } else {
                    printf("%.2Lf\n", numInfo.value.float_val);
                }
                break;
            case(FLOAT_NUM):
                printf("float)");
                if (numInfo.value.float_val >= 10) {
                    printf("%.2Le\n", numInfo.value.float_val);
                } else {
                    printf("%.2Lf\n", numInfo.value.float_val);
                }
                break;
            case(LONG_DOUBLE):
                printf("long double)");
                if (numInfo.value.float_val >= 10) {
                    printf("%.2Le\n", numInfo.value.float_val);
                } else {
                    printf("%.2Lf\n", numInfo.value.float_val);
                }
                break;
    }
}

void printAST(union astnode* node, int indent) {
    int count = 1; 
    printIndents(indent);

    switch(node->generic.type){
        case UNOP_NODE: 
            if (node->unop.operator == SIZEOF) {
                printf("SIZEOF\n");
            } else if (node->unop.operator == '&') {
                printf("ADDRESSOF\n");
            } else if (node->unop.operator == '*') {
                printf("DEREF\n");
            } else if (node->unop.operator == PLUSPLUS) {
                printf("UNARY OP POSTINC\n");
            } else if (node->unop.operator == MINUSMINUS) {
                printf("UNARY OP POSTDEC\n");
            } else{
                printf("UNARY OP %c\n", node->unop.operator);
            }
            printAST(node->unop.operand, indent+1); 
            break;
        case BINOP_NODE:
            if ((node->binop.operator >= LOGAND && node->binop.operator <= XOREQ) || node->binop.operator == '=') {
                printBinop(node->binop.operator); 
            } else if (node->binop.operator == '.') {
                if ((node->binop.left)->unop.operator && (node->binop.left)->unop.operator == '*') {
                    printf("INDIRECT SELECT, member %s\n", (node->binop.right)->id.ident);
                    printAST((node->binop.left)->unop.operand, indent+1);  
                } else {
                    printf("SELECT, member %s\n", (node->binop.right)->id.ident);
                    printAST(node->binop.left, indent+1);  
                }
                break;
            } else {
                printf("BINARY OP %c\n", node->binop.operator);
            }
            printAST(node->binop.left, indent+1); 
            printAST(node->binop.right, indent+1); 
            break;
        case TERNOP_NODE:
            printf("TERNARY OP, IF:\n");
	        printAST(node->ternop.left, indent+1);
            printf("THEN:\n");
            printAST(node->ternop.middle, indent+1);
	        printf("ELSE:\n");
            printAST(node->ternop.right, indent+1);
            break;
        case NUMBER_NODE:
            printf("CONSTANT: (type=");
            printNum(node->num.numInfo);
            break;
        case IDENT_NODE:
            printf("IDENT %s\n", node->id.ident);
            break;
        case STRING_NODE:
            printf("STRING\t%s\n", node->str.string_literal);
            break;
        case ARGLIST_NODE:
            printIndents(indent + 1);
            printf("arg #%d=\n", count);
            printAST((node->list.arg_head)->arg.argument, indent+1);
            while(node->list.arg_next != NULL) {
                printIndents(indent + 1);
                printf("arg #%d=\n", ++count);
                printAST((node->list.arg_next)->arg.argument, indent+1);
                node = node->list.arg_next;
            }
            break;
        case FUNCTION_NODE:
            printf("FNCALL, %d arguments\n", node->func.num_args);
            printAST(node->func.function_name, indent+1);
            if (node->func.arg_head) {
                printAST(node->func.arg_head, indent-1);
            }
            break;
        case ARGUMENT_NODE:
        break; 
    }
    free(node); 
}

int main(){
  //yydebug = 1;
  int t;
  while(!(t = yyparse())){
  };
}

void yyerror(char *str) {
  fprintf(stderr,"error: %s\n",str);
}
