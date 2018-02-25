#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int arr[N];

int main(){
    int n;
    int mn = INF;
    int x = INF;
    int p = -INF;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i], mn = min(mn, arr[i]);
    for(int i = 0; i < n; i++) if(arr[i] == mn)
        x = min(x, i - p), p = i;

    cout << x << endl;
}
