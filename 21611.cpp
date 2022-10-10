#include <bits/stdc++.h>
using namespace std;

int n, m, ans[4], Map[51][51], num[51][51];
int dx[] = {0,-1,1,0,0};
int dy[] = {0,0,0,-1,1};
int rot[] = {3,2,4,1};
vector<int> v;

void blizzard(int d, int k){
    for(int i=1;i<=k;i++){
        int nx = n/2 + dx[d]*i;
        int ny = n/2 + dy[d]*i;
        int idx = num[nx][ny];
        v[idx] = -1;
    }
    for(int i=0;i<v.size();i++){
        if(v[i] == -1) v.erase(v.begin()+i);
    }
}

int nextOrder(int i){
    return i == 3 ? 0 : i+1;
}

void makeNumMap(int x, int y){
    v.push_back(Map[x][y]);
    int order=0, number=1, cnt=1;
    while(1){
        if(number >= n*n) return;
        for(int k=0;k<2;k++){
            for(int i=0;i<cnt;i++){
                x += dx[rot[order]];
                y += dy[rot[order]];
                num[x][y] = number;
                v.push_back(Map[x][y]);
                number++;
            }
            order = nextOrder(order);
        }
        cnt++;
    }
}

bool explosion(){
    bool flag = false;
    for(int i=0;i<v.size();i++){
        if(!v[i]) continue;
        int cnt = 0;
        for(int j=i;j<v.size();j++){
            if(v[i] == v[j]) cnt++;
            else break;
        }
        if(cnt >= 4){
            int tmp = v[i];
            flag = true;
            for(int j=i;j<v.size();j++){
                if(tmp == v[j]) v[j] = -1;
                else break;
            }
            i += cnt-1;
            ans[tmp] += cnt;
        }
    }
    vector<int> tmp;
    for(int i=0;i<v.size();i++){
        if(v[i] != -1) tmp.push_back(v[i]);
    }
    v = tmp;
    return flag;
}

void grouping(){
    vector<int> tmp;
    tmp.push_back(0);
    for(int i=0;i<v.size();i++){
        if(!v[i]) continue;
        int cnt = 0;
        for(int j=i;j<v.size();j++){
            if(v[i] == v[j]) cnt++;
            else break;
        }

        tmp.push_back(cnt);
        tmp.push_back(v[i]);
        i += cnt-1;
    }
    if(tmp.size() > n*n) tmp.erase(tmp.begin()+n*n, tmp.end());
    v = tmp;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> Map[i][j];
    }
    makeNumMap(n/2, n/2);
    for(int i=0;i<m;i++){
        int d, s;
        cin >> d >> s;
        blizzard(d, s);
        while(explosion()){
        }
        grouping();
    }
    cout << ans[1] + ans[2]*2 + ans[3]*3;
}