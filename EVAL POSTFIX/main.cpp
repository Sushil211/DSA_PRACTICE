#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top=0;

void push(int x)
{
    struct Node *p;
    p=new struct Node;
    if(p==0)
        cout<<"Stack overflow"<<endl;
    else
    {
        p->data=x;
        p->next=top;
        top=p;
    }
}

char pop()
{
    struct Node *p;
    int x=-1;
    if(p==0)
        cout<<"stack underflow"<<endl;
    else
    {
        p=top;
        x=p->data;
        top=top->next;
        delete p;
    }return x;
}

int operand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    else
        return 1;
}

int precedence(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    else
        return 0;
}

int Evaluation(char *problem)
{
    int i,x1,x2,r;
    for(i=0;problem[i]!='\0';i++)
    {
        if(operand(problem[i]))
            push(problem[i]-'0');
        else
        {
            x2=pop();
            x1=pop();
            switch(problem[i])
            {
                case '+': r=x1+x2;push(r);break;
                case '-': r=x1-x2;push(r);break;
                case '*': r=x1*x2;push(r);break;
                case '/': r=x1/x2;push(r);break;
            }
        }
    }return pop();
}

int main(){
    char *problem="234*+82/-";
    cout<<Evaluation(problem);
}
