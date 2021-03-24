#include <iostream>
#include <algorithm>
using namespace std;
int n, ans=987654321;
char coin[21][21];
int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> coin[i];
    for(int row=0;row<(1<<n);row++){
        int sum = 0;
        for(int j=0;j<n;j++){
            int T = 0;
            for(int i=0;i<n;i++){
                char cur = coin[i][j];
                if(row & (1 << i)){
                    if(cur=='T')
                        cur='H';
                    else
                        cur='T';
                }
                if(cur == 'T')
                    T += 1;
            }
            sum += min(T, n-T);
        }
        ans = min(sum, ans);
    }
    cout << ans;
}