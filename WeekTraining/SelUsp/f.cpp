#include <bits/stdc++.h>

using namespace std;

int main(){
	int r, scr = 0;
	cin >> r;
	r = r*r;
	for(int i = 0, x, y, d; i < 3; i++)
	{
		cin >> x >> y, d = x*x + y*y;
		if(d > r)
			continue;
		scr += 11 - ceil(sqrt(d/r));
		if(d == 0) scr--;
	}
	cout << scr << endl;

}
