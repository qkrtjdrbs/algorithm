#include <bits/stdc++.h>
using namespace std;

int n, m;
bool bead[100][100];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        bead[b][a] = 1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == k || j == k) continue;
                if(bead[i][k] && bead[k][j]) bead[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        int cnt1 = 0, cnt2 = 0;
        for(int j=1;j<=n;j++){
            if(bead[i][j]) cnt1++;
            else if(bead[j][i]) cnt2++;
        }
        if(cnt1 >= (n+1)/2 || cnt2 >= (n+1)/2) ans++;
    }
    cout << ans;
}