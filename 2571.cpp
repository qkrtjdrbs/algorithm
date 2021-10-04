#include <bits/stdc++.h>
using namespace std;

int n, psum[103][103];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        for(int r=x;r<=x+10;r++){
            for(int c=y;c<=y+10;c++)
                psum[r][c] = 1;
        }
    }
    for(int i=1;i<=101;i++){
        for(int j=1;j<=101;j++){
            psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
    }
    cout << "z";
}