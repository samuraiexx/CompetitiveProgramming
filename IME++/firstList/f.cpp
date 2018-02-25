#include<bits/stdc++.h>
using namespace std;
int fib[47];

int main(){
  fib[1] = 1;
  for(int i = 2; i < 47; i++) fib[i] = fib[i - 1] + fib[i - 2];
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cout << fib[i] << " \n"[i == n -1];
}
