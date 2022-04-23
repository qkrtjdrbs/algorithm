#include <bits/stdc++.h>
using namespace std;

int Map[21][21];
int dx[] = {0,0,-1,1,1,1,-1,-1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

pair<int, int> omok(int x, int y, int dir1, int dir2){
    // 가로, 세로
    priority_queue<pair<int, int>> pq, clear;
    pq.push({-y, -x});

    for(int i=1;;i++){
        int nx = x + dx[dir1]*i;
        int ny = y + dy[dir1]*i;
        if(nx < 0 || nx >= 19 || ny < 0 || ny >= 19) break;
        if(Map[nx][ny] != Map[x][y]) break;
        pq.push({-ny, -nx});
    }
    for(int i=1;;i++){
        int nx = x + dx[dir2]*i;
        int ny = y + dy[dir2]*i;
        if(nx < 0 || nx >= 19 || ny < 0 || ny >= 19) break;
        if(Map[nx][ny] != Map[x][y]) break;
        pq.push({-ny, -nx});
    }
    
    if(pq.size() == 5){
        return {-pq.top().second, -pq.top().first};
    }
    return {-1, -1};
}

tuple<int, int, int> check(int x, int y){
    
    auto [xx, yy] = omok(x, y, 0, 1);
    if(xx != -1){
        return {Map[x][y], xx, yy};
    }
    tie(xx, yy) = omok(x, y, 2, 3);
    if(xx != -1){
        return {Map[x][y], xx, yy};
    }
    tie(xx, yy) = omok(x, y, 4, 7);
    if(xx != -1){
        return {Map[x][y], xx, yy};
    }
    tie(xx, yy) = omok(x, y, 5, 6);
    if(xx != -1){
        return {Map[x][y], xx, yy};
    }
    return {-1, -1, -1};
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            cin >> Map[i][j];
        }
    }
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            if(Map[i][j]){
                auto [f, x, y] = check(i, j);
                if(f > 0){
                    cout << f << '\n';
                    cout << x+1 << ' ' << y+1;
                    return 0;
                }
            }
        }
    }
    cout << 0;
}