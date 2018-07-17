#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+5;

long long t[N], dp[N];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int u;
		scanf("%d", &u);
		t[i] = u;
	}
	sort(t, t+n);

	dp[0] = t[0];
	dp[1] = t[1];
	for(int i=2;i<n;i++) dp[i] = min(dp[i-1] + t[i] + t[0],
					 dp[i-2] + t[i] + t[1] + t[0] + t[1]);

	printf("%lld\n", dp[n-1]);

	return 0;
}
