#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
typedef long long ll;

int main(){
  set<int> tk;
  for(int i = 0, a; i < 10; i++)
    cin >> a, tk.insert(a);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int cnt = 0;
    for(int i = 0, a; i < 6; i++)
      cin >> a, cnt += tk.count(a);
    if(cnt >= 3) cout << "Lucky" << endl;
    else cout << "Unlucky" << endl;
  }
}
