#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int Size;
    int top;
    int *s;
};

void create(struct Stack *st)
{
    cout<<"Enter size of the stack"<<endl;
    cin>>st->Size;
    st->top=-1;
    st->s=new int[st->Size];
}

void display(struct Stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    {
        cout<<st.s[i]<<endl;
    }cout<<endl;
}

void push(struct Stack *st,int x)
{
    if(st->top==st->Size-1)
        cout<<"Stack overflow"<<endl;
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}

int pop(struct Stack *st)
{
    int x=-1;
    if(st->top==-1)
        cout<<"Stack underflow"<<endl;
    else
    {
        x=st->s[st->top];
        st->top--;
    }return x;
}

int peek(struct Stack st,int position)
{
    int x=-1;
    if(position> st.top+1 || position<1)
        cout<<"Invalid position"<<endl;
    else
    {
        x=st.s[st.top - position + 1];
    }return x;
}

int StackTop(struct Stack st)
{
    if(st.top==-1)
        return -1;
    else
        return st.top;
}

int IsEmpty(struct Stack st)
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

int main()
{
    struct Stack st;
    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);

    display(st);

    cout<<pop(&st)<<endl;
    cout<<pop(&st)<<endl;
    cout<<pop(&st)<<endl;
    cout<<pop(&st)<<endl;
    //cout<<pop(&st)<<endl;

    cout<<endl;

    display(st);
}
