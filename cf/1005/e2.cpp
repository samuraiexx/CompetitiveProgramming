#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
int v[N], cnt[N];

int main(){
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    cin >> v[i];
    cnt[i] = cnt[i - 1];
    if(v[i] < k) cnt[i]--;
    else if(v[i] > k) cnt[i]++;
  }
}
