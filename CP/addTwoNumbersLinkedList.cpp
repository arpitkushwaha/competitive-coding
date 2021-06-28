#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode* t; int ld=0,no=0;
    while(1)
    {
        if(!t)
        {
            ld=(l1->val+l2->val)%10;
            t = new ListNode(ld, NULL);
            no = (l1->val+l2->val)/10;
            l1 = l1->next; l2= l2->next;
        }
        if(l1&&l2)
        {
            ld=(l1->val+l2->val+no)%10;
            t->next = new ListNode(ld, NULL);
            t = t->next;
            no = (l1->val+l2->val+no)/10;
            l1 = l1->next; l2= l2->next;
        }
        if(!l1&&l2)
        {
            ld=(l2->val+no)%10;
            t->next = new ListNode(ld, NULL);
            t = t->next;
            no = (l2->val+no)/10;
            l2= l2->next;
        }
        if(l1&&!l2)
        {
            ld=(l1->val+no)%10;
            t->next = new ListNode(ld, NULL);
            t = t->next;
            no = (l1->val+no)/10;
            l1 = l1->next; 
        }
        if(!l1&&!l2)
        {
            return t;
        }
    }
    
}


int main()
{
    ListNode* l1, *l2, *l3;
    l1 = new ListNode(2, new ListNode(4, new ListNode(3, NULL)));
    l2 = new ListNode(5, new ListNode(6, new ListNode(4, NULL)));
    l3 = addTwoNumbers(l1,l2);
    cout<<endl;
    while(l3!=NULL)
        {
            cout<<l3->val<<endl;
            l3 = l3->next;
        }

    return 0;
}
