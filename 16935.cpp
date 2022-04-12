#include <bits/stdc++.h>
using namespace std;

int n, m, r, Map[101][101];

void operation(int num){
    int tmp[101][101];
    memset(tmp, 0, sizeof(tmp));
    if(num == 1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                tmp[n-i+1][j] = Map[i][j];
            }
        }
    } else if(num == 2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                tmp[i][m-j+1] = Map[i][j];
            }
        }
    } else if(num == 3){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                tmp[j][n-i+1] = Map[i][j];
            }
        }
        swap(n, m);
    } else if(num == 4){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                tmp[m-j+1][i] = Map[i][j];
            }
        }
        swap(n, m);
    } else if(num == 5){
        for(int i=1;i<=n/2;i++){
            for(int j=1;j<=m/2;j++){
                tmp[i][j+m/2] = Map[i][j];
            }
        }
        for(int i=1;i<=n/2;i++){
            for(int j=m/2+1;j<=m;j++){
                tmp[i+n/2][j] = Map[i][j];
            }
        }
        for(int i=n/2+1;i<=n;i++){
            for(int j=m/2+1;j<=m;j++){
                tmp[i][j-m/2] = Map[i][j];
            }
        }
        for(int i=n/2+1;i<=n;i++){
            for(int j=1;j<=m/2;j++){
                tmp[i-n/2][j] = Map[i][j];
            }
        }
    } else {
        for(int i=1;i<=n/2;i++){
            for(int j=1;j<=m/2;j++){
                tmp[i+n/2][j] = Map[i][j];
            }
        }
        for(int i=1;i<=n/2;i++){
            for(int j=m/2+1;j<=m;j++){
                tmp[i][j-m/2] = Map[i][j];
            }
        }
        for(int i=n/2+1;i<=n;i++){
            for(int j=m/2+1;j<=m;j++){
                tmp[i-n/2][j] = Map[i][j];
            }
        }
        for(int i=n/2+1;i<=n;i++){
            for(int j=1;j<=m/2;j++){
                tmp[i][j+m/2] = Map[i][j];
            }
        }
    }
    memcpy(Map, tmp, sizeof(tmp));
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> r;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin >> Map[i][j];
    }
    for(int i=0;i<r;i++){
        int num;
        cin >> num;
        operation(num);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << Map[i][j] << ' ';
        }
        cout << '\n';
    }
}