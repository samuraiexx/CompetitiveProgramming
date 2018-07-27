nclude <iostream>
#include <list>

using namespace std;

list<int> adj[100001];
int sup[100001];
int lazy[100001]; //1 to wake 2 to put in bed
int seg[100001];
int sub[100001];

int countsub(int s)
{
	int sum = 0;
	for(auto a : adj[s])
		sum += countsub(a);
	sub[s] = sum;
	seg[s] = sum;
	return sum + 1;
}


void lazyf(int s)
{
	if(sup[s] != 0)
		lazyf(sup[s]);
	if(lazy[s])
	{
		for(auto a : adj[s])
			lazy[a] = lazy[s];
		if(lazy[s] == 1)
			seg[s] = sub[s];
		else
			seg[s] = 0;
		lazy[s] = 0;
	}
}


void update(int s, int type)
{
	lazyf(s);
	int nseg;
	for(auto a : adj[s])
		lazy[a] = type;
	if(type == 1)
		nseg = sub[s];
	else
		nseg = 0;
	int tmp = s;
	while(sup[tmp])
		tmp = sup[tmp], seg[tmp] += nseg - seg[s];
	seg[s] = nseg;
	
}

int query(int s)
{
	lazyf(s);
	return seg[s];
}

int main()
{
	int n, q;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int s;
		scanf("%d ", &s);
		adj[s].push_back(i);
		sup[i] = s;
	}
	countsub(0);
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int t, s;
		scanf("%d %d", &s, &t);
		if(t == 3)
			printf("%d\n", query(s));
		else
			update(s, t);
	}
	return 0;
}

