#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;

int n, m, t, Map[251][251];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) Map[i][j] = 0;
            else Map[i][j] = MAX;
        }
    }
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(c){
            Map[a][b] = Map[b][a] = 0;
        } else {
            Map[a][b] = 0;
            Map[b][a] = 1;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                Map[i][j] = min(Map[i][j], Map[i][k]+Map[k][j]);
            }
        }
    }
    cin >> t;
    for(int i=0;i<t;i++){
        int a, b;
        cin >> a >> b;
        cout << Map[a][b] << '\n';
    }
}