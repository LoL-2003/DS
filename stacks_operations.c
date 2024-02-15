#include<stdio.h>
#include<stdlib.h>

void push(int);
int pop();
void display();

#define STACKSIZE 5

int s[20],top=-1;

main()
{
	int id,ch,ele;
	while(1)
	{
		printf("Enter 1:Push\n2:Pop\n3:Display\n4:Exit\n");
		printf("Enter the choice:\n");
		scanf("%d",&ch); 
		switch(ch)
		{
			case 1:printf("Enter the element to be pushed:\n");
				scanf("%d",&ele);
				push(ele);
				break;
			case 2:id=pop();
				printf("The popped element is:%d\n",id);
				break;
			case 3:display();
				break;
			case 4:exit(0);
		}
	}
}
void push(int ele)
{
	if(top==STACKSIZE-1)
	{
		printf("The stack is full\n");
		return;
	}
	top++;
	s[top]=ele;
}
int pop()
{
	int ele;
	if(top==-1)
	{
		printf("The stack is empty\n");
		return;
	}
	ele=s[top--];
	return (ele);
}

void display()
{
	int i;	if(top==-1)
	{
		printf("The stack is empty\n");
		return;
	}
	printf("The contents of stack are:\n");
	for(i=top;i>=0;i--)
		printf("%d\t",s[i]);
}

			
