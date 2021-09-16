#include <bits/stdc++.h>
using namespace std;
int n, m, ans=987654321;
vector<pair<int, int>> chick, home;
bool v[14];

void dfs(int idx, int selected){
    if(idx > chick.size())
        return;
    if(selected == m){
        int result = 0;
        for(int i=0;i<home.size();i++){ 
            int homeX, homeY, dist=987654321;
            tie(homeX, homeY) = home[i];
            for(int j=0;j<chick.size();j++){
                if(v[j]){
                    int chickX, chickY;
                    tie(chickX, chickY) = chick[j];
                    dist = min(dist, abs(chickX-homeX)+abs(chickY-homeY));
                }
            }
            result += dist;
        }
        ans = min(result, ans);
        return;
    }
    v[idx] = 1;
    dfs(idx+1, selected+1);
    v[idx] = 0;
    dfs(idx+1, selected);
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int city;
            cin >> city;
            if(city == 1)
                home.push_back({i, j});
            if(city == 2)
                chick.push_back({i, j});
        }
    }
    dfs(0, 0);
    cout << ans;
}