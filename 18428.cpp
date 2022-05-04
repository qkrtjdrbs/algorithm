#include <bits/stdc++.h>
using namespace std;

int n;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[7][7];
bool flag;

bool allOk(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(Map[i][j] == 'T'){
                for(int k=0;k<4;k++){
                    for(int l=1;l<=n;l++){
                        int nx = i + dx[k]*l;
                        int ny = j + dy[k]*l;
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) break;
                        if(Map[nx][ny] == 'S'){
                            return false;
                        }
                        if(Map[nx][ny] == 'O'){
                            break;
                        }
                    }      
                } 
            }
        }
    }
    return true;
}

void barrier(int idx, int cnt){
    if(cnt == 3){
        if(allOk()) flag = true;
        return;
    }
    if(flag) return;
    if(idx >= n*n) return;

    int x=idx/n, y=idx%n;
    if(Map[x][y] == 'X'){
        Map[x][y] = 'O';
        barrier(idx+1, cnt+1);
        Map[x][y] = 'X';
    }
    barrier(idx+1, cnt);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> Map[i][j];
        }
    }
    barrier(0, 0);
    cout << (flag ? "YES" : "NO");
}