#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 4e4 + 5;
int b[N];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> b[i];
  b[n] = 0x3f3f3f3f;

  int ans = 0;

  deque<int> q;
  int open = 0;
  int topen = 0;
  for(int i = 0; i < n; i++){
    if(open){
      //db(open _ topen _ b[i]);
      if(open + 120 >= b[i]) open = max(open, b[i]) + 20;
      else ans += open - topen, open = 0, topen = 0;
    }
    if(!open) q.push_back(b[i]);

    if(q.size() and q.front() + 30*60 < b[i + 1])
      topen = q.front() + 30*60, open = topen, ans += 120;

    if(open) while(q.size()) open += 20, q.pop_front();
    //db(topen _ open);
  }

  ans += open - topen;

  cout << ans << endl;
}
