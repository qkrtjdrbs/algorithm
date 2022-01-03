#include <bits/stdc++.h>
using namespace std;

int n, m, k;
bool lamp[51][51];
vector<int> on[51];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x;
            cin >> x;
            lamp[i][j] = x - '0';
        }
    }
    cin >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!lamp[i][j]) on[i].push_back(j);
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(k < on[i].size()) continue;
        if(k % 2 == on[i].size() % 2){
            for(auto col : on[i]){
                for(int row=0;row<n;row++){
                    lamp[row][col] = !lamp[row][col];
                }
            }
            int res = 0;
            for(int i=0;i<n;i++){
                bool flag = true;
                for(int j=0;j<m;j++){
                    if(!lamp[i][j]){
                        flag = false;
                        break;
                    }
                }
                if(flag) res++;
            }
            ans = max(ans, res);
            for(auto col : on[i]){
                for(int row=0;row<n;row++){
                    lamp[row][col] = !lamp[row][col];
                }
            }
        }
    }
    cout << ans;
}