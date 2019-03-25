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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e5+5;

int n;

void print(int x, int f, string s) {
    for(int i = min(x, f); i; i--) {
        string s2 = s + to_string(i);
        int k = x-i;
        if(k) {
            s2.push_back('+');
            print(k, i, s2);
        }
        else {
            printf("%s\n", s2.c_str());
        }
    }
}

int main() {
    scanf("%d", &n);
    string s;
    print(n, n, s);
    return 0;
}
