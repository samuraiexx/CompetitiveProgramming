#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e9 + 1;
const ll M = 1e5 + 5;
ll num[M];
ll ord[M];

int main(){
    ll n, x, k, ans = 0;
    cin >> n >> x >> k;
    for(ll i = 1; i <= n; i++)
        cin >> num[i], ord[i] = num[i];

    sort(&ord[1], &ord[n]);

for(ll i = 1; i <= n; i++){
        ll a = (num[i] + x - 1)/x*x + (k - 1)*x - 1;
        ll b = (num[i] + x - 1)/x*x + k*x - 1;
        if(k == 0) a = num[i] - 1;
        ans += upper_bound(&ord[1], &ord[n + 1], b) -
               upper_bound(&ord[1], &ord[n + 1], a);
    }
    cout << ans << endl;
    return 0;
}
