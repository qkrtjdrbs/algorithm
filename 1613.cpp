#include <bits/stdc++.h>
using namespace std;
int n, k, s, arr[401][401];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][k] && arr[k][j]){
                    arr[i][j] = 1;
                }
            }
        }
    }
    cin >> s;
    for(int k=0;k<s;k++){
        int a, b;
        cin >> a >> b;
        if(arr[a][b]) cout << -1;
        else if(arr[b][a]) cout << 1;
        else cout << 0;
        cout << '\n';
    }
}
