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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e6+5;

int sieve[N], k;
int main() {
    scanf("%d", &k);
    for(ll i=2; i*i < N; i++) if(!sieve[i]){
        for(ll j=2*i; j < N; j+=i) sieve[j] = 1;
    }

    int cnt = 0;
    for(int i=2; i<N; i++) {
        if(!sieve[i]) cnt++;
        if(cnt == k) return printf("%d\n", i), 0;
    }

    return 0;
}
