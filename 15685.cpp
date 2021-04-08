#include <bits/stdc++.h>
using namespace std;
int n, Map[101][101], ans;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

void makeCurve(int x, int y, int d, int g){
    int cnt = 0;
    int X = x + dx[d];
    int Y = y + dy[d];
    Map[Y][X] = d;
    vector<pair<int, int>> v;
    vector<int> dInfo;
    v.push_back({Y, X});
    dInfo.push_back(d);
    while(cnt < g){
        vector<pair<int, int>> tmp1;
        vector<int> tmp2;
        int newY, newX;
        int len = v.size();
        tie(newY, newX) = v[len-1];
        for(int i=v.size()-1, j=dInfo.size()-1;i>=0, j>=0;i--, j--){
            int newD, ty, tx;
            tie(ty, tx) = v[i];
            newD = dInfo[j];
            newD == 3 ? newD = 0 : newD += 1;
            newY += dy[newD];
            newX += dx[newD];
            tmp1.push_back({newY, newX});
            tmp2.push_back(newD);
            if(newY <= 100 || newY >= 0 || newX <= 100 || newX >= 0){
                Map[newY][newX] = newD;
            }
        }
        v.insert(v.end(), tmp1.begin(), tmp1.end());
        dInfo.insert(dInfo.end(), tmp2.begin(), tmp2.end());
        ++cnt;
    }
}

void check(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            int diagX = i+1;
            int diagY = j+1;
            if(Map[i][j]==-1 || Map[diagX][j]==-1 || Map[i][diagY]==-1 || Map[diagX][diagY]==-1){
                continue;
            }
            ++ans;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(Map, -1, sizeof(Map));
    cin >> n;
    for(int i=0;i<n;i++){
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        Map[y][x] = 0;
        makeCurve(x, y, d, g);    
    }
    check();
    cout << ans;
}