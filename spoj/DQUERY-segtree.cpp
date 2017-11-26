#include<bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;
const int M = 1e6 + 5;
int val[N];
int last[M];
pair<int, int> qry[N];
int ans[N];
int ord[N];
int st[4*N];

int query(int n, int l, int r, int i){
    if(i > r) return 0;
    if(i <= l) return st[n];
    int mid = (l + r)/2;
    return query(2*n, l, mid, i) + query(2*n + 1, mid + 1, r, i);
}

void update(int n, int l, int r, int pos, int val){
    if(l == r){ st[n] = val; return; }
    int mid = (l + r)/2;
    if(pos <= mid) update(2*n, l, mid, pos, val);
    else update(2*n + 1, mid + 1, r, pos, val);
    st[n] = st[2*n] + st[2*n + 1];
}

int main(){
    int n, q;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &val[i]);
    scanf("%d", &q);
    for(int i = 1; i <= q; i++)
        scanf("%d%d", &qry[i].first, &qry[i].second),
        ord[i] = i;

    sort(&ord[1], &ord[q + 1], [](int v1, int v2) {
            return qry[v1].second < qry[v2].second; });

    int lastj = 0;
    for(int i = 1; i <= q; i++){
        for(int j = lastj + 1; j <= qry[ord[i]].second; j++){
            if(last[val[j]]) update(1, 1, n, last[val[j]], 0);
            update(1, 1, n, j, 1);
            last[val[j]] = j;
        }
        lastj = qry[ord[i]].second;
        ans[ord[i]] = query(1, 1, n, qry[ord[i]].first);
    }
    for(int i = 1; i <= q; i++) printf("%d\n", ans[i]);
    return 0;
}
