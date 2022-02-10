/*
COMPILERS LAB ASSIGNMENT 3
GROUP 18
SUNANDA MANDAL|19CS10060
KAUSHAL BANTHIA|19CS10039
*/

/*************************** declaration return types(Lexical Elements) ***************************/
%{
    #define KEYWORD 1
    #define IDENTIFIER 2
    #define CONSTANT_INT 3
    #define CONSTANT_FLOAT 4
    #define CONSTANT_ENUM 5
    #define CONSTANT_CHAR 6
    #define ESCAPE_SEQUENCE 7
    #define STRING_LITERAL 8
    #define PUNCTUATOR 9
    #define COMMENT_SIN 10
    #define COMMENT_MUL 11
    #define COMMENT_MUL_START 12
    #define COMMENT_MUL_END 13
    #define ERR_COMMENT 14
    #define UNKNOWN 15
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

STRING_LITERAL              \"{S_CHAR}+\"

ESCAPE_SEQUENCE             \\['"?\\abfnrtv]

WHITESPACE                  [ \n\t\v\f]

/**************************************** Lexical RULES *****************************************/
%%


{KEYWORD}                                       { return KEYWORD; }
{IDENTIFIER}                                    { return IDENTIFIER; }
{CONSTANT_INT}                                  { return CONSTANT_INT; }
{CONSTANT_FLOAT}                                { return CONSTANT_FLOAT; }
{CONSTANT_CHAR}                                 { return CONSTANT_CHAR; }
{STRING_LITERAL}                                { return STRING_LITERAL; }
{PUNCTUATORS}                                   { return PUNCTUATOR; }
{ESCAPE_SEQUENCE}                               { return ESCAPE_SEQUENCE; }
{WHITESPACE}				                    { /* Ignore */ }

"/*"                                            { BEGIN(COMMENT); return COMMENT_MUL_START; }
<COMMENT>"*/"                                   { BEGIN(INITIAL); return COMMENT_MUL_END; }
<COMMENT>([^*]|\n)+|.                           { return COMMENT_MUL; }
<COMMENT><<EOF>>                                { return ERR_COMMENT; }

"//".*                                          { return COMMENT_SIN; }

.                                               { return UNKNOWN; }

%%

