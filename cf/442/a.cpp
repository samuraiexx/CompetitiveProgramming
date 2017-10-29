#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int main(){
    int ans = 0;
    string names[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    string in;
    cin >> in;
    for(auto s : names){
        int j = 0;
        for(int i = 0; i < in.size(); i++)
        {
            if(in[i] == s[j]) j++;
           else j = 0;
           if(j == s.size() && (i + 1 == in.size() || in[i + 1] < 'a' || in[i + 1] > 'z') ){ ans++; continue;}
           else if(j == s.size()) j = 0;
        }
    }
    if(ans != 1)
        cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
