#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int main(){
    int n;
    cin >> n;

    cout << n << endl;
    for(int i = 0; i <= n; i++) if(i%2) cout << 1 << ' ';
                                else cout << -1 << ' ';
    
    cout << endl << n - 1 << endl;
    for(int i = 1; i < n; i++) cout << 0 << ' ';
    cout << 1 << endl;
}
