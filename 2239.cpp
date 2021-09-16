#include <bits/stdc++.h>
using namespace std;

char Map[10][10];

bool ok(int x, int y, int n){
    for(int i=0;i<9;i++){
        if(Map[i][y] == n + '0') return false;
    }
    for(int i=0;i<9;i++){
        if(Map[x][i] == n + '0') return false;
    }
    int sx = x / 3, sy = y / 3;
    for(int i=sx*3;i<sx*3+3;i++){
        for(int j=sy*3;j<sy*3+3;j++){
            if(Map[i][j] == n + '0') return false;
        }
    }
    return true;
}

void go(int start){
    for(int i=start;i<81;i++){
        int x = i / 9, y = i % 9;
        if(Map[x][y] == '0'){
            for(int j=1;j<10;j++){
                if(ok(x, y, j)){
                    Map[x][y] = j + '0';
                    go(i+1);
                    Map[x][y] = '0';
                }
            }
            if(Map[x][y] == '0') return;
        }
    }
    bool flag = true;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(Map[i][j] == '0'){
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    if(flag){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << Map[i][j];
            }
            cout << '\n';
        }
        exit(0);
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> Map[i][j];
        }
    }
    go(0);
}