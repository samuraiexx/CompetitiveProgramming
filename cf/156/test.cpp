#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 100;
int st[2*N];
int n = 50;

int query(int a, int b) {
  a += n; b += n;
  int s = 0;
  while (a <= b) {
    if (a%2 == 1) s += st[a++];
    if (b%2 == 0) s += st[b--];
    a /= 2; b /= 2;
  }
  return s;
}

void update(int p, int val) {
  p += n;
  st[p] += val;
  for (p /= 2; p >= 1; p /= 2)
    st[p] = st[2*p]+st[2*p+1];
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  update(1, 3);
  update(5, 1);
  update(8, 2);

  db(query(1, 1) _ query(1, 5) _ query(2, 2) _ query(3, 8));
}
