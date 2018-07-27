#include <iostream>
#include <algorithm>

using namespace std;

int lis[500000];

int main()
{
	int n, s = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if(s == 0)
			lis[s++] = x;
		else if(lis[s - 1] < x)
			lis[s++] = x;
		else
			*upper_bound(lis, &lis[s], x) = x;
	}
	cout << s << endl;
	return 0;
}
