#include<iostream>
#include<vector>
using namespace std;

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
    bubble_sort(n,a);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}