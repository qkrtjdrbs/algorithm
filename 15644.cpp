#include <bits/stdc++.h>
#define MAX 15
using namespace std;
int n, m, ans=987654321;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char dir[] = {'L', 'R', 'U', 'D'};
string Map[MAX];
string Ans;
string tmp2;

int gravity(int x, int y, int dir, char marble){
    int cnt = 0;
    while(1){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m){
            if(!cnt)
                return -1;
            return 0;
        }
        if(Map[nx][ny] == '#' || Map[nx][ny] == 'B' || Map[nx][ny] == 'R'){
            if(!cnt)
                return -1;
            return 0;
        }
        if(Map[nx][ny] == 'O'){
            if(marble == 'R'){
                Map[x][y] = '.';
                return 1;
            }
            if(marble == 'B'){
                return -2;
            }
        }
        swap(Map[x][y], Map[nx][ny]);
        x = nx;
        y = ny;
        ++cnt;
    }
    return 0;
}

int Find(int dir){
    int cnt = 0;
    if(dir == 0){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(Map[i][j] == 'R' || Map[i][j] == 'B'){
                    int res = gravity(i, j, dir, Map[i][j]);
                    if(res == 1){
                        cnt = 100;
                    }
                    if(res == -1){
                        cnt++;
                    }
                    if(res == -2){
                        return -1;
                    }
                }
            }
        }
    } else if(dir == 1){
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(Map[i][j] == 'R' || Map[i][j] == 'B'){
                    int res = gravity(i, j, dir, Map[i][j]);
                    if(res == 1){
                        cnt = 100;
                    }
                    if(res == -1){
                        cnt++;
                    }
                    if(res == -2){
                        return -1;
                    }
                }
            }
        }
    } else if(dir == 2){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(Map[i][j] == 'R' || Map[i][j] == 'B'){
                    int res = gravity(i, j, dir, Map[i][j]);
                    if(res == 1){
                        cnt = 100;
                    }
                    if(res == -1){
                        cnt++;
                    }
                    if(res == -2){
                        return -1;
                    }
                }
            }
        }
    } else if(dir == 3){
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(Map[i][j] == 'R' || Map[i][j] == 'B'){
                    int res = gravity(i, j, dir, Map[i][j]);
                    if(res == 1){
                        cnt = 100;
                    }
                    if(res == -1){
                        cnt++;
                    }
                    if(res == -2){
                        return -1;
                    }
                }
            }
        }
    }
    return cnt;
}

void go(int cnt){
    if(cnt > 10 || cnt >= ans) return;
    string tmp[MAX];
    string res;
    for(int i=0;i<n;i++){
        tmp[i] = Map[i];
    }
    res = tmp2;
    int endCnt = 0;
    for(int i=0;i<4;i++){
        for(int i=0;i<n;i++){
            Map[i]= tmp[i];
        }
        tmp2 = res;
        endCnt = Find(i);
        tmp2.push_back(dir[i]);
        if(endCnt >= 99){
            ans = min(ans, cnt);
            Ans = tmp2;
            continue;
        }
        if(endCnt == -1){
            continue;
        }
        if(endCnt != 2){
            go(cnt+1);
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> Map[i];
    go(1);
    if(ans == 987654321) ans = -1;
    cout << ans << '\n';
    if(ans != -1)
        for(auto x : Ans){
            cout << x;
        }
    return 0;
}