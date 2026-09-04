#include<bits/stdc++.h>
using namespace std;
int front=-1;
int rear=-1;
void enqueue(int queue[],int n)
{
     int x;
    cout<<"Enter the data what you want to push:"<<endl;
    cin>>x;
    if(rear==n-1)
    {
        cout<<"OVERFLOW"<<endl;
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        cout<<"UNDERFLOW"<<endl;
    }
    else if(front==rear)
{
    front=rear=-1;
}
else
{
    front++;
}
}
void print(int queue[],int front,int rear)
{
    cout<<"The queue is:"<<endl;
    for(int i=front;i<rear+1;i++)
    {
        cout<<queue[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter size:"<<endl;
    cin>>n;
    int queue[n];
    while(1)
    {
        int choice;
        cout<<"Enter 1 for push or 2 for pop 0r 0 for break:"<<endl;
        cin>>choice;
        if(choice==1)
        {
            enqueue(queue,n);
            print(queue,front,rear);
        }
        else if(choice==2)
        {
            dequeue();
            if(front!=-1 && rear!=-1){
            print(queue,front,rear);
            }
        }
        else
        {
            break;
        }
    }

}
