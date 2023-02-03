/*-----------------------------------------------------------------------------------------------------------------\
|      TO DO                                                                                                       |
|      1. REGEX for numbers (all diff types refer to Dan's ss), strings, CHARLIT                                   |
|      2. Figure out how to handle different number types in yylval                                                |     
|            a. convert to internal representation (i.e. how to store the number "int integer" is not universal)   |
|      3.File name and line number (start conditions)                                                              |
\-----------------------------------------------------------------------------------------------------------------*/

/* Definition Section */

%{
#include "tokens-manual.h"
%}

DECIMAL   [0-9] 
DIGIT  DECIMAL
LETTER  [a-zA-Z]
STRING  \"(?:[^"\\]|\\.)*\"
%s FILENAME
/* Rule Section  */
/*
.* {return STRING;}
NEED TO DO CHARLIT
*/
%%
[ \t\f\r]+ /* ignore whitespace */ 

#[ ][0-9]+ {report.lineNum = atoi(yytext+2); BEGIN(FILENAME);} /* get file number two tokens in, jump to getting filename */
<FILENAME>{STRING} {
                     if (report.fileName) {free (report.fileName);};
                     report.fileName = strdup(yytext+1); /* skip beginning quote */
                     report.fileName[strlen(yytext)-2] = '\0'; /* delete ending quote */
                     BEGIN(INITIAL); 
                   }
\n {report.lineNum++;}
<<EOF>>  {return TOKEOF;}
{DIGIT}* {yylval.integer = atoi(yytext); return NUMBER;} /* Decimal need to do other number types */
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
({LETTER}|_)({DIGIT}|{LETTER}|_)* {yylval.string_literal = strdup(yytext); return IDENT;}
%%
  
/* Code Section */
int yywrap(){}
int main(){

      int t;
      while ((t = yylex())) {
            if (t == 0) {
                  continue;
            }
            printf("%s\t\t\t", report.fileName);
            printf("%d\t\t\t", report.lineNum);
            printf("%d\t\t\t", t);

            switch(t) {
                  case(IDENT):
                        printf("%s\n", yylval.string_literal);
                        break;
                  case(NUMBER):
                        printf("%d\n", yylval.integer);
                        break;
                  default:
                        printf("\n");
                        break;
            }
      }
  
return 0;
}