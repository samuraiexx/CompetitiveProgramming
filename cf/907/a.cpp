#include<bits/stdc++.h>
using namespace std;

int main(){
    int v1, v2, v3, vm;
    cin >> v3 >> v2 >> v1 >> vm;
    int c11, c12, c21, c22, c31, c32;
    c11 = max(vm, v1);
    c12 = min(2*vm, 2*v1);
    c21 = max(2*vm + 1, v2);
    c22 = 2*v2;
    c31 = max(2*vm + 1, v3);
    c32 = 2*v3;
    int c1 = c11, c2 = max(c1 + 1, c21), c3 = max(c2 + 1, c31);
    if(c1 > c12 or c2 > c22 or c3 > c32) return cout << -1 << endl, 0;
    cout << c3 << endl << c2 << endl << c1 << endl;
}

