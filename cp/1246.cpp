#include <iostream>
#include <map>

using namespace std;

int pos[10000];
int siz[10000];

int main()
{
	int c, n;
	while(!(cin >> c >> n).eof())
	{
		map<int, int> flot;
		int ans = 0;
		flot[0] = c;
		for(int i = 0; i < n; i++)
		{
			char c;
			while(cin >> c, c == '\n');
			if(c == 'C')
			{
				int p, q;
				cin >> p >> q;
				for(auto it = flot.begin(); it != flot.end(); it++)
					if(it->second >= q)
					{
						ans += 10;
						if(it->second != q)
							flot[it->first + q] = it->second - q;
						pos[p] = it->first;
						siz[p] = q;
						flot.erase(it);
						break;
					}
			}
			else
			{
				int p, x, size;
				cin >> p;
				size = siz[p];
				x = pos[p];
				auto it = flot.lower_bound(x), up = it;
				if(it != flot.begin() && (--it)->first + it->second == x)
					it->second += size;
				else	it = flot.insert(make_pair(x, size)).first;
				if(up != flot.end() && up->first == it->second + it->first)
					 it->second += up->second, flot.erase(up);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
