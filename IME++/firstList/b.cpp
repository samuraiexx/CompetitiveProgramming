#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  while(cin >> n, n){
    int a = 0, b = 0;
    for(int i = 0, x, y; i < n; i++){
      cin >> x >> y;
      if(x > y) a++;
      else if( y > x) b++;
    }
    cout << a << ' ' << b << endl;
  }
}
