#include <bits/stdc++.h>
#define MAX 401
using namespace std;
int n, e, Map[MAX][MAX];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> e;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) Map[i][j] = 0;
            else Map[i][j] = 987654321;
        }
    }
    for(int i=0;i<e;i++){
        int a, b, c;
        cin >> a >> b >> c;
        Map[a][b] = c;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(Map[i][j] > Map[i][k] + Map[k][j]){
                    Map[i][j] = Map[i][k] + Map[k][j];
                }
            }
        }
    }
    int ans = 987654321;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(i == k) continue;
            ans = min(ans, Map[i][k] + Map[k][i]);
        }
    }
    if(ans == 987654321) ans = -1;
    cout << ans;
}