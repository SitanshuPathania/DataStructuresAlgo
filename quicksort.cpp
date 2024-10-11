#include<iostream>
#include<vector>
using namespace std;

int quick(vector<int> &a,int low,int high)
{
    int pivot=a[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(a[i]<=pivot && i<high)
        {
            i++;
        }
        while(a[j]>pivot && j>low)
        {
            j--;
        }
        if(i<j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp2=a[low];
    a[low]=a[j];
    a[j]=temp2;
    return j;
}

void quickSort(vector<int> &a, int low, int high)
{
    if(low>=high)
    {
        return;
    }
    int pivotIndex=quick(a,low,high);
    quickSort(a,low,pivotIndex-1);
    quickSort(a,pivotIndex+1,high);
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
    int low=0;
    int high=n-1;
    quickSort(a,low,high);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}