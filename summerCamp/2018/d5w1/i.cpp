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


char type[N], s[N];

int main() {
    freopen("isharp.in", "r", stdin);
    freopen("isharp.out", "w", stdout);

    scanf("%s", type);
    while(~scanf("%s", s)) {
        printf("%s", type);
        int n = strlen(s);

        s[n-1] = 0;
        for(int i=n-2; i>=0; i--) {
            if(s[i] == '&' or s[i] == '*') {
                printf("%c", s[i]);
            }
            else if(s[i] == ']') {
                printf("[]");
                i--;
            }
            else break;
            s[i] = 0;
        }

        printf(" %s;\n", s);
    }
    return 0;
}
