#include<iostream>


using namespace std;

int n;
int bit[100001][26];
char seq[100001];

void update(int x,char d)
{
	int tmp = x;
	if(seq[x])
		for(; tmp <= n; tmp += tmp&-tmp)
			bit[tmp][seq[x]-'a'] -= 1;
	seq[x] = d;
	for(;x <= n;x+=x&-x)
		bit[x][d-'a'] += 1;
}

bool query(int la, int ra)
{	
	int odd = 0;
	la--; // includes at l
	for(int i = 0; i < 26; i++)
	{
		int l = la, r = ra;
		int nl = 0;
		for(;r>0;r -= r&-r)
			nl+=bit[r][i];
		for(;l > 0; l -= l&-l)
			nl-=bit[l][i];
		if(nl%2)
			odd++;
	}	
	return odd < 2;
}


int main(){
	int q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		{
			char c;
			cin >> c;
			update(i, c);
		}
	for(int i = 0; i < q; i++)
	{
		int opt;
		cin >> opt;
		if(opt == 1)
		{
			int p;
			char x;
			cin >> p >> x;
			update(p, x);				
		}
		else {
			int l, r;
			cin >> l >> r;
			if(query(l, r))
				cout << "yes\n";
			else
				cout << "no\n";		
		}
	}	
	return 0;
}
