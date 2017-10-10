#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int r, d, n;
	int ans = 0;
	cin >> r >> d >> n;
	for(int i = 0; i < n; i++)
	{
		int x, y, ri;
		cin >> x >> y >> ri;
		if(x*x + y*y >= (ri + r - d)*(ri + r - d) && x*x + y*y <= (-ri + r)*(-ri + r))
			ans++;
	}
	cout << ans << endl;
	return 0;
}
