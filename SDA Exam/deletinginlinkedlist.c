#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *DeleteFromBeg(struct node *head)
{
    if(head==0)
    {
        printf("Delete is not possible\n");
    }
    else
    {
        struct node *temp;
        temp=head;
        head=head->next;
        free(temp);
    }
    return head;
};
struct node *DeleteFromEnd(struct node *head)
{
    struct node *previous,*temp;
    temp=head;
    while(temp->next!=0)
    {
        previous=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=0;
        free(temp);
    }
    else
    {
        previous->next=0;
    }
    free(temp);
    return head;
};
struct node *DeleteFromAnyPosition(struct node *head)
{
    struct node *temp,*nextnode;
    int position,i=1;
    temp=head;
    printf("Enter position:\n");
    scanf("%d",&position);
    while(i<position-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
    return head;
};
void print(struct node *head)
{
    struct node *temp=head;
    printf("The linked list is:\n");
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    struct node *head,*newnode,*temp;
    head=0;
    int choice=1,count=0;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("DO you want to continue(0,1):");
        scanf("%d",&choice);
        count++;
    }
    printf("%d\n",count);
    print(head);
    head=DeleteFromBeg(head);
    print(head);
    head=DeleteFromEnd(head);
    print(head);
    head=DeleteFromAnyPosition(head);
    print(head);
    return 0;
}
