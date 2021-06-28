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

int lengthOfLinkedList(Node* head)
{
	Node* cur = head;
	int count = 0;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
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
		cout << "Do You Want to continue? press 1 for Yes 0 for No" << endl;
		cin >> ch;
		if (ch == 0 || ch>1 )
			return head;
	} while (1);
	
}

void displayLinkedList(Node* head)
{
	Node* cur = head;
	cout << "Your List is : ";
	while (cur != NULL)
	{
		cout << cur->data<<"->";
		cur = cur->next;
	}
	cout << endl;
}

//Inseartion

Node* insertAtEnd(Node* head)
{
	Node* cur=head;
	Node* newNode = createNode();
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newNode;
	return head;
}

Node* insertAtFirst(Node* head)
{
	Node* newNode = createNode();
	newNode->next = head;
	head = newNode;
	return head;
}


Node* insertAtPosition(Node* head)
{
	int position;
	Node* currentNode = head;
	cout << "Enter Position ";
	cin >> position;
	cout << endl;
	if (position == 1)
	{
		head = insertAtFirst(head);
	}
	else if (position > lengthOfLinkedList(head) || position<1)
	{
		cout << "Enter valid Position"<<endl;
		return head;
	}

	else if (position == lengthOfLinkedList(head))
	{
		head = insertAtEnd(head);
		return head;
	}

	else
	{
		Node* newNode = createNode();
		while (position>2)
		{
			currentNode = currentNode->next;
			position--;
		}
		newNode->next = currentNode->next;
		currentNode->next = newNode;
		return head;
	}
}
//Deletion

Node* deletionAtFirst(Node* head)
{
	Node* currentNode = head;
	currentNode = currentNode->next;
	head = currentNode;
	return head;
}

Node* deletionAtEnd(Node* head)
{
	Node* currentNode = head;
	while(currentNode->next->next != NULL)
	{
		currentNode = currentNode->next;
	}
	currentNode->next = NULL;
	return head;
}

Node* deleteElementFromSpecificPosition(Node* head)
{

	int position;
	Node* currentNode = head,*prevNode=head;
	cout << "Enter Position ";
	cin >> position;
	cout << endl;
	currentNode = currentNode->next;
	if (position == 1)
	{
		head = deletionAtFirst(head);
	}
	else if (position > lengthOfLinkedList(head) || position < 1)
	{
		cout << "Enter valid Position" << endl;
		return head;
	}

	else if (position == lengthOfLinkedList(head))
	{
		head = deletionAtEnd(head);
		return head;
	}
	else
	{
		while (position > 1)
		{
			currentNode = currentNode->next;
			prevNode = prevNode->next;
			position--;
		}
		prevNode->next = currentNode->next;
		currentNode->next = NULL;
		return head;
	}
}

int main()
{
	Node* head=NULL;
	int choice=0;
	while (1)
	{
		cout << "************************" << endl;
		cout << "Press 0 for exits" << endl;
		cout << "Press 1 for display" << endl;
		cout << "Press 2 for create a list" << endl;
		cout << "Press 3 to insert at end" << endl;
		cout << "Press 4 to insert at First" << endl;
		cout << "Press 5 to insert element at sepecific position"<< endl;
		cout << "Press 6 to delete a node from front" << endl;
		cout << "Press 7 to delete a node from end" << endl;
		cout << "Press 8 to delete a node from a specific position" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: return 0;
				break;
		case 1: displayLinkedList(head);
				break;
		case 2: head = createList(head);
				break; 
		case 3: head = insertAtEnd(head);
				break;
		case 4: head = insertAtFirst(head);
				break;
		case 5: head = insertAtPosition(head);
				break;
		case 6: head = deletionAtFirst(head);
				break;
		case 7: head = deletionAtEnd(head);
				break;
		case 8: head = deleteElementFromSpecificPosition(head);
				break;
		}
	}
}