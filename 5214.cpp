#include <bits/stdc++.h>
using namespace std;

int n, k, m, visited[1001], visited2[100001];
vector<int> tube[1001], station[100001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k >> m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=k;j++){
            int x; cin >> x;
            tube[i].push_back(x);
            station[x].push_back(i);
        }
    }
    queue<int> q;
    q.push(1);
    visited2[1] = 1;
    while(!q.empty()){
        int st = q.front();
        q.pop();
        for(auto nextT : station[st]){
            if(!visited[nextT]){
                visited[nextT] = 1;
                for(auto nextS : tube[nextT]){
                    if(!visited2[nextS]){
                        q.push(nextS);
                        visited2[nextS] = visited2[st] + 1;
                    }
                }
            }
        }
    }
    cout << (visited2[n] == 0 ? -1 : visited2[n]);
}