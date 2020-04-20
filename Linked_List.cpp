#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*Head;

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    Head=new Node;
    Head->data=A[0];
    Head->next=Head;
    last=Head;

    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p){
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=Head);
}

void Rdisplay(struct Node *p){
    static int flag=0;
    if(p!=Head || flag==0){
        flag =1;
        cout<<p->data<<" ";
        Rdisplay(p->next);
    }flag=0;
}

int length(struct Node *p){
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=Head);
    return len;
}

void INSERT(int index,int x){
    struct Node *t,*p;
    int i;
    if(index<0 || index>length(Head))
        return;
    else if(index==0)
    {
        t=new Node;
        t->data=x;
        if(Head==0)
        {
            Head=t;
            Head->next=Head;
        }else
        {
            p=Head;
            while(p->next!=Head){
                p=p->next;
            }
            p->next=t;
            t->next=Head;
            Head=t;
        }
    }else
    {
        p=Head;
        for(int i=0;i<index-1;i++)
            p=p->next;
        t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}

int DELETE(int index)
{
    int x;
    struct Node *p,*q;
    if(index<1 || index>length(Head))
        return -1;
    else if(index==1)
    {
        p=Head;
        while(p->next!=Head)
            p=p->next;
        if(p==Head)
        {
            x=p->data;
            delete Head;
            Head=0;
            return x;
        }else
        {
            p->next=Head->next;
            x=Head->data;
            delete Head;
            Head=p->next;
            return x;
        }
    }else
    {
        p=Head;
        for(int i=0;i<index-2;i++)
            p=p->next;
        q=new Node;
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
        return x;
    }
}

int main(){
    struct Node *temp=0;
    int A[]={1,2,3,4,5};
    create(A,5);
    display(Head);
    cout<<endl;
    cout<<DELETE(8);
    cout<<endl;
    display(Head);
}
