#include <bits/stdc++.h>
using namespace std;
int t, inDegree[1001], cnt[1001];
vector<int> edge[1001];
vector<int> order[1001];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        int k, m, p;
        cin >> k >> m >> p;
        for(int i=0;i<p;i++){
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            ++inDegree[b];
        }
        queue<int> q;
        for(int i=1;i<=m;i++){
            if(inDegree[i] == 0){
                cnt[i] = 1;
                q.push(i);
            }
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto next : edge[cur]){
                --inDegree[next];
                order[next].push_back(cnt[cur]);
                if(inDegree[next] == 0){
                    q.push(next);
                    int maxOrder = 0, count = 0;
                    for(auto X : order[next]){
                        maxOrder = max(maxOrder, X);
                    }
                    for(auto X : order[next]){
                        if(X == maxOrder){
                            ++count;
                        }
                    }
                    count <= 1 ? cnt[next] = maxOrder : cnt[next] = maxOrder + 1;
                }
            }
        }
        int maxOrder = 1;
        for(int i=1;i<=m;i++){
            maxOrder = max(maxOrder, cnt[i]);
        }
        cout << k << " " << maxOrder << '\n';
        for(int i=1;i<=m;i++){
            edge[i].clear();
            order[i].clear();
            inDegree[i] = 0;
            cnt[i] = 0;
        }
    }
}