#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    int ans = -1;
    cin >> n >> k;
    for(int i = 0, a; i < n; i++){
        cin >> a;
        if(k%a == 0) ans = max(ans, a);
    }
    cout << k/ans << endl;
}
