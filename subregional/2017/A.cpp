#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int st[4*N][9], lz[4*N];

void build(int p, int l, int r)
{
        if(l == r)
                st[p][1] = 1;
        else
                build(2*p, l, (l+r)/2), build(2*p + 1, (l + r)/2 + 1, r), st[p][1] = st[2*p][1] + st[2*p + 1][1];
}

void lazy(int p, int l, int r)
{
        if(lz[p] = lz[p]%9)
        {
                for(int i = 0; i < lz[p]; i++)
                {
                        int tmp = st[p][8];
                        for(int j = 8; j > 0; j--)
                                st[p][j] = st[p][j - 1];
                        st[p][0] = tmp;
                }
                if(l != r) lz[2*p] += lz[p], lz[2*p + 1] += lz[p];
                lz[p] = 0;
        }
}

void update(int p, int l, int r, int i, int j, int v)
{
        lazy(p, l, r);
        if(l > j || r < i) return;
        if(l >= i && r <= j){ lz[p] += v, lazy(p, l, r); return;} 
        update(2*p, l, (l + r)/2, i, j, v);
        update(2*p + 1, (l + r)/2 + 1, r, i, j, v);
        for(int k = 0; k < 9; k++)
                st[p][k] = st[2*p][k] + st[2*p + 1][k];
}

void query(int p, int l, int r, int i, int j, vector<int> &feq)
{
        lazy(p, l, r);
  if(l > j || r < i) return;
        if(l >= i && r <= j)
        {
                for(int k = 0; k < 9; k++) feq[k] += st[p][k];
                return;
        }
        query(2*p, l, (l + r)/2, i, j, feq);
        query(2*p + 1, (l + r)/2 + 1, r, i, j, feq);
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, q;
        cin >> n >> q;
        build(1, 1, n);
        for(int i = 0; i < q; i++)
        {
                int a, b, mx = 0, bst;
                vector<int> feq(9);
                cin >> a >> b;
                query(1, 1, n, a + 1, b + 1, feq);
                for(int j = 0; j < 9; j++)
                        if(feq[j] >= mx) mx = feq[j], bst = j;
                update(1, 1, n, a + 1, b + 1, bst);
        }
        for(int i = 1; i <= n; i++)
        {
                vector<int> q(9);
                query(1, 1, n, i, i, q);
                for(int j = 0; j < 9; j++) if(q[j]) cout << j << '\n';
        }
        return 0;
}
