#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;

int n, m, t, k, Map[101][101], friends[101];

void init(){
    memset(friends, 0, sizeof(friends));
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(i != j) Map[i][j] = MAX;
            else Map[i][j] = 0;
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        init();
        cin >> n >> m;
        for(int i=0;i<m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            Map[a][b] = Map[b][a] = c;
        }
        cin >> k;
        for(int i=0;i<k;i++) cin >> friends[i];
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
                }
            }
        }
        int ans = MAX, num = n;
        for(int i=1;i<=n;i++){
            int res = 0;
            for(int j=0;j<k;j++){
                res += Map[friends[j]][i];
            }
            if(res < ans){
                ans = res;
                num = i;
            }
        }
        cout << num << '\n';
    }
}