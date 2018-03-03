#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
#define pb push_back
#define st first
#define nd second

const int N = 105;

int nxt[N][10];

string s;
vector<int> v;

bool verify(){
  int i = 0;
  for(auto x : v){
    i = nxt[i][x];
    if(i == -1) return false;
  }
  return true;
}

int main(){
  cin >> s;
  int ans = 0;

  vector<int> nxtv(10, -1);

  for(int i = s.size(); i >= 0; i--){
    for(int j = 0; j < 10; j++)
      nxt[i][j] = nxtv[j];
    if(i) nxtv[s[i - 1] - '0'] = i;
  }

  for(int i = 0; i < 10; i++)
    v.pb(i);

  ans += verify();
  while(next_permutation(v.begin(), v.end())) ans += verify();

  cout << ans << endl;
}
