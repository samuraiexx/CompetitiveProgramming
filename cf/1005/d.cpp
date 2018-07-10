#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  string s;
  cin >> s;

  int z = 0, o = -1, t = -1;
  int cnt1 = 0, cnt2 = 0;
  for(auto c : s){
    int x = c - '0';
    if(x%3 == 1)
      swap(t, z), swap(o, t);
    if(x%3 == 2)
      swap(t, z), swap(o, z);
    z++;
    
    z = max({z, o, t});
  }

  cout << z << endl;
}
