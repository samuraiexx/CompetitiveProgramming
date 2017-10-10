#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int i;
    cin >> n;
    for(i = 1; i*i < n; i++);
    int j = i - 1;
    if(n - j*j <= j) cout << 4*j + 2 << endl;
    else cout << 4*i << endl;
    return 0;
}
