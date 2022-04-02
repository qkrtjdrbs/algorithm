#include <bits/stdc++.h>
using namespace std;

int n, m, k, cnt[100001], cond[100001], bcnt[100001];
vector<int> nxt[100001];

bool canBuild(int num){
    if(cond[num] == bcnt[num]) return true;
    return false;
}

bool canDestory(int num){
    if(!cnt[num]) return false;
    return true;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> b >> a;
        nxt[b].push_back(a);
        cond[a]++;
    }
    for(int i=0;i<k;i++){
        int cmd, x;
        cin >> cmd >> x;
        if(cmd == 1){
            if(canBuild(x)){
                if(++cnt[x] == 1){
                    for(auto num : nxt[x]){
                        bcnt[num]++;                        
                    }
                }
            } else {
                cout << "Lier!";
                return 0;
            }
        } else {
            if(canDestory(x)){
                if(--cnt[x] == 0){
                    for(auto num : nxt[x]){
                        bcnt[num]--;
                    }
                }
            } else {
                cout << "Lier!";
                return 0;
            }
        }
    }
    cout << "King-God-Emperor";
}