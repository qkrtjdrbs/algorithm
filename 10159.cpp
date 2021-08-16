#include <bits/stdc++.h>
using namespace std;
int n, m, arr[101][101];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][k] && arr[k][j]) arr[i][j] = 1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            if(arr[i][j] || arr[j][i]) continue;
            cnt++;
        }
        cout << cnt << '\n';
    }
}