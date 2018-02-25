#include<bits/stdc++.h>
using namespace std;
int seg[101];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            for(int k = i; k <= j; k++)
                seg[k]++;

    int mx = 0;
    for(int i = 1; i <= n; i++)
        mx = max(mx, seg[i]);

    cout << mx + 1 << endl;
}
