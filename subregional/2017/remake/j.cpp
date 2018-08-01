#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  string n;
  cin >> n;

  int ans = 0;
  for(auto c : n)
    ans = (ans + c - '0')%3;

  cout << ans << endl;
}
