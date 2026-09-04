#include<bits/stdc++.h>
using namespace std;
int top=-1;
void print();
int push();
int pop();
int push(int stack[],int n)
{
    int x;
    cout<<"Enter item:";
    cin>>x;
    top++;
    stack[top]=x;
    return top;
}
int pop()
{
    top=top-1;

}

void print(int stack[],int top)
{
    cout<<"Stack is:";
    for(int i=0; i<=top; i++)
    {
        cout<<stack[i]<<" ";
    }
    cout<<endl;
    cout<<"Top is:"<<top<<endl;
}
int main()
{
    int n;
    cout<<"Enter size of the stack:";
    cin>>n;
    int stack[n];
    while(1)
    {
        int choice;
        cout<<"Enter 1 for push or 0 for pop or 2 for break;"<<endl;
        cin>>choice;
        if(choice==1)
        {
            if(top<n-1)
            {
                push(stack,n);
                print(stack,top);
            }
            else
            {
                cout<<"OVERFLOW"<<endl;
                print(stack,top);
            }

        }
        else if(choice==0)
        {
            if(top>0)
            {
                cout<<"The elements which is popped:"<<stack[top]<<endl;
                pop();
                print(stack,top);
            }
            else
            {
                cout<<"UNDERFLOW"<<endl;
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}
