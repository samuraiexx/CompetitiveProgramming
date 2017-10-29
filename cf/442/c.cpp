#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << n*3/2 << endl;
    for(int i = 2; i <= n; i+= 2) cout << i << ' ';
    for(int i = 1; i <= n; i+= 2) cout << i << ' ';
    for(int i = 2; i <= n; i+= 2) cout << i << ' ';

    cout << endl;
    
    return 0;
}
