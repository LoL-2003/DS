#include"stdio.h"
#include"stdlib.h"
struct node{
    int data;
    struct node *link;
};
struct node* add_front(struct node* last,int d)
{
        struct node* ptr=last,*temp=NULL;
        temp=(struct node*)malloc(sizeof(struct node));
        if(temp==NULL)
        {
            printf("Memory allocation failed");
            return last;
        }
        if(last==NULL)
        {
           temp->data=d;
           temp->link=temp;
           return temp;
        }
        temp->data=d;
        ptr=last->link;
        temp->link=ptr;
        last->link=temp;
}
void display(struct node* last)
{
    if(last==NULL)
    {
        printf("list is empty");
    }
    struct node *ptr=last->link;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }while(ptr!=last->link);
}
struct node* add_end(struct node*last,int d)
{

    struct node* temp = NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Memory allocation failed");
        return last;
    }
    temp->data=d;
    temp->link=last->link;
    last->link=temp;
    return temp;
}
struct node* del_end(struct node*last)
{
    struct node *ptr=last->link,*temp;
    if(last==NULL)
    {
        printf("List is empty");
        return last;
    }
    do{
        ptr=ptr->link;
    }while(ptr!=last->link->link);
    temp=ptr->link->link;
    free(ptr->link);
    ptr->link=temp;
    return ptr;
}
struct node* del_front(struct node* last)
{
    struct node* temp,*ptr=last->link;
    if(last==NULL)
    {
        printf("list is empty");
        return last;
    }
    if(last->link==ptr->link)
    {
        free(ptr->link);
        return NULL;
    }
    ptr=ptr->link;
    free(last->link);
    last->link=ptr;
    return last;

}
void count(struct node*last)
{
    if(last==NULL){
        printf("list is empty");
    }
    struct node*ptr=last->link;
    int count=0;
    do{
        count++;
        ptr=ptr->link;
    }while(ptr!=last->link);
    printf("\n total number of nodes = %d",count);
}
void search(struct node*last,int d)
{
    if(last==NULL){
        printf("list is empty");
    }
    struct node*ptr=last->link;
    int count=0,flag=0;
    do{
        count++;
        ptr=ptr->link;
        if(ptr->data==d)
        {
            printf("\n%d data found at %d node",d,count+1);
            flag=1;
        }
    }while(ptr!=last->link);
    if(flag==0){printf("\nElement not found");}
}
int main()
{
    struct node *last=NULL;
    last=add_front(last,45);
    last=add_front(last,4);
    last=add_front(last,5);
    last=add_front(last,4+5);
    last=add_end(last,90);
    last=del_front(last);
    last=del_end(last);
    display(last);
    search(last,5);
    count(last);
}
