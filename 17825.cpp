#include <bits/stdc++.h>
using namespace std;

int n, ans, red[35] = {0,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,33,23,24,25,31,25,26,27,30,25,32,21,33},
score[35] = {0,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,13,16,19,25,26,27,28,22,24,30,35},
blue[35], horse[4]={1,1,1,1}, sum[4];
const int FINAL = 33;
bool visited[35];
vector<int> dice;

void go(int turn){
    if(turn == 10){
        int res = 0;
        for(int i=0;i<4;i++) res += sum[i];
        ans = max(ans, res);
        return;
    }
    int len = dice[turn];
    for(int i=0;i<4;i++){
        if(horse[i] != FINAL){
            int prev = horse[i];
            for(int j=0;j<len;j++){
                if(j == 0 && blue[horse[i]]) horse[i] = blue[horse[i]];
                else horse[i] = red[horse[i]];
            }
            if(horse[i] != FINAL && visited[horse[i]]){
                horse[i] = prev;
                continue;
            }
            visited[prev] = 0;
            visited[horse[i]] = 1;
            sum[i] += score[horse[i]];
            go(turn+1);
            sum[i] -= score[horse[i]];
            visited[horse[i]] = 0;
            visited[prev] = 1;
            horse[i] = prev;
        }
    }
    int res = 0;
    for(int i=0;i<4;i++) res += sum[i];
    ans = max(ans, res);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    blue[6] = 22; blue[11] = 29; blue[16] = 28;
    for(int i=0;i<10;i++){
        int x;
        cin >> x;
        dice.push_back(x);
    }
    go(0);
    cout << ans;
}