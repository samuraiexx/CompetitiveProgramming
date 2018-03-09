#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 

int main(){
  int n, sum = 0;
  cin >> n;
  for(int i = 0, a; i < n; i++)
    cin >> a, sum += abs(a);

  cout << sum << endl;
}

