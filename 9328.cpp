#include <bits/stdc++.h>
using namespace std;
int t, n, m, Visit[105][105];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[105][105];
string bits = "abcdefghijklmnopqrstuwxyz";
string ubits = "ABCDEFGHIJKLMNOPQRSTUWXYZ";

int findIdx(char x){
    if(isupper(x)) return find(ubits.begin(), ubits.end(), x) - ubits.begin();
    return find(bits.begin(), bits.end(), x) - bits.begin();
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        memset(Visit, 0, sizeof(Visit));
        memset(Map, '0', sizeof(Map));
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                cin >> Map[i][j];
        }
        string key = "";
        bitset<26> bit;
        bit.reset();
        cin >> key;
        if(key[0] != '0'){
            for(auto x : key){
                int idx = findIdx(x);
                bit.flip(idx);
            }
        }
        queue<pair<int, int>> q;
        queue<pair<int, int>> door[26];
        q.push({0, 0});
        int ans = 0;
        while(!q.empty()){
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            if(Map[x][y] == '$') {
                ans++;
            }
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx > n+1 || ny < 0 || ny > m+1 || Map[nx][ny] == '*') continue;
                if(Visit[nx][ny]) continue;
                Visit[nx][ny] = 1;
                if(isalpha(Map[nx][ny])){
                    if(islower(Map[nx][ny])){
                        q.push({nx, ny});
                        if(!bit.test(findIdx(Map[nx][ny]))){
                            bit.flip(findIdx(Map[nx][ny]));
                            while(!door[findIdx(Map[nx][ny])].empty()){
                                q.push(door[findIdx(Map[nx][ny])].front());
                                door[findIdx(Map[nx][ny])].pop();
                            }
                        }
                    } else {
                        if(bit.test(findIdx(Map[nx][ny]))){
                            q.push({nx, ny});
                        } else {
                            door[findIdx(Map[nx][ny])].push({nx, ny});
                        }
                    }
                } else {
                    q.push({nx, ny});
                }
            }
        }
        cout << ans << '\n';
    }
}