#include <bits/stdc++.h>
using namespace std;

int n;
char s[2001];
string ans;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> s[i];
    int l = 0, r = n-1;
    while(l <= r){
        if(s[l] > s[r]){
            ans += s[r--];
        } else if(s[l] < s[r]){
            ans += s[l++];
        } else {
            int nl = l+1, nr = r-1, cnt=0;
            bool flag = false;
            while(nl <= nr){
                if(s[nl] < s[nr]) {
                    for(int k=0;k<cnt;k++) {
                        ans += s[l++];
                        ans += s[r--];
                    }
                    ans += s[l++];
                    flag = true;
                    break;
                } else if(s[nl] > s[nr]){
                    for(int k=0;k<cnt;k++) {
                        ans += s[l++];
                        ans += s[r--];
                    }
                    ans += s[r--];
                    flag = true;
                    break;
                } else {
                    nl++; nr--; cnt++;
                }
            }
            if(!flag) {
                for(int i=0;i<cnt;i++){
                    ans += s[l++];
                    ans += s[r--];
                }
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        if(i && i % 80 == 0) cout << '\n';
        cout << ans[i];
    }
}