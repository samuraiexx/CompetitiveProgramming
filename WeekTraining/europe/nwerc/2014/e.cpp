#include<bits/stdc++.h>
using namespace std;
int n;
double p, s, v;

double f(double p1)
{
	return n*pow(log2(n),p1*pow(2, 0.5))/p/1e9 +  s*(1 + 1/p1)/v;	
}

int main(){
	double i = 0, j = 1e18;
	cin >> n >> p >> s >> v;
	while(j - i > 1e-7)
	{
		double p1, p2;
		p1 = (2*i + j)/3;
		p2 = (2*j + i)/3;
		if(f(p1) > f(p2))
			i = p1;
		else
			j = p2;
	}
	printf("%.6lf %.6lf\n", f(i), i);
	return 0;
}
