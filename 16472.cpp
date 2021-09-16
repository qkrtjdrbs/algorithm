#include <bits/stdc++.h>
using namespace std;

int n;
string s;
map<char, int> m;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> s;
    int l = 0, r = 0, len = 1, ans = 1;
    m[s[0]]++;
    while(l <= r && l < s.size() && r < s.size()){
        if(m.size() <= n){         
            ans = max(ans, len);
            if(r + 1 < s.size()){
                m[s[++r]]++;
                len++;
            } else break;
        } else {
            if(m[s[l]] == 1) {
                m.erase(s[l++]);               
            } else {
                m[s[l++]]--;
            }
            len--;
        }
    }
    cout << ans;

}