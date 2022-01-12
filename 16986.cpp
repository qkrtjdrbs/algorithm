#include <bits/stdc++.h>
using namespace std;

int n, k, info[10][10], rcp[21][4];
bool canWin, myHand[10];

void go(int aWin, int bWin, int cWin, int bIdx, int cIdx, int out){
    if(bWin == k || cWin == k) return;
    if(aWin == k){
        canWin = true;
        return;
    }
    if(canWin) return;
    int x, y;
    if(out == 1){
        x = 2; y = 3;
    } else if(out == 2){
        x = 1; y = 3;
    } else {
        x = 1; y = 2;
    }
    if(x != 1 && y != 1){
        int res = info[rcp[bIdx++][x]][rcp[cIdx++][y]];
        if(res == 0){
            if(x == 2) go(aWin, bWin, cWin+1, bIdx, cIdx, 2);
            else go(aWin, bWin+1, cWin, bIdx, cIdx, 3);
        } else if(res == 1){
            if(x < y) go(aWin, bWin, cWin+1, bIdx, cIdx, 2);
            else go(aWin, bWin+1, cWin, bIdx, cIdx, 3);
        } else {
            if(x == 2) go(aWin, bWin+1, cWin, bIdx, cIdx, 3);
            else go(aWin, bWin, cWin+1, bIdx, cIdx, 2);
        }
    } else {
        int op = (x == 1 ? y : x);
        int opHand = (op == 2 ? rcp[bIdx++][op] : rcp[cIdx++][op]);
        for(int i=1;i<=n;i++){
            if(info[i][opHand] == 2 && !myHand[i]){
                myHand[i] = 1;
                go(aWin+1, bWin, cWin, bIdx, cIdx, op);
                myHand[i] = 0;
            } else if(info[i][opHand] == 0 && !myHand[i]){
                myHand[i] = 1;
                op == 2 ? go(aWin, bWin+1, cWin, bIdx, cIdx, 1) : go(aWin, bWin, cWin+1, bIdx, cIdx, 1);
                myHand[i] = 0;
            } else if(info[i][opHand] == 1 && !myHand[i]){
                myHand[i] = 1;
                op == 2 ? go(aWin, bWin+1, cWin, bIdx, cIdx, 1) : go(aWin, bWin, cWin+1, bIdx, cIdx, 1);
                myHand[i] = 0;
            }
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin >> info[i][j];
    }
    for(int i=2;i<=3;i++){
        for(int j=1;j<=20;j++) cin >> rcp[j][i];
    }
    go(0, 0, 0, 1, 1, 3);
    cout << canWin;
}