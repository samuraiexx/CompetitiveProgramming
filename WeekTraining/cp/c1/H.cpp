#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

pair<double, double> ps[100000];

int main(){
	int n, r, w, h;
	while(cin >> n >> r >> w >> h)
	{
		multiset<double> lis;
		for(int i = 0; i < n; i++)
		{
			cin >> ps[i].first >> ps[i].second;
			double tmp = ps[i].first;
			ps[i].first = ps[i].second - r*ps[i].first;
			ps[i].second = ps[i].second + r*tmp;
		}
		sort(ps, &ps[n]);
		lis.insert(ps[0].second);
		for(int i = 1; i < n; i++)
		{
			double y = ps[i].second;
			auto it = lis.lower_bound(y);
			if(it != lis.end())
				lis.erase(it);
			lis.insert(y);
		}
		cout << lis.size() << '\n';
	}
}
