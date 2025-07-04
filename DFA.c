#include<stdio.h>

int main()
{
	int n, inp_n,f_n,final[20],trans[20][20];
	char alpha[20],input[20];
	
	printf("Enter the no. of states:");
	scanf("%d",&n);
	printf("Enter the no. of input alphabets:");
	scanf("%d",&inp_n);
	printf("Enter the input alphabets\n");
	scanf("%s",alpha);
	printf("Enter the transitions:\n");

//read and store the transitions as transition matrix
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<inp_n;j++)
		{
			printf("From state %d on alphabet %c: ",i,alpha[j]);
			scanf("%d",&trans[i][j]);
		}
	}
	printf("Enter the no. of final states:");
	scanf("%d",&f_n);
	printf("Enter the final states\n");
	for(int i=0;i<f_n;i++)
	{
		scanf("%d",&final[i]);
	}
	printf("Enter the input string('exit' to exit the loop: ");
	scanf("%s",input);
	do{
	int i=0;
	int current_state=0;
	while(input[i]!='\0')
	{
		int char_match=-1;
		for(int j=0;j<inp_n;j++)
		{
			if(alpha[j]==input[i])
			{
				char_match=j;
				break;
			}
		}
		
		if(char_match==-1)
		{
			printf("Invalid input alphabet\n");
			return 1;
		}
		else{
			current_state=trans[current_state][char_match];
			char_match=-1;
		}
		i++;
	}
	int accepted=-1;
	for(int j=0;j<f_n;j++)
	{
		if(final[j]==current_state)
		{
			printf("String accepted!\n");
			accepted=1;
		}
	}
	if(accepted !=1)
		printf("String rejected\n");
	/* aaabbbccddd */
	printf("Enter the input string('exit' to exit the loop): ");
	scanf("%s",input);
	}while(input!="exit");
}
