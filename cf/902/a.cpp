#include<bits/stdc++.h>
using namespace std;
const int N = 200;
int r;


int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        if(a > r) return cout << "NO" << endl, 0;
        r = max(r, b);
        if(b >= m) return cout << "YES" << endl, 0;
    }

    return cout << "NO" << endl, 0;
}
