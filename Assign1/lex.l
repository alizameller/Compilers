/* Definition Section has one variable
 which can be accessed inside yylex() 
 and main() */

%{
#include "tokens-manual.h"
int count = 0;
int yylval;
%}

DIGIT    [0-9] 

/* Rule Section has three rules, first rule 
 matches with capital letters, second rule
 matches with any character except newline and 
 third rule does not take input after the enter */

/*[A-Z] {printf("%s capital letter\n", yytext);}
[0-9]+ {yylval=atoi(yytext); returnNUMBER;} 
\+ {returnPLUS;} */
%%
<<[EOF]>> {return TOKEOF=0;}
\n {return 0;}
.* {return STRING;}
{DIGIT}* {yylval = atoi(yytext); return NUMBER;}
[ {return '['}
] {return ']'}
( {return '('}
) {return ')'}
\{ {return '{'} 
\} {return '}'} 
\. {return '.'}
-> {return 899} /* I don't know */
& {return '&'}
\* {return '*'}
\+ {return '+'}
- {return '-'}
~ {return '~'}
! {return '!'}
\/ {return '/'} 
% {return '%'}
\^ {return '^'}
\| {return '|'}
\? {return '?'}
\: {return ':'}
\; {return ';'}
= {return '='}
, {return ','} 
# {return '#'}
## {return 900} /* I do not know */
\<\: {return '['} 
\:\>  {return ']'}
\<%  {return '{'}
%\>  {return '}'}
%\:  {return '#'}
%\:%\: {return 900}
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
%= {return MODEEQ;}
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
%%
  
/* Code Section prints the number of
capital letter present in the given input */
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
            printf("%d", t);
      }
  
return 0;
}