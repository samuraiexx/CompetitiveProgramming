#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
pair<string, bool> files[100001];

int alloc[100001];



int main(){
    int n;
    int ex = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> files[i].st >> file[i].nd;
        if(file[i].nd) ex++;
    }
    set<string> dispe, disp;
    for(int i = 1; i <= n; i++)
        if(i <= ex) dispe.insert(i);
        else disp.insert(i);
    for(int i = 1; i <= n; i++)
    {
        if(files[i].nd)
        {
            if(dispe.count(files[i].first))
            {
                dispe.erase(files[i].first);
                alloc[i] = true;
            }
            else if(disp.count(files[i].first)
            {
                disp.erase(files[i].first);
                alloc[i] = 2;
            }
        }
        else if(!files[i].nd)
        {
            disp(files[i].first))
            {
                disp.erase(files[i].first);
                alloc[i] = true;
            }
            dispe(files[i].st)
            {
                dispe.erase(files[i].st);
                alloc[i] = 3;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        if(!alloc[i])
        {
            if(files[i].nd && disp(files[i].first
        }

}
