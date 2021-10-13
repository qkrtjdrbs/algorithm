#include <bits/stdc++.h>
using namespace std;

int n, m, k, a[51][51];
vector<int> order;
vector<tuple<int, int, int>> op;

void rotate(int idx){
    int r, c, s, tmp[51][51];
    tie(r, c, s) = op[idx];
    memcpy(tmp, a, sizeof(a));
    for(int k=0;;k++){
        if(r-s+k == r+s-k) break;
        for(int i=c-s+k;i<c+s-k;i++) tmp[r-s+k][i+1] = a[r-s+k][i];
        for(int i=r-s+k;i<r+s-k;i++) tmp[i+1][c+s-k] = a[i][c+s-k];
        for(int i=c+s-k;i>c-s+k;i--) tmp[r+s-k][i-1] = a[r+s-k][i];
        for(int i=r+s-k;i>r-s+k;i--) tmp[i-1][c-s+k] = a[i][c-s+k];
    }
    memcpy(a, tmp, sizeof(tmp));
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin >> a[i][j];
    }
    for(int i=0;i<k;i++){
        int r, c, s;
        cin >> r >> c >> s;
        op.push_back({r, c, s});
        order.push_back(i);
    }
    int tmp[51][51], ans = 987654321;
    memcpy(tmp, a, sizeof(a));
    do{
        memcpy(a, tmp, sizeof(tmp));
        for(auto i : order){
            rotate(i);
        }
        int res = 987654321;
        for(int i=1;i<=n;i++){
            int sum = 0;
            for(int j=1;j<=m;j++){
                sum += a[i][j];
            }
            res = min(res, sum);
        }
        ans = min(ans, res);
    } while (next_permutation(order.begin(), order.end()));
    cout << ans;
}