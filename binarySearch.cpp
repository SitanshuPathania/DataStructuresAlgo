#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &arr, int target)
{
    int low=0;
    int high=arr.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==target)
        {
            return mid;
            break;
        }
        else if(arr[mid]<target)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int binarySearchRec(vector<int> &arr,int low,int high,int target)
{
    if(low>high)
    {
        return -1;
    }
    int mid=low+(high-low)/2;
    if(arr[mid]==target)
    {
        return mid;
    }
    else if(arr[mid]>target)
    {
        return binarySearchRec(arr,low,mid-1,target);
    }
    else{
        return binarySearchRec(arr,mid+1,high,target);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    int target;
    cout<<"Enter the target value: "<<endl;
    
    cin>>target;
    vector<int> arr(n);
    //Only enter sorted array
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // cout<<binarySearch(arr,target);
    cout<<binarySearchRec(arr,0,n-1,target);
    return 0;
}

// Time complexity: O(logN)