#include <bits/stdc++.h>
using namespace std;

int n, m, wx, wy;
char Map[20][20];
string cmds;

bool boxCanMove(int x, int y){
    return Map[x][y] != '#' && Map[x][y] != 'B' && Map[x][y] != 'b';
}

void move(int x, int y, int nx, int ny, char cmd, int flag){
    if(Map[nx][ny] == '.'){
        if(Map[x][y] == 'w' || Map[x][y] == 'b') Map[x][y] = '.';
        else if(Map[x][y] == 'W' || Map[x][y] == 'B') Map[x][y] = '+';
        if(!flag) Map[nx][ny] = 'w';
        else Map[nx][ny] = 'b';
        if(!flag){
            wx = nx; wy = ny;
        }
    } else if(Map[nx][ny] == '+'){
        if(Map[x][y] == 'w' || Map[x][y] == 'b') Map[x][y] = '.';
        else if(Map[x][y] == 'W' || Map[x][y] == 'B') Map[x][y] = '+';
        if(!flag) Map[nx][ny] = 'W';
        else Map[nx][ny] = 'B';
        if(!flag){
            wx = nx; wy = ny;
        }
    } else if(Map[nx][ny] == 'b' && !flag){
        int nnx=nx, nny=ny;
        if(cmd == 'U') nnx--;
        else if(cmd == 'D') nnx++;
        else if(cmd == 'L') nny--;
        else nny++;
        if(boxCanMove(nnx, nny)){
            move(nx, ny, nnx, nny, cmd, 1);
            wx = nx; wy = ny;
            if(Map[x][y] == 'w') Map[x][y] = '.';
            else if(Map[x][y] == 'W') Map[x][y] = '+';
            Map[wx][wy] = 'w';
        }
    } else if(Map[nx][ny] == 'B' && !flag){
        int nnx=nx, nny=ny;
        if(cmd == 'U') nnx--;
        else if(cmd == 'D') nnx++;
        else if(cmd == 'L') nny--;
        else nny++;
        if(boxCanMove(nnx, nny)){
            move(nx, ny, nnx, nny, cmd, 1);
            wx = nx; wy = ny;
            if(Map[x][y] == 'w') Map[x][y] = '.';
            else if(Map[x][y] == 'W') Map[x][y] = '+';
            Map[wx][wy] = 'W';
        }
    }
}

bool isEnd(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] == 'b' || Map[i][j] == '+'){
                return false;
            }
        } 
    }
    return true;
}

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << Map[i][j];
        } 
        cout << '\n';
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    for(int t=1;;t++){
        bool flag = false;
        cin >> n >> m;
        if(!n && !m) break;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> Map[i][j];
                if(Map[i][j] == 'w' || Map[i][j] == 'W'){
                    wx = i; wy = j;
                }
            } 
        }
        cin >> cmds;
        for(auto cmd : cmds){
            int nx=wx, ny=wy;
            if(cmd == 'U') nx--;
            else if(cmd == 'D') nx++;
            else if(cmd == 'L') ny--;
            else ny++;
            move(wx, wy, nx, ny, cmd, 0);
            if(isEnd()){
                flag = true;
                cout << "Game " << t << ": " << "complete" << '\n';
                print();
                break;
            }
        }
        if(!flag){
            cout << "Game " << t << ": " << "incomplete" << '\n';
            print();
        }
    }
}