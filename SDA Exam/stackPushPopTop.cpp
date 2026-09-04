#include<bits/stdc++.h>
using namespace std;
#define N 5
int stack[N];
int top=-1;
void push()
{
    int x;
    cout<<"Enter data:"<<endl;
    cin>>x;
    if(top==N-1)
    {
        cout<<"OVERFLOW"<<endl;
    }
    else{
        top++;
        stack[top]=x;
    }
}
void pop()
{
    int item;
    if(top==-1)
    {
        cout<<"UNDERFLOW"<<endl;
    }
    else{
        item=stack[top];
        top--;
        cout<<"the popped element is:"<<item<<endl;
    }
}
void peek()
{
    if(top==-1)
    {
        cout<<"top is empty"<<endl;
    }
    else
    {
        cout<<"top element is:"<<stack[top]<<endl;
    }
}
void display()
{
    int i;
    cout<<"The stack is:"<<endl;
    for(int i=top;i>=0;i--)
    {
        cout<<stack[i]<<" "<<endl;
    }
}
int main()
{

    int choice;
    cout<<"Enter choice:"<<endl;
    if(choice==1)
    {
        push();
    }
    else if(choice==2)
    {
        pop();
    }
    else if(choice==3)
    {
        peek();
    }
    else if(choice==4)
    {
        display();
    }
}
