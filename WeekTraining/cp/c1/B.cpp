#include <iostream>
#include <vector>

using namespace std;

char t[26][26];

int dx = {-1, 1, -1, 1};
int dy = {1, 1, -1, -1};

int main(){
	int n;
	while(!(cin >> n).eof())
	{
		vector<pair<int, int>> wl;
		vector<pair<int, int>> bl;
		pair<int, int> ans;
		for(int i = 0; i <=n; i++)
			t[0][i] = t[i][0] = '.';
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				char c;
				cin >> c;
				if( c == '_' || c == 'W')
					t[i][j] = '_';
				else
					t[i][j] = '.';
				
				if(c == 'W')
					wl.push_back(make_pair(i, j));
				if(c == 'B')
					bl.push_back(make_pair(i, j)):
			}
		string ini(wl.size(), 1);
		for(auto b : bl)
		{
			set<pair<string, pair<int, int>>> vis;
			queue<pair<string, pair<int, int>> q;
			t[b.first][b.second] = "_";
			q.push(make_pair(ini, make_pair(b.first, b.second)));
			while(q.size())
			{
				int p = q.front();
				q.pop()
				int x = p.second.first;
				int y = p.second.second;
				bool ok = 1;

				for(auto a : p.first)
					if(a == '0')
					{
						ok = 0;
						break;
					}
				if(ok)
				{
					ans.push_back(make_pair(x, y);
					break;
				}
				
				for(int i = 0; i < 4; i++)
					for(int i = 0; i <  wl.size(); i++)
					{
						auto w = wl[i];
						if(p.first[i] == '1' && w.first == x + dx[i] && w.second == y + dy[i] && t[x + 2*dx[i]][y + 2*dy[i]] == '_')
						{
							string tmp = p.first;
							tmp[i] = '0';
							q.push(make_pair(tmp, make_pair(x+2*dx[i], y+2*dy[i]));
						}
					}
					
			}
			t[b.first][b.second] = ".";
		}
		if(ans.size() == 0)
			cout << "None\n";
		else if(ans.size() > 1)
			cout << "";
	}
}
