#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void heapify(vector<int> &a, int n, int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && left>0 &&  a[left]>a[largest])
    {
        largest=left;
    }
    if(right<=n && right>0 && a[right]>a[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(a[largest],a[i]);
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
        swap(a[1],a[size]);
        size--;
        heapify(a,size,1);
    }
}

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<int> a(n+1);
    a[0]=-1;//For 1-based indexing
    cout<<"Enter your array: ";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    heapsort(a,n);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}