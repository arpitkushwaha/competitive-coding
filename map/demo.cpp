#include <iostream>
#include <map>
#include <string>

using namespace std;

void demo()
{
    map<int, string> m;
    int i=1, key;
    string value;

    while(i)
    {   
        cout<<"int: ";cin>>key;
        cin.ignore();
        cout<<"string: ";
        getline(cin, value);
        m.insert({key, value});
        cout<<"i: ";cin>>i;
    }

    for(auto itr=m.begin(); itr!=m.end(); itr++)
    {
        cout<<itr->first<<" : "<<itr->second;
    }


}

int main()
{
    demo();
    return 0;
}