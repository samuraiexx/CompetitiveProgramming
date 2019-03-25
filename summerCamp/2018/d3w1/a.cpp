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

int main() {
    map<string, int> m;
    vector<string> ans;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string uni, team;
        int lim = 2;
        cin >> uni >> team;
        if(uni == "SCH") continue;
        if(uni == "MSU") lim = 4;
        if(m[uni] < lim) m[uni]++, ans.push_back(uni + ' ' + team);
        if(ans.size() == 10) break;
    }

    cout << ans.size() << endl;
    for(auto s : ans) cout << s << endl;
}
