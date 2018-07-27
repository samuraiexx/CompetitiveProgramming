#include <bits/stdc++.h>

using namespace std;

const int opn = 0x3f3f3f3f;

pair<int, int> ls[300009];

int yp[100005];

int yred[300009];

pair<int, int> dys[100005];

int bit[300009];

int ans[100005];

void update(int y1, int y2, int val)
{
	y1++;
	for(; y2 <= 300009; y2+=y2&-y2)	bit[y2] -= val;
	for(; y1 <= 300009; y1+=y1&-y1)	bit[y1] += val;
}

int query(int p)
{
	int ans = 0;
	for(; p > 0; p -= p&-p) ans += bit[p];
	return ans;
}

int main(){
	int n, m;
	map<int, int> red;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		ls[i] = {x, i};
		yp[i] = y;
		yred[i] = y;
	}
	int k = n;
	for(int i = 1; i <= m; i++)
	{
		int xi, yi, xf, yf;
		cin >> xi >> yi >> xf >> yf;
		yred[k] = yi;
		ls[k++] = { xi, opn + i};
		yred[k] = yf;
		ls[k++] = { xf, -i};
		dys[i] = {yi, yf};
	}
	sort(ls, &ls[k]);
	sort(yred, &yred[k]);
	for(int i = 0; i < k; i++)
		red[yred[i]] = i + 1;

	for(int i = 0; i < n; i++)
		yp[i] = red[yp[i]];
	for(int i = 1; i <= m; i++)
		dys[i] = {red[dys[i].first], red[dys[i].second]};
	
	for(int i = 0; i < k; i++)
	{
		int y1, y2;
		pair<int, int> pnt = ls[i];
		if(pnt.second > opn)
		{
			y1 = dys[pnt.second - opn].first;
			y2 = dys[pnt.second - opn].second;
			update(y1, y2, 1);
		}
		else if(pnt.second < 0)
		{
			y1 = dys[-pnt.second].first;
			y2 = dys[-pnt.second].second;
			update(y1, y2, -1);
		}
		else
			ans[pnt.second] = query(yp[pnt.second]);

	}
	
	for(int i = 0; i < n; i++)
		cout << ans[i] << '\n';
	
	return 0;
}
