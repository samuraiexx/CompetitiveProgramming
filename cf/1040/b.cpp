#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int n, k;
  cin >> n >> k;
  if(n <= (2*k + 1))
    return cout << 1 << endl << n/2 + 1 << endl, 0;

  int amt = n/(2*k + 1);
  int x = n - (2*k + 1)*amt;
  bool last = false;
  if(x < k + 1 and x > 0) amt--, x += k, last = true;

  cout << amt + (x > 0) + last << endl;
  if(x > 0)
    cout << x - k << ' ';

  for(int i = 0; i < amt; i++)
    cout << x - k + (2*k + 1)*(i + 1) << ' ';

  if(last) cout << n;
  cout << endl;
}
