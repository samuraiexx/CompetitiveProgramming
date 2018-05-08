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
  map<set<char>, int> m;
  cin >> n;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    set<char> l;
    for(auto c : s) l.insert(c);
    m[l]++;
  }
  cout << m.size() << endl;
}
