#include <bits/stdc++.h>
using namespace std;
const int MAX_ROW = 12;
const int MAX_COL = 6;
int res, ans, v[MAX_ROW][MAX_COL];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
string s[MAX_ROW];

void isDelete(int x, int y, int cnt, char p){
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= MAX_ROW || ny < 0 || ny >= MAX_COL || v[nx][ny] || s[nx][ny] != p) continue;
        v[nx][ny] = v[x][y] + 1;
        res++;
        isDelete(nx, ny, cnt+1, p);
    }
}

void Delete(int x, int y, char p){
    s[x][y] = '.';
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= MAX_ROW || ny < 0 || ny >= MAX_COL || v[nx][ny] || s[nx][ny] != p) continue;
        v[nx][ny] = v[x][y] + 1;
        Delete(nx, ny, p);
    }
}

void Gravity(int x, int y){
    int nx = x+1;
    if(nx >= MAX_ROW) return;
    if(s[nx][y] == '.') {
        swap(s[nx][y], s[x][y]);
        Gravity(nx, y);
    }
}

void Puyo(){
    for(int col=0;col<MAX_COL;col++){
        for(int row=MAX_ROW-2;row>=0;row--){
            int nr = row+1;
            if(s[row][col] != '.') Gravity(row, col);
        }
    }
}

void init(){
    for(int row=0;row<MAX_ROW;row++){
        for(int col=0;col<MAX_COL;col++){
            v[row][col] = 0;       
        }
    }
}

int main(){
    for(int i=0;i<MAX_ROW;i++){
        cin >> s[i];
    }
    while(1){
        queue<pair<int, int>> list;
        for(int row=0;row<MAX_ROW;row++){
            for(int col=0;col<MAX_COL;col++){
                if(!v[row][col] && s[row][col] != '.'){
                    res = 1;
                    v[row][col] = 1;
                    isDelete(row, col, 1, s[row][col]);
                    if(res >= 4){
                        list.push({row, col});
                    }
                }
            }
        }
        init();
        if(list.empty()){
            cout << ans;
            break;
        }
        while(!list.empty()){
            int x, y;
            tie(x, y) = list.front();
            list.pop();
            v[x][y] = 1;
            Delete(x, y, s[x][y]);
        }
        Puyo();
        init();
        ans++;
    }
}