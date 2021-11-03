#include <bits/stdc++.h>
using namespace std;

int n, ans, b[51];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++){
        int l = i-1, r = i+1, res = 0;
        while(l > 0){
            if(b[l] >= b[l-1]) break;
            l--; res++;
        }
        while(r < n){
            if(b[r] >= b[r+1]) break;
            r++; res++;
        }
        ans = max(ans, res);
    }
    cout << ans;
}