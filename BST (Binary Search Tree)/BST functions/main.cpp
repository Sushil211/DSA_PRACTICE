#include<bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=0;

void Insert(int key)
{
    struct Node *t=root;
    struct Node *r,*p;

    if(t==0)
    {
        p=new struct Node;
        p->data=key;
        p->lchild=p->rchild=0;
        root=p;
        return;
    }
    while(t)
    {
        r=t;
        if(t->data==key)
            return;
        else if(t->data > key)
            t=t->lchild;
        else
            t=t->rchild;
    }
    p=new struct Node;
    p->data=key;
    p->lchild=p->rchild=0;
    if(key > r->data)
        r->rchild=p;
    else if(key < r->data)
        r->lchild=p;
}

void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

struct Node * Search(int key)
{
    struct Node *p=root;
    if(p==0)
        return 0;
    while(p)
    {
        if(key==p->data)
            return p;
        else if(key < p->data)
            p=p->lchild;
        else
            p=p->rchild;
    }
    return NULL;
}

struct Node * RSearch(struct Node *p,int key)
{
    if(p==0)
        return 0;
    while(p)
    {
        if(key==p->data)
            return p;
        else if(key < p->data)
            return RSearch(p->lchild,key);
        else
            return RSearch(p->rchild,key);
    }

}

struct Node * RInsert(struct Node *p,int key)
{
    struct Node *t=0;
    if(p==0)
    {
        t=new struct Node;
        t->lchild=t->rchild=0;
        t->data=key;
        return t;
    }
    if(key > p->data)
        p->rchild = RInsert(p->rchild,key);
    else if(key < p->data)
        p->lchild = RInsert(p->lchild,key);
    return p;
}

int Height(struct Node *p)
{
    int x=0,y=0;
    if(p==0)
        return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

struct Node * Inpre(struct Node *p)
{
    while(p && p->rchild)
        p=p->rchild;
   return p;
}

struct Node * InSucc(struct Node *p)
{
    while(p && p->lchild)
        p=p->lchild;
    return p;
}

struct Node * Delete(struct Node *p,int key)
{
    struct Node *q;

    if(p==0)
        return 0;
    if(!p->lchild && !p->rchild)
    {
        if(p==root)
            root=0;
        delete p;
        return 0;
    }

    if(key < p->data)
        p->lchild = Delete(p->lchild,key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild,key);
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q=Inpre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }return p;
}

int main()
{
    root = RInsert(root,20);
    RInsert(root,30);
    RInsert(root,10);
    RInsert(root,40);
    RInsert(root,50);

    Delete(root,40);
    Delete(root,10);
    inorder(root);

    cout<<endl<<Search(10);
    cout<<endl<<RSearch(root,10);
}
