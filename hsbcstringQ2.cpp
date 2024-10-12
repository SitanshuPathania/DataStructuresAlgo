#include<iostream>
#include<string>
#include<climits>
using namespace std;

int main()
{
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    int maxi=INT_MIN;
    for(int i=0;i<str.size()-2;i++)
    {
        int temp=1;
        for(int j=i;j<str.size()-2;j=j+2)
        {
            if(str[j+2]-str[j]==2)
            {
                temp++;
            }
            else
            {
                break;
            }
        }
        maxi=max(temp,maxi);
    }
    cout<<maxi;
    return 0;
}