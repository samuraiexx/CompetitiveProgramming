#include <bits/stdc++.h>

using namespace std;

char sides[] = {'E', 'S', '0', 'N'};

int main()
{
	int x0, y0, x, y;
	char side;
	int is;
	cin >> x0 >> y0 >> side >> x >> y;
	x -= x0, y -= y0;
	if(side == '0')
		is = 2;
	else if(side == 'S')
		is = 1;
	else if(side == 'E')
		is = 0;
	else if(side == 'N')
		is = 3;
	int td1, td2;
	if(x == 0) td1 = -1;
	else if(x > 0) td1 = 0;
	else td1 = 2;

	if(y == 0) td2 = -1;
	else if(y > 0) td2 = 3;
	else td2 = 1;
	int s1 = 0, s2 = 0;
	int tmp = is;
	while(tmp != td1 && td1 != -1)
		tmp = (tmp + 1)%4, s1++;
	while(tmp != td2 && td2 != -1)
		tmp = (tmp + 1)%4, s1++;
	tmp = is;
	while(tmp != td2 && td2 != -1)
		tmp = (tmp + 1)%4, s2++;
	while(tmp != td1 && td1 != -1)
		tmp = (tmp + 1)%4, s2++;
	tmp = is;
	if(x < 0)
		x = -x;
	if(y < 0)
		y = -y;
	if(s1 < s2)
	{
		cout << s1 + (x != 0) + (y != 0) << '\n';
		while(tmp != td1 && td1 != -1)
			tmp = (tmp + 1)%4, cout << "D\n";
		if(x != 0)
			cout << "A " << x << '\n';
		while(tmp != td2 && td2 != -1)
			tmp = (tmp + 1)%4, cout << "D\n";
		if(y != 0)
			cout << "A " << y << '\n';
	}
	else
	{
		cout << s2 + (x != 0) + (y != 0) << '\n';
		while(tmp != td2 && td2 != -1)
			tmp = (tmp + 1)%4, cout << "D\n";
		if(y != 0)
			cout << "A " << y << '\n';
		while(tmp != td1 && td1 != -1)
			tmp = (tmp + 1)%4, cout << "D\n";
		if(x != 0)
			cout << "A " << x << '\n';
	}
	return 0;
}
