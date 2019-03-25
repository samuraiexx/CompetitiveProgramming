#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
#define mp make_pair
typedef long long ll;
const int N = 1e6 + 5;
pair<int, int> v[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> v[i].st;

  sort(v, v + n);

  int ans = 0;
  for(int i = 0; i < n;){
    if(v[i].nd < 0) i = lower_bound(v, v + n, mp(v[i].st, 0)) - v;

    int pos = upper_bound(v, v + n, v[i]) - v;
    int amt = pos - i;
    ans += amt/3;
    amt = amt%3;
    int x = v[i].st;

    for(int i = 0; i < amt; i++){
      int p1 = lower_bound(v, v + n, mp(x + 1, 0)) - v;
      int p2 = lower_bound(v, v + n, mp(x + 2, 0)) - v;
      if(p1 < n and p2 < n and v[p1].st == x + 1 and v[p2].st == x + 2){
        v[p1].nd = -1;
        v[p2].nd = -1;
        ans++;
      } else break;
    }
    i = lower_bound(v, v + n, mp(v[i].st + 1, 0)) - v;
  }

  int tans = ans;
  ans = 0;

  for(int i = 0; i < n; i++)
    v[i].st = m - v[i].st, v[i].nd = 0;
  sort(v, v + n);

  for(int i = 0; i < n;){
    db(v[i].st _ ans);
    if(v[i].nd < 0) i = lower_bound(v, v + n, mp(v[i].st, 0)) - v;

    int pos = upper_bound(v, v + n, v[i]) - v;
    int amt = pos - i;
    ans += amt/3;
    amt = amt%3;
    int x = v[i].st;

    for(int i = 0; i < amt; i++){
      int p1 = lower_bound(v, v + n, mp(x + 1, 0)) - v;
      int p2 = lower_bound(v, v + n, mp(x + 2, 0)) - v;
      if(p1 < n and p2 < n and v[p1].st == x + 1 and v[p2].st == x + 2){
        v[p1].nd = -1;
        v[p2].nd = -1;
        ans++;
      } else break;
    }
    i = lower_bound(v, v + n, mp(v[i].st + 1, 0)) - v;
  }

  cout << max(tans, ans) << endl;
}
