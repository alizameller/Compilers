enum tokens {
	TOKEOF=0,
	IDENT=257,	/* This is where yacc will put it */
	CHARLIT,
	STRING,
	NUMBER,
	INDSEL,
	PLUSPLUS,
	MINUSMINUS,
	SHL,
	SHR,
	LTEQ,
	GTEQ,
	EQEQ,
	NOTEQ,
	LOGAND,
	LOGOR,
	ELLIPSIS,
	TIMESEQ,
	DIVEQ,
	MODEQ,
	PLUSEQ,
	MINUSEQ,
	SHLEQ,
	SHREQ,
	ANDEQ,
	OREQ,
	XOREQ,
	AUTO,
	BREAK,
	CASE,
	CHAR,
	CONST,
	CONTINUE,
	DEFAULT,
	DO,
	DOUBLE,
	ELSE,
	ENUM,
	EXTERN,
	FLOAT,
	FOR,
	GOTO,
	IF,
	INLINE,
	INT,
	LONG,
	REGISTER,
	RESTRICT,
	RETURN,
	SHORT,
	SIGNED,
	SIZEOF,
	STATIC,
	STRUCT,
	SWITCH,
	TYPEDEF,
	UNION,
	UNSIGNED,
	VOID,
	VOLATILE,
	WHILE,
	_BOOL,
	_COMPLEX,
	_IMAGINARY
};

typedef union {
          char *string_literal;
          int integer;
} YYSTYPE;

YYSTYPE yylval;

struct info {
      char *fileName; 
      int lineNum;
};

struct info report;