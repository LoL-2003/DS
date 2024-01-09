void search(struct node* head,int d)
{
    struct node*ptr=head;
    if(head == NULL)
    {
        printf("list is empty");
    }
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        if(ptr->data==d)
        {
            printf("\nthe element %d found at %d node\n",d,count);
        }
        ptr=ptr->link;
    }
}
