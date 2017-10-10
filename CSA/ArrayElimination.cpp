#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int arr[N];

int bit[N];

void update(int a)
{
    for(int i = a; i <= n; i += i&-i) bit[i]++;
}

int query(int a, int b)
{
    int ans = 0;
    a--;
    for(int i = a; i <= n; i -= i&-i) ans -= bit[i];
    for(int i = b; i <= n; i -= i&-i) ans += bit[i];
}

int main(){
    cin >> n;
    map<int, set<int>> dn;
    pair<pair<int, int>, pair<int, int>> dp;
    for(int i = 1; i <= n; i++) cin >> arr[i], dn[arr[i]].insert(i);
    dp = {{0x3f3f3f3f, 0}, {dn.begin()->second.back()}};
    dn.erase(map.begin());
    for(auto k : dn)
    {
        set<int> &a = k.second;
        pair<int, int> st;
        if(dp.first == -1)
            

    }
}
