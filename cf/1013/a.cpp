#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int n;
  cin >> n;

  ll sum1 = 0, sum2 = 0;
  for(int i = 0, a; i < n; i++)
    cin >> a, sum1 += a;
  for(int i = 0, a; i < n; i++)
    cin >> a, sum2 += a;

  if(sum1 >= sum2) cout << "Yes" << endl;
  else cout << "No" << endl;
}
