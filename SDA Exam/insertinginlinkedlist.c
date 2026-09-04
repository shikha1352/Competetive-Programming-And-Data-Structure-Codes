#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
/*struct node* insert(struct node *head)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=head;
        head=newnode;
        return head;

};*/
/*struct node* insert(struct node *head)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        temp=head;
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        return head;

};*/
struct node* insert(struct node *head,int count)
{
    int position,i=1;
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter position whrere inert a data:\n");
        scanf("%d",&position);
        if(position>count)
        {
            printf("Invalid position\n");
        }
        else{
        //newnode->next=0;
        temp=head;
        while(i<position-1)
        {
            temp=temp->next;
            i++;
        }
        printf("insert data:");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
        return head;
        }
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
    head=insert(head,count);
    print(head);
    return 0;
}
