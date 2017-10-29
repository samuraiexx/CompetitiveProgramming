#include <bits/stdc++.h>
using namespace std;

vector<int> lb;

int abs(int a) { return a > 0 ? a : -a; }

pair<int, int> pos(int a){
    int i;
    for(i = 0; ; i++)
        if(lb[i] >= a) break;
    int x = -i, y = -i;
    int d = lb[i] - a;
    if(a == 0) return {x, y};
    if(d < 2*i) return {x, y + d};
    y += 2*i, d -= 2*i;
    if(d < 2*i) return {x + d, y};
    x += 2*i, d -= 2*i;
    if(d < 2*i) return {x, y - d};
    y -= 2*i, d -= 2*i;
    return {x - d, y};
}

int main(){
    int a, b;
    cin >> a >> b;
    lb.push_back(1);
    for(int i = 1; ;i++)
    {
        lb.push_back(lb[i - 1] + i*8);
        if(lb[i] >= 1e9) break;
    }
    pair<int, int> pa = pos(a), pb = pos(b);
    cout << abs(pa.first - pb.first) + abs(pa.second - pb.second) << endl;
    
    return 0;
}
