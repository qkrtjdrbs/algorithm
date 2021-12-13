#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    int ans = 0;
    for(int i=-9;i<10;i++){
        for(int j=100;j<=n;j++){
            string tmp = to_string(j);
            bool flag = true;
            for(int k=0;k<tmp.size()-1;k++){
                if(tmp[k]-tmp[k+1] != i){
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
    }
    cout << (n < 100 ? n : ans+99);
}