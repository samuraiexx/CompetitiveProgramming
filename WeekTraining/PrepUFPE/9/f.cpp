#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector <int> vi;

int dir, x, y, n, a, b, ok;
char str[20];
vi v;

int main () {
    scanf("%d%d%d ", &x, &y, &n);
    for (int i = 0; i < n; i++) {
        scanf("%s ", str);
        if (str[0] == 'F') v.pb(0);
        if (str[0] == 'R') v.pb(1);
        if (str[0] == 'L') v.pb(-1);
    }
    for (int i = 0; i < n; i++) {
        vi u = v;
        for (int d = -1; d <= 1; d++) {
            u[i] = d;
            dir = a = b = 0;
            for (int j = 0; j < n; j++) {
                if (u[j] == 0 and dir == 0) b++;
                if (u[j] == 0 and dir == 1) a++;
                if (u[j] == 0 and dir == 2) b--;
                if (u[j] == 0 and dir == 3) a--;
                if (u[j] == 1) dir++;
                if (u[j] == -1) dir--;
                dir += 4;
                dir %= 4;
                if (a < -50 or a > 50) break;
                if (b < -50 or b > 50) break;
            }
            if (a == x and b == y) {
                printf("%d %s\n", i+1, d == -1 ? "Left" : d == 0 ? "Forward" : "Right");
                ok = 1;
            }
            if (ok) break;
        }
        if (ok) break;
    }

}
