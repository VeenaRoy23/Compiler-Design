#include<stdio.h>
int top=0;
char input[20],stack[20];
int slno=1,j=0;


void reduce()
{
	for(int z=0;z<top;z++)
	{
		if(stack[z]=='i')
		{
			stack[z]='E';
			printf("%d\t$%s\t%s$\treduce E-->i\n",slno,stack,input);
			slno++;
		}
	}
	
	for(int z=0;z<top;z++)
	{
		if(stack[z]=='(' && stack[z+1]=='E' && stack[z+2]==')')
		{
			stack[z]='E';
			stack[z+1]='\0';
			printf("%d\t$%s\t%s$\treduce E-->(E)\n",slno,stack,input);
			slno++;
			top=top-2;
		}
	}
	
	for(int z=0;z<top;z++)
	{
		if(stack[z]=='E' && stack[z+1]=='+' && stack[z+2]=='E')
		{
			stack[z]='E';
			stack[z+1]='\0';
			printf("%d\t$%s\t%s$\treduce E-->E+E\n",slno,stack,input);
			slno++;
			top=top-2;
		}
	}
	
	for(int z=0;z<top;z++)
	{
		if(stack[z]=='E' && stack[z+1]=='*' && stack[z+2]=='E')
		{
			stack[z]='E';
			stack[z+1]='\0';
			printf("%d\t$%s\t%s$\treduce E-->E*E\n",slno,stack,input);
			slno++;
			top=top-2;
		}
	}
		
}

int main()
{
	printf("Enter the string: ");
	scanf("%s",input);
	printf("slno\tstack\tinput\taction\n");
	
	while(input[j]!='\0')
	{
		char ch=input[j];
		stack[top++]=ch;
		stack[top]='\0';
		input[j]=' ';
		j++;
		printf("%d\t$%s\t%s$\tshift %c\n",slno,stack,input,ch);
		slno++;
		reduce();
	}
	
	if(stack[0]=='E' && stack[1]=='\0')
	{
		printf("Accepted\n");
		
	}
	else
		printf("rejected\n");
}
		
		
