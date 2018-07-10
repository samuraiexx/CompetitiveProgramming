#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int n, m;
  string s;
  cin >> n >> m;

  bool x = false;
  for(int i = 0; i < n; i++){
    if(x) s.push_back('0');
    else s.push_back('1');
    x = !x;
  }
  cout << s << endl;

}
