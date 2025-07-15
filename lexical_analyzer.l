%{
	#include<stdio.h>
	#include<stdlib.h>
	int line=1;
	int sl_no=1;
	FILE * fp;
%}
DIGIT [0-9]
ALPHA [a-zA-Z]
WS [ \t]
%%
{WS} {}
"\n" {line++;}
";" {fprintf(fp,"%d\t;\tSemiColon\t%d\n",sl_no,line);sl_no++;}
"+"|"-"|"*"|"/" {fprintf(fp,"%d\t%s\tArthmetic_Op\t%d\n",sl_no,yytext,line);sl_no++;}
"<"|">"|"<="|">="|"!"|"!="|"==" {fprintf(fp,"%d\t%s\tRelational_Op\t%d\n",sl_no,yytext,line);sl_no++;}
"=" {fprintf(fp,"%d\t=\tAssignment_Op\t%d\n",sl_no,line);sl_no++;}
"void"|"main"|"printf"|"scanf"|"int"|"include"|"stdio.h"|"if"|"else" {fprintf(fp,"%d\t%s\tKeywords\t%d\n",sl_no,yytext,line);sl_no++;}
{ALPHA}({ALPHA}|{DIGIT})* {fprintf(fp,"%d\t%s\tIdentifier\t%d\n",sl_no,yytext,line);sl_no++;}
{DIGIT}+"."{DIGIT}+ {fprintf(fp,"%d\t%s\tFloatingpoint_number\t%d\n",sl_no,yytext,line);sl_no++;}
{DIGIT}+ {fprintf(fp,"%d\t%s\tNumber\t%d\n",sl_no,yytext,line);sl_no++;}
"{"|"("|"[" {fprintf(fp,"%d\t%s\tOpen_Brackets\t%d\n",sl_no,yytext,line);sl_no++;}
"}"|")"|"]" {fprintf(fp,"%d\t%s\tClose_Brackets\t%d\n",sl_no,yytext,line);sl_no++;}
"#"|"," {fprintf(fp,"%d\t%s\tSpecial_Op\t%d\n",sl_no,yytext,line);sl_no++;}
. {fprintf(fp,"%d\t%s\tUnrecognized\t%d\n",sl_no,yytext,line);sl_no++;}

%%
void main(int argc,char * argv[]){
	yyin=fopen(argv[1],"r");
	fp=fopen(argv[2],"w");
	yylex();
}
int yywrap(){
	return 1;
}
	
