#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 

int main(){
  ll a, b;
  cin >> a >> b;
  while(a and b and max(a, b) >= 2*min(a, b)){
    if(a > b) a = a%(2*b);
    else b = b%(2*a);
  }

  cout << a << ' ' << b << endl;
}

