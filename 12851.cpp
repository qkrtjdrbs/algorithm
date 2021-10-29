#include <bits/stdc++.h>
using namespace std;

int n, k, ans1, ans2;
bool visited[100001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = 1;
    while(!q.empty()){
        int x, cnt;
        tie(x, cnt) = q.front();
        q.pop();
        visited[x] = 1;
        if(!ans1 && x == k){
            ans1 = cnt;
            ans2++;
            continue;
        } else if(ans1 && ans1 == cnt && x == k){
            ans2++;
            continue;
        }
        if(x-1 >= 0 && !visited[x-1]){
            q.push({x-1, cnt+1});
        }
        if(x+1 <= 100000 && !visited[x+1]){
            q.push({x+1, cnt+1});
        }
        if(2*x <= 100000 && !visited[2*x]){
            q.push({2*x, cnt+1});
        }
    }
    cout << ans1 << '\n' << ans2;
}