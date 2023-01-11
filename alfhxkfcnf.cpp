#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};

string bfs(int sx, int sy, int ex, int ey){
    bool visited[51][51];
    memset(visited, 0, sizeof(visited));
    queue<tuple<int, int, string>> q;
    q.push({sx, sy, ""});
    visited[sx][sy] = 1;
    while(!q.empty()){
        auto [x, y, route] = q.front();
        q.pop();
        if(x == ex && y == ey){
            return route;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            string nr = route;
            if(nx <= 0 || nx > n || ny <= 0 || ny > m || visited[nx][ny]) continue;
            if(i == 0) nr += "d";
            else if(i == 1) nr += "l";
            else if(i == 2) nr += "r";
            else nr += "u";

            q.push({nx, ny, nr});
            visited[nx][ny] = 1;
        }
    }
    return "X";
}

string dfs(int x, int y, int ex, int ey, int k, int cnt){
    string res = "";
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
        if(i == 0) res += "d";
        else if(i == 1) res += "l";
        else if(i == 2) res += "r";
        else res += "u";

        if(abs(ex-nx) + abs(ey-ny) + cnt+1 == k) res += bfs(nx, ny, ex, ey);
        else res += dfs(nx, ny, ex, ey, k, cnt+1);
        break;
    }
    return res;
}

string solution(int nn, int mm, int x, int y, int r, int c, int k) {
    n = nn;
    m = mm;
    int res = abs(r-x) + abs(c-y);
    if((res%2 != k%2) || (res > k)){
        return "impossible";
    }

    string ans = dfs(x, y, r, c, k, 0);
    return ans;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cout << solution(3, 4, 2, 3, 3, 1, 5) << '\n';
    cout << solution(2, 2, 1, 1, 2, 2, 2) << '\n';
    cout << solution(3, 3, 1, 2, 3, 3, 4) << '\n';
}