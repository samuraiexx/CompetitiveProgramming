#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
using namespace std;

typedef long long ll;

const int N = 2e5+1, SQ = 450;

int v[N];
ll amt[(int)1e6 + 5];
ll ans;

void add(ll p) { 
  amt[p]++;
  ans = ans + (amt[p]*amt[p] - (amt[p] - 1)*(amt[p] - 1))*p;
}

void rem(ll p) { 
  amt[p]--;
  ans = ans + (amt[p]*amt[p] - (amt[p] + 1)*(amt[p] + 1))*p;
}

struct query { ll i, l, r, ans; } qs[N];

bool c1(query a, query b) { 
  int b1 = a.l/SQ;
  int b2 = b.l/SQ;
  if(b1 != b2) return a.l < b.l;
  return b1&1 ? a.r > b.r : a.r < b.r;
}
bool c2(query a, query b) { return a.i < b.i; }

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; i++)
    cin >> v[i];

  for(int i = 0; i < q; i++){
    cin >> qs[i].l >> qs[i].r;
    qs[i].l--, qs[i].r--;
    qs[i].i = i; 
  }

  sort(qs, qs+q, c1);

  int l = 0, r = -1;
  for (int i = 0; i < q; ++i) {
    query &q = qs[i];
    while (r < q.r) add(v[++r]);
    while (l > q.l) add(v[--l]);
    while (r > q.r) rem(v[r--]);
    while (l < q.l) rem(v[l++]);

    q.ans = ans;
  }

  sort(qs, qs + q, c2);
  for(int i = 0; i < q; i++)
    cout << qs[i].ans << '\n';
}
