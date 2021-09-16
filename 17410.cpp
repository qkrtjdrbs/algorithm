#include <bits/stdc++.h>
using namespace std;
int r, c, k, sec, a[501][501];

bool sorting(int maxR, int maxC, char op){
    int tmp[101][101], cnt[101];
    priority_queue<pair<int, int>> pq;
    for(int i=1;i<=100;i++){
        cnt[i] = 0;
        for(int j=1;j<=100;j++){
            tmp[i][j] = 0;
        }
    }
    if(op == 'R'){
        for(int i=1;i<=maxR;i++){
            for(int j=1;j<=maxC;j++){
                cnt[a[i][j]]++;
            }
            for(int j=1;j<=100;j++){
                if(!cnt[j]) continue;
                pq.push({-cnt[j], -j});
                cnt[j] = 0;
            }
            for(int j=1;j<=100;j+=2){
                int num, times;
                if(pq.empty()) break;
                tie(times, num) = pq.top();
                pq.pop();
                times = -times;
                num = -num;
                tmp[i][j] = num;
                tmp[i][j+1] = times;
            }
        }
    } else {
        for(int i=1;i<=maxC;i++){
            for(int j=1;j<=maxR;j++){
                cnt[a[j][i]]++;
            }
            for(int j=1;j<=100;j++){
                if(!cnt[j]) continue;
                pq.push({-cnt[j], -j});
                cnt[j] = 0;
            }
            for(int j=1;j<=100;j+=2){
                int num, times;
                if(pq.empty()) break;
                tie(times, num) = pq.top();
                pq.pop();
                times = -times;
                num = -num;
                tmp[j][i] = num;
                tmp[j+1][i] = times;
            }
        }
    }
    if(tmp[r][c] == k) {
        return true;
    }
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            a[i][j] = tmp[i][j];
        }
    }
    return false;
}

bool go(){
    int maxR = 0, maxC = 0;
    char op;
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(!a[i][j]) continue;
            maxR = max(maxR, i);
            maxC = max(maxC, j);
        }
    }
    if(maxR >= maxC) op = 'R';
    else op = 'C';

    bool flag = sorting(maxR, maxC, op);
    if(flag) return true;
    return false;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> r >> c >> k;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin >> a[i][j];
        }
    }
    if(a[r][c] == k){
        cout << 0;
        return 0;
    }
    sec = 1;
    while(sec <= 100){
        if(go()){
            cout << sec;
            return 0;
        }
        sec++;
    }
    cout << -1;
}