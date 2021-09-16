#include <bits/stdc++.h>
using namespace std;
int n, m, Map[101][101];
vector<int> adj[101][101];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i != j) {
                Map[i][j] = 987654321;
            }
            adj[i][j].push_back(i);
            adj[i][j].push_back(j);
        }
    }
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(Map[a][b] > c){
            Map[a][b] = c;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(Map[i][j] > Map[i][k] + Map[k][j]){
                    Map[i][j] = Map[i][k] + Map[k][j];
                    adj[i][j].clear();
                    for(auto x : adj[i][k]) adj[i][j].push_back(x);
                    for(int x=1;x<adj[k][j].size();x++) adj[i][j].push_back(adj[k][j][x]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(Map[i][j] == 987654321) Map[i][j] = 0;
            cout << Map[i][j] << " "; 
        }
        cout << '\n';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!Map[i][j]){
                cout << 0 << " ";
            } else {
                cout << adj[i][j].size() << " ";
                for(auto x : adj[i][j]){
                    cout << x << " ";
                }
            }
            cout << '\n';
        }
    }
}