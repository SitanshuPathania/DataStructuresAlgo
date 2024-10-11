#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>



void heapify(vector<int> &a,int n,int i)
{
    int left=2*i;
    int right=2*i+1;
    int largest=i;
    if(left<=n && left>0 && a[largest]<a[left])
    {
        largest=left;
    }
    if(right<=n && right>0 && a[largest]<a[right])
    {
        largest=right;
    }
    if(largest!=i)//If my largest is changed
    {
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}

void heapsort(vector<int> &a,int n)
{
    for(int i=n/2;i>0;i--)
    {
        heapify(a,n,i);
    }
    int size=n;
    while(size>1)
    {
        //step1
        swap(a[1],a[size]);
        size--;
        //step2
        heapify(a,size,1);
    }
    
}

int main()
{
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int> a(n+1);//1-based indexing
    a[0]=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    // for(int i=n/2;i>0;i--)
    // {
    //     heapify(a,n,i);
    // }
    heapsort(a,n);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
}