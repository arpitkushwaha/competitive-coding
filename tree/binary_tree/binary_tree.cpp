#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct BinaryTree{
    int data;
    struct BinaryTree* left;
    struct BinaryTree* right;
};

typedef struct BinaryTree Node;

Node* createNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* create(vector<int> v)
{
    Node* root =NULL;
    for(int &e: v)
    {
        root = insert(e, root);
    }
}

Node* insert(int data, Node* root)
{
    Node* temp;
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->left==NULL)
        {
            temp->left = createNode(data);
            break;
        }
        else
            q.push(temp->left);

        if(temp->right==NULL)
        {
            temp->right = createNode(data);
            break;
        }
        else
            q.push(temp->right);
            
    }
}


int main()
{

    return 0;
}