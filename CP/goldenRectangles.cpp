//https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/almost-golden-rectangular-1c9d72c0/
#include<iostream>
using namespace std;

int main()
{
    int t,count=0;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        double w,h;
        cin>>w;cin>>h;
        double ratio = w/h;
        if((w/h >=1.6000 && w/h <=1.70000) || (h/w >=1.6000 && h/w <=1.70000))
        {
            count++;
        } 
            
    }
    cout<<count;
    return 0;
}