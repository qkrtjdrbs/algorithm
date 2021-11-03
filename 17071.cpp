#include <bits/stdc++.h>
#define MAX 500000
using namespace std;

int n, k, visited[MAX+1][2];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    memset(visited, -1, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n][0] = 0;
    while(!q.empty()){
        int x, sec;
        tie(x, sec) = q.front();
        q.pop();
        for(int i=0;i<3;i++){
            int next;
            if(i == 0) next = x+1;
            else if(i == 1) next = x-1;
            else next = x*2;
            if(next < 0 || next > MAX || visited[next][(sec+1)%2] != -1) continue;
            q.push({next, sec+1});
            visited[next][(sec+1)%2] = sec+1;
        }
    }
    for(int i=0;i<=MAX;i++){
        int nk = k + i*(i+1)/2;
        if(nk > MAX) break;
        
        if(visited[nk][i%2] != -1 && visited[nk][i%2] <= i) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}