#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " <<
typedef long long ll;
const ll N = 1e5 + 5;
ll v[N];
ll dp[N];

struct min_queue{
  ll plus = 0;
  deque<pair<ll, ll>> dq;

  bool empty() { return dq.size() == 0; }
  void clear() { plus = 0; dq.clear(); }
  void add(ll x){ plus += x; } // Adds x to every element in the queue
  ll min(){ return dq.begin()->first + plus; } // Returns the maximum element in the queue

  void push(ll x){
    ll amt = 0;
    while(dq.size() and dq.back().first >= x)
      amt += dq.back().second + 1, dq.pop_back();
    dq.push_back({ x - plus, amt});
  }

  void pop(){
    if(!dq.size()) return;
    if(!dq.front().second) dq.pop_front();
    else dq.front().second--;
  }
}mq;

int main(){
  ll n, c, sum = 0;
  cin >> n >> c;
  for(ll i = 0; i < n; i++) cin >> v[i], sum += v[i];

  if(n < c) return cout << sum << endl, 0;
  for(ll i = 0; i < c; i++) mq.push(v[i]);
  dp[c - 1] = mq.min();

  for(ll i = c; i < n; i++){
    mq.pop();
    mq.push(v[i]);
    dp[i] = max(mq.min() + dp[i - c], dp[i - 1]);
  }

  cout << sum - dp[n - 1] << endl;
}
