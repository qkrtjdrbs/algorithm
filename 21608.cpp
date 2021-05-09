#include <bits/stdc++.h>
using namespace std;
int n, Map[21][21], ans;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

vector<int> fav[401];
queue<int> order;

bool isFav(int sNum, int x, int y){
    for(auto X : fav[sNum]){
        if(X == Map[x][y])
            return true;
    }
    return false;
}

pair<int, int> spaceInfo(int sNum, int x, int y){
    int emptyCnt = 0, favCnt = 0;
    for(int k=0;k<4;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(Map[nx][ny]){
            if(isFav(sNum, nx, ny)){
                ++favCnt;
            }
        } else {
            ++emptyCnt;
        }
    }
    return {favCnt, emptyCnt};
}

void sitDown(int sNum){
    priority_queue<tuple<int, int, int, int>> pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!Map[i][j]){
                int favCnt, emptyCnt;
                tie(favCnt, emptyCnt) = spaceInfo(sNum, i, j);
                pq.push({favCnt, emptyCnt, -i, -j});
            }
        }
    }
    int f, e, x, y;
    tie(f, e, x, y) = pq.top();
    if(x < 0) x *= -1;
    if(y < 0) y *= -1;
    Map[x][y] = sNum;
}

int satisfaction(int x, int y){
    int score = 0;
    for(int k=0;k<4;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        for(auto X : fav[Map[x][y]]){
            if(X == Map[nx][ny])
                ++score;
        }
    }
    if(score == 0) return 0;
    else return pow(10, score-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n*n;i++){
        int num, s[4];
        cin >> num;
        order.push(num);
        for(int j=0;j<4;j++){
            cin >> s[j];
            fav[num].push_back(s[j]);
        }
    }
    while(!order.empty()){
        int num = order.front();
        order.pop();
        sitDown(num);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans += satisfaction(i, j);
        }
    }
    cout << ans;
}