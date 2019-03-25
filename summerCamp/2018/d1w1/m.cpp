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

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e5 + 5;

int gcd(int a, int b){ return b ? gcd(b, a%b) : a; }

int main() {
    int s1, s2;
    set<int> sqr;

    for(int i = 1; i < N; i++)
        sqr.insert(i*i);

    int xi, xf, yi, yf;
    cin >> xi >> yi >> xf >> yf;
    s1 = (xi - xf)*(xi - xf) + (yi - yf)*(yi - yf);
    cin >> xi >> yi >> xf >> yf;
    s2 = (xi - xf)*(xi - xf) + (yi - yf)*(yi - yf);

    int s = gcd(s1, s2);

    if(!sqr.count(s1/s) or !sqr.count(s2/s))
        return cout << "NO" << endl, 0;

    cout << "YES" << endl;
    printf("%lf\n", sqrt(s));
}












