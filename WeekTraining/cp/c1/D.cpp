#include<iostream>
#include <vector>

using namespace std;
int gx[1000], gy[1000], gr[1000];
int dir[1000]; //  0 not set, dir3 or dir4
int tg;

int dfs(int n, vector<int> *adj) // 2 dead end or ok cycle, 1 found the target, -1 cannot move 
{
	int res = 2;
	for(auto a : adj[n])
	{
		if(dir[a] && dir[a] == dir[n])
			return -1;
		if(!dir[a])
		{
			dir[a] = dir[n]^1;
			res = min(res, dfs(a, adj));
		}
	}
	if(n == tg)
		return min(res, 1);
	return res;
}

int main(){
	int n;
	while(!(cin >> n).eof())
	{
		tg = n - 1;
		vector<int> *adj = new vector<int>[n];
		for(int i = 0; i < n; i++)
			cin >> gx[i] >> gy[i] >> gr[i], dir[i] = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(i != j && (gx[i] - gx[j])*(gx[i] - gx[j]) + 
				(gy[i] - gy[j])*(gy[i] - gy[j]) <= (gr[i] + gr[j])*(gr[i] + gr[j]))
					adj[i].push_back(j), adj[j].push_back(i);
		
		dir[0] = 3;
		int ans = dfs(0, adj);
		if(ans == -1)
			cout << -1 << '\n';
		else if(ans == 2)
			cout << 0 << '\n';
		else
		{	
			int a = gr[0], b = gr[tg];
			while(a && b)
			{
				if(a > b)
					swap(a, b);
				b = b%a;
			}
			a = a | b;
			if(dir[tg] != dir[0])
				gr[0] = - gr[0];
			cout << gr[tg]/a << ' ' << gr[0]/a << '\n';
		}
		delete[] adj;
	}
}
