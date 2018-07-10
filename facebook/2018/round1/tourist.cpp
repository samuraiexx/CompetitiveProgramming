#include<bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    long long n, k, v;
    cin >> n >> k >> v;
    v = (((v - 1)%n)*(k%n))%n;

    vector<string> atr(n);
    for(int i = 0; i < n; i++)
      cin >> atr[i];


    cout << "Case #" << t << ": ";
    set<int> ans;
    for(int i = 0; i < k; i++){
      ans.insert((v + i)%n);
    }

    for(auto it = ans.begin(); it != ans.end(); it++){
      if(it != ans.begin()) cout << ' ';
      cout << atr[*it];
    }
    cout << endl;
  }
}
