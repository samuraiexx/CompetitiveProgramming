#include <iostream>
#include <set>

using namespace std;

bool prime[100000];

int main(){
	set<long long> primes;
	for(long long i = 4; i*i <= ((long long)1 << 31); i++)
		if(!prime[i])
		{
			primes.insert(i);
			for(long long j = i; j*j <= ((long long)1 << 31); j += i)
				prime[j] = 1;
		}
	long long n;
	while(!(cin >> n).eof())
	{
		long long ans = 0;
		if(n == 3)
		{
			cout << 4 << '\n';
			continue;
		}
		if(n < 7)
		{
			cout << "No such base\n";
			continue;
		}
		for(auto a : primes)
			if((n - 3)%a == 0)
			{
				ans = a;
				break;
			}
		if(ans)
			cout << ans << '\n';
		else
		{
			if((n - 3)%3 == 0)
				cout << (n - 3)/3 << '\n';
			else if((n - 3)%2 == 0)
				cout << (n - 3)/2 << '\n';
			else 
				cout << n - 3 << '\n';
		}
	}
	return 0;
}
