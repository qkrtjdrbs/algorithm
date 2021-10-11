#include <bits/stdc++.h>
using namespace std;

int n, m, ans, visited[1001][1001];
char Map[1001][1001];

int go(int x, int y, int cnt){
    int &res = visited[x][y];
    if(res != 0) return res;
    res = cnt;
    int nx = x, ny = y;
    if(Map[x][y] == 'U') nx--;
    else if(Map[x][y] == 'D') nx++; 
    else if(Map[x][y] == 'R') ny++;
    else ny--;
    res = go(nx, ny, cnt);
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> Map[i][j];
    }
    int cnt = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                go(i, j, cnt);
                cnt++;
            }
        }
    }
    set<int> s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            s.insert(visited[i][j]);
        }
    }
    cout << s.size();
}