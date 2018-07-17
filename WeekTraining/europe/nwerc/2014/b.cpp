#include<bits/stdc++.h>
using namespace std;

#define px first
#define py second
typedef long double Ld;

const Ld EPS = 1e-12;
const int INF = 0x3f3f3f3f;
pair<int, int> beg, endd, bs[1000];
int vw, vb, n;
pair<int, int> wall[4];
pair<int, int> delt[4];

inline pair<Ld, Ld> operator+(pair<Ld, Ld> p1, pair<Ld, Ld> p2){
    return {p1.first + p2.first, p1.second + p2.second};
}
inline pair<Ld, Ld> operator*(pair<Ld, Ld> p1, Ld p){
    return {p1.first*p, p1.second*p};
}

Ld dtt(pair<Ld, Ld> beg, pair<Ld, Ld> endd, int v){
    return sqrtl((beg.px - endd.px)*(beg.px - endd.px) + (beg.py - endd.py)*(beg.py - endd.py))/v;
}

Ld ts(function<Ld (Ld)> f){
    Ld a = 0, b = 1;
    //while((b > a ? b - a : a - b) > EPS)
    for (int i = 0; i < 100; i++)
    {
        Ld p1 = (a*2 + b)/3, p2 = (a + b*2)/3;
        if(f(p1) > f(p2)) a = p1;
        else b = p2;
    }
    return f(a);
}

int main(){
    Ld ans;
    cin >> vw >> vb;

    pair<int, int> mn, mx;
    cin >> mn.px >> mn.py >> mx.px >> mx.py;
    wall[0] = {mn.px, mn.py}, wall[1] = {mn.px, mn.py}, wall[2] = {mx.px, mn.py}, wall[3] = {mn.px, mx.py};
    delt[0] = {mx.px - mn.px, 0}, delt[1] = {0, mx.py - mn.py}, delt[2] = {0, mx.py - mn.py}, delt[3] = {mx.px - mn.px, 0};

    cin >> beg.px >> beg.py;
    cin >> endd.px >> endd.py;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> bs[i].px >> bs[i].py;
    
    ans = dtt(beg, endd, vw);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j)
                ans = min(ans, dtt(beg, bs[i], vw) + 
                      dtt(bs[i], bs[j], vb) + 
                      dtt(bs[j], endd, vw));
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < n; j++)
        {
            ans = min(ans, dtt(beg, bs[j], vw) + ts([i, j] (Ld p){ return dtt(bs[j], wall[i] + delt[i]*p, vb) + dtt(endd, wall[i] + delt[i]*p, vw); }));
            ans = min(ans, dtt(endd, bs[j], vw) + ts([i, j] (Ld p){ return dtt(bs[j], wall[i] + delt[i]*p, vb) + dtt(beg, wall[i] + delt[i]*p, vw); }));
        }
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
                ans = min(ans,
                          ts([i, j] (Ld p){
                              return dtt(beg, wall[i] + delt[i]*p, vw) + ts([i, j, p] (Ld p2) { return dtt(wall[i] + delt[i]*p, wall[j] + delt[j]*p2, vb) + dtt(wall[j] + delt[j]*p2, endd, vw); });
                          }));

    printf("%.9f\n", (double)ans);
    return 0;
}
