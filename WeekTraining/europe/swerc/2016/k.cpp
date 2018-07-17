#include<bits/stdc++.h>
using namespace std;
const long long N = 5*1e4 + 5;

map<long long, vector<long long>> adj, adjf;
set<long long> vis, visf;

bool dfs(long long n, long long f, set<long long> &vis, map<long long, vector<long long>> &adj)
{
    bool c = 0;
    set<long long> lvis;
    lvis.insert(n), lvis.insert(f);
    if(vis.count(n))
        return 1;
    vis.insert(n);
    for(auto a : adj[n])
        if(!lvis.count(a))
            lvis.insert(a), c = c || dfs(a, n, vis, adj);
    return c;
}

int main(){
    long long k;
    cin >> k;
    long long ns, nf;
    for(long long i = 0; i < k; i++)
    {
         long long x1, y1, z1, x2, y2, z2;
         cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
         long long n1 = x1 + y1*1e3 + z1*1e6;
         long long n2 = x2 + y2*1e3 + z2*1e6;
         ns = n1;
         adj[n1].push_back(n2);
         adj[n2].push_back(n1);
         n1 -= 1e6*z1, n2 -= 1e6*z2;
         nf = n1;
         adjf[n1].push_back(n2);
         adjf[n2].push_back(n1);
    }
    if(dfs(ns, -1, vis, adj))
        cout << "True closed chains\n";
    else
        cout << "No true closed chains\n";
    if(dfs(nf, -1, visf, adjf))
        cout << "Floor closed chains\n";
    else 
        cout << "No floor closed chains\n";
    return 0;

}
