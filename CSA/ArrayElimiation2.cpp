#include <bits/stdc++.h>

using namespace std;

int v[100000];
int tmp[100000];
int n;

int margesort(int l, int r)
{
	if(l == r)
		return 0;
	int inv = 0;
	int m = (l + r)/2;
	inv += margesort(l, m), inv += margesort(m + 1, r); 
	int p1 = l, p2 = m + 1;
	for(int i = l; i <= r; i++)
	{
		if(p1 > m)
			tmp[i] = v[p2++];
		else if(p2 > r)
			tmp[i] = v[p1++];
		else if(v[p1] <= v[p2])
			tmp[i] = v[p1++];
		else
			inv += m - p1 + 1, tmp[i] = v[p2++];
	}
	for(int i = l; i <= r; i++)
		v[i] = tmp[i];
	return inv;
}

int main(){
	cin >> n;
	set<int> cnt;
	for(int i = 0; i < n; i++)
		cin >> v[i], cnt.insert(v[i]);
	cout << margesort(0, n - 1) << endl;
		
}
