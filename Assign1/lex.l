/* Definition Section */

%{
#include "tokens-manual.h"
int count = 0;
%}

DIGIT   [0-9] 
LETTER  [a-zA-Z]

/* Rule Section  */
/*
[0-9]+ {yylval=atoi(yytext); returnNUMBER;} 
[/t]+ ignore whitespace
.* {return STRING;}
*/
%%
[ \t\f\r]+ /* ignore whitespace */ 
<<EOF>>  {return TOKEOF;} 
\n {count++;}
{DIGIT}* {yylval.integer = atoi(yytext); return NUMBER;} /* Decimal */
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
  
// Explanation:
// yywrap() - wraps the above rule section
/* yyin - takes the file pointer 
          which contains the input*/
/* yylex() - this is the main flex function
          which runs the Rule Section*/
// yytext is the text in the buffer
  
// Uncomment the lines below 
// to take input from file
/* FILE *fp;
char filename[50];
printf("Enter the filename: \n");
scanf("%s",filename);
fp = fopen(filename,"r");
yyin = fp; */

int t;
      while ((t = yylex())) {
            if (t == 0) {
                  continue;
            }
            printf("yytext is %s\n", yytext);
            if (t == IDENT) {
                  printf("yyval is %s\n", yylval.string_literal);
            } else if (t == NUMBER) {
                  printf("yyval is %d\n", yylval.integer);
            }
            printf("return val is %d, count is %d\n", t, count);
      }
  
return 0;
}