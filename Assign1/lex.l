/*-----------------------------------------------------------------------------------------------------------------\
|      TO DO                                                                                                       |
|      1. REGEX for numbers (all diff types refer to Dan's ss), strings, CHARLIT                                   |
|      2̶.̶ F̶i̶g̶u̶r̶e̶ o̶u̶t̶ h̶o̶w̶ t̶o̶ h̶a̶n̶d̶l̶e̶ d̶i̶f̶f̶e̶r̶e̶n̶t̶ n̶u̶m̶b̶e̶r̶ t̶y̶p̶e̶s̶ i̶n̶ y̶y̶l̶v̶a̶l̶                                                |     
|            a̶.̶ c̶o̶n̶v̶e̶r̶t̶ t̶o̶ i̶n̶t̶e̶r̶n̶a̶l̶ r̶e̶p̶r̶e̶s̶e̶n̶t̶a̶t̶i̶o̶n̶ (̶i̶.̶e̶.̶ h̶o̶w̶ t̶o̶ s̶t̶o̶r̶e̶ t̶h̶e̶ n̶u̶m̶b̶e̶r̶ "̶i̶n̶t̶ i̶n̶t̶e̶g̶e̶r̶"̶ i̶s̶ n̶o̶t̶ u̶n̶i̶v̶e̶r̶s̶a̶l̶)̶   |
|            b. MAKE LOCAL variable for base to do conversion                                                      |
|      3̶.̶F̶i̶l̶e̶ n̶a̶m̶e̶ a̶n̶d̶ l̶i̶n̶e̶ n̶u̶m̶b̶e̶r̶ (̶s̶t̶a̶r̶t̶ c̶o̶n̶d̶i̶t̶i̶o̶n̶s̶)̶                                                              |
\-----------------------------------------------------------------------------------------------------------------*/

/* Definition Section */

%{
#include "tokens-manual.h"
#include <limits.h>
%}

/*FLOAT_DEC ^(0|[1-9]\d*)?(\.\d+)?$*/
/*INT_SUFFIX                    (([uU]?(l{1,2}|L{1,2})?)|((l{1,2}|L{1,2})?[uU]?))*/
DECIMAL                       [+|-]?[1-9]+
HEX                           [+|-]?0[xX][0-9a-fA-F]+
OCTAL                         [+|-]?0[0-7]+
LETTER                        [a-zA-Z]
NAME                           \"(?:[^"\\]|\\.)*\" 
/* STRING_LITERAL             \"([^\'\\\n]|\\[\\\'\"\?abfnrtv]|\\[0-7]{1,3}|\\[xX][0-9a-fA-F]+)\" */
/* CHAR_LITERAL               L?\'([^\'\\\n]|\\[\\\'\"\?abfnrtv]|\\[0-7]{1,3}|\\[xX][0-9a-fA-F]+)\' */

%s FILENAME
%s ENDL
%s SUFFIX
%x STRING
%x CHAR
/* Rule Section  */
/*
NEED TO DO CHARLIT AND STRINGS
*/
%%
%{
int base;
char *token;
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
\n {report.lineNum++;}
<<EOF>>  {return TOKEOF;}
{DECIMAL} {
            token = strdup(yytext); 
            base = 10; 
            BEGIN(SUFFIX);
            } 
{HEX} {
            token = strdup(yytext); 
            base = 16; 
            BEGIN(SUFFIX);
       }
{OCTAL} {
            token = strdup(yytext); 
            base = 8; 
            BEGIN(SUFFIX);
         }
<SUFFIX>{
      [uU]$ {
            if (token[0] == '-') {
                  fprintf(stderr, "Error cannot use '-' with 'u' in %s%s\n", token, yytext);
                  exit(1); 
            }
            yylval.numInfo.value.int_val = atoi(token); 
            yylval.numInfo.meta = UNSIGNED_INT; 
            return NUMBER; 
            BEGIN(INITIAL); 
            }
      [uU][lL]|[lL][uU]$ {
            if (token[0] == '-') {
                  fprintf(stderr, "Error cannot use '-' with 'u' in %s%s\n", token, yytext);
                  exit(1); 
            }
            yylval.numInfo.value.int_val  = strtol(token, NULL, base); 
            yylval.numInfo.meta = UNSIGNED_LONG;
            return NUMBER; 
            BEGIN(INITIAL); 
            }
      [uU][lL]{2}|[lL]{2}[uU]$ {
            if (token[0] == '-') {
                  fprintf(stderr, "Error cannot use '-' with 'u' in %s%s\n", token, yytext);
                  exit(1); 
            }
            yylval.numInfo.value.int_val  = strtoll(token, NULL, base); 
            yylval.numInfo.meta = UNSIGNED_LONGLONG;
            return NUMBER; 
            BEGIN(INITIAL); 
            }
      [lL]$ {
            yylval.numInfo.value.int_val  = strtol(token, NULL, base); 
            yylval.numInfo.meta = SIGNED_LONG;
            return NUMBER; 
            BEGIN(INITIAL); 
            }
      [lL]{2}$ {
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
L?\' {buf_ptr = buf; BEGIN(CHAR);}
L?\" {buf_ptr = buf; BEGIN(STRING);}
<CHAR,STRING>{
       \" {   
            BEGIN(INITIAL);
            *buf_ptr = '\0'; 
            if (!(yylval.string_literal = malloc(strlen(buf)))) {
			fprintf(stderr, "Error %s\n", strerror(errno));
			exit(1);
		}
		memcpy(yylval.string_literal, buf, strlen(buf));
            /*if (yylval.string_literal) { 
                  free (yylval.string_literal);
            }; */
            //yylval.string_literal = strdup(buf); 
            return STRING; 
         }
      [^\"\'\\\n]+ {
            char *ptr = yytext; 
            while(*ptr) {
                  *buf_ptr++ = *ptr++;
            }
      }
      \\\" {*buf_ptr++ = '\"';}
      \\\? {*buf_ptr++ = '\?';}
      \\a {*buf_ptr++ = '\a';}
      \\b {*buf_ptr++ = '\b';}
      \\f {*buf_ptr++ = '\f';}
      \\n {*buf_ptr++ = '\n';}
      \\r {*buf_ptr++ = '\r';}
      \\t {*buf_ptr++ = '\t';}
      \\v {*buf_ptr++ = '\v';}
      \\[0-7]{1,3} {
            char temp = strtol(yytext+1, NULL, 8);
            if ((int)temp > 0xff) {
                  fprintf(stderr, "Warning: Octal escape sequence %s out of range", yytext); 
                  *buf_ptr++ = 0xff; 
            } else {
                  *buf_ptr++ = (char)temp; 
            }
      }
      \\[xX][0-9a-fA-F] {
            char temp = strtol(yytext, NULL, 16);
            if ((int) temp > 0xff) {
                  fprintf(stderr, "Warning: Hex escape sequence %s out of range", yytext);
                  *buf_ptr++ = 0xff;  
            } else {
                  *buf_ptr++ = (char)temp; 
            }
      }
      \n {
            fprintf(stderr, "Error: unterminated string constant");
      }
}
<CHAR>{
      \' {  
            BEGIN(INITIAL);
            if ((buf_ptr - buf) > 1) {
                  fprintf(stderr, "Warning: Unsupported multibyte character literal truncated to first byte\n");
            }
            yylval.char_literal = buf[0]; 
            return CHARLIT; 
         }
      \\\' {*buf_ptr++ = '\'';} 
}
<STRING>\' {*buf_ptr++ = '\'';} 
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
            if (report.fileName) {
                  printf("%s\t\t\t", report.fileName);
            } else {
                  printf("<STDIN>\t\t\t");
            };
            printf("%d\t\t\t", report.lineNum);

            switch(t) {
                  case(IDENT):
                        printf("IDENT\t\t\t%s\n", yylval.string_literal);
                        break;
                  case(NUMBER):
                        printf("NUMBER\t\t\tVAL:%lld\t\t\tTYPE:%d\n", yylval.numInfo.value.int_val, yylval.numInfo.meta);
                        break;
                  case(CHARLIT):
                        printf("CHARLIT\t\t\t%c\n", yylval.char_literal);
                        break;
                  case(STRING):
                        printf("STRING\t\t\t%s\n", yylval.string_literal);
                        free(yylval.string_literal); 
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