#include <bits/stdc++.h>
using namespace std;

int t, g, n, ans;
bool visited[100001];

bool bfs(){
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = 1;
    while(!q.empty()){
        int cur, cnt;
        tie(cur, cnt) = q.front();
        q.pop();
        if(cnt > t) return false;
        if(cur == g) {
            ans = cnt;
            return true;
        }
        // A
        if(!visited[cur+1] && cur+1 <= 99999){
            visited[cur+1] = 1;
            q.push({cur+1, cnt+1});
        }
        // B
        int t = cur * 2;
        if(t > 99999) continue;
        string tmp = to_string(t);
        int fir = stoi(tmp.substr(0, 1)) - 1;
        if(fir == -1) continue;
        char x = fir + '0';
        string res = x + tmp.substr(1, tmp.size()-1);
        int next = stoi(res);
        if(!visited[next] && next <= 99999){
            visited[next] = 1;
            q.push({next, cnt+1});
        }
    }
    return false;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> t >> g;
    bfs() ? cout << ans : cout << "ANG";
}