#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    struct Node *next;
}*top=0;

void push(char x)
{
    struct Node *p;
    p=new struct Node;
    if(p==0)
        cout<<"Stack overflow"<<endl;
    else
    {
        p->data=x;
        p->next=top;
        top=p;
    }
}

char pop()
{
    struct Node *p=top;
    char x='\0';
    if(p==0)
        cout<<"stack underflow"<<endl;
    else
    {
        x=p->data;
        top=top->next;
        delete p;
    }return x;
}

void display()
{
    struct Node *p=top;
    while(p)
    {
        cout<<p->data<<endl;
        p=p->next;
    }cout<<endl;
}

int IsBalance(char *exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(top->data<50 && top->data+1==exp[i])
                pop();
            else if(top->data>50 && top->data+2==exp[i])
                pop();
            else
                return 0;
        }

    }if(top==0)
        return 1;
    else
        return 0;
}

int main()
{
    char *exp="{([a+b)*[c-d])/e}";
    cout<<IsBalance(exp);
}
