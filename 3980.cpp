#include <bits/stdc++.h>
#define MAX 11
using namespace std;

int t, ans;
bool visited[MAX];
vector<int> player[MAX], selected;

void go(int num, int cnt){
    if(cnt == MAX){
        int res = 0;
        for(auto x : selected) res += x;
        ans = max(ans, res);
        return;
    }
    for(int i=0;i<MAX;i++){
        if(!player[num][i]) continue;
        if(visited[i]) continue;
        visited[i] = 1;
        selected.push_back(player[num][i]);
        go(num+1, cnt+1);
        selected.pop_back();
        visited[i] = 0;
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        for(int i=0;i<MAX;i++) player[i].clear();
        memset(visited, 0, sizeof(visited));
        selected.clear();
        ans = 0;

        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                int x;
                cin >> x;
                player[i].push_back(x);
            }
        }
        go(0, 0);
        cout << ans << '\n';
    }
}