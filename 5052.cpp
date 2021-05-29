#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s[n];
        for(int i=0;i<n;i++){
            cin >> s[i];
        }
        sort(s, s+n);
        for(int i=1;i<n;i++){
            if(s[i-1].size() >= s[i].size()){
                continue;
            } else{
                if(s[i].substr(0, s[i-1].length()) == s[i-1]){
                    cout << "NO" << '\n';
                    goto exit;
                }
            }
        }
        cout << "YES" << '\n';
        exit: continue;
    }
}