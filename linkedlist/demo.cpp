#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node* next = NULL;
};
typedef struct Node Node;

Node* createNode()
{
	Node* newNode;
	int value;
	cout << "Enter Data";
	cin >> value;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

Node* createList(Node* head)
{
	int ch=0;
	Node* cur = head;
	do
	{
		Node* newNode = createNode();
		if (head == NULL)
		{
			head = newNode;
			cur = newNode;
		}
		else
		{
			cur->next = newNode;
			newNode->next = NULL;
			cur = cur->next;
		}
		cout << "Do You Want to continue? press 1 for YES 0 for NO";
		cin >> ch;
		if (ch == 0)
			return head;
	} while (1);
	
}

void displayLinkedList(Node* head)
{
	Node* cur = head;
	while (cur != NULL)
	{
		cout << cur->data<<"->";
		cur = cur->next;
	}
}

int main()
{
	Node* head=NULL;
	int choice;
	
	while (1)
	{
        cout <<endl<< "0 for exits" << endl;
	    cout << "1 for create:" << endl;
	    cout << "2 for display" << endl;
	    
        cin >> choice;
		
        switch (choice)
		{
        case 0: return 0; 
                break;
		case 1: head=createList(head);
				break;
		case 2: displayLinkedList(head);
				break;
		}
	}
}