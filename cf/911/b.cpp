#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, n;
    int mx = 0;
    cin >> n >> a >> b;
    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= b; j++)
            if(i + j == n)
                mx = max(mx, min(a/i, b/j));

    cout << mx << endl;
}
