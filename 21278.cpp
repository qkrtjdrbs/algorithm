#include <bits/stdc++.h>
using namespace std;
int n, m, Visit[101], sum=987654321, ans1, ans2;
vector<int> adj[101];

int bfs(int start){
    if(Visit[start] == -1) return 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto i : adj[x]){
            if(Visit[i] == -1){
                return Visit[x] + 1;
            } else if(Visit[i] == 0){
                Visit[i] = Visit[x] + 1;
                q.push(i);
            }
        }
    }
    return -1;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        Visit[i] = -1;
        for(int j=i+1;j<=n;j++){
            Visit[j] = -1;
            int tmpSum = 0;
            for(int k=1;k<=n;k++){
                tmpSum += bfs(k);
                for(int h=1;h<=n;h++){
                    if(Visit[h] != -1)
                        Visit[h] = 0;
                }
            }
            Visit[j] = 0;
            if(sum > tmpSum){
                sum = tmpSum;
                ans1 = i; ans2 = j;
            } else if(sum == tmpSum){
                int tmpSmall = min(i, j);
                int ansSmall = min(ans1, ans2);
                tmpSmall < ansSmall ? ans1 = i, ans2 = j : 1;
                if(tmpSmall == ansSmall){
                    int tmpBig = max(i, j);
                    int ansBig = max(ans1, ans2);
                    ansBig > tmpBig ? ans1 = i, ans2 = j : 1;
                }
            }
        }
        Visit[i] = 0;
    }
    cout << ans1 << " " << ans2 << " " << sum*2;
}