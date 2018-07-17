#include <bits/stdc++.h>

using namespace std;

int p[51][2];

int dp[101][51];

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n, k, r;
		bool ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> p[i][0] >> p[i][1];
		cin >> k >> r;
		for(int i = 1; i <= k; i++)
			for(int j = 1; j <= n; j++)
			{
				dp[i][j] = dp[i][j - 1];
				if(i >= p[j][1])
					dp[i][j] = max(dp[i][j], dp[i - p[j][1]][j - 1] + p[j][0]);
			}
		for(int i = 0; i <= k; i++)
			if(dp[i][n - 1] >= r)
			{
				cout << "A resistencia do castelo " << r << " nao suportou o ataque da missao " << dp[i][n - 1] << endl;
				ans = 1;
				break;
			}
		if(!ans)
			cout << "Missao falhou\n";
	}
	return 0;
}
