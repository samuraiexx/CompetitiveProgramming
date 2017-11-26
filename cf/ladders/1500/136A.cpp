#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;
int v[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1, p; i <= n; i++)
        cin >> p, v[p] = i;

    for(int i = 1, p; i <= n; i++)
        cout << v[i] << ' ';
    cout << endl;

    return 0;
}
