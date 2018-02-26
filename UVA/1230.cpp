#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    int x, y, n;
    scanf("%d %d %d", &x, &y, &n);

    int exp = 1;
    while(y)
      if(y%2 == 1) exp = (exp*x)%n, y--;
      else exp = (exp*exp)%n, y /= 2;

    printf("%d\n", exp);
  }
}
