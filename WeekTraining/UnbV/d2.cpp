#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n;
int num[N];
int pf;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){ cin >> num[i]; if(i < n/2) pf += num[i]; }
    
    int mx = pf, p = 0;
    for(int i = 0; i <= n/2; i++) {
        if(pf > mx) mx = pf, p = i;
        pf -= num[n/2 - 1 - i], pf += num[n - 1 - i];
    }

    cout << mx << endl;
    for(int i = 0; i < n/2; i++) if(i < p) printf("%c", 'R'); else printf("%c", 'L');
    cout << endl;

    
}
