#include<bits/stdc++.h>
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
 
using namespace std;
const int N = 1e6 + 5;;
const int SQ = 175;
int has[N];
int v[N];
int ans[N];
int cnt;
 
int l = 0, r = -1;
 
struct query{
  int l, r, i;
} qry[N];
 
void add(int i){
  if(!has[i]) cnt++;
  has[i]++;
}
 
void rem(int i){
  if(has[i] == 1) cnt--;
  has[i]--;
}
 
struct cmp{
  bool operator()(query a, query b){
    return a.l/SQ == b.l/SQ ? a.r < b.r : a.l < b.l;
  }
};
 
int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n, q;
  cin >> n;
 
  for(int i= 0; i < n; i++)
    cin >> v[i];
 
  cin >> q;
 
  for(int i = 0; i < q; i++){
    cin >> qry[i].l >> qry[i].r;
    qry[i].l--, qry[i].r--;
    qry[i].i = i;
  }
  
  sort(qry, qry + q, cmp());
  for(int i = 0; i < q; i++){
    while (r < qry[i].r) add(v[++r]);
    while (r > qry[i].r) rem(v[r--]);
    while (l < qry[i].l) rem(v[l++]);
    while (l > qry[i].l) add(v[--l]);
 
    ans[qry[i].i] = cnt;
  }
 
  for(int i = 0; i < q; i++)
    cout << ans[i] << '\n';
}
