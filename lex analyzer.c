%{
#include<stdio.h>
%}
char [a-zA-Z]
digit [0-9]
id {char}+({char}|{digit})*
fun {id}\(\)
number {digit}+(\.{digit}+)*
lit \"({char}*{digit}*)*\"
%%
int|float { printf("%s is a keyword\n",yytext);}
"{" { printf("%s is an opening block\n",yytext);}
"}" { printf("%s is a closing block\n",yytext);}
"(" { printf("%s is a opening paranthesis\n",yytext);}
")" { printf("%s is a closing paranthesis\n",yytext);}
#.* { printf("%s is a preprocessor directive\n",yytext);}
int|float|char|for|if {printf("%s is a keyword\n",yytext);}
"+"|"-"|"/"|"*" {printf("%s is an arithmetic operator\n",yytext);}
"<"|"<="|">"|">="|"!=" {printf("%s is an relational operator\n",yytext);}
"=" {printf("%s is an assignment operator\n",yytext);}
";"|"," {printf("%s is a special symbol\n",yytext);}
{id} { printf("%s is an identifier\n",yytext);}
{number} {printf("%s is a number\n",yytext);}
"&&"|"||" {printf("%s is a logical operator\n",yytext);}
{fun} {printf("%s is an identifier\n",yytext);}
{lit} { printf("%s is a literal\n",yytext);}
%%
int main()
{
FILE *fp;
fp=fopen("ccode.c","r");
yyin=fp;
yylex();
fclose(fp);
}
int yywrap()
{
return 1;
}
