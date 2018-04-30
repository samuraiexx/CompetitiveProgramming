#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 2e5 + 5;
ll v[N]; // vetor com os valores em cada posicao do array
ll freq[N]; // vetor com a frequencia de acesso da posição

int main(){
  ll n, q;
  cin >> n >> q;
  for(ll i = 1; i <= n; i++)
    cin >> v[i];
  for(ll i = 0; i < q; i++){
    ll l, r;
    cin >> l >> r;
    freq[l]++, freq[r + 1]--;
  }
  for(ll i = 1; i <= n; i++)
    freq[i] += freq[i - 1];


  sort(freq + 1, freq + n + 1);
  sort(v + 1, v + n + 1);

  ll ans = 0;
  for(ll i = 1; i <= n; i++)
    ans += freq[i]*v[i];

  cout << ans << endl;
}
