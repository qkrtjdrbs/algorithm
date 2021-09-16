#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int cant = 0;
        int idx = 0;
        int end = 0;
        int len = s.length();
        while(1){
            if(cant){
                cout << "NO" << '\n';
                end = 1;
                break;
            }
            if(idx >= len) break;
            if(s[idx] == '1'){
                if(idx+1 < len && idx+2 < len && s[idx+1] == '0' && s[idx+2] == '0'){
                    idx += 3;
                    int i, j;
                    for(i = idx; i<len; i++){
                        if(s[i] == '1'){
                            idx = i;
                            break;
                        }
                    }
                    if(i == len){
                        if(s[i-1] == '0'){
                            cant = 1;
                            continue;
                        } else{
                            break;
                        }
                    }
                    if(s[idx+1] == '0'){
                        ++idx;
                        continue;
                    }
                    for(j = idx; j<len; j++){
                        if(s[j] == '0'){
                            idx = j-1;
                            break;
                        }
                    }
                    if(j == len){
                        if(s[j-1] == '0'){
                            cant = 1;
                            continue;
                        } else{
                            break;
                        }
                    }
                    continue;
                } else ++idx;
            } else{
                if(s[idx+1] == '1'){
                    idx += 2;
                } else cant = 1;
            }
        }
        if(end) continue;
        else cout << "YES" << '\n';
    }
}