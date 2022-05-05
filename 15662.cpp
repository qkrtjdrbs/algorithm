#include <bits/stdc++.h>
using namespace std;

int n, k, check[1001];
string wheel[1001];

void rotate(int idx, int dir){
    string tmp = wheel[idx];
    if(dir == -1){
        for(int i=0;i<8;i++){
            if(i == 0){
                tmp[7] = wheel[idx][i];
            } else {
                tmp[i-1] = wheel[idx][i];
            }
        }
    } else {
        for(int i=0;i<8;i++){
            if(i == 7){
                tmp[0] = wheel[idx][i];
            } else {
                tmp[i+1] = wheel[idx][i];
            }
        }
    }
    wheel[idx] = tmp;
}

void go(int idx, int dir){
    check[idx] = dir;

    for(int i=idx;i>1;i--){
        if(wheel[i][6] != wheel[i-1][2]){
            check[i-1] = (i-1) % 2 == idx % 2 ? dir : -dir;
        } else break;
    }
    for(int i=idx;i<n;i++){
        if(wheel[i][2] != wheel[i+1][6]){
            check[i+1] = (i+1) % 2 == idx % 2 ? dir : -dir;
        } else break;
    }
    for(int i=1;i<=n;i++){
        if(check[i]){
            rotate(i, check[i]);
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> wheel[i];
    }
    cin >> k;
    for(int i=0;i<k;i++){
        int num, dir;
        cin >> num >> dir;
        memset(check, 0, sizeof(check));
        go(num, dir);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(wheel[i][0] == '1') cnt++;
    }
    cout << cnt;
}