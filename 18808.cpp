#include <bits/stdc++.h>
using namespace std;

int n, m, k;
bool Map[41][41];
vector<vector<vector <int>>> stickers;

void rotation(vector<vector <int>> &v){
    vector<vector<int>> tmp(v[0].size(), vector<int>(v.size(), 0));
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            tmp[j][v.size()-i-1] = v[i][j];
        }
    }
    v = tmp;
    return;
}

void go(){
    bool tmp[41][41];
    for(auto sticker : stickers){
        bool rotate = true; 
        for(int ro=0;ro<4;ro++){
            int r = sticker.size();
            int c = sticker[0].size();
            for(int i=0;i<=n-r;i++){
                for(int j=0;j<=m-c;j++){
                    bool canStick = true;
                    memcpy(tmp, Map, sizeof(Map));
                    for(int ii=i;ii<i+r;ii++){
                        for(int jj=j;jj<j+c;jj++){
                            if(Map[ii][jj] && sticker[ii-i][jj-j]){
                                canStick = false;
                                break;
                            } else if(!Map[ii][jj] && sticker[ii-i][jj-j]){
                                Map[ii][jj] = 1;
                            }
                        }
                        if(!canStick) break;
                    }
                    if(!canStick) memcpy(Map, tmp, sizeof(tmp));
                    else {
                        rotate = false;
                        break;
                    }
                }
                if(!rotate) break;
            }
            if(rotate){
                rotation(sticker);
            }
            else break;
        }
    }
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j]) res++;
        }
    }
    cout << res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=0;i<k;i++){
        int r, c;
        cin >> r >> c;
        vector<vector <int>> sticker;
        for(int i=0;i<r;i++){
            vector<int> tmp;
            for(int j=0;j<c;j++){
                int x;
                cin >> x;
                tmp.push_back(x);
            }
            sticker.push_back(tmp);
        }
        stickers.push_back(sticker);
    }
    go();
}