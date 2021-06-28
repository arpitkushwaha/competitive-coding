#include<iostream>
#include<stack>
#include<unordered_map>
#include<map>
#include<vector>
#include<set>
#include<cstring>

using namespace std;

void balanceParanthesisNaive()
{
    stack<char> s;
    string input;
    int flag=1;
    cin>>input;

    for(int i=0; i<input.size(); i++)
    {
        if(input[i] == '(' || input[i] == '[' || input[i] == '{')
        {
            s.push(input[i]);
        }
        else
        {
            if(s.size() == 0) 
            {
                flag=0;
                break;
            }
            
            if((input[i]==')' && s.top() == '(')    ||  (input[i]==']' && s.top() == '[')   ||  (input[i]=='}' && s.top() == '{') )
            {
                s.pop();
                continue;
            }
            else
            {
                flag=0; 
                break;
            }
            
            
        }
    }

    if(flag==1 && s.size() == 0)
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
}


void balanceParanthesis()
{
    unordered_map<char, int> symbols = {{'(',-1}, {'[',-2}, {'{',-3}, {'}',3}, {']',2}, {')',1} } ;
    stack<int> s;
    string input;
    int flag=1;
    cin>>input;
    for (char &e: input)
    {
        if(symbols[e]<0)
        {
            s.push(e);
        }
        else
        {   
            if(s.empty() || (symbols[e]+symbols[s.top()]))
            {
                flag=0;
                break;
            }
            s.pop();
        }
    }

    if(s.empty() && flag==1)
    {
        cout<<"Balanced";
    }
    else
    {
        cout<<"Not Balanced";
    }
    
}


void nextGreatestInteger()
{
    unordered_map<int, int> m;
    stack<int> st;
    vector<int> list;
    int element;
    
    while(1){
        cin>>element;
        if(element==0) break;
        list.push_back(element);
    }

    for(int &no: list)
    {
        while(1)
        {
            if(!st.empty() && st.top()<no)
            {
                m[st.top()] = no;
                st.pop();
            }
            else
            {
                break;
            }
        }
        st.push(no);
    }

    while(!st.empty())
    {
        m[st.top()] = -1;
        st.pop();
    }

    for(auto &no: list)
    {
        cout<<m[no]<<", ";
    }

}


int maxValueOfUnorderedMap(unordered_map<int, int> m)
{
    int max = m.begin()->second;
    int max_key = m.begin()->first;
    for(auto &itr: m)
    {
        if(max<itr.second)
        {
            max = itr.second;
            max_key = itr.first;
        }
    }
    cout<<"KEY: "<<max_key<<", VALUE: "<<max;
    return max;
}

void willSheAcceptHim()
{
    vector<string> ans; vector<pair<string, string>> m;
	int test_cases;
	cin>>test_cases;

	for(int i=0; i<test_cases; i++)
	{
		string his_name, her_name;
		cin>> his_name; cin>> her_name;

		m.push_back({his_name, her_name}); 
	}

    cout<<endl;
    for(auto &e: m)
    {
        cout<<"FIRST: "<<e.first<<", SECOND: "<<e.second<<endl;
    }
    cout<<endl;

	for(auto &itr: m)
	{
		int i, j;
		for(i=0, j=0; i<itr.second.size(); i++)
		{
			if(itr.first[j] == itr.second[i])
			{
				j++;
				if(itr.first.size() == j)
				{
					ans.push_back("Love you too");
					break;
				}
					
			}
		}

		if(itr.first.size() != j)
			ans.push_back("We are only friends");
	}

	for(auto &e: ans)
	{
		cout<<e<<endl;
	}
}



int sumOfHexadecimalDigits(vector<char> no)
{
    int sum=0;
    map<char, int> m = {{'0',0},{'1', 1},{'2', 2},{'3', 3},{'4', 4},{'5', 5},{'6', 6},{'7', 7},{'8', 8},{'9', 9},{'A', 10},{'B', 11},{'C', 12},{'D', 13},{'E', 14},{'F', 15}};
    
    for(auto &num: no)
    {
        sum+=m[num];
    }

    return sum;
}



int decToHex(int no)
{
    vector<char> ans; 

    while(no)
    {
        int r = no%16;
        no = no/16;
        r<10 ? ans.push_back(48+r) : ans.push_back(55+r);
    }

    for(auto &e: ans)
    {
        cout<<e<<", ";
    }

    return sumOfHexadecimalDigits(ans);
}




int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

void hexadecimalNumbers()
{
    vector<pair<int, int>> v;
    int t;
    cin>>t;

    for(int i=0; i<t; i++)
    {
        int a,b;
        cin>>a;cin>>b;
        v.push_back({a,b});
    }

    for(auto &e: v)
    {
        int count=0;
        for(int i = e.first; i<=e.second; i++)
        {
            gcd(i, decToHex(i))>1 ? count++ : 0;
        }
        cout<<count;
    }


}



void sortArrayOfStrings()
{
    multiset<string> m;
    int maxChar[26]={0};
    while(1)
    {
        string temp;
        cin>>temp;
        if(temp=="0") break;
        m.insert(temp);
    }

    for(auto &str: m)
    {
        string temp="";
        for(auto &ch: str)
        {
            maxChar[ch - 'a']++;
        }
        for(int i=0; i<26; i++)
        {
            for(int j=0; j<maxChar[i]; j++)
            {
                temp+=(char)(i+'a');
            }
        }
        str.copy(&temp[0],str.length());
    }

    for(auto &str: m)
        cout<<str<<endl;

}

template <typename X>
void swap(X *a, X *b)
{
    X t;
    t = *a;
    *a = *b;
    *b = t;
}

void permute(char *str, int l, int r, multiset<string> &list)
{
    int i;
    if(l==r)
    {
        list.insert(str);
    }
    else
    {
        for(i=l; i<=r; i++)
        {
            swap((str+l), (str+i));
            permute(str, l+1, r, list);
            swap((str+l), (str+i));
        }
    }
}

void permutationOfString()
{
    multiset<string> list;
    string str;
    cin>>str;

    permute(&str[0], 0, str.length()-1, list);

    for(auto &e: list)
    {
        cout<<e<<endl;
    }

}

int fib(int n, vector<int> &memo)
{
    if(n<=0)
        return 0;
    else if(n==1)
        return 1;
    else if(memo[n]>0)
        return memo[n];
    else
        {
            memo[n] = fib(n-1, memo) + fib(n-2, memo);
            return memo[n];
        }

}

void fibonacciMemoization()
{
    vector<int> memo(100000, 0);
    int no;
    cin>>no;
    for(int i=0; i<no; i++)
    {
        cout<<i<<": "<<fib(i,memo)<<endl;
    }
}

void balancedParanthesisNew()
{
    string s;
    cin>>s;
    int count=0;
    for(char e: s)
    {
        if(count<0)
        {
            cout<<"false";
            return;
        }
        if(e=='(')
        {
            count++;
        }
        else if(e==')')
        {
            count--;
        }
    }

    if(count!=0)
        cout<<"false";
    else
        cout<<"true";
}

int main()
{
   balancedParanthesisNew();
    return 0;
}

