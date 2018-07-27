#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 4e5+5;

ll prod = 1, v[N], st[4*N];

int gcd(int a, int b){	return b ? gcd(b, a%b) : a ;	}

void build(int p, int l, int r){
	if(l == r){	st[p] = v[l]; return;	}
	build(2*p, l, (l+r)/2);
	build(2*p+1, (l+r)/2, r);
	st[p] = gcd(st[2*p], st[2*p+1]);
}

int query(int p, int l, int r, int i, int j){
	if(r < i or l > j) return prod;
	if(l >= i and r <= j) return st[p];
	return gcd(query(2*p, l, (l+r)/2, i, j), query(2*p+1, (l+r)/2+1, r, i, j));
}

int main(){
	int n;
	scanf("%d", &n);

}
