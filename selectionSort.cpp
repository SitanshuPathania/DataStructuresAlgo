#include<iostream>
#include<vector>
using namespace std;

void selection_sort(int n, vector<int> &a)
{
    for(int i=0;i<n;i++)
    {
        int mini=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[mini])
            {
                mini=j;
            }
        }
        int temp=a[i];
        a[i]=a[mini];
        a[mini]=temp;
    }
}

int main()
{
    int n;
    
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> a(n);
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    selection_sort(n,a);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}