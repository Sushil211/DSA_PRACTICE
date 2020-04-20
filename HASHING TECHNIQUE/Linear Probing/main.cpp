#include<bits/stdc++.h>
#define SIZE 10
using namespace std;

int Hash(int key)
{
    return key%SIZE;
}

int Probe(int HT[],int key)
{
    int i=0;
    int index = Hash(key);

    while(HT[(index+i)%SIZE]!=0)
        i++;
    return (index+i)%SIZE;
}

void Insert(int HT[],int key)
{
    int index = Hash(key);
    if(HT[index]!=0)
        index = Probe(HT,key);

    HT[index] = key;
}

int Search(int HT[],int key)
{
    int i=0;
    int index=Hash(key);
    while(HT[(index+i)%SIZE]!=key && HT[(index+i)%SIZE]!=0)
        i++;

    if(HT[(index+i)%SIZE]==key)
        return (index+i)%SIZE;
    else if(HT[(index+i)%SIZE]==0)
        return -1;
}

int main()
{
    int HT[10]={0};

    Insert(HT,12);
    Insert(HT,35);
    Insert(HT,45);
    Insert(HT,77);

    cout<<"Key is found at "<<Search(HT,55);
}
