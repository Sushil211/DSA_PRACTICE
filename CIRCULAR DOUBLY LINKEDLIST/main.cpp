#include<bits/stdc++.h>
using namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*Head;

void create(int A[],int n){
   struct Node *t,*last;
   int i;
   Head=new struct Node;
   Head->data=A[0];
   Head->next=Head;
   Head->prev=Head;
   last=Head;

   for(i=1;i<n;i++)
   {
       t=new struct Node;
       t->data=A[i];
       t->next=last->next;
       t->prev=last;
       last->next=t;
       last=t;
       Head->prev=last;
   }
}

void display(struct Node *p)
{
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=Head);
}

int length(struct Node *p){
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=Head);
    return len;
}

void INSERT(int index,int x)
{
    struct Node *p,*t;
    int i;
    if(index<0 || index>length(Head))
        cout<<"Invalid index!"<<endl;
    else if(index==0)
    {
        t=new struct Node;
        t->data=x;
        t->prev=Head->prev;
        t->next=Head;
        Head->prev->next=t;
        Head->prev=t;
        Head=t;
    }else
    {
        t=new struct Node;
        p=Head;
        for(i=0;i<index-1;i++)
            p=p->next;
        t->data=x;
        t->prev=p;
        t->next=p->next;
        p->next->prev=t;
        p->next=t;
    }
}

int DELETE(int index)
{
    struct Node *p=Head;
    int i,x=-1;
    if(index<1 || index>length(Head))
        return x;
    else if(index==1)
    {
        Head->prev->next=Head->next;
        Head->next->prev=Head->prev;
        Head=Head->next;
        x=p->data;
        delete p;
        return x;
    }else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        x=p->data;
        p->next->prev=p->prev;
        p->prev->next=p->next;
        delete p;
        return x;
    }
}

int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    display(Head);
    cout<<endl;
    cout<<DELETE(1)<<endl;
    display(Head);
}
