#include<bits/stdc++.h>
using namespace std;
void Insert(char s[]){
    char x[10];
    cout<<"Enter the inserted string:"<<endl;
    cin.getline(x,10);
    int position;
    cout<<"Enter the position where the string will insert:"<<endl;
    cin>>position;
    for(int i=strlen(s);i>=position-1;i--){
        s[i+strlen(x)]=s[i];
    }
    for(int i=0;i<strlen(x);i++){
        s[position+i-1]=x[i];
    }
    cout<<"The string after insertion:"<<endl;
    cout<<s<<endl;
}
void substring(char s[]){
    int m,n,c=0;
    cout<<"Enter the initial number of new string:"<<endl;
    cin>>m;
    cout<<"Enter the length of the new string:"<<endl;
    cin>>n;
    for(int i=m;i<strlen(s);i++){
        cout<<s[i-1];
        c++;
        if(c==n){
            break;
        }
    }
    cout<<endl;
}
void Delete(char s[]){
    int position;
    cout<<"Enter the position of the deleting string:"<<endl;
    cin>>position;
    int length;
    cout<<"Enter the length of the deleting string:"<<endl;
    cin>>length;
    for(int i=0;i<strlen(s);i++){
        if(i==position-1){
            cout<<s[i+length];
            i=i+length;
        }
        else{
            cout<<s[i];
        }
    }
    cout<<endl;
}
void Index(char s[]){
    char x[10];
    cout<<"Enter the text:"<<endl;
    cin.getline(x,10);
    int j=0,count=0,d=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]==x[j]){
            j++;
            count++;
            d=i+1;{
            if(count==strlen(x))
            {
                break;
            }
            }
        }
        else{
            j=0;
            count=0;
        }
    }
    cout<<count<<endl;
    cout<<"The index number is:"<<endl;
    if(count==strlen(x)){
        cout<<(d+1)-count<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
}
void Replace(char s[]){
    char x[10];
    char y[10];
    cout<<"Enter the string which will replace:"<<endl;
    cin.getline(x,10);
    cout<<"Enter the string which is replaced:"<<endl;
    cin.getline(y,12);
    int j=0,count=0,d;
    for(int i=0;i<strlen(s);i++){
        if(s[i]==x[j]){
            j++;
            count++;
            d=i+1;
            if(count==strlen(x)){
                break;
            }

        }
        else{
            j=0;
            count=0;
        }
    }
    int index=d-count;
    int c=abs(strlen(x)-strlen(y));
    int k=0;
    if(count==strlen(x)){
        if(strlen(y)>=strlen(x)){
            for(int i=strlen(s);i>=(index+strlen(x));i--){
                 s[i+c]=s[i];
            }
            for(int i=index;i<(index+strlen(y));i++){
                s[i]=y[k];
                k++;
            }
        }
        else{
            for(int i=index;i<(index+strlen(y));i++){
                s[i]=y[k];
                k++;
            }
            for(int i=(index+strlen(x));i<=strlen(s);i++){
                s[i-c]=s[i];
            }
        }
        cout<<"The replacement string is:"<<endl;
        cout<<s<<endl;
    }
    else{
        cout<<s<<endl;
    }
}
int main(){
    char s[100];
    cout<<"Enter the string:"<<endl;
    cin.getline(s,100);
    //Insert(s);
    //substring(s);
    //Delete(s);
    //Index(s);
    Replace(s);

}