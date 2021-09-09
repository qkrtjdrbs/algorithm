#include <bits/stdc++.h>
using namespace std;

string n;
int k, len, ans=-1;
bool visited[1000001][11];

void bfs(){
    queue<pair<string, int>> q;
    q.push({n, 0});
    visited[stoi(n)][0] = 1;
    while(!q.empty()){
        string cur; int cnt;
        tie(cur, cnt) = q.front();
        q.pop();
        if(cnt == k){
            ans = max(ans, stoi(cur));
            continue;
        }
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(i == 0 && cur[j] == '0') continue;
                string next = cur;
                char tmp = next[i];
                next[i] = next[j];
                next[j] = tmp;
                if(!visited[stoi(next)][cnt+1]) {
                    visited[stoi(next)][cnt+1] = 1;
                    q.push({next, cnt+1});
                }
            }
        }
    }
    cout << ans;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    len = n.size();
    bfs();
}