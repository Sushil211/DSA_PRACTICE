#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top=0;

void push(int x)
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

int pop()
{
    struct Node *p=top;
    int x=-1;
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

int peek(int position)
{
    struct Node *p=top;
    int i;
    if(position<1)
        return -1;
    for(i=0;p!=0 && i<position-1;i++)
    {
        p=p->next;
    }
    if(p!=0)
        return p->data;
    else
        return -1;
}

int StackTop()
{
    if(top)
        return top->data;
    else
        return -1;
}

int IsEmpty()
{
    return top==0?1:0;
}

int IsFull()
{
    struct Node *t;
    t=new struct Node;
    return t==0?1:0;
    delete t;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    display();

    pop();
    pop();
    pop();

    cout<<IsEmpty()<<endl;
}
