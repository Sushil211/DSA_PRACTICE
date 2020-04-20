#include<bits/stdc++.h>
using namespace std;

struct Node{
    int coeff;
    int exp;
    struct Node *next;
}*poly;

void create()
{
    struct Node *t,*last=0;
    int num, i;
    cout<<"Enter number of terms"<<endl;
    cin>>num;
    cout<<"Enter coeff and exponent of each term"<<endl;
    for(i=0;i<num;i++)
    {
        t=new struct Node;
        cin>>t->coeff;
        cin>>t->exp;
        t->next=0;
        if(poly==0)
        {
            poly=t;
            last=t;
        }else
        {
            last->next=t;
            last=t;
        }
    }
}

void display(struct Node *p)
{
    while(p->next)
    {
        cout<<p->coeff<<"x"<<p->exp<<" +";
        p=p->next;
    }cout<<p->coeff<<"x"<<p->next<<endl;

}

int Eval(struct Node *p,int x)
{
    int val=0;
    while(p)
    {
        val+= p->coeff*pow(x,p->exp);
        p=p->next;
    }return val;
}

int main()
{
    create();
    display(poly);
    cout<<endl<<Eval(poly,2)<<endl;
    return 0;
}
