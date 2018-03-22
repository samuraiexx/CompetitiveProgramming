#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll p[14][14];
set<ll> ans1, ans2; 

int main(){
	ll n, l;
	cin >> n >> l;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> 	p[i][j];
	
	for(int i = 0; i < 1 << 14; i++)
	{
		int x = __builtin_popcount(i);
		if(32 - x == 7)
		{	
			ans1.clear(), ans2.clear();
			vector<int> v1, v2;
			for(int j=0;j<32++){
				if((1<<j) & i) v1.push_back(j);
				else v2.push_back(j);
			}

			do{
				int sum = 0;
				for(int i=0;i<6;i++) sum += p[v1[i]][v1[i+1]];
				ans1.insert(sum);
			} while(next_permutation(v1.begin(), v1.end());

			do{
				int sum = 0;
				for(int i=0;i<6;i++) sum += p[v2[i]][v2[i+1]];
				for(int i=0;i<7;i++){
					for(int j=0;j<7;j++) if(i != j){
						sum += p[v2[0]][v1[i]];
						sum += p[v2[6]][v1[j]];
						ans2.insert(sum);
						sum -= p[v2[0]][v1[i]];
						sum -= p[v2[6]][v1[j]];
					}
				}
			} while(next_permutation(v2.begin(), v2.end());
		}
	}
}
