#include <iostream>

using namespace std;

struct scubber_cylinder{
	int o, n, w;
} cyl[1001];

int dp[1001][22][80];

const int INF = 100000000;


int main()
{
	int c;
	cin >> c;
	for(int i = 0; i < c; i++)
	{
		int t, a, n;
		cin >> t >> a >> n;
		for(int i = 1; i <= n; i++)
			cin >> cyl[i].o >> cyl[i].n >> cyl[i].w;

		for(int j = 0; j <= t; j++)
			for(int k = 0; k <= a; k++)
				dp[0][j][k] = INF;
		dp[0][0][0] = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j <= t; j++)
				for(int k = 0; k <= a; k++)
					dp[i][j][k] = min(dp[i - 1][max(0, j - cyl[i].o)][max(0, k - cyl[i].n)] + cyl[i].w, dp[i - 1][j][k]);
		cout << dp[n][t][a] << '\n';
	}
	return 0;
}
