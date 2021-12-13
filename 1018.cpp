#include <bits/stdc++.h>
using namespace std;

int n, m;
char Map[51][51];

bool check(int x, int y){
    return x >= 0 && x+7 < n && y >= 0 && y+7 < m;
}

int painting(int x, int y, char p){
    int res = 0;
    for(int i=x;i<x+8;i++){
        for(int j=y;j<y+8;j++){
            if(Map[i][j] != p) res++;
            p == 'W' ? p = 'B' : p = 'W';
        }
        p == 'W' ? p = 'B' : p = 'W';
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
        }
    }
    int ans = 100;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(check(i, j)){
                ans = min({ans, painting(i, j, 'W'),  painting(i, j, 'B')});
            }
        }
    }
    cout << ans;
}