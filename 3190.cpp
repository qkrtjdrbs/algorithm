#include <bits/stdc++.h>
using namespace std;
int n, k, l, dummy[101][101];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
deque<pair<int, char>> dir;
deque<pair<int, int>> snake;

void go(int x, int y, int dirIdx, int t){
    if(x < 1 || x > n || y < 1 || y > n || dummy[x][y] == 8){
        cout << t;
        return;
    }
    if(dummy[x][y] == 0){
        if(!snake.empty()){  
            int backX, backY;
            tie(backX, backY) = snake.back();
            dummy[backX][backY] = 0;
            snake.pop_back();
        }
    }
    dummy[x][y] = 8;
    snake.push_front({x, y});
    int sec; char d;
    tie(sec, d) = dir.front();
    if(sec == t){
        int dirI;
        dir.pop_front();
        if(d == 'L'){
            dirI = dirIdx == 3 ? 0 : dirIdx + 1;
        } else if(d == 'D'){
            dirI = dirIdx == 0 ? 3 : dirIdx - 1; 
        }
        go(x+dx[dirI], y+dy[dirI], dirI, t+1);   
    } else
        go(x+dx[dirIdx], y+dy[dirIdx], dirIdx, t+1);    
}

int main(){
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int x, y;
        cin >> x >> y;
        dummy[x][y] = 1;
    }
    cin >> l;
    for(int i=0;i<l;i++){
        int sec;
        char d;
        cin >> sec >> d;
        dir.push_back({sec, d});
    }
    go(1, 1, 0, 0);
}
