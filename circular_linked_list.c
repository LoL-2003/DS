#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void print_count(struct node* last) {
    if (last == NULL) {
        printf("The list is empty\n");
    } else {
        int count = 1;
        struct node *temp = last->link; // Start from the first node
        do {
            printf("The element at %d node is %d\n", count, temp->data);
            count++;
            temp = temp->link;
        } while (temp != last->link); // Traverse till the first node is reached again
    }
}

struct node* add_front(struct node* last, int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return last;
    }

    temp->data = data;
    if (last == NULL) {
        temp->link = temp;
        return temp;
    }
    temp->link = last->link;
    last->link = temp;
    return last;
}
struct node* add_end(struct node* last, int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return last;
    }

    temp->data = data;
    if (last == NULL) {
        temp->link = temp;
        return temp;
    }
    temp->link = last->link;
    last->link = temp;
    return last;
}
struct node* del_end(struct node* last) {
    struct node *temp ;
    if (last == NULL) {
        printf("List is empty");
        return NULL;
    }
    temp=last->link;
    do
    {
        temp=temp->link;
    }while(temp->link!=last);
    temp->link=last->link;
    free(last);
    return temp;
}
struct node* del_front(struct node* last) {
    struct node *temp ;
    if (last == NULL) {
        printf("List is empty");
        return NULL;
    }
    temp=last->link->link;
    free(last->link);
    last->link=temp;
    return last;
}

int main() {
    struct node *last = NULL;

    last = add_front(last, 24);
    last = add_front(last, 34);
    last = add_front(last, 89);
    last = add_end(last,45);
    last= del_end(last);
    last= del_front(last);
    print_count(last);
    return 0;
}
