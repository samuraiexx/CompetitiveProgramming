#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  string s, t;
  cin >> s >> t;
  int i = s.size() - 1;
  int j = t.size() - 1;

  while(i >= 0 and j >= 0){
    if(s[i] != t[j]) break;
    i--, j--;
  }

  cout << i + j + 2 << endl;
}
