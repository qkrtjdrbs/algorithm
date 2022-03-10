#include <bits/stdc++.h>
using namespace std;

int n, Map[21][21];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool check(int x, int y, int d1, int d2){
    return x+d1+d2 <= n && 1 <= y-d1 && y-d1 < y && y < y+d2 && y+d2 <= n;
}

int go(int x, int y, int d1, int d2){
    int cnt[6] = {0,}, visited[21][21];
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<=d1;i++) visited[x+i][y-i] = 5;
    for(int i=0;i<=d2;i++) visited[x+i][y+i] = 5;
    for(int i=0;i<=d2;i++) visited[x+d1+i][y-d1+i] = 5;
    for(int i=0;i<=d1;i++) visited[x+d2+i][y+d2-i] = 5;

    for(int i=x+1;i<x+d1+d2;i++){
        for(int j=1;j<=n;j++){
            if(visited[i][j] == 5){
                for(int k=j+1;;k++){
                    if(visited[i][k] == 5) break;
                    visited[i][k] = 5;
                }
                break;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(visited[i][j] == 5) cnt[5] += Map[i][j];
            else if(1 <= i && i < x+d1 && 1 <= j && j <= y) cnt[1] += Map[i][j];
            else if(1 <= i && i <= x+d2 && y < j && j <= n) cnt[2] += Map[i][j];
            else if(x+d1 <= i && i <= n && 1 <= j && j < y-d1+d2) cnt[3] += Map[i][j];
            else if(x+d2 < i && i <= n && y-d1+d2 <= j && j <= n) cnt[4] += Map[i][j];
        }
    }
    int mx = *max_element(cnt+1, cnt+6);
    int mn = *min_element(cnt+1, cnt+6);
    return mx - mn;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> Map[i][j];
        }
    }
    int ans = 987654321;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int d1=1;d1<n;d1++){
                for(int d2=1;d2<n;d2++){
                    if(check(i, j, d1, d2)){
                        ans = min(ans, go(i, j, d1, d2));
                    }
                }
            }
        }
    }
    cout << ans;
}