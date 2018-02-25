#include<bits/stdc++.h>
using namespace std;

struct pnt{
    long long x, y;
    pnt operator-(pnt p){ return {x - p.x, y - p.y}; }
    long long operator!(){ return x*x+y*y; }
};

ostream &operator<<(ostream &out, pnt p){
    out << '(' << p.x << " ," << p.y << ')';
    return out;
}

const int N = 1e5 + 5;
pnt pnts[N];
pnt tmp[N];
pnt p1, p2;
unsigned long long d = 9e18;

void closest(int l, int r){
    if(l == r) return;
    int mid = (l + r)/2;
    
    int midx = pnts[mid].x;
    closest(l, mid), closest(mid + 1, r);

    merge(pnts + l, pnts + mid + 1, pnts + mid + 1, pnts + r + 1, tmp + l,
            [](pnt a, pnt b){ return a.y < b.y; });

    for (int i = l; i <= r; i++) pnts[i] = tmp[i];

    vector<pnt> margin;
    for(int i = l; i <= r; i++)
        if((pnts[i].x - midx)*(pnts[i].x - midx) < d)
            margin.push_back(pnts[i]);

    for(int i = 0; i < margin.size(); i++)
        for(int j = i + 1;
            j < margin.size() and
            (margin[j].y - margin[i].y)*(margin[j].y - margin[i].y) < d;
            j++) {
            if(!(margin[i] - margin[j]) < d)
                p1 = margin[i], p2 = margin[j], d = !(p1 - p2);
        }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> pnts[i].x >> pnts[i].y;

    sort(pnts, pnts+n ,[](pnt a, pnt b){ return a.x < b.x; });
    closest(0, n - 1);

    cout << p1.x << ' ' << p1.y << endl;
    cout << p2.x << ' ' << p2.y << endl;
}
