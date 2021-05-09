#include <bits/stdc++.h>
using namespace std;
int n, weight[501], d[501], result[501];
vector<int> adj[501];

void go(){
    queue<int> q;
    for(int i=0;i<n;i++){
        if(d[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto next : adj[cur]){
            result[next] = max(result[cur]+weight[cur], result[next]);
            if(--d[next] == 0){
                q.push(next);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> weight[i];
        while(1){
            int x;
            cin >> x;
            if(x == -1) break;
            adj[x-1].push_back(i);
            ++d[i];
        }
    }
    go();
    for(int i=0;i<n;i++){
        cout << result[i] + weight[i] << '\n';
    }
}
