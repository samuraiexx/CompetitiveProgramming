#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n%4 == 0){
        cout << 0 << endl << n/2 << ' ';
        for(int i = 1; i <= n/2; i+= 2) printf("%d %d ", i, n - i + 1);
        cout << endl;
    }
    else if(n%4 == 1){
        cout << 1 << endl << n/2 << ' ';
        for(int i = 2; i <= n/2; i+= 2) printf("%d %d ", i, n - i + 2);
        cout << endl;
    }
    else if(n%4 == 2){
        cout << 1 << endl << n/2 << ' ';
        for(int i = 1; i < n/2; i+= 2) printf("%d %d ", i, n - i + 1);
        cout << n/2 << endl;
    }
    else if(n%4 == 3){
        cout << 0 << endl << n/2 + 1 << ' ' << 1 << ' ' << n/2 + 1 << ' ';
        for(int i = 2; i <= n/2; i+= 2) printf("%d %d ", i, n - i + 2);
        cout << endl;
    }
}
