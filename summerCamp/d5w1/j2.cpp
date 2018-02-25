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
int cont[N], is_vogal[N];

bool dfs(int u, int g) {
    if(par[u] == (g^1)) return false;
    if(par[u]) return true;
    par[u] = g;
    cont[g]++;
    for (int v: adj[u]) {
        if(!dfs(v, g^1)) return false;
    }

    db( (char)(u+'a') _ par[u]);
}

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

set<pair<int, int>> gr;
set<int> ans;

bool sum(int s, int g) {
    if(s > 5) return false;
    if(g >= 2*27 and s == 5) return true;
    if(g >= 2*27) return false;

    s += cont[g];
    if(sum(s, g+2)) {
            is_vogal[g] = 1;
            return true;
    }

    s -= cont[g];
    s += cont[g^1];
    if(sum(s, g+2)) {
            is_vogal[g^1] = 1;
            return true;
    }
    db( g _ is_vogal[g] );
   return false;
}

int main() {
    freopen("javanese.in", "r", stdin);
    freopen("javanese.out", "w", stdout);

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
    }

    for(int i=0; i<='z'-'a'; i++) {
        if(!dfs(i, 2*(i+1))) {
            cout << "impossible\n";
            return 0;
        }
    }

    if(!sum(0, 2)) {
        cout << "impossible\n";
        return 0;
    }

    map<char, char> code;
    for(int i=0; i<26; i++) {
        if(is_vogal[par[i]]) code[i + 'A'] = vog[vcnt++];
        else code[i + 'A'] = con[ccnt++];
    }

    for(auto s : str){
        for(auto c : s) cout << code[c]; 
        cout << ' ';
    }
    cout << endl;
}



