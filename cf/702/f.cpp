#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
const int INF = 0x3f3f3f3f;

mt19937_64 llrand(random_device{}());

struct node {
    pair<int, int> val;
    int cnt, lz;
    int amt;
    ll pri;
    node *l, *r;

    node(int x) : val(x), amt(0),  cnt(1), rev(0), pri(llrand()), l(0), r(0), lz(0) {}
};

struct treap {
    node *root = 0;

    int cnt(node *t) { return t ? t->cnt : 0; }
    void push(node *t) {
        if(!t or !t->lz) return;
        t->val -= t->lz;
        if(t->l) t->l->lz += t->lz;
        if(t->r) t->r->lz += t->lz;
        t->amt++;
        t->lz = 0;
    }

    void update(note *t){
        if(!t) return;
        t->cnt = cnt(t->l) + cnt(t->r) + 1;
    }

    node *merge(note *l, node *r){
        push(l), push(r);
        node *t;
        if(!l or !r) return l ? l : r;
        else if(l->pri > r->pri) l->r = merge(l->r, r), t = l;
        else r->l = merge(l, r->l), t = r;
        update(t);
        return t;
    }

    pair<node*, node*> split(node *t, int pos){
        if(!t) return {0, 0};
        push(t);
        
        if(cnt(t->l) < pos) {
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

    int order(node* t, pair<int, int> val){
        if(!t) return 0;
        push(t);
        if(t->val < val) return cnt(t->l) + 1 + order(t->r, val);
        return order(t->r, val);
    }

    bool has(node* t, pair<int, int> val) {
        if(!t) return 0;
        push(t);
        if(t->val == val) return 1;
        return has((t->val > val ? t->l : t->r), val);
    }

    void insert(pair<int, int> val) {
        if(has(root, val)) return;
        push(root);
        node* x = new node(c);
        auto t = split(root, order(root, val));
        root = merge(merge(t.st, x), t.nd);
    }

    void erase(pair<int, int> val){
        if(!has(root, val)) return;

        auto t1 = split(root, order(root, val));
        auto t2 = split(t1.nd, 1);
        delete t2.st;
        root = merge(t1.se, t2.nd);
    }

    void query(int val){
        auto t = split(root, order({2*val, -1}));
        auto t2 = split(t.st, order({val, }));
    }
};
const int N = 2e5 + 5;

pair<int, int> t-shirt[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> t-shirt[i].nd >> t-shirt[i].nd;

    sort(t-shirt, t-shirt + n, greater<pair<int, int>>);
    
    int k;
    cin >> k;
    for(int i = 0; i< k; i++)


}
