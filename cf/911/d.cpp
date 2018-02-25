#include<bits/stdc++.h>
using namespace std;
const int N = 1500;
int v[N];

int main(){
    int n, m;
    bool odd = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            if(v[i] > v[j]) odd = !odd;
    cin >> m;
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        long long n = r - l + 1;
        n = n*(n - 1)/2;
        if(n&1) odd = !odd;
        if(odd) cout << "odd" << endl;
        else cout << "even" << endl;
    }
}
