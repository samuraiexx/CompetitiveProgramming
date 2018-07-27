#include <iostream>

using namespace std;

int cars[1000001];

int main()
{
	int n, a;
	bool found = 0;
	cin >> n >> a;
	for(int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		if(c == a || cars[c] >= cars[a])
			cars[c]++;
	}
	for(int i = 1; i <= 1000000; i++)
		if(i != a && cars[i] >= cars[a])
		{
			cout << i << endl;
			found = 1;
			break;
		}
	if(!found)
		cout << -1 << endl;
	return 0;		
}
