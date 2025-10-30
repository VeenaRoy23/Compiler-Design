#include<stdio.h>
#include<string.h>

int main(){
    char ip[30],input[30],stack[30],prec[30][30],symbol;
    int n;
    printf("Enter no. of ip: ");
    scanf("%d",&n);
    printf("Enter:\n");
    for(int i=0;i<n;i++)
    {
        scanf(" %c",&ip[i]);
    }
    printf("Precedence: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%c to %c: ",ip[i],ip[j]);
            scanf(" %c",&prec[i][j]);
        }
    }
    

    
    do{
        printf("String : ");
        scanf("%s",input);
        int p,q,top=-1,j=0,flag=0;
        char ch;
        int s=1;
        
        for(int k=0;input[k]!='\0';k++){
            char cur=input[k-1];
            char next=input[k];
            if((cur=='+' || cur=='*') && (next=='+' || next=='*')){
                flag=1;
                break;
            }
        }
        
        if(flag==1){
            printf("Rejected\n");
            continue;
        }
        
        
        
        flag=0;
        
        stack[++top]=input[j++];
        
        do{
            for(int k=0;k<n;k++)
            {
                if(stack[top]==ip[k]){
                    p=k;
                    break;
                }
            }
            
            for(int k=0;k<n;k++)
            {
                if(input[j]==ip[k]){
                    q=k;
                    break;
                }
            }
            
            ch=prec[p][q];
            
            if(ch=='-'){
                flag=1;
                break;
            }
            
            else if(ch=='<' || ch=='='){
                stack[++top]=input[j++];
            }
            
            else{
                do{
                    for(int k=0;k<n;k++)
                    {
                        if(stack[top--]==ip[k]){
                            p=k;
                            break;
                        }
                    }
                    
                    for(int k=0;k<n;k++)
                    {
                        if(stack[top]==ip[k]){
                            q=k;
                            break;
                        }
                    }
                    
                    symbol=prec[q][p];
                    
                }while(symbol!='<' && symbol!='=');
            }
        }while(!(stack[top]=='$' && input[j]=='$'));
        
        if(flag==0)
            printf("Accepted\n");
        else
            printf("Rejected\n");
    }while(strcmp(input,"E")!=0);
}
