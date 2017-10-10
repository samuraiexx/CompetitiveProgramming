#include <iostream>
#include <algorithm>

using namespace std;

struct query
{
	int l, r, i, ans;
};

int n, m, d;

bool byr(query q1, query q2)
{
	return q1.r < q2.r;
}

bool byi(query q1, query q2)
{
	return q1.i < q2.i;
}

int bit[100001];
int pos[100001];
int per[100001];
query qry[100000];

void update(int p)
{
	int x = per[p];
	for(int i = x - d; i <= x + d; i++)
		if(i > 0 && i <= n && pos[i] <= p)
			for(int tmp = pos[i];tmp <= n; tmp+=tmp&-tmp)
				bit[tmp]++;
}

int see(int l)
{
	int sum = 0;
	l--;
	for(int i = n; i > 0; i -= i&-i)
		sum += bit[i];
	for(; l > 0; l -= l&-l)
		sum -= bit[l];
	return sum;
}


int main()
{
	cin >> n >> m >> d;
	for(int i = 1; i <= n; i++)
	{
		int p;
		cin >> p;
		pos[p] = i, per[i] = p;
	}
	for(int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		qry[i] = {l, r, i, -1};
	}
	sort(qry, qry+m, byr);
	int j = 1;
	for(int i = 0; i < m; i++)
	{
		query &q = qry[i];
		for(;j <= q.r; j++)
			update(j);
		q.ans = see(q.l);
	}	
	sort(qry, qry+m, byi);
	for(int i = 0; i < m; i++)
		cout << qry[i].ans << endl;
	return 0;	
}
