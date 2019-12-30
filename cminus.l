%option noyywrap
%{
	#include "y.tab.h"
	extern YYSTYPE yylval;
%}

/* 数字 */
NUM         (0|[1-9][0-9]*)
/* 标识符 */
ID          [a-z_A-Z][a-z_A-Z0-9]*
/* 保留字 */
INT         int
RETURN      return
IF          if  
ELSE        else
VOID        void
WHILE       while
/* 注释(需要跳过) */
A           [/]
B           [*]
C           [^*/]
COMMENT     ("/*"{A}*({C}{A}*|{B}|{C})*"*/")
/* 空格(需要跳过) */
SPACES      [ \t\n\r\f\v]+

%%
{COMMENT}   {}
{SPACES}    {}

{ELSE}		{return ELSE;}
{IF}		{return IF;}
{INT}		{return INT;}
{RETURN} 	{return RETURN;}
{VOID} 		{return VOID;}
{WHILE} 	{return WHILE;}

{ID}	    {strcpy(yylval.s, yytext); return ID;}
{NUM}		{yylval.n = atoi(yytext); return NUM;}

"<="		{return LTE;}
">="		{return GTE;}
"=="		{return EQUAL;}
"!="		{return NOTEQUAL;}
"<"			{return yytext[0];}
">"			{return yytext[0];}
"="			{return yytext[0];}

"\("		{return yytext[0];}
"\)"		{return yytext[0];}
"\["		{return yytext[0];}
"\]"		{return yytext[0];}
"\{"		{return yytext[0];}
"\}"		{return yytext[0];}

"\+"		{return yytext[0];}
"\-"		{return yytext[0];}
"\*"		{return yytext[0];}
"\/"		{return yytext[0];}

";"			{return yytext[0];}
","			{return yytext[0];}

"\n"		{yylineno++;}
%%




