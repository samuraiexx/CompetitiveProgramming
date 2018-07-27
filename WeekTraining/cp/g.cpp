#include <iostream>
#include <map>
#include <utility>

using namespace std;

int stup[1000000][20];
int stdn[1000000][20];

int main()
{
	int n;
	while(!(cin >> n).eof())
	{
		int ans = 0;
		map<int, pair<bool, pair<int, int>>, greater<int>> pos; //0 up, 1 down
		for(int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			stup[i][0] = x;
			if(pos.count(x))
				pos[x].second.second = i;
			else
				pos[x] = make_pair(0, make_pair(i, -1));
		}
		for(int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			stdn[i][0] = x;
			if(pos.count(x))
			{
				if(pos[x].first == 0)
					pos.erase(x), ans = max(ans, x);
				else
					pos[x].second.second = i;
			}
			else
				pos[x] = make_pair(1, make_pair(i, -1));
		}
		
		for(int k = 1; 1 << k < n; k++)
			for(int i = 0; i + (1 << k) < n; i++)
				stup[i][k] = max(stup[i][k-1], stup[i + (1 << k - 1)][k-1]),
				stdn[i][k] = max(stdn[i][k-1], stdn[i + (1 << k - 1)][k-1]);

		for(auto it = pos.begin(); it != pos.end(); it++)
		{
			int a = it->second.second.first, b = it->second.second.second;
			if(it->first < ans)
				break;
			if(a > b)
				swap(a, b);
			if(a + 1 == b)
				continue;
			a++;
			b--;
			int mab;
			if(a == b)
				if(it->second.first == 0)
					mab = stup[a][0];
				else
					mab = stdn[a][0];
			else
			{
				int k;
				for(k = 20; k >= 0; k--)
					if(1 << k & b - a)
						break;
				if(it->second.first == 0)
					mab =  max(stup[a][k], stup[b - (1 << k)][k]);
				else	
					mab =  max(stdn[a][k], stdn[b - (1 << k)][k]);
			}
			mab = min(it->first, mab);
			ans = max(ans, mab);
		}
		cout << ans << '\n';
	}
	return 0;

}
