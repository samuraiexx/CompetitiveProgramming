#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, p;
  cin >> n >> p;

  n = n%6;
  for(int j = n; j > 0; j--)
    if(j%2){
      if(p == 0) p = 1;
      else if(p == 1) p = 0;
    }else{
      if(p == 1) p = 2;
      else if(p == 2) p = 1;
    }
  cout << p << endl;
}
