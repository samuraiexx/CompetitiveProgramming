#include<bits/stdc++.h>
using namespace std;

int main(){
  int sum;
  while(cin >> sum){
    while(sum >= 10){
      int tmp = sum;
      sum = 0;
      while(tmp) sum += tmp%10, tmp /= 10;
    }

    cout << sum << endl;
  }
  return 0;
}
