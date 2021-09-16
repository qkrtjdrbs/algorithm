#include <bits/stdc++.h>
using namespace std;
int n, Visit[11], people[11], ans=987654321;
vector<int> adj[11];

bool isConnected(vector<int> region){
    int tmp[11] = {0,};
    queue<int> q;
    q.push({region[0]});
    tmp[region[0]] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto next : adj[x]){
            if(!tmp[next] && Visit[next] == Visit[region[0]]){
                tmp[next] = 1;
                q.push(next);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(Visit[i] == Visit[region[0]] && !tmp[i]) return false;
    }
    return true;
}

int sum(vector<int> region){
    int res = 0;
    for(auto i : region){
        res += people[i];
    }
    return res;
}

void cal(){
    vector<int> blue, red;   
    for(int i=1;i<=n;i++){
        if(Visit[i]) blue.push_back(i);
        else red.push_back(i);
    }
    if(isConnected(blue) && isConnected(red)){
        ans = min(ans, abs(sum(blue) - sum(red)));
    }
}

void dfs(int start, int cnt, int selected){
    if(cnt == selected){
        cal();
        return;
    }
    for(int i=start;i<=n;i++){
        if(!Visit[i]){
            Visit[i] = 1;
            dfs(i+1, cnt, selected+1);
            Visit[i] = 0;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int p;
        cin >> p;
        people[i] = p;
    }
    for(int i=1;i<=n;i++){
        int m;
        cin >> m;
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }
    for(int cnt=1;cnt<=n/2;cnt++){
        dfs(1, cnt, 0);
    }
    ans == 987654321 ? cout << -1 : cout << ans;
}