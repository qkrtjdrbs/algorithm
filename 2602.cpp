#include <bits/stdc++.h>
using namespace std;

string magic, angel, evil;
int dp[2][21][101], n, m;

int go(int cur, int next, int idx){
    if(next == m) return 1;
    int &res = dp[cur][next][idx];
    if(res != -1) return res;
    res = 0;
    if(cur == 0) { //천사
        for(int i=idx;i<n;i++){
            if(evil[i] == magic[next]) res += go(1, next+1, i+1);
        }
    } else { //악마
        for(int i=idx;i<n;i++){
            if(angel[i] == magic[next]) res += go(0, next+1, i+1);       
        }
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> magic >> evil >> angel;
    n = angel.size();
    m = magic.size();
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0, 0) + go(1, 0, 0);
}