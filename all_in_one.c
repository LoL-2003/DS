#include<stdio.h>
#include"stdlib.h"
struct node{
    int data;
    struct node *link;
};
void Cal(struct node *head) {
    if (head == NULL)
    {
        printf("linked list is empty");
    }
    struct node *ptr =head;
    int count=0;
    while(ptr != NULL)
    {
        printf("the element is = %d\n",ptr->data);
        ptr = ptr->link;
        count+=1;
    }
    printf("the number of elements = %d",count);
}
void add_to_end(struct node *head ,int data){
    struct node *ptr,*temp;
    ptr=head;
    temp->data = data;
    temp->link = NULL;
    while(ptr->link!=NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}
struct node* add_pos(struct node *head ,int data ,int pos){
    struct node *ptr,*ptr2;
    ptr2 = (struct node*)malloc(sizeof(struct node*));
    ptr2->data = data;
    ptr2->link = NULL;
    ptr=head;
    while(pos!=1)
    {
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
    return NULL;
}
struct node* del_front(struct node* head)
{
    if (head == NULL)
    {
        printf("list is empty\n");
        return NULL;
    }
    else{
        struct node* ptr = head;
        head= ptr->link;
        printf("%d is deleted\n",ptr->data);
        free(ptr);
        return head;
    }
}
struct node* del_end(struct node* head)
{
    struct node* ptr=head;
    if(head==NULL)
    {
        printf("list is empty\n");
        return NULL;
    }
    else{
        while(ptr->link->link != NULL)
        {
            ptr=ptr->link;
        }
        printf("%d is deleted\n",ptr->link->data);
        free(ptr->link);
        ptr->link=NULL;
        return head;
    }
}
int main() {
    struct node *head = malloc(sizeof(struct node));
    head->data=35;
    head->link=NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data=40;
    current->link=NULL;
    head->link=current;
    add_pos(head ,45,2);
    add_to_end(head ,90);
    head = del_front(head);
    head = del_end(head);
    Cal(head);
}
