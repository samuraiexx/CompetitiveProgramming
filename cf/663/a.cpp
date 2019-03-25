#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

// Extended Euclid: gcd(a, b) = x*a + y*b
void euclid(int a, int b, int &x, int &y, int &d) {
  if (b) euclid(b, a%b, y, x, d), y -= x*(a/b);
  else x = 1, y = 0, d = a;
}

// Solves a*x + b*y = c
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    euclid(abs(a), abs(b), x0, y0, g);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

// all x' and y' are a valid solution for any integer k
// x' = x + k*b/gcd
// y' = y - k*a/gcd
// Here a and b are actually a/gcd and b/gcd
void shift_solution (int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int a, b, c;
  cin >> a >> b >> c;
  int x, y, g;
  if(!find_any_solution(a, b, c, x, y, g)) return cout << "No\n", 0;
  a /= g, b /= g;

  if(x < 0) shift_solution(x, y, a, b, (-x + b - 1)/b);
  if(y < 0) shift_solution(x, y, a, b, -(-y + a - 1)/a);
  if(x < 0 or y < 0) cout << "No\n";
  else cout << "Yes\n";
}
