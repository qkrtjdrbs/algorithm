#include <bits/stdc++.h>
using namespace std;

int up[11];

int solution(int storey) {
    int ans=0;
    string str = to_string(storey);
    for(int i=str.size()-1;i>=0;i--){
        int n = str[i] - '0';
        n += up[i+1];
        if(n >= 10){
            up[i]++;
            n = 0;
        }
        if(n < 5){
            ans += n;
        } else if(n > 5){
            ans += 10 - n;
            up[i]++;
        } else {
            if(i == 0){
                ans += n;
            } else {
                int nn = str[i-1] - '0';
                if(nn < 5){
                    ans += n;
                } else {
                    ans += 10 - n;
                    up[i]++;
                }
            }
        }
    }
    ans += up[0];
    return ans;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    // cout << solution(16) << '\n';
    cout << solution(2554);
}