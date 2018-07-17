#include<iostream>

using namespace std;

long long s, f;

long long dp[10000001];

long long count(long long e)
{
	if(e <= 0)
		return 1;
	return dp[e];
}

int main()
{
	long long e;
	while(!(cin >> e >> s >> f).eof())
	{
		for(int i = 0; i <= e; i++)
		{
			dp[i] = min(count(i - s) + count(i - f), (long long)0x3f3f3f3f);
		}
		long long n = count(e);
		double ans = 200/(double)(n - 1);
		if(ans > 25)
			ans = 225/(double)n;
		printf("%.6lf\n", ans);
	}
	return 0;
}
