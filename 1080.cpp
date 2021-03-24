#include <iostream>
#include <algorithm>
using namespace std;
int n, m, cnt = 0, a[51][51], b[51][51];
void ff(int r, int c){
    for(int i=r;i<=r+2;i++){
        for(int j=c;j<=c+2;j++){
            a[i][j] = 1 - a[i][j];
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            scanf("%1d",&a[i][j]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            scanf("%1d",&b[i][j]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!=b[i][j] && i+2 < n && j+2 < m){
                ff(i,j);
                cnt += 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!=b[i][j]){
                cout << -1;
                return 0;
            }
        }
    }
    cout << cnt;
}