/*-----------------------------------------------------------------------------------------------------------------\
|      TO DO:                                                                                                      |
|      Figure out how to free the string_literals now that the "free" from the print message is gone               |
\-----------------------------------------------------------------------------------------------------------------*/
/* Definition Section */
%option noyywrap

%{
#include "parse.tab.h"
#include <limits.h>
#include <ctype.h>
%}

DECIMAL                       [1-9][0-9]*
HEX                           0[xX][0-9a-fA-F]+
OCTAL                         0[0-7]*
LETTER                        [a-zA-Z]
NAME                           \"(?:[^"\\]|\\.)*\" 
DFC                           (([0-9]*\.[0-9]+)|([0-9]+\.[0-9]*))([eE][+-]?[0-9]+)?|[0-9]+[eE][+-]?[0-9]+
HFC                           ({HEX}?\.{HEX})|({HEX})[pP][+-]?[0-9+]
FLOAT                         {DFC}|{HFC}

%s FILENAME
%s ENDL
%x INTEGER_SUFFIX
%x FLOAT_SUFFIX
%x STR
%x CHARACTER

/* Rule Section  */

%%
%{
char buf[65535];
char *buf_ptr;
%}
[ \t\f\r]+ /* ignore whitespace */ 
#[ ][0-9]+ {report.lineNum = atoi(yytext+2); BEGIN(FILENAME);} /* get file number two tokens in, jump to getting filename */
<FILENAME>{NAME} {
                     if (report.fileName) {free (report.fileName);};
                     report.fileName = strdup(yytext+1); /* skip beginning quote */
                     report.fileName[strlen(yytext)-2] = '\0'; /* delete ending quote */
                     BEGIN(ENDL); 
                  }
<ENDL>.*\n { /* Jump to the end of the line (i.e. skip over the flags) */
            BEGIN(INITIAL);
           }
<<EOF>>  {return TOKEOF;}
\n {report.lineNum++;}
{DECIMAL} {
            yylval.numInfo.value.int_val  = strtoll(yytext, NULL, 10);
            yylval.numInfo.meta = SIGNED_INT;
            BEGIN(INTEGER_SUFFIX);
            } 
{HEX} {
            yylval.numInfo.value.int_val  = strtoll(yytext, NULL, 16);
            yylval.numInfo.meta = SIGNED_INT;
            BEGIN(INTEGER_SUFFIX);
       }
{OCTAL} {
            yylval.numInfo.value.int_val  = strtoll(yytext, NULL, 8);
            yylval.numInfo.meta = SIGNED_INT;
            BEGIN(INTEGER_SUFFIX);
         }
{FLOAT} {
            yylval.numInfo.value.float_val = strtold(yytext, NULL);
            yylval.numInfo.meta = DOUBLE_NUM;
            BEGIN(FLOAT_SUFFIX);
}
<INTEGER_SUFFIX>{
      [uU] {
            yylval.numInfo.value.int_val = (unsigned int) yylval.numInfo.value.int_val;
            yylval.numInfo.meta = UNSIGNED_INT; 
            BEGIN(INITIAL);
            return NUMBER;  
            }
      [uU][lL]|[lL][uU] {
            yylval.numInfo.value.int_val = (unsigned long) yylval.numInfo.value.int_val;
            yylval.numInfo.meta = UNSIGNED_LONG;
            BEGIN(INITIAL);
            return NUMBER;  
            }
      [uU][lL]{2}|[lL]{2}[uU] {
            yylval.numInfo.meta = UNSIGNED_LONGLONG;
            BEGIN(INITIAL);
            return NUMBER;  
            }
      [lL] {
            yylval.numInfo.value.int_val = (long) yylval.numInfo.value.int_val;
            yylval.numInfo.meta = SIGNED_LONG;
            BEGIN(INITIAL);
            return NUMBER;  
            }
      [lL]{2} {
            yylval.numInfo.meta = SIGNED_LONGLONG;
            BEGIN(INITIAL);
            return NUMBER;  
            }
}
<FLOAT_SUFFIX>{
      [fF] {
            yylval.numInfo.value.float_val = (float) yylval.numInfo.value.float_val;
            yylval.numInfo.meta = FLOAT_NUM;
            BEGIN(INITIAL);
            return NUMBER;  
            }
      [lL] {
            yylval.numInfo.value.float_val = (long double) yylval.numInfo.value.float_val;
            yylval.numInfo.meta = LONG_DOUBLE;
            BEGIN(INITIAL);
            return NUMBER;  
            }
}
<FLOAT_SUFFIX,INTEGER_SUFFIX>{

      [\t\r\v\f ]+ {
            BEGIN(INITIAL); 
            return NUMBER;
            }
      \n {
            yyless(0); //put current character (i.e. the one after the number we currently wish to read) back in scanner
            BEGIN(INITIAL);
            return NUMBER;
      }
      . {
            yyless(0); //put current character (i.e. the one after the number we currently wish to read) back in scanner
            BEGIN(INITIAL);
            return NUMBER;
        }
}
L?\' {buf_ptr = buf; BEGIN(CHARACTER);}
L?\" {buf_ptr = buf; BEGIN(STR);}
<CHARACTER,STR>{
       \" {   
            BEGIN(INITIAL);
            *buf_ptr = '\0'; 
            yylval.stringInfo.length = buf_ptr - buf; 
            if (!(yylval.stringInfo.string_literal = (char *) malloc((yylval.stringInfo.length + 1)*sizeof(char)))) {
			fprintf(stderr, "%s:%d:Error mallocing %s\n", report.fileName, report.lineNum, strerror(errno));
			exit(1);
		}
            
		memcpy(yylval.stringInfo.string_literal, buf, (yylval.stringInfo.length + 1)*sizeof(char));

            return STRING; 
         }
      [^\"\'\\\n]+ {
            char *ptr = yytext; 
            while(*ptr) {
                  *buf_ptr++ = *ptr++;
            }
      }
      \\\\ {*buf_ptr++ = '\\';}
      \\\" {*buf_ptr++ = '\"';}
      \\\? {*buf_ptr++ = '\?';}
      \\a {*buf_ptr++ = '\a';}
      \\b {*buf_ptr++ = '\b';}
      \\f {*buf_ptr++ = '\f';}
      \\n {*buf_ptr++ = '\n';}
      \\r {*buf_ptr++ = '\r';}
      \\t {*buf_ptr++ = '\t';}
      \\v {*buf_ptr++ = '\v';}
      \\' {*buf_ptr++ = '\'';}
      \\[0-7]{1,3} {
            long int temp = strtol(yytext + 1, NULL, 8);
            if (temp > 0xff) {
                  fprintf(stderr, "%s:%d:Warning:Octal escape sequence %s out of range", report.fileName, report.lineNum, yytext); 
                  *buf_ptr++ = 0xff; 
            } else {
                  *buf_ptr++ = (char)temp; 
            }
      }
      \\[xX][0-9a-fA-F]+ {
            long int temp = strtol(yytext + 2, NULL, 16);
            if (temp > 0xff) {
                  fprintf(stderr, "%s:%d:Warning:Hex escape sequence %s out of range", report.fileName, report.lineNum, yytext);
                  *buf_ptr++ = 0xff;  
            } else {
                  *buf_ptr++ = (char)temp; 
            }
      }
      \n {
            fprintf(stderr, "%s:%d:Error:Unterminated string constant", report.fileName, report.lineNum);
      }
}
<CHARACTER>{
      \' {  
            BEGIN(INITIAL);
            if ((buf_ptr - buf) > 1) {
                  fprintf(stderr, "%s:%d:Warning:Unsupported multibyte character literal truncated to first byte\n", report.fileName, report.lineNum);
            }
            yylval.char_literal = buf[0]; 
            return CHARLIT; 
         }
}
<STR>\' {*buf_ptr++ = '\'';} 
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
auto {return AUTO;}
break {return BREAK;}
case {return CASE;}
char {return CHAR;}
const {return CONST;}
continue {return CONTINUE;}
default {return DEFAULT;}
do {return DO;}
double {return DOUBLE;}
else {return ELSE;}
enum {return ENUM;}
extern {return EXTERN;}
float {return FLOAT;}
for {return FOR;}
goto {return GOTO;}
if {return IF;}
inline {return INLINE;}
int {return INT;}
long {return LONG;}
register {return REGISTER;}
restrict {return RESTRICT;}
return {return RETURN;}
short {return SHORT;}
signed {return SIGNED;}
sizeof {return SIZEOF;}
static {return STATIC;}
struct {return STRUCT;}
switch {return SWITCH;}
typedef {return TYPEDEF;}
union {return UNION;}
unsigned {return UNSIGNED;}
void {return VOID;}
volatile {return VOLATILE;}
while {return WHILE;}
_Bool {return _BOOL;}
_Complex {return _COMPLEX;}
_Imaginary {return _IMAGINARY;}
({LETTER}|_)([0-9]*|{LETTER}|_)* {yylval.stringInfo.string_literal = strdup(yytext); return IDENT;}
%%