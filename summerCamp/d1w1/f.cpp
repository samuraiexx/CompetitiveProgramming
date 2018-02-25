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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 50;

int fib[N];
int ps[N];

string foo(int n, int k){
    if(n == 0) return "";
    int z = lower_bound(&ps[0], &ps[N - 1], k) - &ps[0];
    string ans;
    cout << ' ' << n << ' ' << k << ' ' << z << endl;
    for(int i = n; i > z; i--)
        ans = ans + '0';
    if(k == 0) return ans;
    ans = ans + '1' + foo(n - z, k - ps[z]);
    cout << ans;
    return ans;
}

int main() {
    fib[1] = 1;
    ps[1] = 1;
    for(int i = 2; i < N; i++) fib[i] = fib[i - 1] + fib[i - 2],
                               ps[i] = ps[i - 1] + fib[i];

    int n, k;
    cin >> n >> k;

    cout << foo(n, k) << endl;
    return 0;
}
