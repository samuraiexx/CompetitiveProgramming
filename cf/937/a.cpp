#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 

int main(){
  int n;
  set<int> scores;
  cin >> n;
  for(int i = 0, a; i < n; i++) cin >> a, scores.insert(a);

  if(scores.count(0)) scores.erase(0);
  cout << scores.size() << endl;
}
