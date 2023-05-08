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
  YYSYMBOL_87_ = 87,                       /* '.'  */
  YYSYMBOL_88___ = 88,                     /* '_'  */
  YYSYMBOL_89_ = 89,                       /* ':'  */
  YYSYMBOL_90_ = 90,                       /* '{'  */
  YYSYMBOL_91_ = 91,                       /* '}'  */
  YYSYMBOL_92_ = 92,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 93,                  /* $accept  */
  YYSYMBOL_start = 94,                     /* start  */
  YYSYMBOL_expression = 95,                /* expression  */
  YYSYMBOL_primary_expression = 96,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 97,        /* postfix_expression  */
  YYSYMBOL_function_call = 98,             /* function_call  */
  YYSYMBOL_argument_expression_list = 99,  /* argument_expression_list  */
  YYSYMBOL_unary_operator = 100,           /* unary_operator  */
  YYSYMBOL_cast_expression = 101,          /* cast_expression  */
  YYSYMBOL_unary_expression = 102,         /* unary_expression  */
  YYSYMBOL_multiplicative_expression = 103, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 104,      /* additive_expression  */
  YYSYMBOL_shift_expression = 105,         /* shift_expression  */
  YYSYMBOL_relational_expression = 106,    /* relational_expression  */
  YYSYMBOL_equality_expression = 107,      /* equality_expression  */
  YYSYMBOL_AND_expression = 108,           /* AND_expression  */
  YYSYMBOL_exclusive_OR_expression = 109,  /* exclusive_OR_expression  */
  YYSYMBOL_inclusive_OR_expression = 110,  /* inclusive_OR_expression  */
  YYSYMBOL_logical_AND_expression = 111,   /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 112,    /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 113,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 114,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 115,      /* assignment_operator  */
  YYSYMBOL_116_constant_expression = 116,  /* constant-expression  */
  YYSYMBOL_declaration_or_fndef = 117,     /* declaration_or_fndef  */
  YYSYMBOL_function_definition = 118,      /* function_definition  */
  YYSYMBOL_119_1 = 119,                    /* $@1  */
  YYSYMBOL_compound_statement = 120,       /* compound_statement  */
  YYSYMBOL_121_2 = 121,                    /* $@2  */
  YYSYMBOL_122_3 = 122,                    /* $@3  */
  YYSYMBOL_decl_or_stmt_list = 123,        /* decl_or_stmt_list  */
  YYSYMBOL_decl_or_stmt = 124,             /* decl_or_stmt  */
  YYSYMBOL_declaration = 125,              /* declaration  */
  YYSYMBOL_statement = 126,                /* statement  */
  YYSYMBOL_declaration_specifiers = 127,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 128,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 129,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 130,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 131,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 132, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 133,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 134,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 135,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 136, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 137,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 138,        /* struct_declarator  */
  YYSYMBOL_type_qualifier = 139,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 140,       /* function_specifier  */
  YYSYMBOL_declarator = 141,               /* declarator  */
  YYSYMBOL_direct_declarator = 142,        /* direct_declarator  */
  YYSYMBOL_pointer = 143,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 144,      /* type_qualifier_list  */
  YYSYMBOL_145_parameter_type_list = 145,  /* parameter-type-list  */
  YYSYMBOL_146_parameter_list = 146,       /* parameter-list  */
  YYSYMBOL_147_parameter_declaration = 147, /* parameter-declaration  */
  YYSYMBOL_148_identifier_list = 148,      /* identifier-list  */
  YYSYMBOL_type_name = 149,                /* type_name  */
  YYSYMBOL_abstract_declarator = 150,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 151, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 152,              /* initializer  */
  YYSYMBOL_153_labeled_statement = 153,    /* labeled-statement  */
  YYSYMBOL_154_selection_statement = 154,  /* selection-statement  */
  YYSYMBOL_155_iteration_statement = 155,  /* iteration-statement  */
  YYSYMBOL_156_jump_statement = 156,       /* jump-statement  */
  YYSYMBOL_expression_opt = 157,           /* expression_opt  */
  YYSYMBOL_158_expression_statement = 158  /* expression-statement  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   904

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  200
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  326

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
      83,    84,    78,    76,    67,    77,    87,    79,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    89,    92,
      74,    68,    75,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    85,     2,    86,    72,    88,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    90,    71,    91,    82,     2,     2,     2,
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
       0,   121,   121,   122,   131,   132,   135,   136,   137,   143,
     144,   147,   148,   152,   153,   156,   161,   162,   167,   168,
     171,   175,   178,   179,   180,   181,   182,   183,   186,   187,
     190,   191,   195,   199,   200,   201,   204,   205,   206,   207,
     210,   211,   212,   215,   216,   217,   220,   221,   222,   223,
     224,   227,   228,   229,   232,   233,   236,   237,   240,   241,
     244,   245,   248,   249,   252,   253,   256,   257,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   273,
     276,   288,   291,   291,   318,   318,   330,   330,   355,   356,
     364,   365,   368,   369,   423,   424,   425,   426,   427,   428,
     431,   432,   440,   441,   447,   448,   457,   458,   461,   462,
     465,   466,   469,   470,   471,   472,   473,   476,   480,   484,
     488,   492,   496,   500,   504,   508,   517,   522,   523,   524,
     527,   528,   531,   532,   535,   539,   540,   546,   547,   555,
     556,   559,   562,   563,   564,   567,   570,   571,   590,   596,
     615,   633,   651,   660,   669,   689,   690,   691,   692,   695,
     696,   699,   700,   703,   704,   707,   712,   720,   723,   724,
     727,   728,   738,   739,   740,   743,   744,   745,   746,   747,
     748,   749,   760,   796,   802,   803,   806,   807,   808,   811,
     812,   813,   814,   819,   826,   827,   828,   831,   832,   835,
     836
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
  "'('", "')'", "'['", "']'", "'.'", "'_'", "':'", "'{'", "'}'", "';'",
  "$accept", "start", "expression", "primary_expression",
  "postfix_expression", "function_call", "argument_expression_list",
  "unary_operator", "cast_expression", "unary_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "AND_expression",
  "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "constant-expression", "declaration_or_fndef", "function_definition",
  "$@1", "compound_statement", "$@2", "$@3", "decl_or_stmt_list",
  "decl_or_stmt", "declaration", "statement", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "type_qualifier", "function_specifier",
  "declarator", "direct_declarator", "pointer", "type_qualifier_list",
  "parameter-type-list", "parameter-list", "parameter-declaration",
  "identifier-list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "labeled-statement",
  "selection-statement", "iteration-statement", "jump-statement",
  "expression_opt", "expression-statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-204)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-85)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     814,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,   705,  -204,  -204,  -204,    39,   814,   814,  -204,     2,
     814,   814,  -204,  -204,  -204,   136,     4,  -204,   -45,  -204,
     -59,   -27,    11,  -204,  -204,   -69,   843,  -204,  -204,  -204,
    -204,   136,   -24,     4,  -204,   593,   -11,   419,     9,   -27,
     843,   843,   639,  -204,   -63,   843,  -204,  -204,  -204,  -204,
      -5,  -204,  -204,  -204,  -204,   634,   634,   651,  -204,  -204,
    -204,  -204,  -204,  -204,   553,  -204,    58,  -204,   593,  -204,
     778,    45,   -12,   152,    -2,   180,    69,    85,    97,   144,
      -1,  -204,  -204,  -204,    86,  -204,  -204,  -204,    68,   115,
     138,  -204,   -48,   121,  -204,   734,  -204,  -204,  -204,   843,
    -204,   593,  -204,  -204,   553,  -204,   -22,  -204,   105,   119,
     169,  -204,  -204,   408,   593,   206,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,   593,
     593,   593,   593,   593,   593,   593,   593,   593,   593,   593,
     593,   593,   593,   593,   593,   593,   593,   593,   593,   128,
     301,    43,    44,  -204,     3,  -204,    88,  -204,   780,   214,
    -204,  -204,  -204,     4,   137,   593,  -204,   162,   117,  -204,
     593,  -204,  -204,   -18,  -204,   -34,  -204,  -204,  -204,  -204,
    -204,    45,    45,   -12,   -12,   152,   152,   152,   152,    -2,
      -2,   180,    69,    85,    97,   144,   -32,  -204,   139,   140,
     593,   149,   160,   364,   176,   284,   205,   593,   207,   208,
    -204,   -44,  -204,   220,  -204,  -204,  -204,    39,  -204,  -204,
    -204,  -204,  -204,  -204,   210,   203,  -204,    88,   211,    48,
    -204,  -204,  -204,   -37,  -204,  -204,  -204,  -204,  -204,   593,
    -204,  -204,   593,   364,  -204,  -204,   219,  -204,   364,   230,
     490,   217,   593,   232,   221,   593,   593,  -204,  -204,  -204,
    -204,  -204,  -204,   228,  -204,     4,  -204,  -204,  -204,  -204,
     364,  -204,   233,   593,   223,  -204,    -6,  -204,     0,   216,
    -204,  -204,  -204,   593,   227,   593,   364,   364,   364,    80,
     593,   229,   281,  -204,  -204,   231,   238,   593,   364,  -204,
     364,   240,  -204,  -204,   364,  -204
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   115,   118,   142,   123,   113,   122,   145,   120,   121,
     116,   143,   119,   124,   114,   130,   112,   131,   125,   117,
     144,     0,     2,    81,    80,     0,   100,   102,   126,     0,
     104,   106,     1,     3,   148,   155,     0,    92,     0,   108,
     110,   146,     0,   101,   103,   128,     0,   105,   107,   159,
     157,   156,     0,     0,    93,     0,     0,     0,     0,   147,
       0,   135,     0,   132,     0,   137,   160,   158,   149,   109,
     110,     6,     8,     9,     7,     0,     0,     0,    22,    24,
      25,    23,    27,    26,     0,    11,    30,    13,     0,    36,
      28,    40,    43,    46,    51,    54,    56,    58,    60,    62,
      64,    66,   182,   111,    86,    83,   168,   154,   167,     0,
     161,   163,     0,     0,   152,     0,   136,   127,   133,     0,
     138,     0,    31,    32,     0,    34,     0,     4,   170,     0,
       0,    16,    17,     0,     0,     0,    33,    28,    69,    70,
      71,    72,    73,    74,    75,    76,    78,    77,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   172,   166,   173,   150,     0,     0,
     151,   153,   129,     0,     0,     0,    10,     0,   172,   171,
       0,    15,    19,     0,    20,     0,    14,    67,    37,    38,
      39,    41,    42,    44,    45,    49,    50,    47,    48,    52,
      53,    55,    57,    59,    61,    63,     0,    85,     6,     0,
       0,     0,     0,     0,     0,     0,     0,   197,     0,     0,
     199,     0,    96,     0,    88,    90,    91,     0,    95,    97,
      98,    99,    94,   180,     0,     0,   176,   174,     0,     0,
     162,   164,   169,     0,   139,   141,    35,     5,    29,     0,
      18,    12,     0,     0,   195,    79,     0,   194,     0,     0,
     197,     0,     0,   198,     0,     0,   197,   200,    87,    89,
     175,   178,   181,     0,   177,     0,   134,    21,    65,   183,
       0,   185,     0,   197,     0,   193,     0,   196,     0,     0,
     179,   140,   184,     0,     0,   197,     0,     0,     0,     0,
     197,     0,   186,   188,   189,     0,     0,   197,     0,   190,
       0,     0,   187,   192,     0,   191
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -204,  -204,   -83,  -204,  -204,  -204,  -204,  -204,   -61,   -51,
      62,    75,   126,    81,   163,   161,   165,   174,   197,  -204,
    -203,   -53,  -204,  -204,   306,  -204,  -204,   272,  -204,  -204,
    -204,   108,  -152,  -170,    13,  -204,   312,  -204,   120,  -204,
    -204,   311,   -46,    94,  -204,    87,   114,  -204,   -25,   -39,
     -31,  -204,  -204,  -204,   188,  -204,   249,   -96,   -55,  -204,
    -204,  -204,  -204,  -204,  -109,  -204
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    21,   231,    85,    86,    87,   193,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   127,   149,   266,    22,    23,    56,   232,   169,   170,
     233,   234,    24,   236,   237,    38,    39,    26,    27,    28,
      29,    62,    63,    64,   253,   254,    30,    31,    52,    41,
      42,    51,   109,   110,   111,   112,   129,   244,   176,   103,
     238,   239,   240,   241,   274,   242
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,   126,   102,    59,    50,    45,    34,    34,   167,    55,
     157,   158,   175,    25,    34,   113,   118,   265,   235,   179,
      67,    60,    53,   185,   122,   123,   125,   136,    70,   119,
     285,   -82,   189,   185,    25,   185,   180,   137,   126,    43,
      44,   126,    34,    47,    48,   185,    34,    54,   277,   259,
     245,   195,   261,   269,   283,   286,    57,   262,    58,   288,
      68,   185,   186,    55,   153,   130,   260,   185,   168,   118,
     108,    34,   159,   160,   131,   132,   154,   174,   306,   104,
     194,   235,    35,   173,   307,   216,   171,    36,   172,   198,
     199,   200,    46,   289,    36,   114,   197,   188,   291,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,    35,   293,   247,
     302,    35,    36,   150,   151,   152,   171,   243,   172,   258,
     246,    37,   257,   247,   284,    59,   312,   313,   314,   137,
     174,   133,   163,   134,   273,   135,    35,   185,   322,    49,
     323,   171,   166,   172,   325,   116,   188,   164,   255,   120,
      65,   294,   155,   156,   315,    66,    61,   299,   165,   137,
       3,   248,   191,   249,    65,    65,    65,   -84,   128,    65,
      61,    61,    61,    35,   304,    61,    11,   273,   187,   296,
     172,   108,   298,   273,   161,   162,   311,    20,    65,   177,
     187,   316,   172,   190,    61,   178,   287,   181,   321,   196,
     273,   137,    70,   183,    35,   201,   202,   252,   128,   217,
     309,   256,   273,   218,    72,    73,    74,   273,   263,    65,
     203,   204,   264,    65,   273,    61,    75,    76,    65,    61,
      35,   267,   209,   210,    61,   187,   243,   172,    77,   268,
       1,   219,   220,     2,     3,   221,   222,   223,     4,   270,
     255,     5,     6,   224,   225,   226,     7,     8,     9,    10,
      11,   227,    12,    13,    14,    15,   228,    16,    17,    18,
      19,    20,   229,   205,   206,   207,   208,   271,   272,   281,
     275,   276,   292,    78,   280,   282,    79,    80,    81,   185,
     308,    82,    83,    84,   218,    72,    73,    74,   290,   295,
     104,   278,   230,   297,   300,   305,   303,    75,    76,   310,
     318,   317,   320,   319,   324,   212,   211,    33,   105,    77,
     213,     1,   219,   220,     2,     3,   221,   222,   223,     4,
     214,   279,     5,     6,   224,   225,   226,     7,     8,     9,
      10,    11,   227,    12,    13,    14,    15,   228,    16,    17,
      18,    19,    20,   229,   215,    69,   251,   218,    72,    73,
      74,   115,   301,   184,    78,     0,     0,    79,    80,    81,
      75,    76,    82,    83,    84,     0,     0,     0,     0,     0,
       0,   104,    77,   230,     0,   219,   220,     0,     0,   221,
     222,   223,     0,     0,     0,     0,     0,   224,   225,   226,
       0,    71,    72,    73,    74,   227,     0,     0,     0,     0,
     228,     0,   106,     0,    75,    76,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    78,     0,     0,
      79,    80,    81,     0,     0,    82,    83,    84,     0,     1,
       0,     0,     2,     3,   104,     0,   230,     4,     0,     0,
       5,     6,     0,     0,     0,     7,     8,     9,    10,    11,
       0,    12,    13,    14,    15,     0,    16,    17,    18,    19,
      20,    78,     0,     0,    79,    80,    81,     0,     0,    82,
      83,    84,   192,    71,    72,    73,    74,     0,     0,     0,
       0,     0,     0,   107,     0,     0,    75,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       1,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       0,     5,     6,     0,     0,     0,     7,     8,     9,    10,
      11,     0,    12,    13,    14,    15,     0,    16,    17,    18,
      19,    20,     0,     0,     0,     0,    71,    72,    73,    74,
       0,     0,     0,    78,     0,     0,    79,    80,    81,    75,
      76,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     2,     3,     0,     0,
       0,     4,     0,     0,     0,     6,    71,    72,    73,    74,
       8,     9,     0,    11,     0,    12,    13,     0,    15,    75,
      76,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,    78,     0,     0,    79,
      80,    81,     0,     0,    82,    83,    84,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,    76,     0,     0,    71,    72,    73,    74,     0,     0,
       0,     0,    77,     0,     0,     0,    78,    75,    76,    79,
      80,    81,     2,     3,    82,    83,    84,     4,     0,    77,
       0,     6,     0,     0,     0,     0,     8,     9,     0,    11,
       0,    12,    13,     0,    15,     0,     0,    17,    18,    19,
      20,     0,     0,     0,     0,    32,     0,    78,     0,     0,
      79,    80,    81,     0,     0,    82,    83,   121,     0,     0,
       0,     0,     0,     0,    78,     0,     0,    79,    80,    81,
     117,     0,    82,    83,   124,     1,     0,     0,     2,     3,
       0,     0,     0,     4,     0,     0,     5,     6,     0,     0,
       0,     7,     8,     9,    10,    11,     0,    12,    13,    14,
      15,     0,    16,    17,    18,    19,    20,     2,     3,     0,
       0,     0,     4,     0,     0,     0,     6,     0,     0,     0,
       0,     8,     9,     0,    11,     0,    12,    13,     0,    15,
       0,     0,    17,    18,    19,    20,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,     0,     0,     0,   250,
       1,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       0,     5,     6,     0,     0,   182,     7,     8,     9,    10,
      11,     0,    12,    13,    14,    15,     0,    16,    17,    18,
      19,    20,     0,     0,     1,     0,   148,     2,     3,     0,
       0,     0,     4,     0,     0,     5,     6,     0,     0,     0,
       7,     8,     9,    10,    11,     0,    12,    13,    14,    15,
       0,    16,    17,    18,    19,    20,     2,     3,     0,     0,
       0,     4,     0,     0,     0,     6,     0,     0,     0,     0,
       8,     9,     0,    11,     0,    12,    13,     0,    15,     0,
       0,    17,    18,    19,    20
};

static const yytype_int16 yycheck[] =
{
      25,    84,    55,    42,    35,     3,     3,     3,     9,    68,
      12,    13,   108,     0,     3,     6,    62,   220,   170,    67,
      51,    90,    67,    67,    75,    76,    77,    88,    53,    92,
      67,    90,   128,    67,    21,    67,    84,    88,   121,    26,
      27,   124,     3,    30,    31,    67,     3,    92,    92,    67,
       6,   134,    86,   223,     6,    92,    83,    89,    85,   262,
      84,    67,    84,    68,    76,     7,    84,    67,    69,   115,
      57,     3,    74,    75,    16,    17,    88,   108,    84,    90,
     133,   233,    78,   108,    84,   168,    83,    83,    85,   150,
     151,   152,    90,   263,    83,    86,   149,   128,   268,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    78,   270,   174,
     290,    78,    83,    78,    79,    80,    83,    84,    85,   190,
      86,    92,   185,   188,    86,   174,   306,   307,   308,   190,
     171,    83,    73,    85,   227,    87,    78,    67,   318,    35,
     320,    83,     8,    85,   324,    61,   187,    72,   183,    65,
      46,   270,    10,    11,    84,    51,    46,   276,    71,   220,
      34,    83,     3,    85,    60,    61,    62,    91,    84,    65,
      60,    61,    62,    78,   293,    65,    50,   270,    83,   272,
      85,   178,   275,   276,    14,    15,   305,    61,    84,    84,
      83,   310,    85,    84,    84,    67,   259,    86,   317,     3,
     293,   262,   237,   119,    78,   153,   154,     3,   124,    91,
     303,    84,   305,     3,     4,     5,     6,   310,    89,   115,
     155,   156,    92,   119,   317,   115,    16,    17,   124,   119,
      78,    92,   161,   162,   124,    83,    84,    85,    28,    89,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    83,
     285,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,   157,   158,   159,   160,     3,    83,    86,
      83,    83,    62,    73,    84,    84,    76,    77,    78,    67,
      84,    81,    82,    83,     3,     4,     5,     6,    89,    92,
      90,    91,    92,    92,    86,    92,    83,    16,    17,    92,
      39,    92,    84,    92,    84,   164,   163,    21,    56,    28,
     165,    30,    31,    32,    33,    34,    35,    36,    37,    38,
     166,   233,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,   167,    53,   178,     3,     4,     5,
       6,    60,   285,   124,    73,    -1,    -1,    76,    77,    78,
      16,    17,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    28,    92,    -1,    31,    32,    -1,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      -1,     3,     4,     5,     6,    51,    -1,    -1,    -1,    -1,
      56,    -1,     3,    -1,    16,    17,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    73,    -1,    -1,
      76,    77,    78,    -1,    -1,    81,    82,    83,    -1,    30,
      -1,    -1,    33,    34,    90,    -1,    92,    38,    -1,    -1,
      41,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    73,    -1,    -1,    76,    77,    78,    -1,    -1,    81,
      82,    83,    84,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      30,    -1,    -1,    33,    34,    -1,    -1,    -1,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    73,    -1,    -1,    76,    77,    78,    16,
      17,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    42,     3,     4,     5,     6,
      47,    48,    -1,    50,    -1,    52,    53,    -1,    55,    16,
      17,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    73,    -1,    -1,    76,
      77,    78,    -1,    -1,    81,    82,    83,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    73,    16,    17,    76,
      77,    78,    33,    34,    81,    82,    83,    38,    -1,    28,
      -1,    42,    -1,    -1,    -1,    -1,    47,    48,    -1,    50,
      -1,    52,    53,    -1,    55,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,     0,    -1,    73,    -1,    -1,
      76,    77,    78,    -1,    -1,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    76,    77,    78,
      91,    -1,    81,    82,    83,    30,    -1,    -1,    33,    34,
      -1,    -1,    -1,    38,    -1,    -1,    41,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    33,    34,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    47,    48,    -1,    50,    -1,    52,    53,    -1,    55,
      -1,    -1,    58,    59,    60,    61,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    29,
      30,    -1,    -1,    33,    34,    -1,    -1,    -1,    38,    -1,
      -1,    41,    42,    -1,    -1,    91,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    -1,    -1,    30,    -1,    68,    33,    34,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    33,    34,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      47,    48,    -1,    50,    -1,    52,    53,    -1,    55,    -1,
      -1,    58,    59,    60,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    33,    34,    38,    41,    42,    46,    47,    48,
      49,    50,    52,    53,    54,    55,    57,    58,    59,    60,
      61,    94,   117,   118,   125,   127,   130,   131,   132,   133,
     139,   140,     0,   117,     3,    78,    83,    92,   128,   129,
     141,   142,   143,   127,   127,     3,    90,   127,   127,   139,
     143,   144,   141,    67,    92,    68,   119,    83,    85,   142,
      90,   131,   134,   135,   136,   139,   139,   143,    84,   129,
     141,     3,     4,     5,     6,    16,    17,    28,    73,    76,
      77,    78,    81,    82,    83,    96,    97,    98,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   152,    90,   120,     3,    84,   127,   145,
     146,   147,   148,     6,    86,   134,   136,    91,   135,    92,
     136,    83,   102,   102,    83,   102,    95,   114,   136,   149,
       7,    16,    17,    83,    85,    87,   101,   102,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    68,   115,
      78,    79,    80,    76,    88,    10,    11,    12,    13,    74,
      75,    14,    15,    73,    72,    71,     8,     9,    69,   121,
     122,    83,    85,   141,   143,   150,   151,    84,    67,    67,
      84,    86,    91,   136,   149,    67,    84,    83,   143,   150,
      84,     3,    84,    99,   114,    95,     3,   114,   101,   101,
     101,   103,   103,   104,   104,   105,   105,   105,   105,   106,
     106,   107,   108,   109,   110,   111,    95,    91,     3,    31,
      32,    35,    36,    37,    43,    44,    45,    51,    56,    62,
      92,    95,   120,   123,   124,   125,   126,   127,   153,   154,
     155,   156,   158,    84,   150,     6,    86,   151,    83,    85,
      29,   147,     3,   137,   138,   141,    84,   114,   101,    67,
      84,    86,    89,    89,    92,   113,   116,    92,    89,   126,
      83,     3,    83,    95,   157,    83,    83,    92,    91,   124,
      84,    86,    84,     6,    86,    67,    92,   114,   113,   126,
      89,   126,    62,   125,   157,    92,    95,    92,    95,   157,
      86,   138,   126,    83,   157,    92,    84,    84,    84,    95,
      92,   157,   126,   126,   126,    84,   157,    92,    39,    92,
      84,   157,   126,   126,    84,   126
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    94,    95,    95,    96,    96,    96,    96,
      96,    97,    97,    97,    97,    97,    97,    97,    98,    98,
      99,    99,   100,   100,   100,   100,   100,   100,   101,   101,
     102,   102,   102,   102,   102,   102,   103,   103,   103,   103,
     104,   104,   104,   105,   105,   105,   106,   106,   106,   106,
     106,   107,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   116,
     117,   117,   119,   118,   121,   120,   122,   120,   123,   123,
     124,   124,   125,   125,   126,   126,   126,   126,   126,   126,
     127,   127,   127,   127,   127,   127,   127,   127,   128,   128,
     129,   129,   130,   130,   130,   130,   130,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   132,   132,   132,
     133,   133,   134,   134,   135,   136,   136,   136,   136,   137,
     137,   138,   139,   139,   139,   140,   141,   141,   142,   142,
     142,   142,   142,   142,   142,   143,   143,   143,   143,   144,
     144,   145,   145,   146,   146,   147,   147,   147,   148,   148,
     149,   149,   150,   150,   150,   151,   151,   151,   151,   151,
     151,   151,   152,   153,   153,   153,   154,   154,   154,   155,
     155,   155,   155,   156,   156,   156,   156,   157,   157,   158,
     158
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     1,     1,     1,     1,
       3,     1,     4,     1,     3,     3,     2,     2,     4,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     2,     2,     2,     2,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     3,     0,     4,     1,     2,
       1,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     2,     5,
       1,     1,     1,     2,     5,     1,     2,     1,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       4,     4,     3,     4,     3,     1,     2,     2,     3,     1,
       2,     1,     3,     1,     3,     2,     2,     1,     1,     3,
       1,     2,     1,     1,     2,     3,     2,     3,     3,     4,
       2,     3,     1,     3,     4,     3,     5,     7,     5,     5,
       7,     9,     8,     3,     2,     2,     3,     0,     1,     1,
       2
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
  case 4: /* expression: assignment_expression  */
#line 131 "parse.y"
                                  {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1594 "parse.tab.c"
    break;

  case 5: /* expression: expression ',' assignment_expression  */
#line 132 "parse.y"
                                           {(yyval.astnode_p) = new_astnode_binop(',', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1600 "parse.tab.c"
    break;

  case 6: /* primary_expression: IDENT  */
#line 135 "parse.y"
                          {(yyval.astnode_p) = new_astnode_ident(IDENT_NODE, (yyvsp[0].stringInfo).string_literal);}
#line 1606 "parse.tab.c"
    break;

  case 7: /* primary_expression: NUMBER  */
#line 136 "parse.y"
             {(yyval.astnode_p) = new_astnode_num(NUMBER_NODE, (yyvsp[0].numInfo));}
#line 1612 "parse.tab.c"
    break;

  case 8: /* primary_expression: CHARLIT  */
#line 137 "parse.y"
              { 
                struct numinfo *temp = (struct numinfo*) malloc(sizeof (struct numinfo));
                temp->meta = UNSIGNED_INT;
                temp->value.int_val = (yyvsp[0].char_literal);
                (yyval.astnode_p) = new_astnode_num(NUMBER_NODE, *temp); 
              }
#line 1623 "parse.tab.c"
    break;

  case 9: /* primary_expression: STRING  */
#line 143 "parse.y"
             {(yyval.astnode_p) = new_astnode_string(STRING_NODE, (yyvsp[0].stringInfo).string_literal);}
#line 1629 "parse.tab.c"
    break;

  case 10: /* primary_expression: '(' expression ')'  */
#line 144 "parse.y"
                       {(yyval.astnode_p) = (yyvsp[-1].astnode_p);}
#line 1635 "parse.tab.c"
    break;

  case 11: /* postfix_expression: primary_expression  */
#line 147 "parse.y"
                                       {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1641 "parse.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 148 "parse.y"
                                           { // E1[E2] is identical to (*((E1)+(E2))) 
                                            union astnode *astnode_temp = new_astnode_binop('+', (yyvsp[-3].astnode_p), (yyvsp[-1].astnode_p));
                                            (yyval.astnode_p) = new_astnode_unop('*', astnode_temp);                           
    }
#line 1650 "parse.tab.c"
    break;

  case 13: /* postfix_expression: function_call  */
#line 152 "parse.y"
                    {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1656 "parse.tab.c"
    break;

  case 14: /* postfix_expression: postfix_expression '.' IDENT  */
#line 153 "parse.y"
                                   {union astnode *astnode_ident = new_astnode_ident(IDENT_NODE, (yyvsp[0].stringInfo).string_literal);
                                    (yyval.astnode_p) = new_astnode_binop('.', (yyvsp[-2].astnode_p), astnode_ident); 
    }
#line 1664 "parse.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression INDSEL IDENT  */
#line 156 "parse.y"
                                      { // E1->E2 is identical to (*E1).E2
                                      union astnode *astnode_temp = new_astnode_unop('*', (yyvsp[-2].astnode_p));
                                      union astnode *astnode_ident = new_astnode_ident(IDENT_NODE, (yyvsp[0].stringInfo).string_literal);
                                      (yyval.astnode_p) = new_astnode_binop('.', astnode_temp, astnode_ident);
    }
#line 1674 "parse.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression PLUSPLUS  */
#line 161 "parse.y"
                                  {(yyval.astnode_p) = new_astnode_unop(PLUSPLUS, (yyvsp[-1].astnode_p));}
#line 1680 "parse.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression MINUSMINUS  */
#line 162 "parse.y"
                                    {(yyval.astnode_p) = new_astnode_unop(MINUSMINUS, (yyvsp[-1].astnode_p));}
#line 1686 "parse.tab.c"
    break;

  case 18: /* function_call: postfix_expression '(' argument_expression_list ')'  */
#line 167 "parse.y"
                                                                     {(yyval.astnode_p) = new_astnode_func((yyvsp[-3].astnode_p), (yyvsp[-1].astnode_p));}
#line 1692 "parse.tab.c"
    break;

  case 19: /* function_call: postfix_expression '(' ')'  */
#line 168 "parse.y"
                                 {(yyval.astnode_p) = new_astnode_func((yyvsp[-2].astnode_p), NULL);}
#line 1698 "parse.tab.c"
    break;

  case 20: /* argument_expression_list: assignment_expression  */
#line 171 "parse.y"
                                                {
                                                union astnode *head = new_astnode_arg((yyvsp[0].astnode_p));
                                                (yyval.astnode_p) = init_list(head);
                                                }
#line 1707 "parse.tab.c"
    break;

  case 21: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 175 "parse.y"
                                                         {(yyval.astnode_p) = append_arg((yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1713 "parse.tab.c"
    break;

  case 22: /* unary_operator: '&'  */
#line 178 "parse.y"
                    {(yyval.operator) = '&';}
#line 1719 "parse.tab.c"
    break;

  case 23: /* unary_operator: '*'  */
#line 179 "parse.y"
          {(yyval.operator) = '*';}
#line 1725 "parse.tab.c"
    break;

  case 24: /* unary_operator: '+'  */
#line 180 "parse.y"
          {(yyval.operator) = '+';}
#line 1731 "parse.tab.c"
    break;

  case 25: /* unary_operator: '-'  */
#line 181 "parse.y"
          {(yyval.operator) = '-';}
#line 1737 "parse.tab.c"
    break;

  case 26: /* unary_operator: '~'  */
#line 182 "parse.y"
          {(yyval.operator) = '~';}
#line 1743 "parse.tab.c"
    break;

  case 27: /* unary_operator: '!'  */
#line 183 "parse.y"
          {(yyval.operator) = '!';}
#line 1749 "parse.tab.c"
    break;

  case 28: /* cast_expression: unary_expression  */
#line 186 "parse.y"
                                  {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1755 "parse.tab.c"
    break;

  case 29: /* cast_expression: '(' type_name ')' cast_expression  */
#line 187 "parse.y"
                                        {(yyval.astnode_p) = new_astnode_binop('\0', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1761 "parse.tab.c"
    break;

  case 30: /* unary_expression: postfix_expression  */
#line 190 "parse.y"
                                     {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1767 "parse.tab.c"
    break;

  case 31: /* unary_expression: PLUSPLUS unary_expression  */
#line 191 "parse.y"
                                { 
                                union astnode* one = astnode_one();
                                (yyval.astnode_p) = new_astnode_binop(PLUSEQ, (yyvsp[0].astnode_p), one);
    }
#line 1776 "parse.tab.c"
    break;

  case 32: /* unary_expression: MINUSMINUS unary_expression  */
#line 195 "parse.y"
                                  { 
                                union astnode* one = astnode_one();
                                (yyval.astnode_p) = new_astnode_binop(MINUSEQ, (yyvsp[0].astnode_p), one);
    }
#line 1785 "parse.tab.c"
    break;

  case 33: /* unary_expression: unary_operator cast_expression  */
#line 199 "parse.y"
                                     {(yyval.astnode_p) = new_astnode_unop((yyvsp[-1].operator), (yyvsp[0].astnode_p));}
#line 1791 "parse.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF unary_expression  */
#line 200 "parse.y"
                              {(yyval.astnode_p) = new_astnode_unop(SIZEOF, (yyvsp[0].astnode_p));}
#line 1797 "parse.tab.c"
    break;

  case 35: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 201 "parse.y"
                               {(yyval.astnode_p) = new_astnode_unop(SIZEOF, (yyvsp[-1].astnode_p));}
#line 1803 "parse.tab.c"
    break;

  case 36: /* multiplicative_expression: cast_expression  */
#line 204 "parse.y"
                                           {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1809 "parse.tab.c"
    break;

  case 37: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 205 "parse.y"
                                                    {(yyval.astnode_p) = new_astnode_binop('*', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1815 "parse.tab.c"
    break;

  case 38: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 206 "parse.y"
                                                    {(yyval.astnode_p) = new_astnode_binop('/', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1821 "parse.tab.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 207 "parse.y"
                                                    {(yyval.astnode_p) = new_astnode_binop('%', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1827 "parse.tab.c"
    break;

  case 40: /* additive_expression: multiplicative_expression  */
#line 210 "parse.y"
                                               {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1833 "parse.tab.c"
    break;

  case 41: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 211 "parse.y"
                                                        {(yyval.astnode_p) = new_astnode_binop('+', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1839 "parse.tab.c"
    break;

  case 42: /* additive_expression: additive_expression '_' multiplicative_expression  */
#line 212 "parse.y"
                                                        {(yyval.astnode_p) = new_astnode_binop('-', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1845 "parse.tab.c"
    break;

  case 43: /* shift_expression: additive_expression  */
#line 215 "parse.y"
                                      {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1851 "parse.tab.c"
    break;

  case 44: /* shift_expression: shift_expression SHL additive_expression  */
#line 216 "parse.y"
                                               {(yyval.astnode_p) = new_astnode_binop(SHL, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1857 "parse.tab.c"
    break;

  case 45: /* shift_expression: shift_expression SHR additive_expression  */
#line 217 "parse.y"
                                               {(yyval.astnode_p) = new_astnode_binop(SHR, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1863 "parse.tab.c"
    break;

  case 46: /* relational_expression: shift_expression  */
#line 220 "parse.y"
                                        {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1869 "parse.tab.c"
    break;

  case 47: /* relational_expression: relational_expression '<' shift_expression  */
#line 221 "parse.y"
                                                 {(yyval.astnode_p) = new_astnode_binop('<', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1875 "parse.tab.c"
    break;

  case 48: /* relational_expression: relational_expression '>' shift_expression  */
#line 222 "parse.y"
                                                 {(yyval.astnode_p) = new_astnode_binop('>', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1881 "parse.tab.c"
    break;

  case 49: /* relational_expression: relational_expression LTEQ shift_expression  */
#line 223 "parse.y"
                                                  {(yyval.astnode_p) = new_astnode_binop(LTEQ, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1887 "parse.tab.c"
    break;

  case 50: /* relational_expression: relational_expression GTEQ shift_expression  */
#line 224 "parse.y"
                                                  {(yyval.astnode_p) = new_astnode_binop(GTEQ, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1893 "parse.tab.c"
    break;

  case 51: /* equality_expression: relational_expression  */
#line 227 "parse.y"
                                           {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1899 "parse.tab.c"
    break;

  case 52: /* equality_expression: equality_expression EQEQ relational_expression  */
#line 228 "parse.y"
                                                     {(yyval.astnode_p) = new_astnode_binop(EQEQ, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1905 "parse.tab.c"
    break;

  case 53: /* equality_expression: equality_expression NOTEQ relational_expression  */
#line 229 "parse.y"
                                                      {(yyval.astnode_p) = new_astnode_binop(NOTEQ, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1911 "parse.tab.c"
    break;

  case 54: /* AND_expression: equality_expression  */
#line 232 "parse.y"
                                    {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1917 "parse.tab.c"
    break;

  case 55: /* AND_expression: AND_expression '&' equality_expression  */
#line 233 "parse.y"
                                             {(yyval.astnode_p) = new_astnode_binop('&', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1923 "parse.tab.c"
    break;

  case 56: /* exclusive_OR_expression: AND_expression  */
#line 236 "parse.y"
                                        {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1929 "parse.tab.c"
    break;

  case 57: /* exclusive_OR_expression: exclusive_OR_expression '^' AND_expression  */
#line 237 "parse.y"
                                                 {(yyval.astnode_p) = new_astnode_binop('^', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1935 "parse.tab.c"
    break;

  case 58: /* inclusive_OR_expression: exclusive_OR_expression  */
#line 240 "parse.y"
                                                 {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1941 "parse.tab.c"
    break;

  case 59: /* inclusive_OR_expression: inclusive_OR_expression '|' exclusive_OR_expression  */
#line 241 "parse.y"
                                                          {(yyval.astnode_p) = new_astnode_binop('|', (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1947 "parse.tab.c"
    break;

  case 60: /* logical_AND_expression: inclusive_OR_expression  */
#line 244 "parse.y"
                                                {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1953 "parse.tab.c"
    break;

  case 61: /* logical_AND_expression: logical_AND_expression LOGAND inclusive_OR_expression  */
#line 245 "parse.y"
                                                            {(yyval.astnode_p) = new_astnode_binop(LOGAND, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1959 "parse.tab.c"
    break;

  case 62: /* logical_OR_expression: logical_AND_expression  */
#line 248 "parse.y"
                                              {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1965 "parse.tab.c"
    break;

  case 63: /* logical_OR_expression: logical_OR_expression LOGOR logical_AND_expression  */
#line 249 "parse.y"
                                                         {(yyval.astnode_p) = new_astnode_binop(LOGOR, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1971 "parse.tab.c"
    break;

  case 64: /* conditional_expression: logical_OR_expression  */
#line 252 "parse.y"
                                              {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1977 "parse.tab.c"
    break;

  case 65: /* conditional_expression: logical_OR_expression '?' expression ':' conditional_expression  */
#line 253 "parse.y"
                                                                      {(yyval.astnode_p) = new_astnode_ternop('?', ':', (yyvsp[-4].astnode_p), (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1983 "parse.tab.c"
    break;

  case 66: /* assignment_expression: conditional_expression  */
#line 256 "parse.y"
                                              {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 1989 "parse.tab.c"
    break;

  case 67: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 257 "parse.y"
                                                                 {(yyval.astnode_p) = new_astnode_binop((yyvsp[-1].operator), (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1995 "parse.tab.c"
    break;

  case 68: /* assignment_operator: '='  */
#line 260 "parse.y"
                         {(yyval.operator) = '=';}
#line 2001 "parse.tab.c"
    break;

  case 69: /* assignment_operator: TIMESEQ  */
#line 261 "parse.y"
              {(yyval.operator) = TIMESEQ;}
#line 2007 "parse.tab.c"
    break;

  case 70: /* assignment_operator: DIVEQ  */
#line 262 "parse.y"
            {(yyval.operator) = DIVEQ;}
#line 2013 "parse.tab.c"
    break;

  case 71: /* assignment_operator: MODEQ  */
#line 263 "parse.y"
            {(yyval.operator) = MODEQ;}
#line 2019 "parse.tab.c"
    break;

  case 72: /* assignment_operator: PLUSEQ  */
#line 264 "parse.y"
             {(yyval.operator) = PLUSEQ;}
#line 2025 "parse.tab.c"
    break;

  case 73: /* assignment_operator: MINUSEQ  */
#line 265 "parse.y"
              {(yyval.operator) = MINUSEQ;}
#line 2031 "parse.tab.c"
    break;

  case 74: /* assignment_operator: SHLEQ  */
#line 266 "parse.y"
            {(yyval.operator) = SHLEQ;}
#line 2037 "parse.tab.c"
    break;

  case 75: /* assignment_operator: SHREQ  */
#line 267 "parse.y"
            {(yyval.operator) = SHREQ;}
#line 2043 "parse.tab.c"
    break;

  case 76: /* assignment_operator: ANDEQ  */
#line 268 "parse.y"
            {(yyval.operator) = ANDEQ;}
#line 2049 "parse.tab.c"
    break;

  case 77: /* assignment_operator: XOREQ  */
#line 269 "parse.y"
            {(yyval.operator) = XOREQ;}
#line 2055 "parse.tab.c"
    break;

  case 78: /* assignment_operator: OREQ  */
#line 270 "parse.y"
           {(yyval.operator) = OREQ;}
#line 2061 "parse.tab.c"
    break;

  case 80: /* declaration_or_fndef: declaration  */
#line 276 "parse.y"
                                  { 
                                    symbol *temp_sym = (yyvsp[0].symbol_p); 
                                    while (temp_sym) {
                                        union astnode *ptr = merging(temp_sym);
                                        /*printf("ret type is %d\n", $1->type_rep->fndef.ret_type->generic.type);
                                        printf("pointer parent is %d\n", $1->type_rep->fndef.ret_type->ptr.parent->generic.type);
                                        printf("ret type of pointed is %d\n", $1->type_rep->fndef.ret_type->ptr.parent->fndef.ret_type->generic.type);
                                        */
                                        printAST(ptr, 0);
                                        temp_sym = temp_sym->next; 
                                    }
                                  }
#line 2078 "parse.tab.c"
    break;

  case 81: /* declaration_or_fndef: function_definition  */
#line 288 "parse.y"
                          {}
#line 2084 "parse.tab.c"
    break;

  case 82: /* $@1: %empty  */
#line 291 "parse.y"
                                                       {    
                                                            if (!current->scope_fileName) {
                                                                current->scope_fileName = report.fileName;
                                                            }
                                                            modify_symbol_type((yyvsp[0].symbol_p), FUNCTION_SYMBOL);
                                                            
                                                            // add decspecs to declaration symbol
                                                            symbol *temp = add_astnode_to_symbol((yyvsp[0].symbol_p), (yyvsp[-1].astnode_p));
                                                            
                                                            if ((yyvsp[-1].astnode_p)->decspec.s_class == UNKNOWN_CLASS) {
                                                                (yyvsp[-1].astnode_p)->decspec.s_class = EXTERN_CLASS;
                                                            }

                                                            union astnode *ptr = merging(temp);

                                                            // if inserting symbol was successful
                                                            if (!insert_symbol(current->symbolTables[OTHER], temp)) {
                                                                // ERROR
                                                               fprintf(stderr, "Error: Symbol for ident %s declared in %s:%d, was not inserted into symbol table\n", temp->key, report.fileName, report.lineNum); 
                                                            }
                                                            // create astnode ptr that contains a pointer to the symbol (for printing purposes)
                                                            //union astnode *ptr = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, temp);
                                                            printAST(ptr, 0);         
                                                        }
#line 2113 "parse.tab.c"
    break;

  case 84: /* $@2: %empty  */
#line 318 "parse.y"
                        {                 
                            if (current->name == FUNCTION_SCOPE) {
                                if (!push_scope(BLOCK_SCOPE)) { // if push_scope returns 0 -> ERROR
                                fprintf(stderr, "Error: Cannot create block scope. Current scope is %d\n", current->name);
                                }
                            } else {
                                if (!push_scope(FUNCTION_SCOPE)) { // if push_scope returns 0 -> ERROR
                                    fprintf(stderr, "Error: Cannot create function scope. Current scope is %d\n", current->name);
                                }
                            }
                        }
#line 2129 "parse.tab.c"
    break;

  case 85: /* compound_statement: '{' $@2 '}'  */
#line 329 "parse.y"
        { pop_scope(); }
#line 2135 "parse.tab.c"
    break;

  case 86: /* $@3: %empty  */
#line 330 "parse.y"
      {                 
        if (current->name == FUNCTION_SCOPE) {
            if (!push_scope(BLOCK_SCOPE)) { // if push_scope returns 0 -> ERROR
            fprintf(stderr, "Error: Cannot create block scope. Current scope is %d\n", current->name);
            }
        } else {
            if (!push_scope(FUNCTION_SCOPE)) { // if push_scope returns 0 -> ERROR
                fprintf(stderr, "Error: Cannot create function scope. Current scope is %d\n", current->name);
            }
        }
      }
#line 2151 "parse.tab.c"
    break;

  case 87: /* compound_statement: '{' $@3 decl_or_stmt_list '}'  */
#line 341 "parse.y"
                          {
                            union astnode *temp = (yyvsp[-1].astnode_p);
                            while ((temp->generic.type == LIST_NODE) && temp->ast_list.prev) { // traverse list to get back to head
                                temp = temp->ast_list.prev;
                            }
                            (yyval.astnode_p) = temp;
                            if (current->name != BLOCK_SCOPE) {
                                printAST(temp, 0);
                            } 
                            pop_scope(); 
                          }
#line 2167 "parse.tab.c"
    break;

  case 88: /* decl_or_stmt_list: decl_or_stmt  */
#line 355 "parse.y"
                                 {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2173 "parse.tab.c"
    break;

  case 89: /* decl_or_stmt_list: decl_or_stmt_list decl_or_stmt  */
#line 356 "parse.y"
                                     {
                                        union astnode *temp = append_astnode_list((yyvsp[-1].astnode_p), (yyvsp[0].astnode_p));
                                        if (temp->ast_list.prev) { // not head of list
                                            (yyval.astnode_p) = temp;
                                        }
                                    }
#line 2184 "parse.tab.c"
    break;

  case 90: /* decl_or_stmt: declaration  */
#line 364 "parse.y"
                           {(yyval.astnode_p) = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, (yyvsp[0].symbol_p));}
#line 2190 "parse.tab.c"
    break;

  case 91: /* decl_or_stmt: statement  */
#line 365 "parse.y"
                {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2196 "parse.tab.c"
    break;

  case 93: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 369 "parse.y"
                                                      {  
                                                        if (!current->scope_fileName) { // if fileName is not set, set it to report.fileName
                                                            current->scope_fileName = report.fileName;
                                                        }
                                                        symbol *temp_sym = (yyvsp[-1].symbol_p); 
                                                        while (temp_sym) {
                                                            // add decspecs to declaration symbol
                                                            symbol *temp = add_astnode_to_symbol(temp_sym, (yyvsp[-2].astnode_p));

                                                            if ((yyvsp[-2].astnode_p)->decspec.s_class == UNKNOWN_CLASS) {
                                                                if (current->name == FUNCTION_SCOPE) {
                                                                    (yyvsp[-2].astnode_p)->decspec.s_class = AUTO_CLASS;
                                                                } else {
                                                                    (yyvsp[-2].astnode_p)->decspec.s_class = EXTERN_CLASS;
                                                                }
                                                            }
                                                            
                                                            if ((yyvsp[-2].astnode_p)->decspec.s_type) {
                                                                if ((yyvsp[-2].astnode_p)->decspec.s_type->scalar.scalarType == SIGNED_TYPE || (yyvsp[-2].astnode_p)->decspec.s_type->scalar.scalarType == UNSIGNED_TYPE) {
                                                                    if ((!((yyvsp[-2].astnode_p)->decspec.prev) && !((yyvsp[-2].astnode_p)->decspec.next))) { // if the dec spec is ONLY signed or unsigned
                                                                        union astnode *int_type = new_astnode_scalar(SCALAR_NODE, INT_TYPE);
                                                                        int_type = new_astnode_declaration_spec(DECSPEC_NODE, int_type, NONE_TYPE, UNKNOWN_CLASS);
                                                                        append_astnode_list((yyvsp[-2].astnode_p), int_type);
                                                                    }
                                                                }
                                                            } else {
                                                                if ((yyvsp[-2].astnode_p)->decspec.q_type) {
                                                                    union astnode *int_type = new_astnode_scalar(SCALAR_NODE, INT_TYPE);
                                                                    modify_astnode_declaration_spec((yyvsp[-2].astnode_p), int_type, NONE_TYPE, UNKNOWN_CLASS);
                                                                }
                                                            }
                                                            
                                                            //printf("ret type of func is %d\n", $2->type_rep->fndef.ret_type->generic.type);

                                                            if (!insert_symbol(current->symbolTables[OTHER], temp)) {
                                                                // ERROR
                                                                fprintf(stderr, "Error: Symbol for ident %s declared in %s:%d, was not inserted into symbol table\n", temp->key, report.fileName, report.lineNum); 
                                                                temp = contains_symbol(current->symbolTables[OTHER], temp->key);
                                                            }
                                    
                                                            if (current->name == FUNCTION_SCOPE || current->name == BLOCK_SCOPE) {
                                                                union astnode *ptr = merging(temp);
                                                                if (current->name == BLOCK_SCOPE) {
                                                                    printAST(ptr, 0);
                                                                }
                                                            }
                                                            
                                                            temp_sym = temp_sym->next;
                                                            
                                                            (yyval.symbol_p) = (yyvsp[-1].symbol_p); 
                                                        }
                                                      }
#line 2253 "parse.tab.c"
    break;

  case 94: /* statement: expression-statement  */
#line 423 "parse.y"
                                {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2259 "parse.tab.c"
    break;

  case 95: /* statement: labeled-statement  */
#line 424 "parse.y"
                        {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2265 "parse.tab.c"
    break;

  case 96: /* statement: compound_statement  */
#line 425 "parse.y"
                         {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2271 "parse.tab.c"
    break;

  case 97: /* statement: selection-statement  */
#line 426 "parse.y"
                          {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2277 "parse.tab.c"
    break;

  case 98: /* statement: iteration-statement  */
#line 427 "parse.y"
                          {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2283 "parse.tab.c"
    break;

  case 99: /* statement: jump-statement  */
#line 428 "parse.y"
                     {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2289 "parse.tab.c"
    break;

  case 100: /* declaration_specifiers: storage_class_specifier  */
#line 431 "parse.y"
                                                {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2295 "parse.tab.c"
    break;

  case 101: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 432 "parse.y"
                                                     { 
                                                        if ((yyvsp[0].astnode_p)->decspec.s_class) { // if there is another storage class declared
                                                            fprintf(stderr, "Error: cannot have declaration with more than one storage class\n");
                                                        } else {
                                                            // Note: if there are already s_class and s_type, fields do not get overwritten
                                                            (yyval.astnode_p) = modify_astnode_declaration_spec((yyvsp[0].astnode_p), NULL, NONE_TYPE, (yyvsp[-1].astnode_p)->decspec.s_class); // the second decspec node is returned because we want to continue parsing dec specs
                                                        }
                                                    }
#line 2308 "parse.tab.c"
    break;

  case 102: /* declaration_specifiers: type_specifier  */
#line 440 "parse.y"
                     {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2314 "parse.tab.c"
    break;

  case 103: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 441 "parse.y"
                                            {
                                                append_astnode_list((yyvsp[-1].astnode_p), (yyvsp[0].astnode_p)); 
                                                if ((yyvsp[-1].astnode_p)->decspec.prev) { // if first in list
                                                    (yyval.astnode_p) = (yyvsp[-1].astnode_p);
                                                }
                                            }
#line 2325 "parse.tab.c"
    break;

  case 104: /* declaration_specifiers: type_qualifier  */
#line 447 "parse.y"
                     {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2331 "parse.tab.c"
    break;

  case 105: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 448 "parse.y"
                                            {
                                                if ((yyvsp[0].astnode_p)->decspec.s_type) {
                                                    (yyval.astnode_p) = modify_astnode_declaration_spec((yyvsp[0].astnode_p), NULL, (yyvsp[-1].astnode_p)->decspec.q_type, UNKNOWN_CLASS); // see note above
                                                } else if ((yyvsp[0].astnode_p)->decspec.s_class) { 
                                                    fprintf(stderr, "Error:  must declare storage class before type qualifier\n");
                                                } else if ((yyvsp[0].astnode_p)->decspec.q_type) {
                                                    fprintf(stderr, "Error:  more than one type qualifier not implemented\n");
                                                }
                                            }
#line 2345 "parse.tab.c"
    break;

  case 108: /* init_declarator_list: init_declarator  */
#line 461 "parse.y"
                                      {(yyval.symbol_p) = (yyvsp[0].symbol_p);}
#line 2351 "parse.tab.c"
    break;

  case 109: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 462 "parse.y"
                                               {(yyval.symbol_p) = append_symbol_list((yyvsp[-2].symbol_p), (yyvsp[0].symbol_p));}
#line 2357 "parse.tab.c"
    break;

  case 110: /* init_declarator: declarator  */
#line 465 "parse.y"
                            {(yyval.symbol_p) = (yyvsp[0].symbol_p);}
#line 2363 "parse.tab.c"
    break;

  case 112: /* storage_class_specifier: TYPEDEF  */
#line 469 "parse.y"
                                 {(yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, NULL, NONE_TYPE, TYPEDEF_CLASS);}
#line 2369 "parse.tab.c"
    break;

  case 113: /* storage_class_specifier: EXTERN  */
#line 470 "parse.y"
             {(yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, NULL, NONE_TYPE, EXTERN_CLASS);}
#line 2375 "parse.tab.c"
    break;

  case 114: /* storage_class_specifier: STATIC  */
#line 471 "parse.y"
             {(yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, NULL, NONE_TYPE, STATIC_CLASS);}
#line 2381 "parse.tab.c"
    break;

  case 115: /* storage_class_specifier: AUTO  */
#line 472 "parse.y"
           {(yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, NULL, NONE_TYPE, AUTO_CLASS);}
#line 2387 "parse.tab.c"
    break;

  case 116: /* storage_class_specifier: REGISTER  */
#line 473 "parse.y"
               {(yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, NULL, NONE_TYPE, REGISTER_CLASS);}
#line 2393 "parse.tab.c"
    break;

  case 117: /* type_specifier: VOID  */
#line 476 "parse.y"
                     {
                        union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, VOID_TYPE);
                        (yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS); 
                     }
#line 2402 "parse.tab.c"
    break;

  case 118: /* type_specifier: CHAR  */
#line 480 "parse.y"
           {
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, CHAR_TYPE);
                (yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS); 
            }
#line 2411 "parse.tab.c"
    break;

  case 119: /* type_specifier: SHORT  */
#line 484 "parse.y"
            {
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, SHORT_TYPE);
                (yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS); 
            }
#line 2420 "parse.tab.c"
    break;

  case 120: /* type_specifier: INT  */
#line 488 "parse.y"
          { 
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, INT_TYPE);
                (yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS); 
           }
#line 2429 "parse.tab.c"
    break;

  case 121: /* type_specifier: LONG  */
#line 492 "parse.y"
           {
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, LONG_TYPE);
                (yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS); 
           }
#line 2438 "parse.tab.c"
    break;

  case 122: /* type_specifier: FLOAT  */
#line 496 "parse.y"
            {
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, FLOAT_TYPE);
                (yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS);
            }
#line 2447 "parse.tab.c"
    break;

  case 123: /* type_specifier: DOUBLE  */
#line 500 "parse.y"
             {
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, DOUBLE_TYPE);
                (yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS);
             }
#line 2456 "parse.tab.c"
    break;

  case 124: /* type_specifier: SIGNED  */
#line 504 "parse.y"
             {
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, SIGNED_TYPE);
                (yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS);
             }
#line 2465 "parse.tab.c"
    break;

  case 125: /* type_specifier: UNSIGNED  */
#line 508 "parse.y"
               {
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, UNSIGNED_TYPE);
                (yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS);
               }
#line 2474 "parse.tab.c"
    break;

  case 135: /* specifier_qualifier_list: type_specifier  */
#line 539 "parse.y"
                                         {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2480 "parse.tab.c"
    break;

  case 136: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 540 "parse.y"
                                              {
                                                append_astnode_list((yyvsp[-1].astnode_p), (yyvsp[0].astnode_p));
                                                if ((yyvsp[-1].astnode_p)->decspec.prev) { // if first in list
                                                    (yyval.astnode_p) = (yyvsp[-1].astnode_p);
                                                }
                                              }
#line 2491 "parse.tab.c"
    break;

  case 137: /* specifier_qualifier_list: type_qualifier  */
#line 546 "parse.y"
                     {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2497 "parse.tab.c"
    break;

  case 138: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 547 "parse.y"
                                              {
                                                append_astnode_list((yyvsp[-1].astnode_p), (yyvsp[0].astnode_p));
                                                if ((yyvsp[-1].astnode_p)->decspec.prev) { // if first in list
                                                    (yyval.astnode_p) = (yyvsp[-1].astnode_p);
                                                }
                                              }
#line 2508 "parse.tab.c"
    break;

  case 141: /* struct_declarator: declarator  */
#line 559 "parse.y"
                              {(yyval.symbol_p) = (yyvsp[0].symbol_p);}
#line 2514 "parse.tab.c"
    break;

  case 142: /* type_qualifier: CONST  */
#line 562 "parse.y"
                      {(yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, NULL, CONST_TYPE, UNKNOWN_CLASS);}
#line 2520 "parse.tab.c"
    break;

  case 143: /* type_qualifier: RESTRICT  */
#line 563 "parse.y"
               {(yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, NULL, RESTRICT_TYPE, UNKNOWN_CLASS);}
#line 2526 "parse.tab.c"
    break;

  case 144: /* type_qualifier: VOLATILE  */
#line 564 "parse.y"
               {(yyval.astnode_p) = new_astnode_declaration_spec(DECSPEC_NODE, NULL, VOLATILE_TYPE, UNKNOWN_CLASS);}
#line 2532 "parse.tab.c"
    break;

  case 146: /* declarator: direct_declarator  */
#line 570 "parse.y"
                              {(yyval.symbol_p) = (yyvsp[0].symbol_p);}
#line 2538 "parse.tab.c"
    break;

  case 147: /* declarator: pointer direct_declarator  */
#line 571 "parse.y"
                                {   
                                    if ((yyvsp[0].symbol_p)->type_rep && (yyvsp[0].symbol_p)->type_rep->generic.type == ARRAY_NODE) {
                                        (yyvsp[-1].astnode_p)->ptr.parent = (yyvsp[0].symbol_p)->type_rep;
                                        (yyval.symbol_p) = add_astnode_to_symbol((yyvsp[0].symbol_p), (yyvsp[-1].astnode_p));
                                    } else {
                                        (yyval.symbol_p) = add_astnode_to_symbol((yyvsp[0].symbol_p), (yyvsp[-1].astnode_p));
                                    }
                                }
#line 2551 "parse.tab.c"
    break;

  case 148: /* direct_declarator: IDENT  */
#line 590 "parse.y"
                         { //symbol type defaults to VARIABLE
                            if (!report.lineNum) { 
                                report.lineNum++; // bc lineNum starts off as 0
                            }
                            (yyval.symbol_p) = new_symbol((yyvsp[0].stringInfo).string_literal, OTHER, NULL, NULL, VARIABLE_SYMBOL); // IS THIS RIGHT
                          }
#line 2562 "parse.tab.c"
    break;

  case 149: /* direct_declarator: '(' declarator ')'  */
#line 596 "parse.y"
                         {
                            if ((yyvsp[-1].symbol_p)->type_rep && (yyvsp[-1].symbol_p)->type_rep->generic.type == POINTER_NODE) {
                                union astnode *parent = new_astnode_fndef(FUNCTION_DEF_NODE, NULL, NULL); // this is not always the case -- BAD
                                union astnode *ptr = new_astnode_fndef(FUNCTION_DEF_NODE, NULL, (yyvsp[-1].symbol_p)->type_rep); // set ret type of function to be pointer
                                (yyvsp[-1].symbol_p)->type_rep->ptr.parent = parent; // change ptr to point to fndef of unknown ret type
                                (yyvsp[-1].symbol_p)->type_rep = ptr; // change symbol type_rep to be fndef returning ptr to fndef
                            } else if ((yyvsp[-1].symbol_p)->type_rep && (yyvsp[-1].symbol_p)->type_rep->generic.type == ARRAY_NODE) {
                                union astnode *ptr = new_astnode_fndef(FUNCTION_DEF_NODE, NULL, (yyvsp[-1].symbol_p)->type_rep); // set ret type of function to be pointer
                                ptr->fndef.ret_type = (yyvsp[-1].symbol_p)->type_rep; // set return type = array
                                (yyvsp[-1].symbol_p)->type_rep = ptr; // change symbol type_rep to be fndef returning an array
                            }
                            (yyval.symbol_p) = (yyvsp[-1].symbol_p);
                        
                        }
#line 2581 "parse.tab.c"
    break;

  case 150: /* direct_declarator: direct_declarator '(' parameter-type-list ')'  */
#line 615 "parse.y"
                                                   {                                                // *** Optional -- Not Implemented ***
                                                        union astnode *ptr = new_astnode_fndef(FUNCTION_DEF_NODE, NULL, NULL);
                                                        if ((yyvsp[-3].symbol_p)->type_rep && (yyvsp[-3].symbol_p)->type_rep->generic.type == FUNCTION_DEF_NODE) {
                                                            modify_astnode_fndef((yyvsp[-3].symbol_p)->type_rep, NULL, ptr);
                                                            //printf("ret type of func is %d\n", $1->type_rep->fndef.ret_type->generic.type);
                                                        } else if ((yyvsp[-3].symbol_p)->type_rep && (yyvsp[-3].symbol_p)->type_rep->generic.type == POINTER_NODE) {
                                                            ptr->fndef.ret_type = (yyvsp[-3].symbol_p)->type_rep; //set return type of function to pointer
                                                            add_astnode_to_symbol((yyvsp[-3].symbol_p), ptr); // set function as symbol type_rep
                                                        } else {
                                                            add_astnode_to_symbol((yyvsp[-3].symbol_p), ptr);
                                                        }

                                                        symbol *sym; 
                                                        if ((yyvsp[-3].symbol_p)->sym_type == VARIABLE_SYMBOL) {
                                                            sym = modify_symbol_type((yyvsp[-3].symbol_p), FUNCTION_SYMBOL);
                                                        } 
                                                        (yyval.symbol_p) = sym;
                                                    }
#line 2604 "parse.tab.c"
    break;

  case 151: /* direct_declarator: direct_declarator '(' identifier-list ')'  */
#line 633 "parse.y"
                                                { // *** Optional -- Not Implemented ***
                                                    union astnode *ptr = new_astnode_fndef(FUNCTION_DEF_NODE, NULL, NULL);
                                                    if ((yyvsp[-3].symbol_p)->type_rep && (yyvsp[-3].symbol_p)->type_rep->generic.type == FUNCTION_DEF_NODE) {
                                                        modify_astnode_fndef((yyvsp[-3].symbol_p)->type_rep, NULL, ptr);
                                                        //printf("ret type of func is %d\n", $1->type_rep->fndef.ret_type->generic.type);
                                                    } else if ((yyvsp[-3].symbol_p)->type_rep && (yyvsp[-3].symbol_p)->type_rep->generic.type == POINTER_NODE) {
                                                        ptr->fndef.ret_type = (yyvsp[-3].symbol_p)->type_rep; //set return type of function to pointer
                                                        add_astnode_to_symbol((yyvsp[-3].symbol_p), ptr); // set function as symbol type_rep
                                                    } else {
                                                        add_astnode_to_symbol((yyvsp[-3].symbol_p), ptr);
                                                    }

                                                    symbol *sym; 
                                                    if ((yyvsp[-3].symbol_p)->sym_type == VARIABLE_SYMBOL) {
                                                        sym = modify_symbol_type((yyvsp[-3].symbol_p), FUNCTION_SYMBOL);
                                                    } 
                                                    (yyval.symbol_p) = sym;
                                                }
#line 2627 "parse.tab.c"
    break;

  case 152: /* direct_declarator: direct_declarator '[' ']'  */
#line 651 "parse.y"
                                {
                                    union astnode *arr = new_astnode_array(ARRAY_NODE, (yyvsp[-2].symbol_p)->dec_specs, -1); // -1 = no size specified
                                    if ((yyvsp[-2].symbol_p)->type_rep && (yyvsp[-2].symbol_p)->type_rep->generic.type == ARRAY_NODE) { 
                                        (yyvsp[-2].symbol_p)->type_rep->arr.element_type = arr;
                                        (yyval.symbol_p) = (yyvsp[-2].symbol_p);
                                    } else {
                                        (yyval.symbol_p) = add_astnode_to_symbol((yyvsp[-2].symbol_p), arr);
                                    }
                                }
#line 2641 "parse.tab.c"
    break;

  case 153: /* direct_declarator: direct_declarator '[' NUMBER ']'  */
#line 660 "parse.y"
                                       {
                                            union astnode *arr = new_astnode_array(ARRAY_NODE, (yyvsp[-3].symbol_p)->dec_specs, (yyvsp[-1].numInfo).value.int_val);
                                            if ((yyvsp[-3].symbol_p)->type_rep && (yyvsp[-3].symbol_p)->type_rep->generic.type == ARRAY_NODE) { 
                                                (yyvsp[-3].symbol_p)->type_rep->arr.element_type = arr;
                                                (yyval.symbol_p) = (yyvsp[-3].symbol_p);
                                            } else {
                                                (yyval.symbol_p) = add_astnode_to_symbol((yyvsp[-3].symbol_p), arr);
                                            }
                                       }
#line 2655 "parse.tab.c"
    break;

  case 154: /* direct_declarator: direct_declarator '(' ')'  */
#line 669 "parse.y"
                                {   
                                    union astnode *ptr = new_astnode_fndef(FUNCTION_DEF_NODE, NULL, NULL);
                                    if ((yyvsp[-2].symbol_p)->type_rep && (yyvsp[-2].symbol_p)->type_rep->generic.type == FUNCTION_DEF_NODE) {
                                        modify_astnode_fndef((yyvsp[-2].symbol_p)->type_rep, NULL, ptr);
                                        //printf("ret type of func is %d\n", $1->type_rep->fndef.ret_type->generic.type);
                                    } else if ((yyvsp[-2].symbol_p)->type_rep && (yyvsp[-2].symbol_p)->type_rep->generic.type == POINTER_NODE) {
                                        ptr->fndef.ret_type = (yyvsp[-2].symbol_p)->type_rep; //set return type of function to pointer
                                        add_astnode_to_symbol((yyvsp[-2].symbol_p), ptr); // set function as symbol type_rep
                                    } else {
                                        add_astnode_to_symbol((yyvsp[-2].symbol_p), ptr);
                                    }

                                    symbol *sym; 
                                    if ((yyvsp[-2].symbol_p)->sym_type == VARIABLE_SYMBOL) {
                                        sym = modify_symbol_type((yyvsp[-2].symbol_p), FUNCTION_SYMBOL);
                                    } 
                                    (yyval.symbol_p) = sym;
                                }
#line 2678 "parse.tab.c"
    break;

  case 155: /* pointer: '*'  */
#line 689 "parse.y"
             {(yyval.astnode_p) = new_astnode_pointer(POINTER_NODE, NULL, NULL);}
#line 2684 "parse.tab.c"
    break;

  case 156: /* pointer: '*' type_qualifier_list  */
#line 690 "parse.y"
                              {(yyval.astnode_p) = new_astnode_pointer(POINTER_NODE, (yyvsp[0].astnode_p), NULL);}
#line 2690 "parse.tab.c"
    break;

  case 157: /* pointer: '*' pointer  */
#line 691 "parse.y"
                  {(yyval.astnode_p) = new_astnode_pointer(POINTER_NODE, NULL, (yyvsp[0].astnode_p));}
#line 2696 "parse.tab.c"
    break;

  case 158: /* pointer: '*' type_qualifier_list pointer  */
#line 692 "parse.y"
                                      {(yyval.astnode_p) = new_astnode_pointer(POINTER_NODE, (yyvsp[-1].astnode_p), (yyvsp[0].astnode_p));}
#line 2702 "parse.tab.c"
    break;

  case 159: /* type_qualifier_list: type_qualifier  */
#line 695 "parse.y"
                                    {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2708 "parse.tab.c"
    break;

  case 161: /* parameter-type-list: parameter-list  */
#line 699 "parse.y"
                                    {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2714 "parse.tab.c"
    break;

  case 163: /* parameter-list: parameter-declaration  */
#line 703 "parse.y"
                                      {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2720 "parse.tab.c"
    break;

  case 165: /* parameter-declaration: declaration_specifiers declarator  */
#line 707 "parse.y"
                                                         {  // add decspecs to declarator symbol
                                                            symbol *temp = add_astnode_to_symbol((yyvsp[0].symbol_p), (yyvsp[-1].astnode_p));
                                                            union astnode *ptr = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, temp);
                                                            (yyval.astnode_p) = ptr;
                                                         }
#line 2730 "parse.tab.c"
    break;

  case 166: /* parameter-declaration: declaration_specifiers abstract_declarator  */
#line 712 "parse.y"
                                                 {
                                                       if ((yyvsp[0].astnode_p)->generic.type == FUNCTION_DEF_NODE) {
                                                          // function
                                                       } else if ((yyvsp[0].astnode_p)->generic.type == ARRAY_NODE) {
                                                          union astnode *node_ptr = modify_astnode_array((yyvsp[0].astnode_p), (yyvsp[-1].astnode_p));
                                                          (yyval.astnode_p) = node_ptr;
                                                       }
                                                    }
#line 2743 "parse.tab.c"
    break;

  case 170: /* type_name: specifier_qualifier_list  */
#line 727 "parse.y"
                                    {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2749 "parse.tab.c"
    break;

  case 171: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 728 "parse.y"
                                                   {
                                                       if ((yyvsp[0].astnode_p)->generic.type == FUNCTION_DEF_NODE) {
                                                          // function
                                                       } else if ((yyvsp[0].astnode_p)->generic.type == ARRAY_NODE) {
                                                          union astnode *node_ptr = modify_astnode_array((yyvsp[0].astnode_p), (yyvsp[-1].astnode_p));
                                                          (yyval.astnode_p) = node_ptr;
                                                       }
                                                    }
#line 2762 "parse.tab.c"
    break;

  case 172: /* abstract_declarator: pointer  */
#line 738 "parse.y"
                             {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2768 "parse.tab.c"
    break;

  case 173: /* abstract_declarator: direct_abstract_declarator  */
#line 739 "parse.y"
                                 {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2774 "parse.tab.c"
    break;

  case 175: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 743 "parse.y"
                                                        {(yyval.astnode_p) = (yyvsp[-1].astnode_p);}
#line 2780 "parse.tab.c"
    break;

  case 176: /* direct_abstract_declarator: '[' ']'  */
#line 744 "parse.y"
                                                        {(yyval.astnode_p) = new_astnode_array(ARRAY_NODE, NULL, 0);}
#line 2786 "parse.tab.c"
    break;

  case 177: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 745 "parse.y"
                                                        {(yyval.astnode_p) = new_astnode_array(ARRAY_NODE, (yyvsp[-2].astnode_p), 0);}
#line 2792 "parse.tab.c"
    break;

  case 178: /* direct_abstract_declarator: '[' NUMBER ']'  */
#line 746 "parse.y"
                                                        {(yyval.astnode_p) = new_astnode_array(ARRAY_NODE, NULL, (yyvsp[-1].numInfo).value.int_val);}
#line 2798 "parse.tab.c"
    break;

  case 179: /* direct_abstract_declarator: direct_abstract_declarator '[' NUMBER ']'  */
#line 747 "parse.y"
                                                        {(yyval.astnode_p) = new_astnode_array(ARRAY_NODE, (yyvsp[-3].astnode_p), (yyvsp[-1].numInfo).value.int_val);}
#line 2804 "parse.tab.c"
    break;

  case 180: /* direct_abstract_declarator: '(' ')'  */
#line 748 "parse.y"
                                                        {(yyval.astnode_p) = new_astnode_fndef(FUNCTION_NODE, NULL, NULL);}
#line 2810 "parse.tab.c"
    break;

  case 181: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 749 "parse.y"
                                                        {(yyval.astnode_p) = new_astnode_fndef(FUNCTION_NODE, NULL, (yyvsp[-2].astnode_p));}
#line 2816 "parse.tab.c"
    break;

  case 183: /* labeled-statement: IDENT ':' statement  */
#line 796 "parse.y"
                                       {
                                            symbol *sym = new_symbol((yyvsp[-2].stringInfo).string_literal, OTHER, NULL, NULL, LABEL_SYMBOL);
                                            insert_symbol(current->symbolTables[OTHER], sym); // nothing will hapen if symbol is already there
                                            union astnode *label_name = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, sym);
                                            (yyval.astnode_p) = new_astnode_label(LABEL_NODE, GOTO_LABEL, label_name, (yyvsp[0].astnode_p));
                                        }
#line 2827 "parse.tab.c"
    break;

  case 184: /* labeled-statement: CASE constant-expression ':' statement  */
#line 802 "parse.y"
                                             {(yyval.astnode_p) = new_astnode_label(LABEL_NODE, CASE_LABEL, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 2833 "parse.tab.c"
    break;

  case 185: /* labeled-statement: DEFAULT ':' statement  */
#line 803 "parse.y"
                            {(yyval.astnode_p) = new_astnode_label(LABEL_NODE, DEFAULT_LABEL, NULL, (yyvsp[0].astnode_p));}
#line 2839 "parse.tab.c"
    break;

  case 186: /* selection-statement: IF '(' expression ')' statement  */
#line 806 "parse.y"
                                                     {(yyval.astnode_p) = new_astnode_if(IF_NODE, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 2845 "parse.tab.c"
    break;

  case 187: /* selection-statement: IF '(' expression ')' statement ELSE statement  */
#line 807 "parse.y"
                                                     {(yyval.astnode_p) = new_astnode_ternop('?', ':', (yyvsp[-4].astnode_p), (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 2851 "parse.tab.c"
    break;

  case 188: /* selection-statement: SWITCH '(' expression ')' statement  */
#line 808 "parse.y"
                                          {(yyval.astnode_p) = new_astnode_switch(SWITCH_NODE, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 2857 "parse.tab.c"
    break;

  case 189: /* iteration-statement: WHILE '(' expression_opt ')' statement  */
#line 811 "parse.y"
                                                            {(yyval.astnode_p) = new_astnode_while(WHILE_NODE, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 2863 "parse.tab.c"
    break;

  case 190: /* iteration-statement: DO statement WHILE '(' expression ')' ';'  */
#line 812 "parse.y"
                                                {(yyval.astnode_p) = new_astnode_while(DO_WHILE_NODE, (yyvsp[-2].astnode_p), (yyvsp[-5].astnode_p));}
#line 2869 "parse.tab.c"
    break;

  case 191: /* iteration-statement: FOR '(' expression_opt ';' expression_opt ';' expression_opt ')' statement  */
#line 813 "parse.y"
                                                                                 {(yyval.astnode_p) = new_astnode_for(FOR_NODE, (yyvsp[-6].astnode_p), (yyvsp[-4].astnode_p), (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 2875 "parse.tab.c"
    break;

  case 192: /* iteration-statement: FOR '(' declaration expression_opt ';' expression_opt ')' statement  */
#line 814 "parse.y"
                                                                          { 
                                                                            union astnode *decl_ptr = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, (yyvsp[-5].symbol_p));
                                                                            (yyval.astnode_p) = new_astnode_for(FOR_NODE, decl_ptr, (yyvsp[-4].astnode_p), (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));
                                                                          }
#line 2884 "parse.tab.c"
    break;

  case 193: /* jump-statement: GOTO IDENT ';'  */
#line 819 "parse.y"
                               {    
                                    symbol *sym = new_symbol((yyvsp[-1].stringInfo).string_literal, OTHER, NULL, NULL, LABEL_SYMBOL);
                                    insert_symbol(current->symbolTables[OTHER], sym); // nothing will hapen if symbol is already there
                                    union astnode *label_name = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, sym);
                                    union astnode *label_ptr = new_astnode_label(LABEL_NODE, GOTO_LABEL, label_name, NULL);
                                    (yyval.astnode_p) = new_astnode_goto(GOTO_NODE, label_ptr);
                                }
#line 2896 "parse.tab.c"
    break;

  case 194: /* jump-statement: CONTINUE ';'  */
#line 826 "parse.y"
                   {(yyval.astnode_p) = new_astnode_cont_break(CONTINUE_NODE);}
#line 2902 "parse.tab.c"
    break;

  case 195: /* jump-statement: BREAK ';'  */
#line 827 "parse.y"
                {(yyval.astnode_p) = new_astnode_cont_break(BREAK_NODE);}
#line 2908 "parse.tab.c"
    break;

  case 196: /* jump-statement: RETURN expression_opt ';'  */
#line 828 "parse.y"
                                {(yyval.astnode_p) = new_astnode_return(RETURN_NODE, (yyvsp[-1].astnode_p));}
#line 2914 "parse.tab.c"
    break;

  case 198: /* expression_opt: expression  */
#line 832 "parse.y"
                 {(yyval.astnode_p) = (yyvsp[0].astnode_p);}
#line 2920 "parse.tab.c"
    break;

  case 199: /* expression-statement: ';'  */
#line 835 "parse.y"
                          {(yyval.astnode_p) = NULL;}
#line 2926 "parse.tab.c"
    break;

  case 200: /* expression-statement: expression ';'  */
#line 836 "parse.y"
                     {(yyval.astnode_p) = (yyvsp[-1].astnode_p);}
#line 2932 "parse.tab.c"
    break;


#line 2936 "parse.tab.c"

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

#line 839 "parse.y"


int main(){
    //yydebug = 1;
    current = NULL;
    push_scope(FILE_SCOPE);
    current->scope_fileName = NULL;
    current->scope_lineNum = 1;
    int t;
    while(!(t = yyparse())){
    };
}

void yyerror(char *str) {
    fprintf(stderr,"error: %s\n",str);
}
