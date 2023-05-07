/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 15 "parse.y"

    #include "symtable.h"

#line 53 "parse.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENT = 258,                   /* IDENT  */
    CHARLIT = 259,                 /* CHARLIT  */
    STRING = 260,                  /* STRING  */
    NUMBER = 261,                  /* NUMBER  */
    INDSEL = 262,                  /* INDSEL  */
    LOGAND = 263,                  /* LOGAND  */
    LOGOR = 264,                   /* LOGOR  */
    SHL = 265,                     /* SHL  */
    SHR = 266,                     /* SHR  */
    LTEQ = 267,                    /* LTEQ  */
    GTEQ = 268,                    /* GTEQ  */
    EQEQ = 269,                    /* EQEQ  */
    NOTEQ = 270,                   /* NOTEQ  */
    PLUSPLUS = 271,                /* PLUSPLUS  */
    MINUSMINUS = 272,              /* MINUSMINUS  */
    TIMESEQ = 273,                 /* TIMESEQ  */
    DIVEQ = 274,                   /* DIVEQ  */
    MODEQ = 275,                   /* MODEQ  */
    PLUSEQ = 276,                  /* PLUSEQ  */
    MINUSEQ = 277,                 /* MINUSEQ  */
    SHLEQ = 278,                   /* SHLEQ  */
    SHREQ = 279,                   /* SHREQ  */
    ANDEQ = 280,                   /* ANDEQ  */
    OREQ = 281,                    /* OREQ  */
    XOREQ = 282,                   /* XOREQ  */
    SIZEOF = 283,                  /* SIZEOF  */
    ELLIPSIS = 284,                /* ELLIPSIS  */
    AUTO = 285,                    /* AUTO  */
    BREAK = 286,                   /* BREAK  */
    CASE = 287,                    /* CASE  */
    CHAR = 288,                    /* CHAR  */
    CONST = 289,                   /* CONST  */
    CONTINUE = 290,                /* CONTINUE  */
    DEFAULT = 291,                 /* DEFAULT  */
    DO = 292,                      /* DO  */
    DOUBLE = 293,                  /* DOUBLE  */
    ELSE = 294,                    /* ELSE  */
    ENUM = 295,                    /* ENUM  */
    EXTERN = 296,                  /* EXTERN  */
    FLOAT = 297,                   /* FLOAT  */
    FOR = 298,                     /* FOR  */
    GOTO = 299,                    /* GOTO  */
    IF = 300,                      /* IF  */
    INLINE = 301,                  /* INLINE  */
    INT = 302,                     /* INT  */
    LONG = 303,                    /* LONG  */
    REGISTER = 304,                /* REGISTER  */
    RESTRICT = 305,                /* RESTRICT  */
    RETURN = 306,                  /* RETURN  */
    SHORT = 307,                   /* SHORT  */
    SIGNED = 308,                  /* SIGNED  */
    STATIC = 309,                  /* STATIC  */
    STRUCT = 310,                  /* STRUCT  */
    SWITCH = 311,                  /* SWITCH  */
    TYPEDEF = 312,                 /* TYPEDEF  */
    UNION = 313,                   /* UNION  */
    UNSIGNED = 314,                /* UNSIGNED  */
    VOID = 315,                    /* VOID  */
    VOLATILE = 316,                /* VOLATILE  */
    WHILE = 317,                   /* WHILE  */
    _BOOL = 318,                   /* _BOOL  */
    _COMPLEX = 319,                /* _COMPLEX  */
    _IMAGINARY = 320,              /* _IMAGINARY  */
    TOKEOF = 321                   /* TOKEOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "parse.y"
 
    struct numinfo numInfo;
    struct stringinfo stringInfo; 
    char char_literal; 
    union astnode *astnode_p; 
    int operator; 
    symbol *symbol_p;

#line 145 "parse.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */
