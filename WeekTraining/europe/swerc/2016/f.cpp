#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const ll N = 1e5 + 5;

vector<ll> adj[N];
vector<ll> st[8*N];
vector<ll> ps[8*N];
ll p = 1;
ll arr[2*N];
map<ll, pair<ll, ll>> arrpos;
ll tme[N], rnk[N];

void dfs(ll n)
{
    arrpos[n].first = p;
    arr[p++] = n;
    for(auto a : adj[n])
        dfs(a);
    arrpos[n].second = p;
    arr[p++] = n;
}

void build(ll p, ll l, ll r){
    if(l == r) { st[p].pb(arr[l]); ps[p].push_back(tme[st[p][0]]); return; }
    build(2*p, l, (l+r)/2);
    build(2*p + 1, (l+r)/2 + 1, r);
    st[p].resize(r - l + 1);
    merge(st[2*p].begin(), st[2*p].end(), 
          st[2*p+1].begin(), st[2*p+1].end(),
          st[p].begin(), [](ll n1, ll n2) { return rnk[n1] < rnk[n2]; });
    ps[p].push_back(tme[st[p][0]]);
    for(ll i = 1; i < st[p].size(); i++)
        ps[p].push_back(ps[p][i - 1] + tme[st[p][i]]);

}

ll query(ll p, ll l, ll r, ll i, ll j, ll a){
    if(j < l or i > r) return 0;
    if(i <= l and j >= r){
        if (lower_bound(st[p].begin(), st[p].end(), a, [](ll n1, ll n2){ return rnk[n1] < rnk[n2] ; }) == st[p].begin()) return 0;
        return ps[p][lower_bound(st[p].begin(), st[p].end(), a, [](ll n1, ll n2){ return rnk[n1] < rnk[n2]; }) - st[p].begin() - 1];
    }

    return query(2*p, l, (l+r)/2, i, j, a) +
           query(2*p + 1, (l+r)/2 + 1, r, i, j, a);
}

int main(){
    ll e;
    ll root;
    scanf("%lld", &e);
    for(ll i = 1; i <= e; i++)
    {
        ll m, r, t;
        scanf("%lld %lld %lld", &m, &r, &t);
        if(m == -1)
            root = i;
        else adj[m].pb(i);
        rnk[i] = r;
        tme[i] = t;
    }
    dfs(root);
    build(1, 1, 2*e);
    
    for(ll i = 1; i <= e; i++)
        printf("%lld\n", query(1, 1, 2*e, arrpos[i].first + 1, arrpos[i].second - 1, i)/2);

}
