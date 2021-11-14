#include <bits/stdc++.h>
using namespace std;

int n, k;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
vector<int> bowls[101];

void addFish(){
    int mn = 987654321;
    vector<int> idxs;
    for(int i=0;i<n;i++){
        int fish = bowls[i][0];
        if(mn == fish) idxs.push_back(i);
        else if(mn > fish){
            idxs.clear();
            idxs.push_back(i);
            mn = fish;
        }
    }
    for(auto idx : idxs) bowls[idx][0]++;
}

void stacking(){
    int fish = bowls[0][0];
    bowls[1].push_back(fish);
    bowls[0].pop_back();
    bool flag = true;
    while(flag){
        int offset = 0;
        for(int i=n-1;i>=0;i--){
            int fishes = bowls[i].size();
            if(fishes < 2) continue;
            if(i + fishes >= n){
                flag = false;
                break;
            }
            for(int j=fishes-1;j>=0;j--){
                bowls[i+j+1+offset].push_back(bowls[i][j]);
            }
            bowls[i].clear();
            offset++;
        }
    }
}

void changeFish(){
    bool visited[101][101];
    memset(visited, 0, sizeof(visited));
    vector<int> tmp[101];
    for(int i=0;i<n;i++) tmp[i] = bowls[i];
    for(int i=0;i<n;i++){
        int fishes = bowls[i].size();
        for(int j=0;j<fishes;j++){
            for(int k=0;k<4;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                int size = bowls[nx].size();
                if(nx < 0 || nx >= n || ny < 0 || ny >= size) continue;
                if(visited[nx][ny]) continue;
                int d = abs(bowls[i][j] - bowls[nx][ny]) / 5;
                if(d){
                    if(bowls[i][j] > bowls[nx][ny]){
                        tmp[i][j] -= d; tmp[nx][ny] += d;
                    } else {
                        tmp[i][j] += d; tmp[nx][ny] -= d;
                    }
                }
                visited[i][j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++) bowls[i] = tmp[i];
}

void rearrange(){
    vector<int> tmp[101];
    int idx = 0;
    for(int i=0;i<n;i++){
        int fishes = bowls[i].size();
        for(int j=0;j<fishes;j++){
            tmp[idx++].push_back(bowls[i][j]);
        }
    }
    for(int i=0;i<n;i++) bowls[i] = tmp[i];
}

void halfStacking(){
    for(int i=0;i<n/2;i++){
        int fish = bowls[i][0];
        bowls[n-i-1].push_back(fish);
        bowls[i].pop_back();
    }
    int idx = 0;
    for(int i=n/2;i<n/2+n/4;i++){
        for(int j=1;j>=0;j--){
            int fish = bowls[i][j];
            bowls[n-idx-1].push_back(fish);
        }
        bowls[i].clear();
        idx++;
    }
}

bool checking(){
    int mn = 987654321, mx = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(auto fish : bowls[i]) sum += fish;
        mn = min(mn, sum);
        mx = max(mx, sum);
    }
    return abs(mn - mx) <= k;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        bowls[i].push_back(x);
    }
    for(int i=0;;i++){
        addFish();
        stacking();
        changeFish();
        rearrange();
        halfStacking();
        changeFish();
        rearrange();
        if(checking()){
            cout << i+1;
            break;
        }
    }   
}