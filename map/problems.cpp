#include<iostream>
#include<map>
#include <set>
#include <vector>
#include<algorithm>
using namespace std;


//https://practice.geeksforgeeks.org/problems/twice-counter4236/1
int countWords(string list[], int n)
        {
            map<string,int> m;
           int count=0;
           //code here.
           for(int i=0; i<n; i++)
           {
               m[list[i]]++;
           }
           
           for(auto &itr: m)
           {
               if(itr.second == 2)
                    count++;
           }
           
           return count;
        }

//https://codeforces.com/problemset/problem/525/A
void vitaliyAndPie()
{
    int n, count=0; string str; vector<int> a(128);
    cin>>n;
    cin>>str;

    for(int i=0; i<str.size(); i++)
    {
        if(i%2 == 0)
        {
            if(!((str[i] - 32) == str[i+1]))
            {
                a[str[i]] = 1;
                if(a[str[i+1]+32] == 0)
                {
                    count++;
                }
                else
                {
                    a[str[i+1]+32]=0;
                }
            }
        }
    }

    cout<<count;

}


//https://codeforces.com/problemset/problem/4/C
void registrationSystem()
{
    int n;
    cin>>n;
    map<string,int> m;
    vector<string> ans;
    for(int i=0; i<n; i++)
    {
        string str;
        cin>>str;
        if(m.find(str) == m.end())
        {
            m[str] = 1;
            ans.push_back("OK");
        }
        else{
            int count = 1;
            string temp;
            while(count)
            {
                temp = str+to_string(count);
                if(find(ans.begin(), ans.end(), temp) != ans.end())
                {
                    count++;    
                }
                else
                {
                    m[temp] = 1;
                    ans.push_back(temp);
                    count = 0;
                }
            }
        }
    }

    cout<<endl<<"ANSWER: "<<endl;
    for(auto &element: ans)
    {
        cout<<element<<endl;
    }

    cout<<endl<<endl;
}



int main()
{
    registrationSystem();
    return 0;
}