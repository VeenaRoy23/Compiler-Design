%{
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int flag=0,a;
%}
DIGIT[0-9]
%%
"+" {flag=1;}
"-" {flag=2;}
"*" {flag=3;}
"/" {flag=4;}
"^" {flag=5;}
{DIGIT}+ {if(flag==0){
	a=atoi(yytext);
	}
	else if(flag==1)
	{	
		a=a+atoi(yytext);
	}
	else if(flag==2)
	{	
		a=a-atoi(yytext);
	}
	else if(flag==3)
	{	
		a=a*atoi(yytext);
	}
	else if(flag==4)
	{	
		a=a/atoi(yytext);
	}
	else if(flag==5)
	{	
		for(int i=0;i<atoi(yytext);i++){
			a=a*a;
		}
	}
}
"\n" {printf("Result: %d\n",a);}
. {printf("Error at character %s\n",yytext);exit(0);}
%%
void main()
{
	yyin=stdin;
	yylex();
}
int yywrap(){
	return 1;
}

