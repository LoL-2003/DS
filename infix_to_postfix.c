#include<stdio.h>
#include<string.h>

int F(char sym) /*F=Stack precedence*/
{
	switch(sym)
	{
		case '+':
		case '-': return 2;

		case '*':
		case '/': return 4;

		case '(': return 0;
		case '#': return -1;

		default: return 8;
	}
				
}

int G(char sym) /*G= Input Precendence*/
{
	switch(sym)
	{
		case '+':
		case '-': return 1;

		case '*':
		case '/': return 3;

		case '(': return 9;
		case ')': return 0;

		default: return 7;
	}
}

void InfixToPostfix(char infix[],char postfix[])
{
	char sym;
	int i,j=0,top=-1;
	char stk[50];
	stk[++top]='#';
	for(i=0;i < strlen(infix);i++)
	{
		sym = infix[i];
		while(F(stk[top]) > G(sym))
		{
			postfix[j] = stk[top--];
			j++;
		}
		if(F(stk[top]) != G(sym))
		{
			stk[++top]=sym;
		}
		else
			top--;

	}
	while(stk[top] != '#')
	{
		if(stk[top] != '(')
			postfix[j++]=stk[top--];
	}
	postfix[j]='\0';
}

void main()
{
	char infix[50],postfix[50];
	printf("Enter the infix expr:");
	scanf("%s",infix);
	InfixToPostfix(infix,postfix);
	printf("The postfix expr. is : %s", postfix);
}
