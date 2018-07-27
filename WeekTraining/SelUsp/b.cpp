#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
const int N = 1e6+7;

int ans[N];

int main(){
	ll n;
	scanf("%lld", &n);
	if(n % 4 == 1 or n % 4 == 2) return printf("-1\n"), 0;
	
	ll sum = n*(n+1)/4;
	for(int i=n;i>0;i--) if(i <= sum) sum -= i, ans[i] = 1;

	for(int i=1;i<=n;i++) printf("%c", ans[i] ? '+' : '-');

	printf("\n");
	return 0;
}
