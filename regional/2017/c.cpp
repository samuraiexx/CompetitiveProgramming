#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 1e4 + 5;
int amt[N];

int main(){
  ios_base::sync_with_stdio(false), cin.tie(0);

  int k, n;
  cin >> k >> n;
  for(int a, i = 0; i < n; i++)
    cin >> a, amt[a]++;

  map<int, vector<int>> m;

  for(int i = 1; i <= k; i++)
    m[amt[i]].pb(i);

  auto it = m.begin();
  auto it2 = it; it2++;

  while(it2 != m.end()){
    if(it2->st - it->st != 1)
      return cout << "*\n", 0;
    it2++, it++;
  }

  it = m.begin();

  if(m.size() > 3)
    cout << "*\n";
  else if(m.size() == 2){
    auto it2 = it; it2++;
    if(it->nd.size() == 1)
      cout << '+' << it->nd.front() << '\n';
    else if(it2->nd.size() == 1)
      cout << '-' << it2->nd.front() << '\n';
    else cout << "*\n";
  } else {
    auto it2 = it; it2++;
    auto it3 = it2; it3++;

    if(it->nd.size() == 1 and it3->nd.size() == 1)
      cout << '-' << it3->nd.front() << " +" << it->nd.front() << '\n';
    else cout << "*\n";
  }
}
