#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e6 + 5;
ll n, p, d;
ll w[N];
ll ps[N];

struct max_queue{
  ll plus = 0;
  deque<pair<ll, ll>> dq;

  bool empty() { return dq.size() == 0; }
  void clear() { plus = 0; dq.clear(); }
  void add(ll x){ plus += x; }
  ll max(){ return dq.begin()->first + plus; }

  void push(ll x){
    ll amt = 0;
    while(dq.size() and dq.back().first <= x)
      amt += dq.back().second + 1, dq.pop_back();
    dq.push_back({ x - plus, amt});
  }

  void pop(){
    if(!dq.size()) return;
    if(!dq.front().second) dq.pop_front();
    else dq.front().second--;
  }
} mq;

bool bs(ll m){
  mq.clear();
  mq.push(ps[d - 1]);

  for(ll i = 0; i < m; i++) 
    mq.push(ps[d + i] - ps[i]);

  if(ps[d + m - 1] - mq.max() <= p) return true;
  for(ll i = m; i < n - d; i++){
    mq.pop(), mq.push(ps[d + i] - ps[i]);
    if(ps[d + i] - ps[i - m] - mq.max() <= p) return true;
  }
  return false;
}

int main(){
  cin >> n >> p >> d;
  cin >> w[0], ps[0] = w[0];
  for(ll i = 1; i < n; i++)
    cin >> w[i], ps[i] = ps[i - 1] + w[i];

  ll l = 0, r = n - d;
  while(l != r){
    ll mid = (l+r + 1)/2;
    if(bs(mid)) l = mid;
    else r = mid - 1;
  }

  cout << d + l << endl;

}
