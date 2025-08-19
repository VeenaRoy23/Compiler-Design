%{
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
%}
%token NUMBER
%%
L:E'\n' {printf("Value: %d\n", $1);exit(1);}
;
E:E'+'T {$$=$1+$3;}
|T {$$=$1;}
;
T:T'*'F {$$=$1*$3;}
|F {$$=$1;}
;
F:NUMBER {$$=$1;}
;
%%
void main()
{
	printf("Enter the expression: ");
	yyparse();
}
yylex()
{
	char ch;
	ch=getchar();
	if(isdigit(ch))
	{
		ungetc(ch,stdin);
		scanf("%d",&yylval);
		return NUMBER;
	}
	else{
		return ch;
	}
}
yyerror()
{
	printf("Invalid Expression\n");
	exit(0);
}	
