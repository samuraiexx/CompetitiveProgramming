#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    if(n == 1 and m == 1) return cout << "YES\n1\n" << endl, 0;
    if(n == 3 and m == 3)
        return cout << "YES\n5 3 8\n1 9 4\n6 7 2\n", 0;
    if(max(m, n) <= 3) return cout << "NO" << endl, 0;
    cout << "YES" << endl;

    vector<int> v;

    int x = max(m, n);
    int y = min(m, n);
    for(int i = 2; i <= x; i+=2) v.push_back(i);
    for(int i = 1; i <= x; i+=2) v.push_back(i);

    vector<vector<int>> mt;
    for(int j = 0; j < y; j++){
        vector<int> vt;
        if(j%2) for(int i = 0; i < v.size(); i++)
                    vt.push_back(v[i] + j*x);
        else for(int i = v.size() - 1; i >= 0; i--) 
                    vt.push_back(v[i] + j*x);
        mt.push_back(vt);
    }

    if(m == x) for(int i = 0; i < mt.size(); i++){
        for(int j = 0; j < v.size(); j++)
            cout << mt[i][j] << ' ';
        cout << endl;
    }
    else
        for(int j = 0; j < v.size(); j++){
            for(int i = 0; i < mt.size(); i++)
                cout << mt[i][j] << ' ';
        cout << endl;
        }
}

