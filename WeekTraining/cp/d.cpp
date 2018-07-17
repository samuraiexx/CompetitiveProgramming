#include <iostream>

using namespace std;

long long xk[10000];
long long h[10001];
long long wh[10000];

int main(){
	long long t;
	cin >> t;
	for(long long i = 0; i < t; i++)
	{
		long long a, n;
		long long ans = 0;
		cin >> a >> n;
		for(long long i = 0; i < n; i++)
			cin >> xk[i];
		for(long long i = 0; i <= n; i++)
			cin >> h[i];
		wh[0] = h[0];
		for(long long i = 1; i < n; i++)
			wh[i] = max(h[i], wh[i-1]);
		wh[n - 1] = min(wh[n - 1], h[n]);
		ans = wh[n - 1]*xk[n-1]*a;
		for(long long i = n - 2; i >= 0; i--)
		{
			wh[i] = min(wh[i], max(wh[i + 1], h[i + 1])); 
			ans += wh[i]*xk[i]*a;
		}
		cout << ans << endl;
	}
	return 0;
}
