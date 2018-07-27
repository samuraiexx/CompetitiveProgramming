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
  map<string, int> balls, pnts;
  pnts["red"] = 1, pnts["yellow"] = 2, pnts["green"] = 3, pnts["brown"] = 4;
  pnts["blue"] = 5, pnts["pink"] = 6, pnts["black"] = 7;

  int mx = 0;
  int tt = 0;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    balls[s]++;
    mx = max(pnts[s], mx);
    tt += pnts[s];
  }

  tt -= balls["red"];
  if(balls.size() == 1) cout << 1 << endl;
  else cout << (1 + mx)*balls["red"] + tt << endl;
}
