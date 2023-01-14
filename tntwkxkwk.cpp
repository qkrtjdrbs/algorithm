#include <bits/stdc++.h>
using namespace std;

// 왼손 pos, 오른손 pos 일 때 numbers의 idx번째 요소로 가는 최단 거리
int dp[12][12][100001];
// x-y 간 최단 거리, 10:*, 11:#
int dist[12][12];
string pad[4], numbers;

int go(int l, int r, int idx){
    if(idx == numbers.size()) return 0;
    int num = numbers[idx] - '0';
    int &res = dp[l][r][idx];
    if(res != -1) return res;
    res = 987654321;
    if(l == num || r == num){
        res = go(l, r, idx+1)+1;
    } else {
        res = min(go(num, r, idx+1)+dist[l][num], go(l, num, idx+1)+dist[r][num]);
    }
    return res;
}

int solution(string str) {
    numbers = str;
    int ans = 0;
    pad[0] = "123";
    pad[1] = "456";
    pad[2] = "789";
    pad[3] = "*0#";

    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            dist[i][j] = 987654321;
        }
    } 
    for(int i=0;i<12;i++) dist[i][i] = 1;

    dist[0][8] = dist[0][10] = dist[0][11] = 2;
    dist[1][2] = dist[1][4] = 2;
    dist[2][1] = dist[2][5] = dist[2][3] = 2;
    dist[3][2] = dist[3][6] = 2;
    dist[4][1] = dist[4][5] = dist[4][7] = 2;
    dist[5][2] = dist[5][4] = dist[5][8] = dist[5][6] = 2;
    dist[6][3] = dist[6][5] = dist[6][9] = 2;
    dist[7][4] = dist[7][8] = dist[7][10] = 2;
    dist[8][5] = dist[8][7] = dist[8][0] = dist[8][9] = 2;
    dist[9][6] = dist[9][8] = dist[9][11] = 2;
    dist[10][7] = dist[10][0] = 2;
    dist[11][9] = dist[11][0] = 2;

    dist[0][7] = dist[0][9] = 3;
    dist[1][5] = 3;
    dist[2][4] = dist[2][6] = 3;
    dist[3][5] = 3;
    dist[4][2] = dist[4][8] = 3;
    dist[5][1] = dist[5][3] = dist[5][7] = dist[5][9] = 3;
    dist[6][2] = dist[6][8] = 3;
    dist[7][5] = dist[7][0] = 3;
    dist[8][4] = dist[8][6] = dist[8][10] = dist[8][11] = 3;
    dist[9][5] = dist[9][0] = 3;
    dist[10][8] = 3;
    dist[11][8] = 3;

    for(int k=0;k<12;k++){
        for(int i=0;i<12;i++){
            for(int j=0;j<12;j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }    
    }

    memset(dp, -1, sizeof(dp));
    ans = go(4, 6, 0);
    return ans;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    solution("1756");
    solution("5123");
}