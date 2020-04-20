#include<bits/stdc++.h>
#define SIZE 10
using namespace std;

int Hash1(int key)
{
    return key%SIZE;
}

int Hash2(int key)
{
    return 7-(key%7); //nearest prime number less than SIZE is 7 here
}

int Probe(int HT[],int key)
{
    int i=0;
    int index = Hash1(key);
    int index2 = Hash2(key);

    while(HT[(index+i*index2)%SIZE]!=0)
        i++;
    return (index+i*index2)%SIZE;
}

void Insert(int HT[],int key)
{
    int index = Hash1(key);
    if(HT[index]!=0)
        index = Probe(HT,key);

    HT[index] = key;
}

int Search(int HT[],int key)
{
    int i=0;
    int index=Hash1(key);
    int index2=Hash2(key);
    while(HT[(index+i*index2)%SIZE]!=key && HT[(index+i*index2)%SIZE]!=0)
        i++;

    if(HT[(index+i*index2)%SIZE]==key)
        return (index+i*index2)%SIZE;
    else if(HT[(index+i*index2)%SIZE]==0)
        return -1;
}

int main()
{
    int HT[10]={0};

    Insert(HT,23);
    Insert(HT,43);
    Insert(HT,13);
    Insert(HT,27);

    cout<<"Key is found at "<<Search(HT,27);
}

