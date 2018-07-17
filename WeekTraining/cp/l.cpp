#include <iostream>
#include <map>

using namespace std;

long long rsubs[5000000];
long long lsubs[5000000];


int main(){
	long long n, t;
	while(!(cin >> n >> t).eof())
	{
		long long ans = 0;
		map<long long, long long> lset;
		for(long long k = 0, i = 1; k < n/2; k++)
		{
			long long x;
			cin >> x;
			for(long long j = i - 1; j >= 0; j--)
				lset[lsubs[i++] = lsubs[j] + x]++;
		}
		long long size = 1;
		for(long long k = n/2; k < n; k++)
		{
			long long x;
			cin >> x;
			for(long long j = size - 1; j >= 0; j--)
				rsubs[size++] = rsubs[j] + x;
		}
		lset[0]++;
		for(long long i = 0; i < size; i++)
		{
			ans += lset[t - rsubs[i]];
		}
		if(t == 0)
			ans--;
		cout << ans << endl;
	}
	return 0;
}
