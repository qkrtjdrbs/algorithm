#include <bits/stdc++.h>
using namespace std;

int n, m, Map[705][705];
vector<pair<int, int>> pos;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=n-1;i>=0;i--){
        pos.push_back({i, 0});
    }
    for(int i=1;i<n;i++){
        pos.push_back({0, i});
    }
    pos.push_back({n+1, n+1});
    for(int k=0;k<m;k++){
        int one, two, three;
        cin >> one >> two >> three;
        int idx1 = 0;
        int idx2 = one;
        int idx3 = one + two;
        if(one){
            Map[pos[idx1].first][pos[idx1].second] += 0;
            Map[pos[idx2].first][pos[idx2].second] -= 0;
        }
        if(two){
            Map[pos[idx2].first][pos[idx2].second] += 1;
            Map[pos[idx3].first][pos[idx3].second] -= 1;
        }
        if(three){
            Map[pos[idx3].first][pos[idx3].second] += 2;
        }
    }
    for(int i=n-1;i>=0;i--){
        Map[i][0] += Map[i+1][0];
    }
    for(int i=1;i<n;i++){
        Map[0][i] += Map[0][i-1];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            Map[i][j] = max({Map[i-1][j-1], Map[i][j-1], Map[i-1][j]});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << Map[i][j]+1 << " ";
        }
        cout << '\n';
    }
}