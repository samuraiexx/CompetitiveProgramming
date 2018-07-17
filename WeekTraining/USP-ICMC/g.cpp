#include <bits/stdc++.h>

using namespace std;

int p[26][26];
int dp[10001][26][26];


int main(){
	int k;
	cin >> k;
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < 26; j++)
			cin >> p[i][j];
	for(int size = 2; size <= k; size++)
		for(int i = 0; i < 26; i++)
			for(int j = 0; j < 26; j++)
			{
				int mn = 0x3f3f3f3f;
				for(int k = 0; k < 26; k++)
					mn = min(mn, dp[size - 1][i][k] + p[k][j]);
				dp[size][i][j] = mn;
			}
	int ans = 0x3f3f3f3f;
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < 26; j++)
			ans = min(ans, dp[k][i][j]);
	cout << ans << endl;
}
