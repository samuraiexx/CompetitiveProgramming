#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
#define LLD "%I64d"

struct pt { ll x, y; pt(ll _x = 0, ll _y = 0) : x(_x), y(_y) {} };

bool yorder(const pt& p1, const pt& p2)
{
	return p1.y < p2.y;
}

bool isInside(const vector<pt>& verts, const vector<pt>& targets)
{
	ll n = verts.size();
	ll im = 0, iM = 0;

	for (ll i = 0; i < n; i++)
	{
		if (verts[im].y > verts[i].y) im = i;
		if (verts[iM].y < verts[i].y) iM = i;
	}

	ll ym = verts[im].y, yM = verts[iM].y;

	vector<pt> ls, rs;
	for (ll i = im; i != iM; i = (i+1) % n)
		ls.push_back(verts[i]);
	ls.push_back(verts[iM]);

	for (ll i = im; i != iM; i = (i+n-1) % n)
		rs.push_back(verts[i]);
	rs.push_back(verts[iM]);

	for (const pt& p : targets)
	{
		if (p.y <= ym || p.y >= yM)
			return false;
	
		auto itl = upper_bound(ls.begin(), ls.end(), p, yorder);
		pt pl1 = itl[-1], pl2 = itl[0];
		if ((pl2.y-pl1.y)*(p.x-pl1.x) <= (pl2.x-pl1.x)*(p.y-pl1.y))
			return false;

		auto itr = upper_bound(rs.begin(), rs.end(), p, yorder);
		pt pr1 = itr[-1], pr2 = itr[0];
		if ((pr2.y-pr1.y)*(p.x-pr1.x) >= (pr2.x-pr1.x)*(p.y-pr1.y))
			return false;
	}

	return true;
}

int main()
{
	ll n, m;
	scanf(LLD LLD, &n, &m);

	vector<pt> verts1(n), verts2(m);
	for (pt& p : verts1) scanf(LLD LLD, &p.x, &p.y);
	for (pt& p : verts2) scanf(LLD LLD, &p.x, &p.y);

	bool ans = isInside(verts1, verts2) || isInside(verts2, verts1);
	puts(ans ? "YES" : "NO");
}
