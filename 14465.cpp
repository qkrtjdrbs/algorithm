#include <bits/stdc++.h>
using namespace std;

int n, k, b, ans;
bool broken[100001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k >> b;
    for(int i=0;i<b;i++) {
        int x;
        cin >> x;
        broken[x] = 1;
    }
    for(int i=1;i<=k;i++){
        if(broken[i]) ans++;
    }
    int l = 1, r = k, res = ans;
    while(r <= n){
        ans = min(ans, res);
        res -= (broken[l++] == 1);
        res += (broken[++r] == 1);
    }
    cout << ans;
}