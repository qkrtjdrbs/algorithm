#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[10001], p[10001], ans;

int Find(int x){    
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    if(a[x] >= a[y]) p[x] = y;
    else p[y] = x;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)
        p[i] = i;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        int v, w;
        cin >> v >> w;
        Union(v, w);
    }
    for(int i=1;i<=n;i++){
        if(i == p[i]){
            if(k >= a[i]){
                ans += a[i];
                k -= a[i];
            } else {
                cout << "Oh no";
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}