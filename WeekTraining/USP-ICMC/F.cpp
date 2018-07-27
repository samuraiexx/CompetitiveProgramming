#include <cstdio>

typedef unsigned long ull;
#define LLU "%lu"

#define MAX(a,b) ((a)>(b)?(a):(b))

ull s[100001], p[100001], d[100001];
ull ss[100001][20];

int main()
{
	ull n, m;
	scanf(LLU LLU, &n, &m);


	p[1] = 0;
	d[1] = 0;
	scanf(LLU, &s[1]);

	for (ull i = 1; i < n; i++)
	{
		ull u;
		scanf(LLU, &u);
		scanf(LLU LLU, &p[u], &s[u]);
	}

	ull dmax = 0;
	for (ull i = 2; i <= n; i++)
	{
		d[i] = 0;
		ull k = p[i];
		while (k)
		{
			d[i]++;
			k = p[k];
		}

		if (dmax < d[i]) dmax = d[i];
	}

	for (ull i = 1; i <= n; i++)
	{
		ull k = i;
		while (k)
		{
			ss[k][d[i]] += s[i];
			k = p[k];
		}
	}

	for (ull j = 0; j < m; j++)
	{
		ull k;
		scanf(LLU, &k);

		ull ms = 0;
		for (ull di = 0; di <= dmax; di++)
			ms = MAX(ms, ss[1][di] - ss[k][di]);

		printf(LLU "\n", ms);
	}
}
