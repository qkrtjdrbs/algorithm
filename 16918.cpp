#include <bits/stdc++.h>
using namespace std;

int n, m, r, explode[201][201];
char Map[201][201];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << Map[i][j];
        }
        cout << '\n';
    }
}

void bomb(int sec){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] == '.'){
                Map[i][j] = 'O';
                explode[i][j] = sec;
            }
        }
    }
}

void explosion(int sec){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] == 'O' && explode[i][j] == sec){
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(Map[nx][ny] == 'O' && explode[nx][ny] == sec) continue;
                    Map[nx][ny] = '.';
                    explode[nx][ny] = 0;
                }
                Map[i][j] = '.';
                explode[i][j] = 0;
            }
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> r;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j] == 'O'){
                explode[i][j] = 3;
            }
        }
    }
    if(r <= 1){
        print();
    } else {
        for(int i=2;i<=r;i++){
            if(i % 2 == 0){
                bomb(i+3);
            } else {
                explosion(i);
            }
        }
        print();
    }
}