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

void bubble_sort(int n, vector<int> &a)
{
    for(int i=0;i<n-1;i++)
    {
        int is_sorted=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                is_sorted=1;
            }
        }
        if(is_sorted==0)// Best case when array is already sorted.
        {
            break;
        }
    }
}

void insertion_sort(int n, vector<int> &a)
{
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j>0 && a[j-1]>a[j])
        {
            int temp=a[j-1];
            a[j-1]=a[j];
            a[j]=temp;
            j--;
        }
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
    insertion_sort(n,a);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}