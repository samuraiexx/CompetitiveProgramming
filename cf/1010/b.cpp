#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 35;
int ok[N];

int main(){
  int m, n;
  cin >> m >> n;

  for(int i = 0; i < n; i++){
    int x;

    cout << 1 << endl;
    cin >> x;

    if(x == 0 or x == -2 or x == 2) return 0;
    ok[i] = x;
  }

  int i = 2, j = m;
  for(int k = 0;; k = (k + 1)%n){
    int mid = (i + j)/2;
    int x;
    
    cout << mid << endl;
    cin >> x;
    x *= ok[k];

    if(x == 0 or x == -2 or x == 2) return 0;

    if(x == -1) j = mid - 1;
    else i = mid + 1;
  }
}
