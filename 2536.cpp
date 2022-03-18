#include <bits/stdc++.h>
using namespace std;

int n, m, k, sx, sy, ex, ey;
bool visited[5001];
tuple<int, int, int, int> bus[5001];

bool check(int num, int x, int y){
    auto [x1, y1, x2, y2] = bus[num];
    if(x1 == x2){
        if(x == x1 && y1 <= y && y <= y2) return true;
    } else if(y1 == y2) {
        if(y == y1 && x1 <= x && x <= x2) return true;
    }
    return false;
}

bool check2(int cur, int next){
    auto [x1, y1, x2, y2] = bus[cur];
    auto [nx1, ny1, nx2, ny2] = bus[next];
    if(x1 == x2 && nx1 == nx2){
        if(x1 == nx1 && y2 >= ny1 && y1 <= ny2) return true;
    } else if(x1 == x2 && ny1 == ny2){
        if(nx1 <= x1 && x1 <= nx2 && y2 >= ny1 && y1 <= ny1) return true;
    } else if(y1 == y2 && nx1 == nx2){
        if(x1 <= nx1 && nx1 <= x2 && ny2 >= y1 && ny1 <= y1) return true;
    } else if(y1 == y2 && ny1 == ny2){
        if(y1 == ny1 && x2 >= nx1 && x1 <= nx2) return true;
    }
    return false;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=0;i<k;i++){
        int b, x, y, xx, yy, mn, mx;
        cin >> b >> x >> y >> xx >> yy;
        if(x == xx){
            mn = min(y, yy);
            mx = max(y, yy);
            bus[b] = {x, mn, xx, mx};
        } else if(y == yy){
            mn = min(x, xx);
            mx = max(x, xx);
            bus[b] = {mn, y, mx, yy};
        }
    }
    cin >> sx >> sy >> ex >> ey;
    queue<pair<int, int>> q;
    for(int i=1;i<=k;i++){
        if(check(i, sx, sy)){
            q.push({i, 1});
            visited[i] = 1;
        }
    }
    while(!q.empty()){
        auto [num, c] = q.front();
        q.pop();
        if(check(num, ex, ey)){
            cout << c;
            return 0;
        }
        for(int i=1;i<=k;i++){
            if(visited[i]) continue;
            if(check2(num, i)){
                q.push({i, c+1});
                visited[i] = 1;
            }
        }
    }
}