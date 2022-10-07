#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int m, s, sx, sy, fish[5][5][9], smell[5][5], maxEats;
int sdx[] = {0,-1,0,1,0};
int sdy[] = {0,0,-1,0,1};
int fdx[] = {0,0,-1,-1,-1,0,1,1,1};
int fdy[] = {0,-1,-1,0,1,1,1,0,-1};
bool visited[5][5];
set<string> st;

int fishMoveDir(int x, int y, int d){
    int tmp = d;
    bool flag = false;
    while(1){
        if(flag && tmp == d) return -1;
        int nx = x + fdx[d];
        int ny = y + fdy[d];
        if(nx <= 0 || nx > 4 || ny <= 0 || ny > 4 || smell[nx][ny] || (sx == nx && sy == ny)){
            d = d == 1 ? 8 : d-1;
            flag = true; 
        } else {
            return d;
        }
    }
    return -1;
}

void fishMove(){
    int tmp[5][5][9];
    memset(tmp, 0, sizeof(tmp));

    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            for(int k=1;k<=8;k++){
                if(fish[i][j][k]){
                    int nd = fishMoveDir(i, j, k);
                    if(nd == -1){
                        tmp[i][j][k] += fish[i][j][k];
                    } else {
                        int nx = i + fdx[nd];
                        int ny = j + fdy[nd];
                        tmp[nx][ny][nd] += fish[i][j][k];
                    }
                }
            }
        }
    }

    memcpy(fish, tmp, sizeof(tmp));
}

int fishSum(int x, int y){
    int sum = 0;
    for(int k=1;k<=8;k++){
        sum += fish[x][y][k];
    }
    return sum;
}

void fishErase(int x, int y){
    for(int k=1;k<=8;k++){
        fish[x][y][k] = 0;
    }
}

bool fishExists(int x, int y){
    for(int k=1;k<=8;k++){
        if(fish[x][y][k]) return true;
    }
    return false;
}

void sharkMove(int x, int y, int cnt, int eats, string str){
    if(cnt == 3){
        if(eats > maxEats){
            st.clear();
            maxEats = eats;
            st.insert(str);
        } else if(eats == maxEats){
            st.insert(str);
        }
        return;
    }
    for(int i=1;i<=4;i++){
        int nx = x + sdx[i];
        int ny = y + sdy[i];
        char nd = i + '0';
        if(nx <= 0 || nx > 4 || ny <= 0 || ny > 4) continue;
        if(!visited[nx][ny]){
            visited[nx][ny] = 1;
            sharkMove(nx, ny, cnt+1, eats+fishSum(nx, ny), str+nd);
            visited[nx][ny] = 0;
        } else {
            sharkMove(nx, ny, cnt+1, eats, str+nd);
        }
    }
}

void smellErase(int turn){
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(smell[i][j] == turn-2) smell[i][j] = 0;
        }
    }
}

void magic(int turn){
    int copied[5][5][9];
    memcpy(copied, fish, sizeof(fish));

    fishMove();

    maxEats = 0;
    st.clear();
    sharkMove(sx, sy, 0, 0, "");
    string res = *st.begin();
    for(int i=0;i<3;i++){
        sx += sdx[res[i]-'0'];
        sy += sdy[res[i]-'0'];
        if(fishExists(sx, sy)){
            fishErase(sx, sy);
            smell[sx][sy] = turn;
        }
    }

    smellErase(turn);
    
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            for(int k=1;k<=8;k++){
                fish[i][j][k] += copied[i][j][k];
            }
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> m >> s;
    for(int i=0;i<m;i++){
        int x, y, z;
        cin >> x >> y >> z;
        fish[x][y][z]++;
    }
    cin >> sx >> sy;
    for(int i=1;i<=s;i++){
        magic(i);
    }
    int ans = 0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            ans += fishSum(i, j);
        }
    }
    cout << ans;
}