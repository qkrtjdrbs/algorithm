#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n, m, s, e, visited[MAX], visited2[MAX];
vector<int> line[MAX], station[MAX];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x;
        while(cin >> x && x != -1){
            line[i].push_back(x);
            station[x].push_back(i);
        }
    }
    cin >> s >> e;
    memset(visited2, -1, sizeof(visited2));
    queue<int> q;
    visited[s] = 1;
    for(auto l : station[s]){
        q.push(l);
        visited2[l] = 0;
    }
    while(!q.empty()){
        int l = q.front();
        q.pop();
        for(auto nextS : line[l]){
            if(visited[nextS]) continue;
            visited[nextS] = 1;
            for(auto nextL : station[nextS]){
                if(visited2[nextL] != -1) continue;
                q.push(nextL);
                visited2[nextL] = visited2[l] + 1;
            }
        }
    }
    int ans = 987654321;
    for(auto l : station[e]){
        if(visited2[l] == -1) continue;
        ans = min(ans, visited2[l]);
    }
    cout << (ans == 987654321 ? -1 : ans);
}