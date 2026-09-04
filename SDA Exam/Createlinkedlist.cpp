#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node *create(Node *head){
    Node *newnode,*temp;
    head=NULL;
    int choice;
    while(choice){
        newnode=new Node;
        int data;
        cout<<"Enter data:"<<endl;
        cin>>newnode->data;
        newnode->next=NULL;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    cout<<"Enter 1 for continue:"<<endl;
    cin>>choice;
    }
    return head;
}
Node *InsertAtBeg(Node *head){
    Node *newnode;
    newnode=new Node;
    int data;
    cout<<"Enter data:"<<endl;
    cin>>newnode->data;
    newnode->next=head;
    head=newnode;
    return head;
}
Node *InsertAtEnd(Node *head){
    Node *newnode,*temp;
    newnode=new Node;
    int data;
    cout<<"Enter data:"<<endl;
    cin>>newnode->data;
    newnode->next=0;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}
Node *InsertAtAnyPos(Node *head){
    Node *newnode,*temp,*t;
   newnode=new Node;
   int count=0;
   t=head;
   while(t!=NULL){
    count++;
    t=t->next;
   }
   int position,i=1;
   cout<<"Enter position where you want to insert:"<<endl;
    cin>>position;
    if(position>count){
        cout<<"Invalid position"<<endl;
    }
    else{
        temp=head;
        while(i<position-1){
            temp=temp->next;
            i++;
        }
        int data;
        cout<<"Enter data:"<<endl;
        cin>>newnode->data;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}
Node *DeleteAtBeg(Node *head){
    Node *temp;
    temp=head;
    head=head->next;
    free(temp);
    return head;

}
Node *DeleteAtEnd(Node *head){
    Node *previous,*temp;
    temp=head;
    while(temp->next!=NULL){
        previous=temp;
        temp=temp->next;
    }
    previous->next=NULL;
    free(temp);
    return head;
}
Node *DeleteAtAnyPos(Node *head){
    Node *nextnode,*temp,*t;
    int count=0;
    t=head;
    while(t!=0){
        count++;
        t=t->next;
    }
    int position;
    cout<<"Enter position where u want to delete:"<<endl;
    cin>>position;
    int i=1;
    if(position>count){
        cout<<"Invalid position"<<endl;

    }
    else{
        temp=head;
        while(i<position-1){
            temp=temp->next;
            i++;
        }
        nextnode=temp->next;
        temp->next=nextnode->next;
        free(nextnode);
        return head;
    }
}
Node *print(Node *head){
    Node *temp;
    temp=head;
    cout<<"The linked list is:"<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return head;
}
int main(){
   Node *head,*temp;
   head=create(head);
   print(head);
   //head=InsertAtAnyPos(head);
   //head=print(head);
   head=DeleteAtAnyPos(head);
   cout<<"\nThe linked list after deletion:"<<endl;
   print(head);
}