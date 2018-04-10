#include<bits/stdc++.h>
using namespace std;


int automata(vector<int> A, vector<int> B, vector<int> C, int D, int E) {
  const int mod = 1e9 + 7;
  vector<int> prev(A.size()), now(A.size());
  now[D] = 1;
  for(int i = 0; i < E; i++){
    swap(prev, now);
    for(int i = 0; i < A.size(); i++){
      now[A[i]] = (now[A[i]] + prev[i])%mod;
      now[B[i]] = (now[B[i]] + prev[i])%mod;
    }
    cerr << "PREV" << endl;
    for(auto x : prev) cerr << x << ' ';
    cerr << endl;
    cerr << "NOW" << endl;
    for(auto x : now) cerr << x << ' ';
    cerr << endl;
  }

  int ans = 0;
  for(auto x : C)
    ans = (ans + now[x])%mod;
  return ans;
}

int main(){
  cout << automata({0, 2, 1}, {1, 0, 2}, {0}, 0, 2);
  cout << endl;
}
