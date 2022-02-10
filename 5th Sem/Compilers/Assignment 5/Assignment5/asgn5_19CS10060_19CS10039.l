/*
COMPILERS LAB ASSIGNMENT 5
GROUP 18
SUNANDA MANDAL|19CS10060
KAUSHAL BANTHIA|19CS10039
*/
%option noyywrap
/*************************** declaration return types(Lexical Elements) ***************************/
%{
    #include <stdio.h>
	#include <string.h>
	#include "asgn5_19CS10060_19CS10039_translator.h"
	#include "asgn5_19CS10060_19CS10039.tab.h"
    extern YYSTYPE yylval;
    extern int line;
    int line = 1;
%}

/******************* Declaration: Regular Expression for Lexical Elements ***********************/

%x COMMENT
KEYWORD                     "auto"|"enum"|"restrict"|"unsigned"|"break"|"extern"|"return"|"void"|"case"|"float"|"short"|"volatile"|"char"|"for"|"signed"|"while"|"const"|"goto"|"sizeof"|"_Bool"|"continue"|"if"|"static"|"_Complex"|"default"|"inline"|"struct"|"_Imaginary"|"do"|"int"|"switch"|"double"|"long"|"typedef"|"else"|"register"|"union"
PUNCTUATORS                 "["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|","|"#"
NON_DIGIT                   [a-zA-Z_]
DIGIT                       [0-9]
EXP                         ([Ee][-+]?{DIGIT}+)
FRACTIONAL                  (({DIGIT}+)?\.{DIGIT}+)|(({DIGIT}+)\.)
C_CHAR                      [^'\\\n]|{ESCAPE_SEQUENCE}
S_CHAR                      [^"\\\n]|{ESCAPE_SEQUENCE}

IDENTIFIER                  {NON_DIGIT}({NON_DIGIT}|{DIGIT})*
CONSTANT_INT                0|[1-9]{DIGIT}*
CONSTANT_FLOAT              ({FRACTIONAL}{EXP}?)|({DIGIT}+{EXP})
CONSTANT_CHAR               \'{C_CHAR}+\'
CONSTANT_ENUMERATION        {IDENTIFIER}

STRING_LITERAL              \"{S_CHAR}*\"

ESCAPE_SEQUENCE             \\['"?\\abfnrtv]

WHITESPACE                  [ \t\v\f]
NEWLINE         			[\n]

/**************************************** Lexical RULES *****************************************/
%%


"_Bool"                 { return BOOL;      }
"_Complex"              { return COMPLEX;   }
"_Imaginary"            { return IMAGINARY; }
"auto"			        { return AUTO;      }
"break"                 { return BREAK;     }
"case"                  { return CASE;      }
"char"                  { return CHAR;      }
"const"                 { return CONST;     }
"continue"              { return CONTINUE;  }
"default"               { return DEFAULT;   }
"do"                    { return DO;        }
"double"                { return DOUBLE;    }
"else"                  { return ELSE;      }
"enum"                  { return ENUM;      }
"extern"                { return EXTERN;    }
"float"                 { return FLOAT;     }
"for"                   { return FOR;       }
"goto"                  { return GOTO;      }
"if"                    { return IF;        }
"inline"                { return INLINE;    }
"int"                   { return INT;       }
"long"                  { return LONG;      }
"register"              { return REGISTER;  }
"restrict"              { return RESTRICT;  }
"return"                { return RETURN;    }
"short"                 { return SHORT;     }
"signed"                { return SIGNED;    }
"sizeof"                { return SIZEOF;    }
"static"                { return STATIC;    }
"struct"                { return STRUCT;    }
"switch"                { return SWITCH;    }
"typedef"               { return TYPEDEF;   }
"union"                 { return UNION;     }
"unsigned"              { return UNSIGNED;  }
"void"                  { return VOID;      }
"volatile"              { return VOLATILE;  }
"while"                 { return WHILE;     }


{IDENTIFIER}            { yylval.symp = ST->lookup(yytext); return IDENTIFIER; /* Identifier Rule */  }
{CONSTANT_INT}          { yylval.intval = atoi(yytext); return INT_CONSTANT; /* Constant Rule */ }
{CONSTANT_FLOAT}        { yylval.char_value = yytext; return FLOAT_CONSTANT; /* Constant Rule */  }
{CONSTANT_CHAR}         { yylval.char_value = yytext; return CHAR_CONSTANT; /* Constant Rule */  }
{STRING_LITERAL}        { yylval.char_value = yytext; return STRING_LITERAL; /* String-literal */ }
{NEWLINE}               { line++; }
{ESCAPE_SEQUENCE}       ;
{WHITESPACE}            { /* Ignore */ }
"/*"                    { BEGIN(COMMENT); }
<COMMENT>"*/"           { BEGIN(INITIAL); line++; }
<COMMENT>([^*]|\n)+|.   {  }
<COMMENT><<EOF>>        {  }
"//".*                  { }


"!"                     { return EXCLAIM; }
"!="			        { return NOTEQUAL; }
"#"                     { return HASH; }
"%"                     { return MOD; }
"%="			        { return MODASSIGN; }
"&"                     { return BITWISE_AND; }
"&&"			        { return AND; }
"&="			        { return ANDASSIGN; }
"("                     { return ROUND_BRACKET_OPEN; }
")"                     { return ROUND_BRACKET_CLOSE; }
"*"                     { return MUL; }
"*="			        { return MULTIPLYASSIGN; }
"+"                     { return PLUS; }
"++"			        { return INCREMENT; }
"+="			        { return ADDASSIGN; }
","                     { return COMMA; }
"-"                     { return MINUS; }
"--"			        { return DECREMENT; }
"-="			        { return SUBTRACTASSIGN; }
"->"			        { return ARROW; }
"."                     { return DOT; }
"..."			        { return ELLIPSIS; }
"/"                     { return DIV; }
"/="			        { return DIVIDEASSIGN; }
":"                     { return COLON; }
";"                     { return SEMICOLON; }
"<"                     { return LESSTHAN; }
"<<"			        { return LEFTSHIFT; }
"<<="			        { return LEFTSHIFTASSIGN; }
"<="			        { return LESSTHANEQUAL; }
"="                     { return ASSIGN; }
"=="			        { return EQUALEQUAL; }
">"                     { return GREATERTHAN; }
">="			        { return GREATERTHANEQUAL; }
">>"			        { return RIGHTSHIFT; }
">>="			        { return RIGHTSHIFTASSIGN; }
"?"                     { return QUESTION; }
"["                     { return SQUARE_BRACKET_OPEN; }
"]"                     { return SQUARE_BRACKET_CLOSE; }
"^"                     { return BITWISE_XOR; }
"^="			        { return XORASSIGN; }
"{"                     { return CURLY_BRACKET_OPEN; }
"|"                     { return BITWISE_OR; }
"|="			        { return ORASSIGN; }
"||"			        { return OR; }
"}"                     { return CURLY_BRACKET_CLOSE; }
"~"                     { return BITWISE_NOT; }

%%