#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;

int v[N];

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main(){
    int m;
    set<int> div;
    cin >> m;
    for(int i = 0; i < m; i++) cin >> v[i], div.insert(v[i]);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            if(!div.count(gcd(v[i], v[j]))) return cout << -1 << endl, 0;

    cout << m << endl;
    for(int i = 0; i < m; i++) cout << v[i] << ' ';
    cout << endl;
    return 0;
}
