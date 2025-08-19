%{
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define YYSTYPE double
%}
%token NUMBER
%left '+''-'
%left '*''/'
%right UMINUS
%%
L:E'\n' {printf("Value: %lf\n", $1);exit(0);}
;
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|'('E')' {$$=$2;}
|'-'E %prec UMINUS {$$=$2;} 
|NUMBER {$$=$1;}
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
		scanf("%lf",&yylval);
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
