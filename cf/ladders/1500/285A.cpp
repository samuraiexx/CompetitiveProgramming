#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        if(i <= k) cout << n + 1 - i << ' ';
        else cout << i - k << ' ';
    }
    cout << endl;

    return 0;
}
