#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	string n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		int a = n[n.size() - 1] - '0';
		if(a == 0 && n.size() == 1)
			cout << 1 << endl;
		else if(a == 1 && n.size() == 1)
			cout << 66 << endl;
		else
			switch(a%5)
			{
				case 0:
					cout << 76 << endl;	
					break;
				case 1:
					cout << 16 << endl;	
					break;
				case 2:
					cout << 56 << endl;	
					break;
				case 3:
					cout << 96 << endl;	
					break;
				case 4:
					cout << 36 << endl;	
					break;
			}
		
	}
	return 0;
}
