#include <bits/stdc++.h>
using namespace std;

int n, k, arr[3][102], robot[102];

void rotate(){
    int tmp[3][102], tmp2[102];
    memset(tmp, 0, sizeof(tmp));
    memset(tmp2, 0, sizeof(tmp2));
    for(int i=1;i<=n;i++){
        tmp[1][i+1] = arr[1][i];
        tmp2[i+1] = robot[i];
    }
    tmp2[1] = 0;
    for(int i=n;i>=1;i--){
        tmp[2][i-1] = arr[2][i];
    }
    tmp[1][1] = arr[2][1];
    tmp[2][n] = arr[1][n];
    for(int i=1;i<=n;i++){
        arr[1][i] = tmp[1][i];
        arr[2][i] = tmp[2][i];
        robot[i] = tmp2[i];
    }
    robot[n] = 0;
}

void move(){
    for(int i=n-1;i>=1;i--){
        if(robot[i] && !robot[i+1] && arr[1][i+1]){
            robot[i+1] = robot[i];
            robot[i] = 0;
            arr[1][i+1]--;
        }
    }
    robot[1] = robot[n] = 0;
}

void up(){
    if(arr[1][1]){
        arr[1][1]--;
        robot[1]++;
    }
}

bool check(){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(!arr[1][i]) cnt++;
        if(!arr[2][i]) cnt++;
    }
    return cnt < k;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> arr[1][i];
    for(int i=n;i>=1;i--) cin >> arr[2][i];
    for(int i=1;;i++){
        rotate();
        move();
        up();
        if(!check()){
            cout << i;
            return 0;
        }
    }
}