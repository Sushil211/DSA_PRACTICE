#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top1=NULL,*top2=NULL;

int isFull(){
    struct Node *t;
    t=new struct Node;
    int x=(t==NULL?1:0);
    delete t;
    return x;

}

int isEmpty(struct Node *p){
    return  p==NULL?1:0;
}

void push1(int x){
    if(isFull())
        cout<<"Stack is full"<<endl;
    else{

        struct Node *t;
        t=new struct Node;
        t->data=x;
        t->next=top1;
        top1=t;
    }
}

void push2(int x){
    if(isFull())
        cout<<"Stack is full"<<endl;
    else{

        struct Node *t;
        t=new struct Node;
        t->data=x;
        t->next=top2;
        top2=t;
  }
}

int pop1(){
    int x=-1;
    struct Node *t=top1;

    if(isEmpty(top1))
        cout<<"Stack1 is empty"<<endl;
    else{
        x=t->data;
        top1=top1->next;
        delete t;
  }
    return x;
}

int pop2(){
    int x=-1;
    struct Node *t=top2;
    if(isEmpty(top2))
        cout<<"Stack 2 is empty"<<endl;

    else{
        x=t->data;
        top2=top2->next;
        delete t;
    }
    return x;
}

void display(struct Node *t){
    while(t){
    cout<<t->data<<endl;
    t=t->next;
  }
}

void enqueue(int x){
    push1(x);
}

int dequeue(){
    int x=-1;
    if(isEmpty(top2)){
        if(isEmpty(top1)){
            cout<<"Queue is empty"<<endl;
            return x;
    }
    else{
        while(!isEmpty(top1)){

            push2(pop1());
            }
        }
    }
    return pop2();
}
int main(){

    for(int i=1;i<=5;i++){enqueue(i*2);}

    display(top1);

    cout<<"Dequeued element is"<<dequeue()<<endl;
    cout<<"Dequeued element is"<<dequeue()<<endl;
    cout<<"Dequeued element is"<<dequeue()<<endl;

    for(int i=10;i<=11;i++){enqueue(i*2);}

    display(top1);

    cout<<endl;

    cout<<"Dequeued element is"<<dequeue()<<endl;
    cout<<"Dequeued element is"<<dequeue()<<endl;
    cout<<"Dequeued element is"<<dequeue()<<endl;

    display(top2);
}