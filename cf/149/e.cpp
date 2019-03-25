#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
const int M = 20;

vector<int> suffix_array(string &s){
  int n = s.size(), alph = 256;
  vector<int> cnt(max(n, alph)), p(n), c(n);

  for(auto c : s) cnt[c]++;
  for(int i = 1; i < alph; i++) cnt[i] += cnt[i - 1];
  for(int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
  for(int i = 1; i < n; i++) 
    c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);

  vector<int> c2(n), p2(n);

  for(int k = 0; (1 << k) < n; k++){
    int classes = c[p[n - 1]] + 1;
    fill(cnt.begin(), cnt.begin() + classes, 0);

    for(int i = 0; i < n; i++) p2[i] = (p[i] - (1 << k) + n)%n;
    for(int i = 0; i < n; i++) cnt[c[i]]++;
    for(int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
    for(int i = n - 1; i >= 0; i--) p[--cnt[c[p2[i]]]] = p2[i];

    c2[p[0]] = 0;
    for(int i = 1; i < n; i++){
      pair<int, int> b1 = {c[p[i]], c[(p[i] + (1 << k))%n]};
      pair<int, int> b2 = {c[p[i - 1]], c[(p[i - 1] + (1 << k))%n]};
      c2[p[i]] = c2[p[i - 1]] + (b1 != b2);
    }

    c.swap(c2);
  }
  return p;
}

vector<int> lcp(string &s, vector<int> &p){
  int n = s.size();
  vector<int> ans(n - 1), pi(n);
  for(int i = 0; i < n; i++) pi[p[i]] = i;

  int lst = 0;
  for(int i = 0; i < n - 1; i++){
    while(s[i + lst] == s[p[pi[i] + 1] + lst]) lst++;

    ans[pi[i]] = lst;
    lst = max(0, lst - 1);
  }

  return ans;
}

int st[N][M];
int str[N][M];

void build(vector<int> &v, int sparse[N][M]){
  int n = v.size();
  for(int i = 0; i < n; i++)
    sparse[i][0] = v[i];

  for(int j = 1; j < M; j++)
    for(int i = 0; i < n; i++)
      sparse[i][j] =
        i + (1 << j - 1) < n
        ? min(sparse[i][j - 1], sparse[i + (1 << j - 1)][j - 1])
        : sparse[i][j - 1];
}

int query(int a, int b, int sparse[N][M]){
  if(a == b) return sparse[a][0];
  int pot = 32 - __builtin_clz(b - a) - 1;
  return min(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

vector<int> calc(int &lo, int &hi, string &s, vector<int> &sa, string &p, int sparse[N][M], bool z){
  vector<int> ans;
  if(z) ans.pb(0);

  for(int k = 0; k < p.size(); k++){
    int n = s.size();
    int i = lo, j = hi;
    while(i != j){
      int mid = (i + j)/2;
      if(s[(sa[mid] + k)%n] >= p[k]) j = mid;
      else i = mid + 1;
    }
    lo = i;
    j = hi;

    while(i != j){
      int mid = (i + j)/2;
      if(s[(sa[mid] + k)%n] > p[k]) j = mid;
      else i = mid + 1;
    }
    hi = i;
    if(hi <= lo) break;
    ans.pb(query(lo, hi - 1, sparse));
  }
  while(ans.size() < p.size()) ans.pb(-1);
  return ans;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  string s;
  int n, m;
  cin >> s >> m;
  n = s.size();

  string sr(s);
  reverse(sr.begin(), sr.end());
  s.pb('$');
  sr.pb('$');

  auto sa = suffix_array(s);
  auto sar = suffix_array(sr);
  build(sa, st), build(sar, str);

  int ans = 0;
  while(m--){
    string p;
    cin >> p;
    if(p.size() == 1) continue;

    int lo = 0, hi = sa.size();
    auto v = calc(lo, hi, s, sa, p, st, false);

    reverse(p.begin(), p.end());
    lo = 0, hi = sar.size();
    vector<int> vr = calc(lo, hi, sr, sar, p, str, true);

    for(int i = 0; i < v.size(); i++){
      if(v[i] == -1) break;
      int j = n - (v[i] + p.size());
      int sz = p.size() - i - 1;
      if(vr[sz] != -1 and vr[sz] <= j){ ans++; break; }
    }
  }

  cout << ans << endl;
}
