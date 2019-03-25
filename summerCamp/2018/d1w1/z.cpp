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

vector<string> ans;

void foo(int n, string s){
    if(n == 0){
        bool ok = 1;
        int cnt = 0;
        for(auto c : s) {
            if(c == ')') cnt--;
            else cnt++;
            if(cnt < 0){ ok = 0; break;}
        }
        if(cnt == 0 and ok) ans.push_back(s);
    }
    else {
        foo(n - 1, s + ')');
        foo(n - 1, s + '(');
    }
}

int main() {
    int n;
    cin >> n;
    foo(2*n, string());

    sort(ans.begin(), ans.end());
    for(auto s : ans) cout << s << endl;
    return 0;
}
