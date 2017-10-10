#include<bits/stdc++.h>
using namespace std;
#define px first
#define py second
const int N = 1e5 + 1;
int S = 70;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int abs(int a) { return a > 0 ? a : -a; }

pair<int, int> lines[N];
int pos[N];

int main(){
	int n, prc, dts;
    bool found = 0;
    srand(5);
    cin >> n >> prc;
    dts = (n * prc + 99)/100;
    for(int i = 0; i < n; i++)
        cin >> lines[i].px >> lines[i].py, pos[i] = i;
    S = min(S, n);
    
    if(dts < 3)
        return cout << "possible\n", 0;

    random_shuffle(pos, &pos[n]);
    for(int i = 0;!found, i < S; i++)
    {
        map<pair<int, int>, int> count;
        pair<int, int> p = lines[pos[i]];
        for(int j = 0;!found, j < n; j++)
        {
            int x = lines[j].px - p.px,
                y = lines[j].py - p.py;
            if(x == 0 && y == 0) continue;
            if(y < 0) y = -y, x = -x;
            int mdc = gcd(abs(x), abs(y));
            if(++count[make_pair(x/mdc, y/mdc)] == dts - 1)
                found = true;
        }
    }
    if(found) cout << "possible\n";
    else cout << "impossible\n";
}
