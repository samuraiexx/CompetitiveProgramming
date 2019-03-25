#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
int perm[N];
bool active[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  string t, p;
  cin >> t >> p;

  int n = t.size();

  for(int i = 0; i < n; i++)
    cin >> perm[i], perm[i]--;

  int i = 0, j = n;
  while(i != j){
    int mid = (i + j)/2;
    for(int i = 0; i < n; i++) active[i] = true;
    for(int i = 0; i <= mid; i++) active[perm[i]] = false;

    int k = 0;
    for(int i = 0; i < n; i++)
      if(k < p.size() and active[i] and t[i] == p[k]) k++;

    if(k == p.size()) i = mid + 1;
    else j = mid;
  }

  cout << i << endl;
}
