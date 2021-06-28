#include <iostream>
#include <math.h>
using namespace std;
 
void nearest_equal_factors(int n)
{
	int i;
	int ip = (int)sqrt(n);
	if(n % ip == 0)
		cout<<"F1 = "<<ip<<"F2 = "<<n / ip;
	else
	{
		int flag;
		int low = pow(ip, 2);
		int high = pow(ip + 1, 2);
		if((n - low) >= (high - n))
			flag = ip + 1;
		else
			flag = ip;
		for(i = flag - 1; i > 0; i--)
		{
			if(n % i == 0)
				break;
		}
		cout<<"F1 = "<<i<<"F2 = "<<(n / i);
	}
}
 
int main()
{
	int i;
	int digital[17];
	
	digital[0] = 16;
	for(i = 1; i < 13; i++)
		digital[i] = digital[i - 1] + 4;

	digital[13] = 100;
	digital[14] = 1024;
	digital[15] = 27000;
	digital[16] = 27001;
	
	cout << "orignal arrays: " << endl;
	for(i = 0; i < 13; i++)
		cout << digital[i] << " ";
	cout << endl;
 
	cout << "after sqrt: " << endl;
	for(i = 0; i < 13; i++)
		cout << (double)sqrt(digital[i]) << " ";
	cout << endl;
	
	cout << "closest factors: " << endl;
	pair<int, int> gn;
	gn = gainClosestFactor(digital[0]);
	int min = (gn.second-gn.first)<0 ? -1*(gn.second-gn.first):(gn.second-gn.first);
	int index  =0;
	for(i = 1; i < 1; i++)
	{
		gn = gainClosestFactor(digital[i]);
		cout << digital[i] << ": ";
		cout << "( " << gn.first << " , " << gn.second << " )" << endl;
		if(min>((gn.second-gn.first)<0 ? -1*(gn.second-gn.first):(gn.second-gn.first)))
		{
			min = ((gn.second-gn.first)<0 ? -1*(gn.second-gn.first):(gn.second-gn.first));
			index = i;
		}
	}

	gn = gainClosestFactor(digital[index]);
	cout<<endl<<"MIN:"<<gn.first<<", "<<gn.second<<endl;
 
	return 0;	
} 
