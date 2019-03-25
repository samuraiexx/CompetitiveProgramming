#include<bits/stdc++.h>
using namespace std;

struct screen{
    long long rh, rv, sh, sv;
    long long p;
};

const long long N = 1e3;

screen ss[N];

int main(){
    freopen("giant.in", "r", stdin);
    freopen("giant.out", "w", stdout);
    long long n;
    screen s;
    cin >> s.rh >> s.rv >> s.sh >> s.sv;
    cin >> n;
    for(long long i = 0; i < n; i++)
        cin >> ss[i].rh >> ss[i].rv >> ss[i].sh >> ss[i].sv >> ss[i].p;

    long long price = 0x3f3f3f3f;

    for(long long i = 0; i < n; i++){
        long long x1 = (s.sh + ss[i].sh - 1)/ss[i].sh;
        long long y1 = (s.sv + ss[i].sv - 1)/ss[i].sv;
        long long x2 = (s.rh + ss[i].rh - 1)/ss[i].rh;
        long long y2 = (s.rv + ss[i].rv - 1)/ss[i].rv;
        price = min(price, max(x1, x2)*max(y1, y2)*ss[i].p);
    }
    for(long long i = 0; i < n; i++){
        long long x1 = (s.sh + ss[i].sv - 1)/ss[i].sv;
        long long y1 = (s.sv + ss[i].sh - 1)/ss[i].sh;
        long long x2 = (s.rh + ss[i].rv - 1)/ss[i].rv;
        long long y2 = (s.rv + ss[i].rh - 1)/ss[i].rh;
        price = min(price, max(x1, x2)*max(y1, y2)*ss[i].p);
    }

    cout << price << endl;
    

}
