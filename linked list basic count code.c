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

int main() {
    struct node *head = malloc(sizeof(struct node));
    head->data=35;
    head->link=NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data=40;
    current->link=NULL;
    head->link=current;
    Cal(head);
}
