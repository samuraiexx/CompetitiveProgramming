#include<iostream>

using namespace std;

int t[1000000];
int d[1000000];

int a, b;

int main()
{
	int n, s;
	double mn = INF;
	cin >> n >> s;
	int lixo;
	cin >> lixo;
	for(int i = 0; i < n; i++)
	{
		cin >> d[i]
		if(i < n - 1)
			cin  >> t[i];
		if(i > 0)
			t[i] -= t[i - 1];
	}
	t[n - 1] = s/d[n-1] + 1;
	int sum = t[0]*d[0];
	int ttime = t[0];
	for(int i = 0, j = 0; i < n; sum-=t[i]*d[i], ttime -= t[i], ++i)
	{
		while(1)
		{
			sum += t[j]*d[j];
			ttime += t[j];
			if(sum < s)
				continue;
			int tsum;
			if(d[i] > d[j])
			{
				int tsum = sum - d[j]*t[j];
				int tttime = ttime - t[j];
				int tmp;
				if(mn > (tmp = tttime + (s - tsum)/(double)d[j]))
				{
					mn = tmp;
					a = tttime*d[j] + s - sum;
					b = d[j];
				}
			}
			else
			{
				int tsum = sum - d[i]*t[i];
				int tttime = ttime - t[i];
				int tmp;
				if(mn > (tmp = tttime + (s - tsum)/(double)d[i]))
				{
					mn = tmp;
					a = tttime*d[i] + s - sum;
					b = d[i];
				}
			}
			break;
		}
	}
	cout << mn << 
}
