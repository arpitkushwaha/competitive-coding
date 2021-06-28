//https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/yet-another-easy-problem-1f3273a0/

#include<iostream>
using namespace std;
int hexa(int a)
{
    int n =a;
    int sum = 0;
    int temp = 0;
    while(n!=0)
    {
        temp=n%16;

        sum=sum+temp;

        n=n/16;
    }
    return sum;
}

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b,a%b);
}


int main()

{
    int L;
    int R,T;
    cin>>T;
    for(int j=0;j<T;++j)
    {
        cin>>L;
        cin>>R;
        int counter=0;//counter
        for(int i=L; i<=R;i++)
        {
            if(i>1)
            {
                if(gcd(i,hexa(i))>1)
                {
                   counter++;
                }
            }
        }
        cout<<counter<<"\n";
    }
    return 0;
}


