#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};
struct node* add_front(struct node* head,int d)
{
    struct node *temp = NULL;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("memory allocation failed");
        return head;
    }
    else{
        temp->data=d;
        temp->link=head;
        return temp;
    }
}
void display(struct node* head)
{
    struct node* ptr = head;
    if (head == NULL)
    {
        printf("List is empty");
    }
        while(ptr!= NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
}
void count(struct node* head)
{
    struct node*ptr=head;
    if(head == NULL)
    {
        printf("List is empty");
    }
    int count=0;
    while(ptr!=NULL)
     {
         ptr=ptr->link;
         count++;
     }
     printf("The total number of nodes are %d\n",count);
}
struct node* add_end(struct node* head,int d)
{
    struct node* temp=NULL,*ptr=head;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("memory allocation failed");
        return head;
    }
    temp->data=d;
    temp->link=NULL;

    if(head == NULL)
    {
        return head;
    }
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    return head;
}

void search(struct node* head,int d)
{
    struct node*ptr=head;
    if(head == NULL)
    {
        printf("list is empty");
    }
    int count=0,flag=0;
    while(ptr!=NULL)
    {
        count++;
        if(ptr->data==d)
        {
            printf("\nthe element %d found at %d node\n",d,count);
            flag=1;
        }
        ptr=ptr->link;
    }
    if(flag==0)
    {
        printf("\nElement not found\n");
    }
}
struct node* del_front(struct node* head)
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    struct node*ptr=head;
    ptr=head->link;
    printf("The node with data %d is deleted\n",head->data);
    free(head);
    return ptr;
}
struct node* del_end(struct node*head)
{
    struct node* ptr=head;
    if(head==NULL)
    {
        printf("List is empty");
    }
    while(ptr->link->link!=NULL)
    {
        ptr=ptr->link;
    }
    printf("The node with data %d is deleted\n",ptr->link->data);
    free(ptr->link);
    ptr->link=NULL;
    return head;
}
int main()
{
    struct node* head=NULL;
    head = add_front(head,57);
    head = add_front(head,28);
    head = add_end(head,45);
    head = del_front(head);
    head = del_end(head);
    count(head);
    display(head);
    search(head,28);

    return 0;
}
