#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, mx = 0;
    cin >> k;
    for(int i = 0, r; i < k; i++)   
        cin >> r, mx = max(mx, r);
    cout << max(mx - 25, 0) << endl;
    return 0;
}
