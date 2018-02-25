#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
typedef long long ll;
const int N = 1e6 + 2;

bool bya[N];


int main(){
  int n, a, b;
  set<int> div;
  cin >> n >> a >> b;
  int x = 0, y = 0;
  for(int i = 0; i <= n; i += a) bya[i] = true;
  for(int i = 0; i <= n and n - i >= 0; i += b) if(bya[n - i]) x = (n - i)/a, y = i/b;
  if(x == 0 and y == 0) return cout << -1 << endl, 0;

  int i = 1;
  for(int j = 0; j < x; j++){
    int first = i;
    for(int k = 1; k < a; k++)
      cout << ++i << ' ';
    cout << first << ' ';
    i++;
  }
  for(int j = 0; j < y; j++){
    int first = i;
    for(int k = 1; k < b; k++)
      cout << ++i << ' ';
    cout << first << ' ';
    i++;
  }
  cout << endl;
}
