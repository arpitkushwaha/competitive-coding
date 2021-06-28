//https://leetcode.com/problems/longest-common-prefix/
#include<iostream>
#include<vector>
using namespace std;

void longestCommonPrefix()
{
    vector<string> strs;
    int s=-1,size=0;
    cin>>size;
    while(size>0)
    {
        string t;
        cin>>t;
        strs.push_back(t);
        size--;
    }

    for(int i=1; i<strs.size(); i++)
    {
        int count=0;
        for(int y=0; y<strs[0].size() && y<strs[i].size(); y++)
        {
            if(strs[0][y]==strs[i][y])
            {
                count++;
            }
            else
                break;
        }

        if(s==-1 || s>count)
                s=count;
    }

    string ans="";
    for(int i=0; i<s; i++)
        ans+=strs[0][i];

    cout<<endl<<ans<<endl;
}

int main()
{
    longestCommonPrefix();
    return 0;
}