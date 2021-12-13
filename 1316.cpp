#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    string s;
    int ans = 0;
    for(int i=0;i<n;i++){
        cin >> s;
        map<char, int> mp;
        bool flag = true;
        for(int j=0;j<s.size();j++){
            if(!mp[s[j]] || mp[s[j]] == j){
                mp[s[j]] = j+1;
            } else {
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }
    cout << ans;
}