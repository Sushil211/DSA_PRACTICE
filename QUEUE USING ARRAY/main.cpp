#include<bits/stdc++.h>
using namespace std;

struct Queue{
    int Size;
    int Front;
    int rear;
    int *Q;
};

void create(struct Queue *q,int Size)
{
    q->Size=Size;;
    q->Q=new int[q->Size];
    q->Front=-1;
    q->rear=-1;
}

void enqueue(struct Queue *q,int x)
{
    if(q->rear==q->Size-1)
        cout<<"Queue is full"<<endl;
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->Front==q->rear)
        cout<<"Queue is empty"<<endl;
    else
    {
        q->Front++;
        x=q->Q[q->Front];
    }return x;
}

void display(struct Queue *q)
{
    int i;
    for(i=q->Front+1;i<=q->rear;i++)
    {
        cout<<q->Q[i]<<" ";
    }cout<<endl;
}

int main()
{
    struct Queue q;
    create(&q,5);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);

    cout<<dequeue(&q)<<endl;
    cout<<dequeue(&q)<<endl;
    cout<<dequeue(&q)<<endl;

    display(&q);
}
