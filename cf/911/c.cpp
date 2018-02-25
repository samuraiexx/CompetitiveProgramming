#include<bits/stdc++.h>
using namespace std;
const int N = 3;
int v[N];

int main(){
    cin >> v[0] >> v[1] >> v[2];
    sort(v, v + 3);

    if(v[0] == 2 and v[1] == 4 and v[2] == 4)
        return cout << "YES" << endl, 0;
    if(v[0] == 1 or v[0] == 2 and v[1] == 2 or v[0] == 3 and v[2] == 3)
        return cout << "YES" << endl, 0;

    return cout << "NO" << endl, 0;
}
