#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << "==" << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 100;

int par[N], sz[N];

vector<int> adj[N];

char vog[] = {'A', 'E', 'I' , 'O', 'U'};
char con[] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P' , 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};
int vcnt, ccnt;

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

set<pair<int, int>> gr;
set<int> ans;
bool sum(set<pair<int, int>>::iterator it, int n, int val) {
    if(!n) return false;
    for(++it; it != gr.end(); it++){
        int tmp = val -= it->st;
        if(!tmp or sum(it, n - 1, tmp)) { ans.insert(it->nd); return true; }
    }
    return false;
}

void unite(int a, int b) {
    if((a = find(a)) == (b = find(b))) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}


int main() {
    freopen("javanese.in", "r", stdin);
    freopen("javanese.out", "w", stdout);

    for(int i = 0;i < 26; i++) par[i] = i, sz[i] = 1;
    vector<string> str;
    string s;
    while(cin >> s){
        str.push_back(s);
        for(int i = 0; i < s.size() - 1; i++){
            adj[s[i] - 'A'].push_back(s[i + 1] - 'A');
            adj[s[i + 1] - 'A'].push_back(s[i] - 'A');
        }
    }

    for(int i = 0; i < 26; i++){
        if(adj[i].empty()) continue;
        for(auto a : adj[i]) unite(adj[i][0], a);
    }

    for(int i = 0; i < 26; i++)
        for(auto a : adj[i])
            if(find(a) == find(i)) return cout << "impossible" << endl, 0;

    for(int i = 0; i < 26; i++) gr.insert({sz[find(i)],  find(i)});
    
    if(!sum(gr.begin(), 5, 5)) return cout << "impossible\n", 0;

    for(auto a : ans) cout << a << endl;

    map<char, char> code;

    for(int i = 0; i < 26; i++)
        if(ans.count(find(i))) code['A' + i] = vog[vcnt++]; 
        else code['A' + i] = con[ccnt++]; 

    for(auto s : str){
        for(auto c : s) cout << code[c];
        cout << ' ';
    }
    cout << endl;
}












