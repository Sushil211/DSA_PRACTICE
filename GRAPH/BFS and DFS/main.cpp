#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*Front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct Node *t;
    t = new struct Node;
    if(t==NULL)
        cout<<"Queue is full"<<endl;
    else
    {
        t->data = x;
        t->next = NULL;
        if(Front==NULL)
            Front=rear=t;
        else
        {
            rear->next=t;
            rear = t;
        }
    }
}
int dequeue()
{
    int x=-1;
    struct Node* t;
    if(Front==NULL)
        cout<<"Queue is empty"<<endl;
    else
    {
        x=Front->data;
        t = Front;
        Front = Front->next;
        delete t;
    }
    return x;
}

int isEmpty()
{
    return Front==NULL;
}

void BFS(int G[][7],int start, int n)
{
    int i=start,j;
    int visited[7]={0};

    cout<<i<<" ";
    visited[i]=1;
    enqueue(i);

    while(!isEmpty())
    {
        i=dequeue();
        for(j=1;j<n;j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                cout<<j<<" ";
                visited[j]=1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[][7],int start, int n)
{
    static int visited[7]={0};
    int j;

    if(visited[start]==0)
    {
        cout<<start<<" ";
        visited[start]=1;

        for(j=1;j<n;j++)
        {
            if(G[start][j]==1 && visited[j]==0)
                DFS(G,j,n);
        }
    }
}

int main()
{
    int G[7][7]={{0,0,0,0,0,0,0},
                {0,0,1,1,0,0,0},
                {0,1,0,0,1,0,0},
                {0,1,0,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};

    BFS(G,1,7);
    cout<<endl;
    BFS(G,4,7);
    cout<<endl;

    DFS(G,1,7);
    cout<<endl;
}
