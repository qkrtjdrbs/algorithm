#include <bits/stdc++.h>
using namespace std;

int n, m, t, dist[1001][1001];
pair<int, int> city[1001];
bool sp[1001];

int calCost(int from, int to){
    return abs(city[from].first - city[to].first) + abs(city[from].second - city[to].second);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> t;
    for(int i=1;i<=n;i++){
        int s, x, y;
        cin >> s >> x >> y;
        sp[i] = s;
        city[i] = {x, y};
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            if(sp[i] && sp[j]) dist[i][j] = dist[j][i] = min(t, calCost(i, j));
            else dist[i][j] = dist[j][i] = calCost(i, j);
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == j) continue;
                if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        cout << dist[a][b] << '\n';
    }
}