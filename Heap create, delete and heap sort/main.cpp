#include<bits/stdc++.h>
using namespace std;

void Insert(int A[],int n)
{
    int i=n,temp=A[i];
    while(i>1 && temp>A[i/2])
        //This condition is for max heap.
        //For min heap, just change the condition as temp < A[i/2]
        //remaining all are same
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

int Delete(int A[],int n)
{
    int temp,i,j,val;
    val=A[1];
    A[1]=A[n];
    A[n]=val;
    i=1;
    j=2*i;

    while(j<n-1)
    {
        if(A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        else
            break;
    }
    return val;
}

int main()
{
    int H[]={0,10,20,30,25,5,40,35};
    //40,25,35,10,5,20,30

    for(int i=2;i<=7;i++)
        Insert(H,i);

    for(int i=7;i>1;i--)
        cout<<"The deleted value is: "<<Delete(H,i)<<endl;;

    for(int i=1;i<=7;i++)
        cout<<H[i]<<" ";
    cout<<endl;
    //Finally the heap is sorted
    //This is called heap sort
}
