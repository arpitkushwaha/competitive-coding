#include <iostream>
#include <vector>
#include <string>
#include<cstring>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};


void checkPermutation()
{
    int hash[53]={0};
    string s1,s2;
    cin>>s1;cin>>s2;
    for(int i=0; i<s1.size(); i++)
        hash[s1[i] - 'A']++;
    for(int i=0; i<s2.size(); i++)
        hash[s2[i] - 'A']--;

    for(int i=0; i<53; i++)
    {
        if(hash[i] != 0)
        {
            cout<<endl<<"Not a Permutation"<<endl;
            return;
        }
    }

    cout<<endl<<"Is a Permutation"<<endl;
}

void checkUniqueStringBitmasking()
{
    string s;
    cin>>s;
    unsigned int checker=0;
    for(int i=s.length()-1; i>=0; i--)
    {
        int no = s[i] - 'a';
        int val = (1<<no);

        if(checker & val)
            {
                cout<<"Not Unique"<<endl;
                return;
            }
        checker|=val;
    }
    cout<<"Unique"<<endl;
}


void urlify()
{
    char s[100];int b;
    
   cin.getline(s,sizeof(s));
   cin>>b;
    cout<<s;
    int a = --b;

    while(s[a] == ' ')
        a--;
    
    while(a>=0 && b>=0)
    {
        if(s[a]!=' ')
        {
            s[b] = s[a];
            b--; a--;
        }
        else
        {
            s[b] = '0';
            s[--b] = '%';
            s[--b] = '2';
            b--;
            a--;
        }
    }

    cout<<endl<<s<<endl;

}

void pallindromePermutation()
{
    string s;
    cin>>s;
    int hash[256]={0};

    for(int i=s.length()-1; i>=0; i--)
    {
        hash[s[i]]++;
    }

    for(int i=s.length()-1; i>=0; i--)
    {
        cout<<s[i]<<" : "<<hash[s[i]]<<endl;
    }

    int count =0;
    for(int i=s.length()-1; i>=0; i--)
    {
        if((hash[s[i]] % 2 != 0) && (count ==0 || count ==1))
        {
            count++;
        }
        if(count>1)
        {
            cout<<"NO"; return;
        }
    }

    cout<<"YES"; 
}

//abcd abec
void oneAway()
{
    string o_s,s;
    cin>>o_s;cin>>s;
    int hash[26]={0}, sum=0;

    for(int i=0; i<o_s.size(); i++)
    {
        hash[o_s[i]-'a']++;
    }
    for(int i=0; i<s.size(); i++)
    {
        hash[s[i]-'a']--;
    }

    int count =0;
    for(int i=0; i<26; i++)
    {
        sum+=hash[i];
        if(hash[i]==1 || hash[i]==-1)
            count++;
    }

    if((sum==0 || sum ==1 || sum==-1) && count<=2)
        cout<<"TRUE";
    else
        cout<<"FALSE";
}


void pallindromePermutationBitvector()
{
    string s; unsigned int checker =0;
    cin>>s;
    int l = s.size();
    for(int i=l-1; i>=0; i--)
    {
        int val = s[i]-'a';
        int d = (1<<val);
        if(checker & d)
            checker&=(~d);
        else
            checker|=d;
    }
    cout<<"checker: "<<checker<<endl;
    if(checker==0 || ((checker & (checker-1))==0))
        cout<<"YES";
    else
        cout<<"NO";
}

void stringCompression()
{
    string s="";
    int count=1;
    string o_s; cin>>o_s;
    int l = o_s.length();

    for(int i=1; i<=l; i++)
    {
        if(i!=l && (o_s[i-1]==o_s[i]))
        {
            count++;
        }
        else
        {
            s+=o_s[i-1];
            cout<<o_s[i-1]<<": "<<s<<endl;
            s+=to_string(count);
            cout<<o_s[i-1]<<": "<<s<<endl<<endl;
            count=1;
        }
    }
    if(o_s.size() > s.size())
        cout<<s;
    else
        cout<<o_s;
}


void duplicateElementsInArray()
{
    int a[100];
    int size;
    cin>>size;
    for(int i=0; i<size; i++)
    {
        cin>>a[i];
    }

    int i=0,j=1;
    while(j<size)
    {
        if(a[i]==a[j])
            j++;
        else
            a[++i] = a[j++];
    }

    for(int k=0; k<=i; k++)
        cout<<a[k];
}




void midPointOfLinkedList()
{
    Node* head=NULL,*currNode=NULL;
    int size, e,flag=0;
    cin>>size;
    while(size--)
    {
        cin>>e;
        Node* temp = new Node();
        temp->data = e;
        temp->next = NULL;

        if(flag==0)
        {
            currNode=temp;
            head = currNode;
        }
        else
        {
            currNode->next = temp;
            currNode = currNode->next;
        }
        
        flag=1;
    }


    if(head==NULL)
    {
        cout<<"Linked List Empty"<<endl;
        return;
    }
    else if(head->next==NULL)
    {
        cout<<endl<<head->data<<endl;
        return;
    }

    Node *fast=head,*slow=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast=fast->next->next;
    }

    cout<<endl<<"Mid Point : "<<slow->data<<endl;

}

Node* createLinkedList()
{
    Node* head=NULL,*currNode=NULL;
    int size, e,flag=0;
    cin>>size;
    while(size--)
    {
        cin>>e;
        Node* temp = new Node();
        temp->data = e;
        temp->next = NULL;

        if(flag==0)
        {
            currNode=temp;
            head = currNode;
        }
        else
        {
            currNode->next = temp;
            currNode = currNode->next;
        }
        
        flag=1;
    }

    return head;
}

void printLinkedList(Node* head)
{
    cout<<endl<<"LIST: ";
    while(head!=NULL)
    {
        cout<<head->data<<", ";
        head=head->next;
    } 
    cout<<endl;
}

//
void arrangeAdjacent()
{
    Node* head;int flag;
    head = createLinkedList();
    printLinkedList(head); 

    Node* fast=head,*slow=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    if(fast==NULL)
        flag=0;
    else
        flag=1;

    fast=head;
    cout<<"FAST: ";
    printLinkedList(fast);
    cout<<"SLOW: ";
    printLinkedList(slow);

    Node* dummy=NULL, *temp=NULL;
   
    while((slow!=NULL && flag==0) || (flag==1 && slow->next!=NULL))
    {
        printLinkedList(dummy);
        if(dummy==NULL)
        {
            dummy=fast;
            fast=fast->next;
            temp=dummy;
        }
        else
        {
            temp->next=fast;
            fast=fast->next;
            temp=temp->next;
        }
    
        temp->next=slow;
        slow=slow->next;
        temp=temp->next;
    }

    printLinkedList(dummy);

}


void removeDups()
{
    Node* head;int hash[100]={0};
    head = createLinkedList();
    printLinkedList(head); 
    Node* temp = head,*prev=head;
    
    while(temp!=NULL)
    {
        hash[temp->data]++;
        if(hash[temp->data]>1)
        {
            prev->next = temp->next;
        }
        else
        {
            prev=temp;
        }
        temp=temp->next;
    }

    printLinkedList(head);
}


void removeDupsWithoutHash()
{
    Node* head;
    head = createLinkedList();
    printLinkedList(head); 
    Node* p1 = head, *p2,*prev;
    
    while(p1!=NULL)
    {
        prev=p1;
        p2=p1->next;

        while(p2!=NULL)
        {
            if(p1->data==p2->data)
                prev->next=p2->next;
            else
                prev = p2;

            p2=p2->next;

        }
        p1=p1->next;
    }

    printLinkedList(head);

}


void returnKToLast()
{
    Node* head; int k;
    head = createLinkedList();
    printLinkedList(head);

    Node* fast=head,*slow=head; int size=0;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        size++;
    }
    if(fast==NULL)
        size=size*2;
    else
        size=size*2+1;

    cin>>k;
    size=size-k;
    fast=head;
    while(size--)
    {
        fast=fast->next;
    }
    cout<<endl<<fast->data<<endl;
}

void returnKToLastIterative()
{
    Node* head=NULL;
    head = createLinkedList();
    printLinkedList(head);
    int k;
    cin>>k;
    Node* p1=head, *p2=head;
    while(k--)
    {
        if(p2==NULL)
            {
                cout<<endl<<"Not Valid"<<endl;
                return;
            }
        p2=p2->next;
    }

    while(p2!=NULL)
    {
        p1=p1->next;
        p2=p2->next;
    }

    cout<<endl<<p1->data<<endl;
}

void deleteMiddleElement()
{
    Node* head;
    head = createLinkedList();
    printLinkedList(head);
    Node* temp = head;
    int pos;
    cin>>pos; pos--;
    while(--pos)
    {
        if(temp==NULL)
        {
            cout<<"Enter Valid Pos"; return;
        }
        temp=temp->next;
    }
    temp->next = temp->next->next;
    printLinkedList(head);
}


void partitionToPivot()
{
    Node* head;
    head = createLinkedList();
    Node* temp=head, *list=NULL, *before=NULL, *b=NULL, *a=NULL, *after=NULL, *tail=NULL, *t=NULL; int val;
    cin>>val;
    
    while(head!=NULL)
    {
        if(head->data>=val)
        {
            if(after==NULL)
            {
                after = head;
                head=head->next;
                after->next=NULL;
            }
            else
            {
                t = head;
                head = head->next;
                t->next = after;
                after = t;
            }
        }
        else
        {
            if(before==NULL)
            {
                before = head;
                head=head->next;
                before->next=NULL;
            }
            else
            {
                t = head;
                head=head->next;
                t->next = before;
                before = t;
            }
        }
    }

    b=before;
    while(b->next!=NULL)
    {
        b=b->next;
    }
    b->next = after;

    printLinkedList(before);
}

unsigned long int reverseANumber(unsigned long int n)
{
    unsigned long int r=0,ld=0;
    while(n!=0)
    {
        ld = n%10;
        r = r*10+ld;
        n=n/10;
    }
    return r;
}

unsigned long int convertALinkedListToNumber(Node* list)
{
    unsigned long int r=0,ld=0;
    while(list!=0)
    {
        r = r*10+list->data;
        list = list->next;
    }
    return r;
}

int lengthOfLinkedList(Node* list)
{
    int len;
    while(list!=NULL)
    {
        len++;
        list = list->next;
    }
    return len;
}

int lengthOfNumber(unsigned long int no)
{
    int len;
    while(no!=0)
    {
        len++;
        no=no/10;
    }
    return len;
}

unsigned long int getNumberFromLinkedList(Node* list)
{
    unsigned long int no = convertALinkedListToNumber(list);
    no = reverseANumber(no);
    int count = lengthOfLinkedList(list) - lengthOfNumber(no);
    cout<<"count= "<<count<<endl;
    if(count>0)
    while(count--)
    {
        no=no*10;
    }

    return no;
}


void sumLinkedListReverse()
{
    Node* l1, *l2;
    l1 = createLinkedList();
    l2 = createLinkedList();
    unsigned long int a = getNumberFromLinkedList(l1);
    unsigned long int b = getNumberFromLinkedList(l2);
    unsigned long int c = a+b;
    cout<<"c: "<<c<<endl;
    Node* rev=NULL, *t=NULL;

    while(c!=0)
    {
        Node* node = new Node();
        node->data = c%10;
        c = c/10;
        if(t==NULL)
        {
            t = node;
            rev = node;
        }    
        else
        {
            t->next = node;
            t=t->next;
        }
        node->next=NULL;
    }    

    printLinkedList(rev);
}



unsigned long int no(Node* l1)
{
    if(l1 == NULL)
        return 0;
    return l1->data + no(l1->next)*10;
}


void sum()
{
    Node* l1, *l2;
    l1 = createLinkedList();
    l2 = createLinkedList();
    unsigned long int n1 =  no(l1);
    unsigned long int n2 =  no(l2);

    unsigned long int s = n1+n2;

    Node* l3=NULL, *temp=NULL;
    while(s!=0)
    {
        Node* t = new Node();
        t->data = s%10;
        t->next = NULL;

        if(l3==NULL)
        {
            l3 = t;
            temp = l3;
        }
        else
        {
            temp->next = t;
            temp=temp->next;
        }
        
        s=s/10;
    }   

    printLinkedList(l3);
}


void sumCarry()
{
    Node* l1, *l2, *l3=NULL, *temp=NULL;
    int n=0,carry=0;
    l1 = createLinkedList();
    l2 = createLinkedList();

    while(1)
    {
        if(l1!=NULL && l2!=NULL)
        {
            n = l1->data+l2->data+carry; l1=l1->next; l2=l2->next;
        }
        else if(l1!=NULL)
        {
            n = l2->data+carry;
            l2=l2->next;
        }
        else if(l2!=NULL)
        {
            n = l1->data+carry;
            l1=l1->next;
        }
        else
        {
            if(carry!=0)
                {
                    temp->next = new Node();
                    temp->next->data = carry;
                    temp->next->next = NULL;
                }
            break;
        }

        carry = n/10;

        Node* t = new Node();
        t->data = n%10;
        t->next = NULL;
        if(l3==NULL)
        {
            l3 = t;
            temp = l3;
        }
        else
        {
            temp->next = t;
            temp=temp->next;
        }

    }

    printLinkedList(l3);
}


void pallindromeLinkedListReverse()
{
    Node* head, *h_t, *rev=NULL, *r_t=NULL;
    head = createLinkedList();
    h_t = head;
    while(h_t!=NULL)
    {
        Node* t = new Node();
        t->data = h_t->data;
        t->next = NULL;
        h_t = h_t->next;

        if(rev == NULL)
        {
            rev = t;
            r_t = rev;
        }
        else
        {
            t->next = rev;
            rev = t; 
        }
    }

    while(rev!=NULL)
    {
        if(rev->data != head->data)
        {
            cout<<"Not Pallindrome";
            return;
        } 
        rev = rev->next; head=head->next;
    }

    cout<<"Pallindrome";


}


void binarySum()
{
    string a,b,s="";
    int carry=0,i,j;
    cin>>a;
    cin>>b;

    for(i=a.length()-1, j=b.length()-1; i>=0 && j>=0; i--,j--)
    {
        if((a[i]=='1' && b[j]=='0') || (a[i]=='0' && b[j]=='1'))
        {
            carry==1 ? s+="0" : s+="1";
        }
        else if(a[i]=='0' && b[j]=='0')
        {
            if(carry==1)
            {
                s+="1"; carry=0;
            }
            else
            {
                s+="0";
            }
        }
        else
        {
            if(carry==1)
            {
                s+="1";
            }
            else
            {
                carry=1; s+="0";
            }
        }
    }
    while(i>=0)
    {
        if(carry==1 && a[i]=='1')
            s+="0";
        else if(carry==1 && a[i]=='0')
        {
            s+="1"; carry=0;
        }
        else
        {
            s+=a[i];
        }
        i--;
    }
    while(j>=0)
    {
        if(carry==1 && b[j]=='1')
            s+="0";
        else if(carry==1 && b[j]=='0')
        {
            s+="1"; carry=0;
        }
        else
        {
            s+=b[j];
        }
        j--;
    }

    if(carry==1)
        s+="1";

    i = s.length()-1;
    while(s[i]=='0')
    {
        s.erase(s.begin()+i);
        i--;
    }

    for(int i=0, j=s.length()-1; i<j; i++,j--)
    {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }

    cout<<s;
}

void circularArray()
{
    int a[5]={0};
    int element;
    for(int i=0; i<7; i=(i+1)%5)
    {
        cin>>element;
        a[i] = element;
        cout<<"ARRAY: ";
        for(int j=0; j<5; j++)
        {
            cout<<a[j]<<", ";
        }
        cout<<endl;
    }
}



int main()
{   
    circularArray();
    return 0;
}




