%{
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
%}
%token DIGIT LETTER
%%
L:A'\n' {printf("Valid variable\n");exit(1);}
;
A:LETTER B
|LETTER
;
B:LETTER B
|DIGIT B
|LETTER
|DIGIT
;
%%
void main()
{	
	printf("Enter the variable name: ");
	yyparse();
}

yylex()
{
	char ch;
	ch=getchar();
	if(isalpha(ch))
	{
		return LETTER;
	}
	else if(isdigit(ch))
	{
		return DIGIT;
	}
	else
		return ch;
}

yyerror()
{
	printf("Invalid variable\n");
	exit(0);
}
