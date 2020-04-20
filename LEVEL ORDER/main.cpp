#include<bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue{
    int Size;
    int Front;
    int rear;
    Node **Q;
};

void Qcreate(struct Queue *q,int Size)
{
    q->Size=Size;
    q->Front=0;
    q->rear=0;
    q->Q=(struct Node **)malloc(q->Size*sizeof(struct Node *));
}

void enqueue(struct Queue *q,Node * x)
{
    if((q->rear+1)%q->Size==q->Front)
        cout<<"Queue is full"<<endl;
    else
    {
        q->rear=(q->rear+1)%q->Size;
        q->Q[q->rear]=x;
    }
}

Node * dequeue(struct Queue *q)
{
    Node *x=0;
    if(q->Front==q->rear)
    {
        cout<<"Queue is empty"<<endl;
        return 0;
    }
    else
    {
        q->Front=(q->Front+1)%q->Size;
        x=q->Q[q->Front];
    }return x;
}

int isQEmpty(struct Queue q)
{
    return q.Front==q.rear;
}

struct Node *root=0;

void Treecreate()
{
    struct Node *p,*t;
    struct Queue q;
    int x;
    Qcreate(&q,100);

    cout<<"Enter root value"<<endl;
    cin>>x;
    //root=new struct Node[];
    //root->data=x;

    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=0;
    enqueue(&q,root);

    while(!isQEmpty(q))
    {
        p=dequeue(&q);
        printf("enter left child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=0;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("enter right child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=0;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}
void Preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void Levelorder(struct Node *p)
{
    struct Queue q;
    Qcreate(&q,20);

    cout<<p->data<<" ";
    enqueue(&q,p);

    while(!isQEmpty(q))
    {
        p=dequeue(&q);
        if(p->lchild)
        {
            cout<<p->lchild->data<<" ";
            enqueue(&q,p->lchild);
        }
        if(p->rchild)
        {
            cout<<p->rchild->data<<" ";
            enqueue(&q,p->rchild);
        }
    }
}

int main()
{
    Treecreate();

    cout<<"Level-order"<<endl;
    Levelorder(root);
}
