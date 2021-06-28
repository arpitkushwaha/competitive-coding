#include<iostream>
using namespace std;

class Student{
    private:
        int rollno;
        string name;
    public:
        Student(int rollno, string name)
        {
            this->rollno = rollno;
            this->name = name;
        }

        int getRollNo()
        {
            return rollno;
        }
        void setRollNo(int rollno)
        {
            this->rollno = rollno;
        } 

        string getName()
        {
            return name;
        }
        void setName(string name)
        {
            this->name = name;
        }
};

class LinkedList{
    public:
        Student *data;
        LinkedList* next;
};

class HashTable{
    public:
        LinkedList* list[10];

    void push(Student *stud)
    {
        LinkedList* node = new LinkedList();
        node->data = stud;
        int index = hashFunc(stud->getRollNo());
        if(this->list[index]==NULL)
            this->list[index] = node;
        else
        {
            LinkedList* temp = this->list[index];
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
    }


    string search(int rollno)
    {
        int index = hashFunc(rollno);
        LinkedList* node = this->list[index];
        while(node!=NULL && node->data->getRollNo()!=rollno)
        {
            node = node->next;
        }
        
        if(node!=NULL)
            return node->data->getName();
        else 
            return "Not Found";
    }


    int hashFunc(int rollno)
    {
        int length = sizeof(list)/sizeof(list[0]);
        return rollno%length;
    }
};

int main()
{
    HashTable* table;
    table = new HashTable();
    int size,rno=1;
    cin>>size;

    for(int i=0; i<size; i++)
    {
        string name; int rollno;
        cin>>rollno; cin>>name;
        Student *stud = new Student(rollno, name);
        table->push(stud);
    }

    while(rno)
    {
        cout<<endl<<"Enter the rollno of the student to search: "; cin>>rno;
        if(rno==0)
            break;
        cout<<"Name: "<<table->search(rno);
    }
    
    return 0;
}