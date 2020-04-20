#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    struct Node *next;
}*top=0;

void push(char x)
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
    char x=-1;
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

int StackTop()
{
    if(top)
        return top->data;
    else
        return -1;
}

int IsEmpty()
{
    return top==0?1:0;
}

/*int operand(char x)
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

char * convert(char *infix)
{
    int i=0,j=0;
    int len=strlen(infix);
    char * postfix;
    postfix=new char[len+2];
    while(infix[i]!='\0')
    {
        if(operand(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(precedence(infix[i]) > precedence(top->data))
                push(infix[i++]);
            else
                postfix[j++]=pop();
        }
    }
    while(top->data!='#')
    {
        postfix[j++]=pop();
    }postfix[j]='\0';
    return postfix;

}*/

int precedence(char x)
{
    if((int(x)>=65 && int(x)>=90) || (int(x)>=97 && int(x)>=122))
        return 5;
    else if(x=='-')
        return 1;
    else if(x=='+')
        return 2;
    else if(x=='*')
        return 3;
    else if(x=='/')
        return 4;
    else
        return 0;
}

char * convert(char *infix)
{
    int i=0,j=0;
    int len=strlen(infix);
    char * postfix;
    postfix=new char[len+2];
    while(infix[i]!='\0')
    {
        if(precedence(infix[i]) > precedence(top->data))
            push(infix[i++]);
        else
            postfix[j++]=pop();
    }
    while(top->data!='#')
    {
        postfix[j++]=pop();
    }postfix[j]='\0';
    return postfix;
}

int main()
{
    char *infix="a+b*c/e";
    push('#');
    char *postfix=convert(infix);
    cout<<postfix;
    return 0;
    
}
