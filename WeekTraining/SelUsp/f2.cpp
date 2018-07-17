#include <bits/stdc++.h>

using namespace std;

const int N = 3e6;

int sc[N];

int main(){
	int r;
	scanf("%d", &r);
	r = r*r;
	for(int i=1;i<=10;i++) sc[i*i*r+1]++;
	for(int i=1;i<N;i++) sc[i] += sc[i-1];

	int x1, x2, x3, y1, y2, y3;

	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d %d", &x3, &y3);

	int r1 = x1*x1 + y1*y1;
	int r2 = x2*x2 + y2*y2;
	int r3 = x3*x3 + y3*y3;

	printf("%d\n", 30-sc[r1]-sc[r2]-sc[r3]);
}
