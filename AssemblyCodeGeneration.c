#include<stdio.h>
#include<ctype.h>
#include<string.h>

char postfix[30];
char stack[30];

int prec(char c){
	if(c=='^') return 3;
	else if(c=='/'||c=='*') return 2;
	else if(c=='+'||c=='-') return 1;
	else return -1;
}


void infixToPostfix(char *expr){
	int len=strlen(expr);
	int j=0,top=-1;
	for(int i=0;i<len;i++){
		char c=expr[i];
		if(isalnum(c)) 
			postfix[j++]=c;
		else if(c=='(')
			stack[++top]=c;
		else if(c==')'){
			while(top!=-1&&stack[top]!='(')
				postfix[j++]=stack[top--];
			top--;
		}
		else{
			while(top!=-1&&(prec(c)<prec(stack[top])||prec(c)==prec(stack[top])))
				postfix[j++]=stack[top--];
			stack[++top]=c;
		}
	}
	
	while(top!=-1)
		postfix[j++]=stack[top--];
	
	postfix[j]='\0';
	printf("Postfix expression:%s\n",postfix);
}



int main()
{
	char expr[30],ch;
	int start,i=0;
	printf("Enter the expression: ");
	scanf("%s", expr);
	printf("Enter the starting address: ");
	scanf("%d",&start);
	infixToPostfix(expr);
	
	ch=postfix[i];
	while(ch!='\0')
	{
		if(isalpha(ch)|| isdigit(ch))
		{	
			printf("%d : MOV A, %c \n",start,ch);
			start++;
			printf("%d : PUSH A\n",start);
			start++;
		}
		
		else{
			printf("%d : POP B\n",start);
			start++;
			printf("%d : POP A\n",start);
			start++;
			
			if(ch=='*')
			{
				printf("%d : MUL B\n",start);
				start++;
			}
			else if(ch=='+')
			{
				printf("%d : ADD B\n",start);
				start++;
			}
			else if(ch=='/')
			{
				printf("%d : DIV B\n",start);
				start++;
			}
			else if(ch=='-')
			{
				printf("%d : SUB B\n",start);
				start++;
			}
			printf("%d : PUSH A\n", start);
			start++;
		}
		ch=postfix[i];
		i++;
	}
	
	printf("%d : POP A\n",start);
	start++;
	printf("%d : HLT\n",start);
}

	
	

