#include <bits/stdc++.h>

using namespace std;

int a[100000];
int s[100000];
bool vis[100000];
vector<vector<int>> ans;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], s[i] = a[i];
	sort(s, &s[n]);
	for(int i = 0 ; i < n; i++)
	{
		if(vis[i])
			continue;
		int x = i;
		vector<int> t_ans;
		while(!vis[x])
		{
			t_ans.push_back(x + 1);
			vis[x] = true;
			x = lower_bound(s, &s[n], a[x]) - s; 
		}
		ans.push_back(t_ans);
	}
	cout << ans.size() << endl;
	for(auto v : ans)
	{
		cout << v.size() << " ";
		for(int i = 0; i < v.size() - 1; i++)
			cout << v[i] << ' ';
		cout << v[v.size() - 1] <<'\n';
	}
	return 0;
}
