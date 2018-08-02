#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
typedef long double ld;
const int N = 1 << 20;
const ld PI = acos(-1);
int v[N];

struct T {
  ld x, y;
  T() : x(0), y(0) {}
  T(ld a, ld b=0) : x(a), y(b) {}

  T operator/=(ld k) { x/=k; y/=k; return (*this); }
  T operator*(T a) const { return T(x*a.x - y*a.y, x*a.y + y*a.x); }
  T operator+(T a) const { return T(x+a.x, y+a.y); }
  T operator-(T a) const { return T(x-a.x, y-a.y); }
} a[N], b[N];

void fft(T* a, int n, int s) {
  for (int i=0, j=0; i<n; i++) {
    if (i>j) swap(a[i], a[j]);
    for (int l=n/2; (j^=l) < l; l>>=1);
  }

  for(int i = 1; (1<<i) <= n; i++){
    int M = 1 << i;
    int K = M >> 1;
    T wn = T(cos(s*2*PI/M), sin(s*2*PI/M));
    for(int j = 0; j < n; j += M) {
      T w = T(1, 0);
      for(int l = j; l < K + j; ++l){
        T t = w*a[l + K];
        a[l + K] = a[l]-t;
        a[l] = a[l] + t;
        w = wn*w;
      }
    }
  }
}

// assert n is a power of two greater of equal product size
// n = na + nb; while (n&(n-1)) n++;
void multiply(T* a, T* b, int n) {
  fft(a,n,1);
  fft(b,n,1);
  for (int i = 0; i < n; i++) a[i] = a[i]*b[i];
  fft(a,n,-1);
  for (int i = 0; i < n; i++) a[i] /= n;
}


int main(){
  int n, x;
  cin >> n >> x;
  for(int i = 1; i <= n; i++){
    int a;
    cin >> a;
    v[i] = v[i - 1] + (a < x);
  }

  int th = v[n];
  for(int i = 1; i <= n; i++){
    a[v[i]].x++;
    b[th - v[i]].x++;
  }
  b[th].x++;

  int pot = 2*th + 1;
  while(pot&(pot - 1)) pot++;
  multiply(a, b, pot);

  ll ans = 0;
  for(ll i = 0; i <= n;){
    ll j;
    for(j = i; j <= n && v[j] == v[i]; j++);
    ans += (j - i - 1)*(j - i - 2)/2 + (j - i - 1);
    i = j;
  }

  cout << ans << ' ';
  for(int i = 1; i <= n; i++)
    cout << (ll)(a[th + i].x + 0.5) << ' ';
  cout << endl;
}
