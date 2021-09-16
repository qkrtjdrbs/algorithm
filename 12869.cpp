#include <bits/stdc++.h>
using namespace std;
int n, scv[3], d[61][61][61];
int dx[6] = { 1,1,3,3,9,9 };
int dy[6] = { 3,9,1,9,1,3 };
int dz[6] = { 9,3,9,1,3,1 };

int go(int x, int y, int z){
    if(x <= 0 && y <= 0 && z <= 0){
        return 0;
    }
    if(x < 0) x = 0;
    if(y < 0) y = 0;
    if(z < 0) z = 0;
    int &res = d[x][y][z];
    if(res != -1) return res;
    res = 987654321;
    for (int k = 0; k < 6; k++) {
        res = min(res, go(x-dx[k], y-dy[k], z-dz[k]) + 1);
    }
    return res;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n;
    memset(d, -1, sizeof(d));
    for(int i=0;i<n;i++)
        cin >> scv[i];
    cout << go(scv[0], scv[1], scv[2]);
}