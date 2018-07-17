#include <iostream>

using namespace std;

int divs[1000001]; 
int pfs[1000001];
int ks[1000001];

int bit[1000001][13]; // k =1, 2, 3

void update(int i, int k)
{
	for(;i <= 1000000; i+=i&-i)
		bit[i][k]++;
}

int query(int a, int b, int k)
{
	int ans = 0;
	a--;
	for(;b > 0; b -= b&-b)
		ans += bit[b][k];
	for(;a > 0; a -= a&-a)
		ans -= bit[a][k];
	return ans;
}

int main()
{
	int p;
	for(int i = 2; i*i <= 1000000; i++)
	{
		if(!divs[i])
			for(int j = i*2; j <= 1000000; j += i)
				divs[j] = i;
	}
	for(int i = 2; i <= 1000000; i++)
	{
		if(!divs[i])
			ks[i] = 1, pfs[i] = i;
		else
		{
			int tmp = i;
			while(tmp % divs[i] == 0)
				tmp /= divs[i];
			pfs[i] = pfs[tmp] + divs[i];
			ks[i] = 1 + ks[pfs[i]];
		}
		update(i, ks[i]);
	}
	cin >> p;
	for(int i = 0; i < p; i++)
	{
		int a, b, k;
		cin >> a >> b >> k;
		if(k > 12)
			cout << 0 << endl;
		else
			cout << query(a, b, k) << endl;
	}
	return 0;	
}
