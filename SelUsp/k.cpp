#include <iostream>

using namespace std;

int main(){
    int k;
    cin >> k;
    if(k == 0)
        return cout << 1 << endl, 0;
    cout << ((1 << k) - 1) << endl;
    return 0;
}
