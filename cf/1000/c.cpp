#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 5e5 + 5;

pair<ll, bool> seg[N];
ll ans[N];

int main(){
  int n;
  cin >> n;
  n = 2*n;

  for(int i = 0; i < n; i+=2){
    cin >> seg[i].st >> seg[i + 1].st;
    seg[i].nd = false;
    seg[i + 1].nd = true;
  }

  sort(seg, seg + n);

  int cnt = 0;
  ll prev = 0;

  for(int i = 0; i < n; i++){
    ans[cnt] += seg[i].st - prev - 1;
    prev = seg[i].st;

    if(seg[i].nd == false) cnt++;


    while(i < n - 1 and seg[i].st == seg[i + 1].st and seg[i + 1].nd == false)
      cnt++, i++;

    ans[cnt]++;

    if(seg[i].nd == true) cnt--;

    while(i < n - 1 and seg[i].st == seg[i + 1].st)
      cnt--, i++;

  }

  for(int i = 1; i <= n/2; i++)
    cout << ans[i] << " \n"[i == n/2];
}
