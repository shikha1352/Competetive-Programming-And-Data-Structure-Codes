#include<bits/stdc++.h>
using namespace std;
int top=-1;
void sum(int stack[])
{
    int res,op1,op2;
    op2=stack[top];
    top--;
    op1=stack[top];
    top--;
    res=op1+op2;
    top++;
    stack[top]=res;
}
void sub(int stack[])
{
    int res,op1,op2;
    op2=stack[top];
    top--;
    op1=stack[top];
    top--;
    res=op1-op2;
    top++;
    stack[top]=res;
}
void multi(int stack[])
{
    int res,op1,op2;
    op2=stack[top];
    top--;
    op1=stack[top];
    top--;
    res=op1*op2;
    top++;
    stack[top]=res;
}
void div(int stack[])
{
    int res,op1,op2;
    op2=stack[top];
    top--;
    op1=stack[top];
    top--;
    res=op1/op2;
    top++;
    stack[top]=res;
}
void pow(int stack[])
{
    int res,op1,op2,i;
    op2=stack[top];
    top--;
    op1=stack[top];
    top--;
    for(int i=0;i<op2;i++){
        res=res*op1;
    }
    top++;
    stack[top]=res;
}
int main(){
    int n;
    cout<<"Enter size:"<<endl;
    cin>>n;
    char s[n+1];
    cout<<"Enter the postfix expression:"<<endl;
    cin>>s;
    int stack[50];
    for(int i=0;s[i]!='\0';i++){
        //if(s[i]!=' '){
            if(s[i]=='+'){
                sum(stack);
            }
            else if(s[i]=='-'){
                sub(stack);
            }
            else if(s[i]=='*'){
                multi(stack);
            }
            else if(s[i]=='/'){
                div(stack);
            }
            else if(s[i]=='^'){
                pow(stack);
            }
            else{
                top++;
                stack[top]=s[i]-48;
            }
        //}
    }
    cout<<"The result is:"<<stack[top]<<endl;
}