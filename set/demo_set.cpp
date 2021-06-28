#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

//https://www.geeksforgeeks.org/modify-array-of-strings-by-replacing-characters-repeating-in-the-same-or-remaining-strings/
void modifyArray()
{
    vector<string> arr;
    vector<string> ans;
    unordered_set<char> flag;
    int i=1;
    while(i)
    {
        string str;
        cout<<"str: ";
        getline(cin,str);
        arr.push_back(str);
        cout<<"i: ";cin>>i;
         cin.ignore();
    }

    for(auto str: arr)
    {
        string temp="";
        for(auto ch: str)
        {
            if(flag.find(ch) == flag.end())
            {
                flag.insert(ch);
                temp+=ch;
            }
        }
        if(temp.size())
            ans.push_back(temp);
    }

    for(auto itr = ans.begin(); itr!=ans.end(); itr++)
    {
        cout<<*itr<<", ";
    }

}

int main()
{
    modifyArray();
    return 0;
}
