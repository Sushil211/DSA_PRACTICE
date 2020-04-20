#include<bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root=0;

int NodeHeight(struct Node *p)
{
    int hl,hr;
    if(p && p->lchild)
        hl=p->lchild->height;
    else
        hl=0;

    if(p && p->rchild)
        hr=p->rchild->height;
    else
        hr=0;

    return hl>hr ? hl+1 : hr+1;
}

int BalanceFactor(struct Node *p)
{
    int hl,hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl-hr;
}

struct Node * LLRotation(struct Node *p)
{
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(root==p)
        root=pl;

    return pl;
}

struct Node * LRRotation(struct Node *p)
{
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    plr->height=NodeHeight(plr);
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(root==p)
        root=plr;

    return plr;
}

struct Node * RRRotation(struct Node *p)
{
    struct Node *pr=p->rchild;
    struct Node *prl=pr->lchild;

    pr->lchild=p;
    p->rchild=prl;
    pr->height=NodeHeight(pr);
    p->height=NodeHeight(p);

    if(root==p)
        root=pr;

    return pr;
}

struct Node * RLRotation(struct Node *p)
{
    struct Node *pr=p->rchild;
    struct Node *prl=pr->lchild;

    p->rchild=prl->lchild;
    pr->lchild=prl->rchild;
    prl->lchild=p;
    prl->rchild=pr;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);

    if(root==p)
        root=prl;

    return prl;
}

struct Node *Rinsert(struct Node *p,int key)
{
    struct Node *t=0;

    if(p==0)
    {
        t=new struct Node;
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=0;
        return t;
    }
    if(key < p->data)
        p->lchild=Rinsert(p->lchild,key);
    else if(key > p->data)
        p->rchild=Rinsert(p->rchild,key);

    p->height=NodeHeight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->lchild)==-1)
        RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->lchild)==1)
        RLRotation(p);

    return p;
}



int main()
{
    root=Rinsert(root,10);
    Rinsert(root,5);
    Rinsert(root,2);

    return 0;
}
