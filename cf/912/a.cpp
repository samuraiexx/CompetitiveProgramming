#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll zero = 0;
    ll a, b;
    ll x, y, z;
    cin >> a >> b;
    cin >> x >> y >> z;
    a -= x*2;
    a -= y, b -= y;
    b -= 3*z;
    a = min(a, zero);
    b = min(b, zero);
    cout << -(a + b) << endl;
}
