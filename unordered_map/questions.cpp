#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <sstream>
#include <string.h>
using namespace std;

//given a string of words, find frequencies of individual words.
void findFrequency()
{
    string str,word;
    unordered_map<string, int> map;
    getline(cin, str);
    stringstream s(str);
    while(s >> word){
        map[word]++;
    }

    unordered_map<string, int> :: iterator itr;
    for(itr = map.begin(); itr!=map.end(); itr++)
    {
        cout<<"("<<itr->first<<", "<<itr->second<<")"<<endl;
    }
    
}



int main()
{
    findFrequency();
    return 0;
}

