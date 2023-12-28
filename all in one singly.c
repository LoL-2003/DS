#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* add_front(struct node* head, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    temp->data = data;
    temp->link = head;
    return temp;
}

struct node* add_end(struct node* head, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    temp->data = data;
    temp->link = NULL;

    if (head == NULL) {
        return temp;
    }

    struct node* ptr = head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = temp;
    return head;
}

struct node* del_front(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    struct node* ptr = head;
    head = head->link;
    printf("%d deleted\n", ptr->data);
    free(ptr);

    if (head == NULL) {
        printf("No more nodes in the list\n");
    }

    return head;
}

struct node* del_end(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    struct node* prev = NULL;
    struct node* current = head;

    while (current->link != NULL) {
        prev = current;
        current = current->link;
    }

    if (prev == NULL) { // If only one node in the list
        free(head);
        return NULL;
    } else {
        prev->link = NULL;
        free(current);
        return head;
    }
}

void print_list(struct node* head) {
    int count = 1;
    struct node* ptr = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (ptr != NULL) {
        printf("The node at %d is %d\n", count++, ptr->data);
        ptr = ptr->link;
    }
}

int main() {
    struct node* head = NULL;

    head = add_front(head, 78);
    head = del_front(head);
    head = add_end(head, 67);
    head = del_end(head);
    head = add_front(head, 90);

    print_list(head);

    return 0;
}
