#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k, visited[2][500001];

void bfs(int who, int pos){
    queue<int> q;
    q.push(pos);
    visited[who][pos] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(who == 0){
            if(x - 1 >= 0 && !visited[who][x-1]){
                visited[who][x-1] = visited[who][x] + 1;
                q.push(x-1);
            }
            if(x + 1 <= 500000 && !visited[who][x+1]){
                visited[who][x+1] = visited[who][x] + 1;
                q.push(x+1);
            }
            if(x*2 <= 500000 && !visited[who][x*2]){
                visited[who][x*2] = visited[who][x] + 1;
                q.push(x*2);
            }
        } else {
            if(x - 1 >= 0 && !visited[who][x]){
                visited[who][x] += (visited[who][x] + 1);
                q.push(x-1);
            }
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
}