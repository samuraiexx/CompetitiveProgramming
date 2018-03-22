#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int main(){
    char c = ',';
    int cnt = 0;
    int sum = 0;
    while(c == ','){
      int x = 0;
      while(cin >> c and c != ',') x *= 10, x += c - '0';
      cnt++;
      sum += x;
    }
    cout << (int)(sum/(double)cnt + 0.5) << endl;
    return 0;
}
