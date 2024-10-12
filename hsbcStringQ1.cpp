#include<iostream>
#include<climits>
#include<string>
using namespace std;

int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    int maxi=INT_MIN;
    int current=0;
    bool isNum=false;
    for(char ch : str)
    {
        if(isdigit(ch))
        {
            current=current*10+(ch-'0');
            isNum=true;
        }
        else
        {
            if(isNum==true)
            {
                maxi=max(maxi,current);
                current=0;
                isNum=false;
            }
        }
    }
    if(isNum)
    {
        maxi=max(maxi,current);
    }
    cout<<maxi;
    return 0;

}