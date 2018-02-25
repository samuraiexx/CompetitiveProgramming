#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
typedef long long ll;

const int N = 1e5 + 2;

int main(){
  string a, b;
  cin >> a;
  b = a;
  for(int i = a.size() - 1; i >= 0; i--)
    b.push_back(a[i]);
  cout << b << endl;
}
