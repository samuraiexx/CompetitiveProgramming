#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;

  cout << min({2*(a1 + a3), 2*a2 + 4*a3, 2*a2 + 4*a1}) << endl;
}
