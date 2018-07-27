#include <cstdio>

using namespace std;

int main()
{
	long n, x;
	scanf("%ld%ld", &n, &x);

	long ans = -1;
	long min = 1000, max = -1000;
	for (long i = 0; i < n; i++)
	{
		long v;
		scanf("%ld", &v);
		
		if (min > v) min = v;
		if (max < v) max = v;
		if (x == v) ans = 1;
	}

	if (ans != 1) if (x >= min && x <= max) ans = 2;
	printf("%ld\n", ans);
}
