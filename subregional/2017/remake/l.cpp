#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
typedef long long ll;
typedef long double ld;
const int N = 1e7;
const ld EPS = 1e-12;
const ld PI = acos(-1);

struct T {
  ld x, y;
  T(ld a = 0, ld b=0) : x(a), y(b) {}

  T operator/=(ld k) { x/=k; y/=k; return (*this); }
  T operator*(T a) const { return T(x*a.x - y*a.y, x*a.y + y*a.x); }
  T operator+(T a) const { return T(x+a.x, y+a.y); }
  T operator-(T a) const { return T(x-a.x, y-a.y); }
  ld operator!(){ return x*x + y*y; }
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

void multiply(T* a, T* b, int n) {
  fft(a,n,1);
  fft(b,n,1);
  for (int i = 0; i < n; i++) a[i] = a[i]*b[i];
  fft(a,n,-1);
  for (int i = 0; i < n; i++) a[i] /= n;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  int n = s.size();

  int sum = 0;
  for(int i = 0; i < n; i++)
    sum += s[i] - 'a' + 1;

  int th = sum;

  sum = 0;
  for(int i = 0; i < n; i++){
    sum += s[i] - 'a' + 1;
    a[sum] = 1;
    b[th - sum] = 1;
  }
  b[th] = 1;

  n = 2*th + 1;
  while(n&(n - 1)) n++;

  multiply(a, b, n);

  int ans = 0;
  for(int i = th + 1; i <= 2*th; i++)
    ans += (!a[i] > 0.5);

  cout << ans << '\n';
}
