#include<bits/stdc++.h>
using namespace std;

int abs(int x){ return x > 0 ? x : -x; }

int main(){
    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    int ans = 0x3f3f3f3f;
    
    if(l == 1)
        if(r == n)
            return cout << 0 << endl, 0;
        else
            return cout << abs(pos - r) + 1 << endl, 0;
    else
        if(r == n)
            return cout << abs(pos - l) + 1 << endl, 0;

    if(abs(pos - l) < abs(pos - r))
        return cout << abs(pos - l) + 2 + r - l << endl, 0;
    else return cout << abs(pos - r) + 2 + r - l << endl, 0;
}
