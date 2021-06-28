#include <iostream>
#include <unordered_map>

using namespace std;

class Class{

    private:
        unordered_map<string, int> student_map;

    public :

    void insertData(string name, int roll_no){
        student_map.insert(make_pair(name,roll_no));
    }

    void find(string name)
    {
        unordered_map<string, int>::iterator itr;
        itr = student_map.find(name);
        if(itr == student_map.end())
        {
            cout<<"No Record Found"<<endl;
        }
        else
        {
            cout<<"Key Found : "<<itr->second;
        }
    }

    void printData()
    {
        unordered_map<string, int> :: iterator itr;
        cout<<endl<<"Data Of All Students : "<<endl;
        int count=1;
        for(itr = student_map.begin(); itr != student_map.end(); itr++, count++)
        {
            cout<<count<<". "<<itr->first<<" : "<<itr->second<<endl;
        }
    }

    void removeData(string name)
    {
        student_map.erase(name);
    }

};


int main()
{
    Class school = Class();
    int i=1, roll_no,choice;
    string name; 
    cout<<"Enter DATA :"<<endl;
    while(i)
    {
        cout<<"name: ";cin>>name;
        cout<<"roll_no: ";cin>>roll_no;
        school.insertData(name, roll_no);
        cout<<"i: ";cin>>i;
    }

    i=1;
    
    while(i)
    {
        cout<<endl<<"1. INSERT DATA \n2. FIND DATA\n3. REMOVE DATA\n4. PRINT DATA\nENTER YOU CHOICE: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"name: ";cin>>name;  cout<<"roll_no: ";cin>>roll_no; school.insertData(name, roll_no); break;
            case 2: cout<<"name: ";cin>>name; school.find(name); break;
            case 3: cout<<"name: ";cin>>name; school.removeData(name); break;
            case 4: school.printData(); break;
            default: i=0;
        }

    }

    return 0;
}