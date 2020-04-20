#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int Size;
    int top;
    struct Node **s;
};

void Stackcreate(struct Stack *st,int Size)
{
    st->Size=Size;
    st->top=-1;
    st->s=(struct Node **)malloc(st->Size*sizeof(struct Node *));
}

void push(struct Stack *st,struct Node *x)
{
    if(st->top==st->Size-1)
        cout<<"Stack overflow"<<endl;
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}

struct Node *pop(struct Stack *st)
{
    struct Node *x=0;
    if(st->top==-1)
        cout<<"Stack underflow"<<endl;
    else
    {
        x=st->s[st->top];
        st->top--;
    }return x;
}

int IsStackEmpty(struct Stack st)
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}

int IsFull(struct Stack st)
{
    if(st.top==st.Size-1)
        return 1;
    else
        return 0;
}

struct Node * StackTop(struct Stack st)
{
    if(st.top==-1)
        return 0;
    else
        return st.s[st.top];
}

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
    create(&q,100);

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

void IterPreorder(struct Node *p)
{
    struct Stack st;
    Stackcreate(&st,20);

    while(p || !IsStackEmpty(st))
    {
        if(p)
        {
            cout<<p->data<<" ";
            push(&st,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&st);
            p=p->rchild;
        }
    }
}

void IterInorder(struct Node *p)
{
    struct Stack st;
    Stackcreate(&st,20);

    while(p || !IsStackEmpty(st))
    {
        if(p)
        {
            push(&st,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&st);
            cout<<p->data<<" ";
            p=p->rchild;
        }
    }
}

void IterPostorder(struct Node *p)
{
    struct Stack st;
    Stackcreate(&st,20);

    do
    {
        while(root)
        {
            if(root->rchild)
                push(&st,root->rchild);
            push(&st,root);

            root=root->lchild;
        }
        root=pop(&st);

        if(root->rchild && StackTop(st)==root->rchild)
        {
            pop(&st);
            push(&st,root);
            root=root->rchild;
        }
        else
        {
            cout<<root->data<<" ";
            root=0;
        }
    }while(!IsStackEmpty(st));
}

int main()
{
    Treecreate();
    cout<<"Pre-order"<<endl;
    IterPreorder(root);
    cout<<endl<<"In-Order"<<endl;
    IterInorder(root);
    cout<<endl<<"Post-Order"<<endl;
    IterPostorder(root);
}
