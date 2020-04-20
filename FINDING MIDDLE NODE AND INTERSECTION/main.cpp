#include<bits/stdc++.h>
using namespace std;

struct NODE{
    int data;
    struct NODE *next;
}*first;

void create(int A[],int n)
{
    struct NODE *t,*last;
    first=new struct NODE;
    first->data=A[0];
    first->next=0;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new struct NODE;
        t->data=A[i];
        t->next=0;
        last->next=t;
        last=t;
    }
}

void display(struct NODE *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int find_middle(struct NODE *p)
{
    struct NODE *q=first;
    while(q)
    {
        q=q->next;
        if(q) q=q->next;
        if(q) p=p->next;
    }return p->data;
}

int main()
{
    int A[]={1};
    create(A,1);
    display(first);
    cout<<endl;
    cout<<find_middle(first);
}
