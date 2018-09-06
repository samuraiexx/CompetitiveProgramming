#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  srand(time(0));

  ll n, k;
  cin >> n >> k;

  ll i = 1, j = n;
  while(1){
    string ans;
    if(j <= i) j = i;
    if(j - i + 1 <= 4*k + 1){
      ll sz = j - i + 1;
      ll pos = i + rand()%sz;
      cout << pos << ' ' << pos << endl;

      cin >> ans;
      if(ans == "Yes" or ans == "Bad") return 0;
      else i = max(1ll, i - k), j = min(n, j + k);
    }else{
      ll mid = (i + j)/2;

      cout << i << ' ' << mid << endl;
      cin >> ans;
      if(ans == "Bad") return 0;
      if(i == mid and ans == "Yes") return 0;
      if(ans == "Yes") i = max(1ll, i - k), j = min(n, mid + k);
      else i = max(1ll, mid + 1 - k), j = min(n, j + k);
    }
  }
}
