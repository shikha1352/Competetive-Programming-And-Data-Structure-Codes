#include<bits/stdc++.h>
using namespace std;
int front=-1,rear=-1;
void enqueue(int queue[],int n)
{
    int x;
    cout<<"Enter the elements what you want to push:"<<endl;
    cin>>x;
    if(front==-1 && rear==-1)
    {

        front=0;
        rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%n==front)
    {
        cout<<"OVERFLOW"<<endl;
    }
    else
    {
        rear=(rear+1)%n;
        queue[rear]=x;
    }
}
void dequeue(int queue[],int n)
{
    if(front==-1 &&rear==-1)
    {
        cout<<"UNDERFLOW"<<endl;
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%n;
    }
}
void print(int queue[],int n)
{
    if(front==-1 && rear==-1)
    {
        cout<<"queue is empty"<<endl;
    }
    else if(front>rear)
    {
        for(int i=front;i<n;i++)
        {
            cout<<queue[i]<<" ";
        }
        for(int i=0;i<rear+1;i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"The queue is:"<<endl;
        for(int i=front;i<rear+1;i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter the size of the queue:"<<endl;
    cin>>n;
    int queue[n];
    int choice;
    while(1)
    {
        cout<<"Enter 1 for enqueue or 2 for dequeue or 0 for break:"<<endl;
        cin>>choice;
        if(choice==1)
        {
            enqueue(queue,n);
            print(queue,n);
        }
        else if(choice==2)
        {
            dequeue(queue,n);
            print(queue,n);
        }
        else
        {
            break;
        }
    }
}
