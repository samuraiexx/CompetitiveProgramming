#include <bits/stdc++.h>

using namespace std;

unsigned long long t[50][50];

int main(){
	unsigned long long n, m;
	cin >> n >> m;
	unsigned long long ans = 0;
	for(unsigned long long i = 0; i < n; i++)
	{
		unsigned long long b = 0;
		for(unsigned long long j = 0; j < m; j++)
		{
			cin >> t[i][j];
			if(t[i][j] == 1)
				b++;
		}
		ans += ((long long) 1 << b) - b - 1;
		ans += ((long long) 1 << m - b) - m + b - 1;
	}
	
	for(unsigned long long j = 0; j < m; j++)
	{
		unsigned long long b = 0;
		for(unsigned long long i = 0; i < n; i++)
			if(t[i][j] == 1)
				b++;
		ans += ((long long) 1 << b) - b - 1;
		ans += ((long long) 1 << n - b) - n + b - 1;
	}
	ans += n*m;
	cout << ans << endl;
	return 0;
}
