#include <bits/stdc++.h>
using namespace std;

enum {
    spring = 1,
    summer = 2,
    fall = 3,
    winter = 4
};

int n, m, k, added[11][11], land[11][11];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
deque<int> woods[11][11];

int go(){
    set<tuple<int, int, int>> dies;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sort(woods[i][j].begin(), woods[i][j].end());
        }
    }
    for(int year=0;year<k;year++){
        for(int season=1;season<=4;season++){
            if(season == spring){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        int idx = 0;
                        for(auto &wood : woods[i][j]){
                            if(land[i][j] >= wood){
                                land[i][j] -= wood;
                                wood++;
                            } else {
                                dies.insert({i, j, idx});
                                break;
                            }
                            idx++;
                        }
                    }
                }
            } else if(season == summer) {
                for(auto i : dies){
                    int x, y, idx = 0;
                    tie(x, y, idx) = i;
                    for(int j=idx;j<woods[x][y].size();j++){
                        land[x][y] += (woods[x][y][j] / 2);
                    }
                    woods[x][y].erase(woods[x][y].begin()+idx, woods[x][y].end());
                }
            } else if(season == fall) {
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        for(auto wood : woods[i][j]){
                            if(wood % 5 == 0){
                                for(int k=0;k<8;k++){
                                    int nx = i + dx[k];
                                    int ny = j + dy[k];
                                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                                    woods[nx][ny].push_front(1);
                                }
                            }
                        }
                    }
                }
            } else {
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        land[i][j] += added[i][j];
                    }
                }
            }
        }
        dies.clear();
    }  
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res += woods[i][j].size();
        }
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            land[i][j] = 5;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin >> added[i][j];
    }
    for(int i=0;i<m;i++){
        int x, y, z;
        cin >> x >> y >> z;
        woods[x-1][y-1].push_back(z);
    }
    ans = go();
    cout << ans;
}