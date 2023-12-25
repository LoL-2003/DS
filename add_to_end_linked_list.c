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
int main() {
    struct node *head = malloc(sizeof(struct node));
    head->data=35;
    head->link=NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data=40;
    current->link=NULL;
    head->link=current;
    add_to_end(head ,90);
    Cal(head);
}
