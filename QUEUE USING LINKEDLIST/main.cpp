#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*Front=0,*rear=0;

void enqueue(int x)
{
    struct Node *t;
    t=new struct Node;
    if(t==0)
        cout<<"Queue is full"<<endl;
    else
    {
        t->data=x;
        t->next=0;
        if(Front==0)
            Front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue()
{
    int x=-1;
    struct Node *p;
    if(Front==rear)
        cout<<"Queue is empty"<<endl;
    else
    {
        p=Front;
        x=p->data;
        Front=Front->next;
        delete p;
    }return x;
}

void display(struct Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }cout<<endl;
}

int main()
{
    struct Node *p;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    cout<<dequeue()<<endl;
    cout<<dequeue()<<endl;
    cout<<dequeue()<<endl;

    display(Front);
}
