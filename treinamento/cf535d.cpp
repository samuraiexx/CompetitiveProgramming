#include<bits/stdc++.h>

using namespace std;

int lps[1000000];

int n, m;
string p;

const int MOD = 1e9 + 7;

void lpsf()
{
	int i = 1, j = 0;
	while(i < p.size())
	{
		if(p[i] == p[j])
			lps[i++] = ++j;
		else if(j == 0)
			i++;
		else
			j = lps[j - 1];
	}
}

int main(){
	cin >> n >> m >> p;
	int prev, filled = 0, s = p.size();
	if(m > 0)
		cin >> prev, filled = s;
	lpsf();
	for(int i = 1; i < m; i++)
	{
		int yi, j = 0;
		cin >> yi;
		if(prev + s > yi)
		{
			j = s;
			while(j > 0 && yi + j != prev + s)
				j = lps[j - 1];
			if(j == 0)
				return cout << 0 << endl, 0;
		}
		filled += s - j;
		prev = yi;
	}
	long long exp = 1, a = 26, b = n - filled;
	while(b)
	{
		if(b%2)	exp = (exp*a)%MOD;
		a = (a*a)%MOD;
		b /= 2;
	}
	cout << exp << endl;
	return 0;

}
