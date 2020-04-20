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

void create(struct Queue *q,int Size)
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

int isEmpty(struct Queue q)
{
    return q.Front==q.rear;
}

struct Node *root=0;

void Treecreate()
{
    struct Node *p,*t;
    struct Queue q;
    int x;
    create(&q,100);

    cout<<"Enter root value"<<endl;
    cin>>x;
    //root=new struct Node[];
    //root->data=x;

    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=0;
    enqueue(&q,root);

    while(!isEmpty(q))
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

int main()
{
    Treecreate();
    cout<<"Pre order"<<endl;
    Preorder(root);
    cout<<endl<<"Post order"<<endl;
    Postorder(root);
    cout<<endl<<"In order"<<endl;
    Inorder(root);

    return 0;
}