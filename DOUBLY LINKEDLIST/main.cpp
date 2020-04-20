#include<bits/stdc++.h>
using namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=0;

void create(int A[],int n){
    struct Node *t,*last;
    first=new struct Node;
    first->prev=0;
    first->data=A[0];
    first->next=0;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new struct Node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p){
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int length(struct Node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }return len;
}

void INSERT(int index,int x)
{
    struct Node *t,*p;
    p=first;
    if(index<0 || index>length(first))
        cout<<"Invalid index!"<<endl;
    else if(index==0)
    {
        t=new struct Node;
        t->prev=0;
        t->data=x;
        t->next=first;
        first->prev=t;
        first=t;
    }else
    {
        t=new struct Node;
        p=first;
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->data=x;
        t->next=p->next;
        t->prev=p;
        if(p->next)
            p->next->prev=t;
        p->next=t;
    }
}

int DELETE(int index)
{
    struct Node *p=first;
    int x=-1;
    if(index<1 || index>length(first))
        return x;
    else if(index==1)
    {
        first=first->next;
        if(first)
            first->prev=0;
        x=p->data;
        delete p;
        return x;
    }else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        delete p;
        return x;
    }
}

void Reverse(struct Node *p){
    struct Node *temp;
    while(p)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;

        if(p!=0 && p->next==0)
            first=p;
    }
}

int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    display(first);
    cout<<endl;
    Reverse(first);
    display(first);
}
