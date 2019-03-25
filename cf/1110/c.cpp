#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 25;
int v[N];
int v2[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int q;
  cin >> q;

  v2[1] = 1;
  v2[2] = 1;
  v2[3] = 5;
  v2[4] = 1;
  v2[5] = 21;
  v2[6] = 1;
  v2[7] = 85;
  v2[8] = 73;
  v2[9] = 341;
  v2[10] = 89;
  v2[11] = 1365;
  v2[12] = 1;
  v2[13] = 5461;
  v2[14] = 4681;
  v2[15] = 21845;
  v2[16] = 1;
  v2[17] = 87381;
  v2[18] = 1;
  v2[19] = 349525;
  v2[20] = 299593;
  v2[21] = 1398101;
  v2[22] = 178481;
  v2[23] = 5592405;
  v2[24] = 1082401;

  int x = 0;
  for(int i = 0; i < 25; i++){
    x += (1 << i);
    v[i] = x;
  }

  while(q--){
    int a;
    cin >> a;
    int x = *lower_bound(v, v + N, a);
    int pos = lower_bound(v, v + N, a) - v;

    cout << (x == a ? v2[pos] : x) << '\n';
  }
}
