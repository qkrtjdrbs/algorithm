#include <bits/stdc++.h>
#define SHARK 17
using namespace std;

typedef struct info {
    int x, y, d;
}Fish;

pair<int,int> Map[5][5];
Fish fish[18];

int dx[] = {0,-1,-1,0,1,1,1,0,-1};
int dy[] = {0,0,-1,-1,-1,0,1,1,1};
int dead[17], ans;

void fishMove(int idx){
    int x = fish[idx].x, y = fish[idx].y, d = fish[idx].d;
    int nx = x + dx[d];
    int ny = y + dy[d];
    int round = d;
    bool isMove = true;
    while(nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || Map[nx][ny].first == SHARK){
        if(d < 8) d += 1;
        else d = 1;
        if(d == round){
            isMove = false;
            break;
        }
        nx = x + dx[d];
        ny = y + dy[d];
    }
    if(isMove){
        fish[idx].d = d;
        Map[x][y].second = d;

        if(Map[nx][ny].first != -1){
            swap(fish[idx], fish[Map[nx][ny].first]);
            int tmp = fish[idx].d;
            fish[idx].d = fish[Map[nx][ny].first].d;
            fish[Map[nx][ny].first].d = tmp;
        } else {
            fish[idx] = {nx, ny, d};
            
        }
        swap(Map[x][y], Map[nx][ny]);
    }
}

int sharkMove(int x, int y, int d, vector<int> &edible){
    for(int i=1;i<=3;i++){
        int nx = x + dx[d] * i;
        int ny = y + dy[d] * i;
        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;
        if(Map[nx][ny].first == -1) continue;
        
        edible.push_back(Map[nx][ny].first);      
    }
    if(edible.size() == 0){
        return 0;
    }
    return 1;
}

void go(int x, int y, int d, int sum){
    ans = max(ans, sum);
    pair<int,int> tmp[5][5];
    Fish t[18];   

    for(int i=1;i<=16;i++){
        if(!dead[i])
            fishMove(i);
    }
    Map[x][y] = {-1, -1};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            tmp[i][j] = Map[i][j];
        }
    }
    for(int i=1;i<=17;i++){
        t[i] = fish[i];
    }

    vector<int> edible;
    if(!sharkMove(x, y, d, edible)) return;
    else {
        for(auto Fish : edible){
            dead[Fish] = 1;
            Map[fish[Fish].x][fish[Fish].y] = { SHARK, fish[Fish].d };
            
            go(fish[Fish].x, fish[Fish].y, fish[Fish].d, sum+Fish);

            dead[Fish] = 0;
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    Map[i][j] = tmp[i][j];
                }
            }
            for(int i=1;i<=17;i++){
                fish[i] = t[i];
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int num, dir;
            cin >> num >> dir;
            Map[i][j] = {num, dir};
            fish[num] = {i, j, dir};
        }
    }
    ans += Map[0][0].first;
    dead[Map[0][0].first] = 1;
    fish[SHARK] = {0, 0, Map[0][0].second};
    Map[0][0].first = SHARK;
    
    go(0, 0, Map[0][0].second, ans);

    cout << ans;
}