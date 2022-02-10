#include<stdio.h>
yywrap(){}

int main(int argc, char *argv[]){
    if(argc!=2){
        printf("ERROR in number of arguments\n");
        exit(0);
    }
    extern FILE *yyin;
    //extern FILE *yyout;
    yyin = fopen(argv[1],"r");
    //yyout = fopen("output.txt","w");
    int token;
    while(token=yylex()){
        switch(token){
            case KEYWORD:
                printf("<KEYWORD, %s >\n",yytext);
                break;
            case IDENTIFIER:
                printf("<IDENTIFIER, %s >\n",yytext);
                break;
            case CONSTANT_INT:
                printf("<INTEGER CONSTANT, %s >\n",yytext);
                break;
            case CONSTANT_FLOAT:
                printf("<FLOATING POINT CONSTANT, %s >\n",yytext);
                break;
            case CONSTANT_ENUM:
                printf("<ENUMERATION CONSTANT, %s >\n",yytext);
                break;
            case CONSTANT_CHAR:
                printf("<CHARACTER CONSTANT, %s >\n",yytext);
                break;
            case ESCAPE_SEQUENCE:
                printf("<ESCAPE SEQUENCE, %s >\n",yytext);
                break;
            case STRING_LITERAL:
                printf("<STRING_LITERAL, %s >\n",yytext);
                break;
            case PUNCTUATOR:
                printf("<PUNCTUATOR, %s >\n",yytext);
                break;
            case COMMENT_MUL_START:
                printf("<MULTIPLE LINE COMMENT STARTS, %s >\n",yytext);
                break;
            case COMMENT_MUL_END:
                printf("\n<MULTIPLE LINE COMMENT ENDS, %s >\n",yytext);
                break;
            case COMMENT_MUL:
                printf("%s",yytext);
                break;
            case COMMENT_SIN:
                printf("<SINGLE LINE COMMENT, %s >\n",yytext);
                break;
            case ERR_COMMENT:
                printf("<COMMENT ERROR :, %s >\n",yytext);
                break;
            default:
                printf("undefined lexeme : %s\n",yytext);
                break;
        }
    }
    return 0;
}