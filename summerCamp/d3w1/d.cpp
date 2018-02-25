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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e5+5;

mt19937_64 llrand(random_device{}());

struct node{
    pair<int, int> val;
    int cnt;
    ll pri;
    node*l, *r;

    node(pair<int, int> val):val(val), cnt(1), pri(llrand()), l(0), r(0) {};
};

struct treap{
    node *root;
    treap():root(0){}
    int cnt(node *t) { return t ? t->cnt : 0; }
    void update(node *t){
        if(!t) return;
        t->cnt = cnt(t->l) + cnt(t->r) + 1;
    }

    node* merge(node *l, node *r){
        node *t;
        if(!r or !l) t = l ? l : r;
        else if(l->pri > r->pri) l->r = merge(l->r, r), t = l;
        else r->l = merge(l, r->l), t = r;
        update(t);
        return t;
    }

    pair<node*, node*> split(node*t , int pos){
        if(!t) return {0, 0};

        if(cnt(t->l) < pos){
            auto x = split(t->r, pos - cnt(t->l) - 1);
            t->r = x.st;
            update(t);
            return {t, x.nd};
        }

        auto x = split(t->l, pos);
        t->l = x.nd;
        update(t);
        return {x.st, t};
    }

    int order(node *t, pair<int, int> val){
        if(!t) return 0;
        if(t->val < val) return cnt(t->l) + 1 + order(t->r, val);
        return order(t->l, val);
    }

    pair<int, int> find(node *t, int n){
        if(cnt(t->l) > n) return find(t->l, n);
        else if(cnt(t->l) < n) return t->r ? find(t->r, n - cnt(t->l) - 1) : t->val;
        else return t->val;
    }

    bool has(node* t, pair<int, int> val){
        if(!t) return 0;
        if(t->val == val) return 1;
        return has((t->val > val ? t->l : t->r), val);
    }

    void insert(pair<int, int> val){
        if(has(root, val)) return;
        node* x = new node(val);
        auto t = split(root, order(root, val));
        root = merge(merge(t.st, x), t.nd);
    }

    void erase(pair<int, int> val) {
        if(!has(root, val )) return;

        auto t1 = split(root, order(root, val));
        auto t2 = split(t1.nd, 1);
        root = merge(t1.st, t2.nd);
    }

    void print() { print(root); cout << endl; }
    void print(node *t){
        if(!t) return;
        print(t->l);
        cout << '(' << t->val.st << ',' << t->val.nd << ") ";
        print(t->r);
    }
};

int main() {
    int n;
    int id = 0;
    map<int, string> id_s;
    map<string, int> s_id;
    map<int, int> id_r;
    treap r_id;
    cin >> n;
    for(int i = 0; i < n; i++){
        string op;
        cin >> op;
        if(op == "ISSUE"){
            string s;
            cin >> s;
            if(s_id.count(s)) { cout << "EXISTS " << s_id[s] << ' ' << id_r[s_id[s]] << endl; continue; }
            id_s[id] = s;
            s_id[s] = id;
            id_r[id] = 0;
            r_id.insert({0, id});
            cout << "CREATED " << id << ' ' << 0 << endl;
            id++;
        }else if(op == "DELETE"){
            string s;
            cin >> s;
            if(!s_id.count(s)) { cout << "BAD REQUEST" << endl; continue; }
            int id = s_id[s];
            int reab = id_r[id];
            cout << "OK " << s_id[s] << ' ' << id_r[id] << endl;
            id_s.erase(id); s_id.erase(s); id_r.erase(id); r_id.erase({-reab, id});
        }else if(op == "RELIABILITY"){
            string s;
            int m;
            cin >> s >> m;
            if(!s_id.count(s)) { cout << "BAD REQUEST" << endl; continue; }
            int id = s_id[s];
            int reab = id_r[id];
            id_r[id] += m;
            r_id.erase({-reab, id}), r_id.insert({-reab - m, id});
            cout << "OK " << id << ' ' << reab + m << endl;
        }else if(op == "FIND"){
            int n;
            cin >> n;
            if(id_s.empty()) { cout << "EMPTY" << endl; continue; }
            auto p = r_id.find(r_id.root, n);
            cout << "OK " << id_s[p.nd] << ' ' <<  p.nd << ' ' << -p.st << endl;
        }
    }

    return 0;
}


















