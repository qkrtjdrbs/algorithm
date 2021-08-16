#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;
long long n, m, dist[501];
vector<pair<int, int>> v[501];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=2;i<=n;i++){
        dist[i] = MAX;
    }
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    for(int numberOfTimes=1;numberOfTimes<=n;numberOfTimes++){
        for(int i=1;i<=n;i++){
            for(int j=0;j<v[i].size();j++){
                int next, cost;
                tie(next, cost) = v[i][j];
                if(dist[i] != MAX && dist[next] > dist[i] + cost){
                    dist[next] = dist[i] + cost;
                    if(numberOfTimes == n) {
                        cout << -1;
                        return 0;
                    }
                }
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(dist[i] == MAX) cout << -1;
        else cout << dist[i];
        cout << '\n';
    }
}