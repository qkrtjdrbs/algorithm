#include <bits/stdc++.h>
using namespace std;

int Map[4][4];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
set<string> s;

bool check(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i == 2 && j == 2) break;
            int idx = i*3 + j+1;
            if(idx != Map[i][j]) return false;
        }
    }
    return true;
}

string visited(){
    string x = "";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            x += (Map[i][j]+'0');
        }
    }
    return x;
}

void go(){
    if(!Map[2][2]){
        if(check()){
            cout << 0;
            return;
        }
    }
    queue<pair<string, int>> q;
    q.push({visited(), 0});
    s.insert(visited());
    while(!q.empty()){
        string cur; int cnt;
        tie(cur, cnt) = q.front();
        q.pop();
        if(cur == "123456780"){
            cout << cnt;
            return;
        }
        int idx = cur.find("0");
        int x = idx / 3, y = idx % 3;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            int ni = nx * 3 + ny;
            swap(cur[idx], cur[ni]);
            if(s.find(cur) == s.end()){
                q.push({cur, cnt+1});
                s.insert(cur);
            }
            swap(cur[idx], cur[ni]);
        }
    }
    cout << -1;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> Map[i][j];
        }
    }
    go();
}