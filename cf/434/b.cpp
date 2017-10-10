#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    int mx = 100, mn = 1;
    cin >> n >> m;
    n--;
    for(int i = 0; i < m; i++)
    {
        int k, f;
        cin >> k >> f;
        k--;
        for(int i = mn; i <= mx; i++)
            if(k/i + 1 > f) mn = max(mn, i + 1);
            else if(k/i + 1 < f){ mx = min(mx, i - 1); break;}
    }
    int ans = n/mn + 1;
    for(int i = mn; i <= mx; i++)
        if(ans != n/i + 1) return cout << -1 << endl, 0;
    cout << ans << endl;
    return 0;
}
