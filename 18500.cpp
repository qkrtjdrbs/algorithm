#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[101][101];

void destory(bool flag, int h){
    if(!flag){
        for(int i=0;i<m;i++){
            if(Map[h][i] == 'x'){
                Map[h][i] = '.';
                break;
            }
        }
    } else {
        for(int i=m-1;i>=0;i--){
            if(Map[h][i] == 'x'){
                Map[h][i] = '.';
                break;
            }
        }
    }
}

void gravity(){
    queue<pair<int, int>> q;
    int comp[101][101], height[3], cnt=1;
    char tmp[101][101];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tmp[i][j] = '.';
        }
    }
    memset(comp, 0, sizeof(comp));
    height[1] = height[2] = 987654321;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!comp[i][j] && Map[i][j] == 'x'){
                vector<pair<int, int>> v;
                q.push({i, j});
                comp[i][j] = cnt;
                while(!q.empty()){
                    auto [x, y] = q.front();
                    v.push_back({x, y});
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx  = x + dx[k];
                        int ny  = y + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(comp[nx][ny] || Map[nx][ny] != 'x') continue;
                        q.push({nx, ny});
                        comp[nx][ny] = cnt;
                    }
                }

                for(auto node : v){
                    auto [x, y] = node;
                    for(int h=1;;h++){
                        if(x + h >= n){
                            height[cnt] = min(height[cnt], h-1);
                            break;
                        }
                        if(Map[x+h][y] == 'x'){
                            if(comp[x+h][y] != comp[x][y]){
                                height[cnt] = min(height[cnt], h-1);
                                break;
                            }
                            if(comp[x+h][y] == comp[x][y]){
                                break;
                            }
                        }
                    }
                }

                for(auto node : v){
                    auto [x, y] = node;
                    tmp[x+height[cnt]][y] = 'x';
                }
                cnt++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           Map[i][j] = tmp[i][j];
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> Map[i][j];
    }
    cin >> k;
    for(int i=0;i<k;i++){
        int h;
        cin >> h;
        destory(i%2, n-h);
        gravity();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cout << Map[i][j];
        }
        cout << '\n';
    }
}