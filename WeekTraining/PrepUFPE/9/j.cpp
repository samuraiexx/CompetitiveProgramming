#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int n;
string s, ans;

int main () {
    scanf("%d ", &n);
    while (n--) {
        getline(cin, s);
        if (s[0] == 'e') {
            int sum = 0;
            for (int i = 2; i < s.size(); i++) {
                if (s[i] != ' ') sum += s[i]-'a'+1;
                sum %= 27;
                ans.pb(sum+'a'-1 == '`' ? ' ' : sum+'a'-1);
            }
        } else {
            for (int i = s.size()-1; i >= 3; i--) {
                char a = s[i];
                char b = s[i-1];
                if (a == ' ') a = 'a' - 1;
                if (b == ' ') b = 'a' - 1; 
                char ch = a-b;
                if (ch == 0) ans.pb(' ');
                else if (ch < 0) {
                    while(ch < 0) ch += 27;
                    ch += 'a'-1;
                    ans.pb(ch);
                }
                else ans.pb('a' + ch - 1);
            }
            ans.pb(s[2]);
            reverse(ans.begin(), ans.end());
        }
        cout << ans << endl;
        ans.clear();
    }
}
