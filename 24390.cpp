#include <bits/stdc++.h>
using namespace std;

int n, ans;
bool visited[4001];

int bfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0] = 1;
    while(!q.empty()){
        auto [cur, cnt] = q.front();
        q.pop();
        if(cur == n){
            return cnt+1;
        }
        if(cur+10 <= n && !visited[cur+10]){
            q.push({cur+10, cnt+1});
            visited[cur+10] = 1;
        }
        if(cur+60 <= n && !visited[cur+60]){
            q.push({cur+60, cnt+1});
            visited[cur+60] = 1;
        }
        if(cur+600 <= n && !visited[cur+600]){
            q.push({cur+600, cnt+1});
            visited[cur+600] = 1;
        }
        if(cur+30 <= n && !visited[cur+30]){
            q.push({cur+30, cnt});
            visited[cur+30] = 1;
        }
    }
    return -1;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    string str;
    int m, s;
    cin >> str;
    sscanf(str.c_str(), "%d:%d", &m, &s);
    n = 60*m + s;
    cout << bfs();
}