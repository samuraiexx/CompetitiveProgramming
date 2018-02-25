#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl;
#define _ << ", " <<;

int main(){
  int n, ans = 0;
  string s;
  bool w;
  pair<int, int> p;
  cin >> n >> s;
  if(s[0] == 'U') w = 1;
  else w = 0;
  for(auto c : s){
    if(c == 'U') p.nd++;
    if(c == 'R') p.st++;

    if(p.st > p.nd and w == 1) w = 0, ans++;
    else if(p.st < p.nd and w == 0) w = 1, ans++;
  }
  cout << ans << endl;
}
