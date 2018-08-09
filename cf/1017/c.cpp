#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int n;
  cin >> n;

  int s;
  for(s = 1; s*s < n; s++);

  int i;
  for(i = n; i > s; i -= s){
    for(int j = s - 1; j >= 0; j--)
      cout << i - j << ' ';
  }

  for(int j = 1; j <= i; j++)
    cout << j << ' ';
  cout << endl;
}
