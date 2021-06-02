#include <bits/stdc++.h>
using namespace std;
int n, s, m, v[101], d[1001][101];

int go(int idx, int vol){
    if(vol < 0 || vol > m)
        return -100;
    if(idx == n) return vol;
    if(d[vol][idx] == -1){
        d[vol][idx] = max(go(idx+1, vol+v[idx+1]), go(idx+1, vol-v[idx+1]));
    }
    return d[vol][idx];
}

int main(){
    cin >> n >> s >> m;
    for(int i=1;i<=n;i++)
        cin >> v[i];
    memset(d, -1, sizeof(d));
    int ans = go(0, s);
    ans == -100 ? ans = -1 : ans;
    cout << ans;
}