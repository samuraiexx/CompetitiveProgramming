#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m, r, k;
    double ans = 0;
    cin >> n >> m >> r >> k;
    ll mps = (m - 2*r + 2)*(n - 2*r + 2);
    mps = max(mps, 0ll);
    if(k < mps)
        ans = k*r*r/(double)((n - r + 1)*(m - r + 1));
    else{
        ans = mps*r*r;
        k -= mps;
        cout << k << endl;
        for(int i = 1; k; i++){
            ll amt = 2*(m + n - 4*r + 4);
            if(k <= amt){ ans += k*(r - i)*r; k = 0; break; }
            k -= amt;
            for(int j = 1; j < i and k; j++)
                if(k <= 8) ans += k*(r - i)*(r - j), k = 0;
                else ans += 8*(r - i)*(r - j), k -= 8;
            if(k <= 4) ans += k*(r - i)*(r - i), k = 0;
            ans += 4*(r - i)*(r - i), k -= 4;
        }
        ans /= (n - r + 1)*(m - r + 1);
    }
    cout << ans << endl;
    return 0;
}
