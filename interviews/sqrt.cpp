#include<bits/stdc++.h>
using namespace std;

int sqrt2(int A) {
  long long i = 0, j = (long long)A + 1;
  while(i != j){
    long long mid = (i + j)/2;
    //cout << mid << endl;
    if(mid < 0) break;
    if(mid > A/mid) j = mid;
    else i = mid + 1;
  }
  return i - 1;
}


int main(){
  cout << sqrt2(400) << endl;
  cout << sqrt2(401) << endl;
  cout << sqrt2(123) << endl;
  cout << sqrt2(2147483647) << endl;
}
