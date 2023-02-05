/*-----------------------------------------------------------------------------------------------------------------\
|      TO DO                                                                                                       |
|      1. REGEX for numbers (all diff types refer to Dan's ss), strings, CHARLIT                                   |
|      2. Figure out how to handle different number types in yylval                                                |     
|            a. convert to internal representation (i.e. how to store the number "int integer" is not universal)   |
|            b. MAKE LOCAL variable for base to do conversion                                                      |
|      3̶.̶F̶i̶l̶e̶ n̶a̶m̶e̶ a̶n̶d̶ l̶i̶n̶e̶ n̶u̶m̶b̶e̶r̶ (̶s̶t̶a̶r̶t̶ c̶o̶n̶d̶i̶t̶i̶o̶n̶s̶)̶                                                              |
\-----------------------------------------------------------------------------------------------------------------*/

/* Definition Section */

%{
#include "tokens-manual.h"
#include <limits.h>

%}

/*FLOAT_DEC ^(0|[1-9]\d*)?(\.\d+)?$*/
/* INTEGER [+|-]?(0|[1-9][0-9]*)*/
INT_SUFFIX                    (([uU]?(l{1,2}|L{1,2})?)|((l{1,2}|L{1,2})?[uU]?))
DECIMAL                       [+|-]?[1-9]*
HEX                           [+|-]?0[xX][0-9a-fA-F]+
OCTAL                         [+|-]?0[0-7]*
LETTER                        [a-zA-Z]
STRING                        \"(?:[^"\\]|\\.)*\" 
%s FILENAME
%s ENDL
%s SUFFIX
/* Rule Section  */
/*
.* {return STRING;}
NEED TO DO CHARLIT
*/
%%
%{
int base;
char *token;
%}
[ \t\f\r]+ /* ignore whitespace */ 
#[ ][0-9]+ {report.lineNum = atoi(yytext+2); BEGIN(FILENAME);} /* get file number two tokens in, jump to getting filename */
<FILENAME>{STRING} {
                     if (report.fileName) {free (report.fileName);};
                     report.fileName = strdup(yytext+1); /* skip beginning quote */
                     report.fileName[strlen(yytext)-2] = '\0'; /* delete ending quote */
                     BEGIN(ENDL); 
                  }
<ENDL>.*\n { /* Jump to the end of the line (i.e. skip over the flags) */
            BEGIN(INITIAL);
           }
\n {report.lineNum++;}
<<EOF>>  {return TOKEOF;}
^{DECIMAL} {
            token = strdup(yytext); 
            base = 10; 
            BEGIN(SUFFIX);
            } 
^{HEX} {
            token = strdup(yytext); 
            base = 16; 
            BEGIN(SUFFIX);
       }
^{OCTAL} {
            token = strdup(yytext); 
            base = 8; 
            BEGIN(SUFFIX);
         }
<SUFFIX>{
      [uU] {
            yylval.numInfo.value.int_val = atoi(token); 
            yylval.numInfo.meta = UNSIGNED_INT; 
            return NUMBER; 
            BEGIN(INITIAL); 
            }
      [uU][lL]|[lL][uU] {
            yylval.numInfo.value.int_val  = strtol(token, NULL, base); 
            yylval.numInfo.meta = UNSIGNED_LONG;
            return NUMBER; 
            BEGIN(INITIAL); 
            }
      [uU][lL]{2}|[lL]{2}[uU] {
            yylval.numInfo.value.int_val  = strtoll(token, NULL, base); 
            yylval.numInfo.meta = UNSIGNED_LONGLONG;
            return NUMBER; 
            BEGIN(INITIAL); 
            }
      [lL] {
            yylval.numInfo.value.int_val  = strtol(token, NULL, base); 
            yylval.numInfo.meta = SIGNED_LONG;
            return NUMBER; 
            BEGIN(INITIAL); 
            }
      [lL]{2} {
            yylval.numInfo.value.int_val  = strtoll(token, NULL, base); 
            yylval.numInfo.meta = SIGNED_LONGLONG;
            return NUMBER; 
            BEGIN(INITIAL); 
            }
      ({OCTAL}|{DECIMAL}|{HEX})$ {
            token  = strdup(yytext); 
            //printf("%s", token); 
            yylval.numInfo.value.int_val = strtoll(token, NULL, base); 
            yylval.numInfo.meta = SIGNED_INT; 
            return NUMBER; 
            BEGIN(INITIAL); 
      }
}
\[ {return '[';}
\] {return ']';}
\( {return '(';}
\) {return ')';}
\{ {return '{';} 
\} {return '}';} 
\. {return '.';}
-> {return INDSEL;}
& {return '&';}
\* {return '*';}
\+ {return '+';}
- {return '-';}
~ {return '~';}
! {return '!';}
\/ {return '/';} 
% {return '%';}
\^ {return '^';}
\| {return '|';}
\? {return '?';}
\: {return ':';}
\; {return ';';}
\< {return '<';}
\> {return '>';}
= {return '=';}
, {return ',';}
# {return '#';}
## {return 900;} /* I do not know */
\<\: {return '[';} 
\:\>  {return ']';}
\<%  {return '{';}
%\>  {return '}';}
%\:  {return '#';}
%\:%\: {return 900;}
\+\+ {return PLUSPLUS;}
-- {return MINUSMINUS;}
\<\< {return SHL;}
\>\> {return SHR;}
\<= {return LTEQ;}
\>= {return GTEQ;}
== {return EQEQ;}
!= {return NOTEQ;}
&& {return LOGAND;}
\|\| {return LOGOR;}
\.\.\. {return ELLIPSIS;}
\*= {return TIMESEQ;}
\/= {return DIVEQ;}
%= {return MODEQ;}
\+= {return PLUSEQ;}
-= {return MINUSEQ;}
\<\<= {return SHLEQ;}
\>\>= {return SHREQ;}
&= {return ANDEQ;}
\|= {return OREQ;}
\^= {return XOREQ;}
"auto" {return AUTO;}
"break" {return BREAK;}
"case" {return CASE;}
"char" {return CHAR;}
"const" {return CONST;}
"continue" {return CONTINUE;}
"default" {return DEFAULT;}
"do" {return DO;}
"double" {return DOUBLE;}
"else" {return ELSE;}
"enum" {return ENUM;}
"extern" {return EXTERN;}
"float" {return FLOAT;}
"for" {return FOR;}
"goto" {return GOTO;}
"if" {return IF;}
"inline" {return INLINE;}
"int" {return INT;}
"long" {return LONG;}
"register" {return REGISTER;}
"restrict" {return RESTRICT;}
"return" {return RETURN;}
"short" {return SHORT;}
"signed" {return SIGNED;}
"sizeof" {return SIZEOF;}
"static" {return STATIC;}
"struct" {return STRUCT;}
"switch" {return SWITCH;}
"typedef" {return TYPEDEF;}
"union" {return UNION;}
"unsigned" {return UNSIGNED;}
"void" {return VOID;}
"volatile" {return VOLATILE;}
"while" {return WHILE;}
"_bool" {return _BOOL;}
"_complex" {return _COMPLEX;}
"_imaginary" {return _IMAGINARY;}
({LETTER}|_)([0-9)*]|{LETTER}|_)* {yylval.string_literal = strdup(yytext); return IDENT;}
%%
  
/* Code Section */
int yywrap(){}
int main(){
      int t;
      while ((t = yylex())) {
            if (t == 0) {
                  continue;
            }
            //printf("%d\t\t\t", t);
            printf("%s\t\t\t", report.fileName);
            printf("%d\t\t\t", report.lineNum);

            switch(t) {
                  case(IDENT):
                        printf("IDENT\t\t\t");
                        printf("%s\n", yylval.string_literal);
                        break;
                  case(NUMBER):
                        printf("NUMBER\t\t\t");
                        printf("VAL:%lld\t\t\t", yylval.numInfo.value.int_val);
                        printf("TYPE:%d\n", yylval.numInfo.meta);
                        break;
                  case(INDSEL):
                        printf("INDSEL\n");
                        break;
                  case(PLUSPLUS):
                        printf("PLUSPLUS\n");
                        break;
                  case(MINUSMINUS):
                        printf("MINUSMINUS\n");
                        break;
                  case(SHL):
                        printf("SHL\n");
                        break;
                  case(SHR):
                        printf("SHR\n");
                        break;
                  case(LTEQ):
                        printf("LTEQ\n");
                        break;
                  case(GTEQ):
                        printf("GTEQ\n");
                        break;
                  case(EQEQ):
                        printf("EQEQ\n");
                        break;
                  case(NOTEQ):
                        printf("NOTEQ\n");
                        break;
                  case(LOGAND):
                        printf("LOGAND\n");
                        break;
                  case(LOGOR):
                        printf("LOGOR\n");
                        break;
                  case(ELLIPSIS):
                        printf("ELLIPSIS\n");
                        break;
                  case(TIMESEQ):
                        printf("TIMESEQ\n");
                        break;
                  case(DIVEQ):
                        printf("DIVEQ\n");
                        break;
                  case(MODEQ):
                        printf("MODEQ\n");
                        break;
                  case(PLUSEQ):
                        printf("PLUSEQ\n");
                        break;
                  case(MINUSEQ):
                        printf("MINUSEQ\n");
                        break;
                  case(SHLEQ):
                        printf("SHLEQ\n");
                        break;
                  case(SHREQ):
                        printf("SHREQ\n");
                        break;
                  case(ANDEQ):
                        printf("ANDEQ\n");
                        break;
                  case(OREQ):
                        printf("OREQ\n");
                        break;
                  case(XOREQ):
                        printf("XOREQ\n");
                        break;
                  case(AUTO):
                        printf("AUTO\n");
                        break;
                  case(BREAK):
                        printf("BREAK\n");
                        break;
                  case(CASE):
                        printf("CASE\n");
                        break;
                  case(CHAR):
                        printf("CHAR\n");
                        break;
                  case(CONST):
                        printf("CONST\n");
                        break;
                  case(CONTINUE):
                        printf("CONTINUE\n");
                        break;
                  case(DEFAULT):
                        printf("DEFAULT\n");
                        break;
                  case(DO):
                        printf("DO\n");
                        break;
                  case(DOUBLE):
                        printf("DOUBLE\n");
                        break;
                  case(ELSE):
                        printf("ELSE\n");
                        break;
                  case(ENUM):
                        printf("ENUM\n");
                        break;
                  case(EXTERN):
                        printf("EXTERN\n");
                        break;
                  case(FLOAT):
                        printf("FLOAT\n");
                        break;
                  case(FOR):
                        printf("FOR\n");
                        break;
                  case(GOTO):
                        printf("GOTO\n");
                        break;
                  case(IF):
                        printf("IF\n");
                        break;
                  case(INLINE):
                        printf("INLINE\n");
                        break;
                  case(INT):
                        printf("INT\n");
                        break;
                  case(LONG):
                        printf("LONG\n");
                        break;
                  case(REGISTER):
                        printf("REGISTER\n");
                        break;
                  case(RESTRICT):
                        printf("RESTRICT\n");
                        break;
                  case(RETURN):
                        printf("RETURN\n");
                        break;
                  case(SHORT):
                        printf("SHORT\n");
                        break;
                  case(SIGNED):
                        printf("SIGNED\n");
                        break;
                  case(SIZEOF):
                        printf("SIZEOF\n");
                        break;
                  case(STATIC):
                        printf("STATIC\n");
                        break;
                  case(STRUCT):
                        printf("STRUCT\n");
                        break;
                  case(SWITCH):
                        printf("SWITCH\n");
                        break;
                  case(TYPEDEF):
                        printf("TYPEDEF\n");
                        break;
                  case(UNION):
                        printf("UNION\n");
                        break;
                  case(UNSIGNED):
                        printf("UNSIGNED\n");
                        break;
                  case(VOID):
                        printf("VOID\n");
                        break;
                  case(VOLATILE):
                        printf("VOLATILE\n");
                        break;
                  case(WHILE):
                        printf("WHILE\n");
                        break;
                  case(_BOOL):
                        printf("_BOOL\n");
                        break;
                  case(_COMPLEX):
                        printf("_COMPLEX\n");
                        break;
                  case(_IMAGINARY):
                        printf("_IMAGINARY\n");
                        break;
                  case('['):
                        printf("[\n");
                        break;
                  case(']'):
                        printf("]\n");
                        break;
                  case('('):
                        printf("(\n");
                        break;
                  case(')'):
                        printf(")\n");
                        break;
                  case('{'):
                        printf("{\n");
                        break;
                  case('}'):
                        printf("}\n");
                        break;
                  case('.'):
                        printf(".\n");
                        break;
                  case('&'):
                        printf("&\n");
                        break;
                  case('*'):
                        printf("*\n");
                        break;
                  case('+'):
                        printf("+\n");
                        break;
                  case('-'):
                        printf("-\n");
                        break;
                  case('~'):
                        printf("~\n");
                        break;
                  case('!'):
                        printf("!\n");
                        break;
                  case('/'):
                        printf("/\n");
                        break;
                  case('%'):
                        printf("%%\n");
                        break;
                  case('^'):
                        printf("^\n");
                        break;
                  case('|'):
                        printf("|\n");
                        break;
                  case('?'):
                        printf("?\n");
                        break;
                  case(':'):
                        printf(":\n");
                        break;
                  case(';'):
                        printf(";\n");
                        break;
                  case('='):
                        printf("=\n");
                        break;
                  case(','):
                        printf(",\n");
                        break;
                  case('#'):
                        printf("#\n");
                        break;
                  case('>'):
                        printf(">\n");
                        break;
                  case('<'):
                        printf("<\n");
                        break;
                  default:
                        printf("\n");
                        break;
            }
      }
      return 0;
}