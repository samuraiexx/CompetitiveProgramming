#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int l, r, x, y, k;	
	cin >> l >> r >> x >> y >> k;
	if(r/k < x || (l + k - 1)/k > y || r/k < (r+k-1)/k)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}
