#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//https://www.geeksforgeeks.org/modify-array-of-strings-by-replacing-characters-repeating-in-the-same-or-remaining-strings/
// void modifyArray()
// {
//     vector<string> a;
//     vector<string> ans;
//     unordered_set<char, int> flag;
//     string str;
//     int i=1;
//     while(i)
//     {
//         cout<<"str: ";cin>>str;
//         a.push_back(str);
//         cout<<"i: ";cin>>i;
//     }

//     for(int i=0; i<a.size(); i++)
//     {
//         string temp;
//         for(int j=0; j<a[i].size(); j++)
//         {
//             if(flag.find(a[i][j]) == flag.end())
//                 {
//                     flag.insert({a[i][j],1});
//                     temp.append(string(1,a[i][j]));
//                 }

//         }        
//         ans.push_back(temp);
//     }

//     for(vector<string>::iterator itr = ans.begin(); itr!=ans.end(); itr++)
//     {
//         cout<<*itr<<", ";
//     }


// }


void twoSum()
{
    vector<int> a;
    unordered_map<int, int> map;
    int target = 0;
    int e=1;
    while(e)
    {
        cin>>e;
        if(e==0)
            break;
        a.push_back(e);
    }

    cout<<"Target: "; cin>>target;

    for(int &first_no: a)
    {
        int second_no = target - first_no;
        if(map.find(second_no) != map.end())
        {
            cout<<"Found : "<<first_no<<", "<<second_no; 
            return;
        }
        map[first_no]++;
    }

    cout<<"Not Found"<<endl;
}


void threeSum()
{
    
}


int main()
{
    twoSum();
    return 0;
}
