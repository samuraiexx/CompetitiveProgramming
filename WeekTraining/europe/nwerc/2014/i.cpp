#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
#define px first
#define py second

int n;
pair<int, int> ctz[N];

int abs(int a) { return a > 0 ? a : -a; }

int dist(pair<int, int> p)
{
    int mx = 0;
    for(int i = 0; i < n; i++)
        mx = max(mx, abs(ctz[i].px - p.px) + abs(ctz[i].py - p.py));
    return mx;
}

int ts(function<int (int)> f)
{
    int a = 0, b = 1e9 + 1;
    while(b - a > 3)
    {
        int a1 = (a+b)/2 - 1, b1 = a1 + 1;
        if(f(a1) > f(b1)) a = a1;
        else b = b1;
    }
    return min(f(a), min(f(b), f(a+1)));
}

int main(){
	int d;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> ctz[i].px >> ctz[i].py;
    cin >> d;
    int mn = ts([] (int x) { return ts([x] (int y) { return dist({x, y});});});
    if(mn <= d)
        cout << mn << endl;
    else cout << "impossible" << endl;
    return 0;
}
