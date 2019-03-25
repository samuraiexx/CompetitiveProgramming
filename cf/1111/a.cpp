#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

bool is(char c){
  return !(c != 'a' and c != 'e' and c != 'i' and c != 'o' and c != 'u');
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  string a, b;
  cin >> a >> b;

  if(a.size() != b.size()) return cout << "No\n", 0;

  for(int i = 0; i < a.size(); i++)
    if(!(is(a[i]) and is(b[i]) or !is(a[i]) and !is(b[i])))
      return cout << "No\n", 0;

  cout << "Yes\n";
}
