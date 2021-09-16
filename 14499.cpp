#include <bits/stdc++.h>
using namespace std;
int n, m, sx, sy, k, Map[21][21], com[1001], dice[7];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void roll(int d){
    int tmp[7];
    for(int i=1;i<=6;i++)
        tmp[i] = dice[i];
    switch (d)
    {
    case 1:
        dice[1] = tmp[4];
        dice[3] = tmp[1];
        dice[4] = tmp[6];
        dice[6] = tmp[3];
        break;
    case 2:
        dice[1] = tmp[3];
        dice[3] = tmp[6];
        dice[4] = tmp[1];
        dice[6] = tmp[4];
        break;
    case 3:
        dice[1] = tmp[5];
        dice[2] = tmp[1];
        dice[5] = tmp[6];
        dice[6] = tmp[2];
        break;
    case 4:
        dice[1] = tmp[2];
        dice[2] = tmp[6];
        dice[5] = tmp[1];
        dice[6] = tmp[5];
        break;
    default:
        break;
    }
}

void go(int y, int x, int idx){
    if(idx > k)
        return;
    int fx, fy;
    while(idx < k){
        fy = y + dx[com[idx]-1];
        fx = x + dy[com[idx]-1];
        if(fy < 0 || fy >= n || fx < 0 || fx >= m){
            idx += 1;
            continue;
        }
        roll(com[idx]);
        cout << dice[1] << '\n';

        if(Map[fy][fx] == 0){
            Map[fy][fx] = dice[1];
        } else {
            dice[6] = Map[fy][fx];
            Map[fy][fx] = 0;
        }
        go(fy, fx, idx+1);
        break;
    }
}

int main(){
    cin >> n >> m >> sy >> sx >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
        }
    }
    for(int i=0;i<k;i++)
        cin >> com[i];
    go(sy, sx, 0);
}