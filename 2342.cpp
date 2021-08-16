#include <bits/stdc++.h>
using namespace std;
int score[5][5], dp[5][5][100001];
vector<int> n;

int dfs(int l, int r, int d){
    return 0;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(1){
        int x;
        cin >> x;
        if(!x) break;
        n.push_back(x);
    }
    for(int i=0;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(i == j) {
                score[i][j] = 1;
                continue;
            }
            if(i == 0){
                score[i][j] = 2;
            }
            if(i == 1){
                if(j == 2 || j == 4) score[i][j] = 3;
                else score[i][j] = 4;
            }
            if(i == 2){
                if(j == 1 || j == 3) score[i][j] = 3;
                else score[i][j] = 4;
            }
            if(i == 3){
                if(j == 2 || j == 4) score[i][j] = 3;
                else score[i][j] = 4;
            }
            if(i == 4){
                if(j == 1 || j == 3) score[i][j] = 3;
                else score[i][j] = 4;
            }
        }
    }
}