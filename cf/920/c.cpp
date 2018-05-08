#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
int v[N];
int s[N];
bool a[N]; 

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> v[i], s[i] = v[i];

  for(int i = 0; i < n - 1; i++){
    char c;
    cin >> c;
    a[i] = c == '1';
  }

  sort(s, s + n);
  set<int> s1, s2;
  for(int i = 0; i < n; i++){
    s1.insert(v[i]);
    s2.insert(s[i]);
    if(!a[i]){
      auto it1 = s1.begin();
      auto it2 = s2.begin();
      while(it1 != s1.end()){
        if(*(it1++) != *(it2++)) return cout << "NO" << endl, 0;
      }

      s1.clear(), s2.clear();
    }
  }

  cout << "YES" << endl;
}
