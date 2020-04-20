#include <bits/stdc++.h>
using namespace std;

struct Queue{
    int Size;
    int Front;
    int rear;
    int *Q;
};

void create(struct Queue *q,int Size)
{
    q->Size=Size;
    q->Front=0;
    q->rear=0;
    q->Q=new int[q->Size];
}

void enqueue(struct Queue *q,int x)
{
    if((q->rear+1)%q->Size==q->Front)
        cout<<"Queue is full"<<endl;
    else
    {
        q->rear=(q->rear+1)%q->Size;
        q->Q[q->rear]=x;
    }
}

void dequeue(struct Queue *q)
{
    int x;
    if(q->Front==q->rear)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    else
    {
        q->Front=(q->Front+1)%q->Size;
        x=q->Q[q->Front];
    }//return x;
}

void display(struct Queue *q)
{
    int i=q->Front+1;
    do
    {
        cout<<q->Q[i]<<" ";
        i=(i+1)%q->Size;
    }while(i!=(q->rear+1)%q->Size);
}

int main()
{
    struct Queue q;
    create(&q,5);

    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    display(&q);
}
