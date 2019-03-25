#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << "==" << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<ll, ll> pii;
typedef pair<ll, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const ll INF = 0x3f3f3f3f, MOD = 1e9+7, N = 2e5+5;

struct pnt {
    ll x, y;

    pnt(){ x = 0; y = 0; }
    pnt(ll x1, ll y1){ x = x1; y = y1; }
    ll operator*(pnt b){ return x*b.x + y*b.y; }
    ll operator^(pnt b){ return x*b.y - y*b.x; }
    pnt operator-(pnt b){ return pnt(x - b.x, y - b.y); }
    pnt operator+(pnt b){ return pnt(x + b.x, y + b.y); }
    const bool operator<(pnt b)const{ return x != b.x ? x < b.x : y < b.y; }
    double operator~(){ return hypot(x, y); }
};

pnt pnts[N];
pnt ogn;

bool cmp(pnt a, pnt b){
    ll cp = ((a-ogn)^(b-ogn));
    return cp ? cp > 0 : ~(a - ogn) < ~(b - ogn);
}

int main() {
    ll n;
    map<pnt, ll> ordem;
    cin >> n;
    cin >> pnts[0].x >> pnts[0].y;
    ogn = pnts[0];
    for(ll i = 1; i < n; i++)
        cin >> pnts[i].x >> pnts[i].y,
        ogn = min(ogn, pnts[i]),
        ordem[pnts[i]] = i;

    sort(pnts, pnts+n, cmp);

    vector<ll> ch;
    for(ll i = 0; i < n; i++) {
        ll n = ch.size();
        while((n = ch.size()) > 1 and
             ((pnts[i] - pnts[ch[n - 2]])^(pnts[ch[n - 1]] - pnts[ch[n - 2]])) >= 0)
            ch.pop_back();
        ch.push_back(i);
    }

    n = ch.size();

    cout << n << endl;
    for(auto i : ch) cout << ordem[pnts[i]] + 1 << ' ';
    cout << endl;

    ld per = 0;
    for(ll i = 1; i < ch.size(); i++)
        per += ~(pnts[ch[i]] - pnts[ch[i - 1]]); 
    per += ~(pnts[ch[n - 1]] - pnts[ch[0]]); 

    printf("%.12Lf\n", per);

    ll area = 0;
    for(ll i = 0; i < n; i++)
        area += pnts[ch[i]].x*pnts[ch[(i + 1)%n]].y - pnts[ch[i]].y*pnts[ch[(i + 1)%n]].x;

    if(area%2) cout << area/2 << ".5" << endl;
    else cout << area/2 << ".0" << endl;

    return 0;
}






