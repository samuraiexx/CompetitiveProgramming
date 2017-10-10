#include<bits/stdc++.h>
using namespace std;

int pnt[1000];

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> pnt[i];
	sort(pnt, &pnt[n]);
	cout << &pnt[n] - lower_bound(pnt, &pnt[n], pnt[n - k]) << endl;
	return 0;
}
