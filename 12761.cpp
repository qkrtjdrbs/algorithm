#include <bits/stdc++.h>
using namespace std;

int a, b, n, m;
bool visited[100001];

int go(int cur){
    queue<pair<int, int>> q;
    q.push({cur, 0});
    while(!q.empty()){
        int x, cnt;
        tie(x, cnt) = q.front();
        q.pop();
        if(x == m) return cnt;
        if(x-1 >= 0 && !visited[x-1]){
            q.push({x - 1, cnt+1}); 
            visited[x-1] = 1;
        }
        if(x+1 <= 100000 && !visited[x+1]){
            q.push({x + 1, cnt+1});
            visited[x+1] = 1;
        }
        if(x-a >= 0 && !visited[x-a]){
            q.push({x - a, cnt+1}); 
            visited[x-a] = 1;
        }
        if(x+a <= 100000 && !visited[x+a]){
            q.push({x + a, cnt+1});
            visited[x+a] = 1;
        }
        if(x-b >= 0 && !visited[x-b]){
            q.push({x - b, cnt+1}); 
            visited[x-b] = 1;
        }
        if(x+b <= 100000 && !visited[x+b]){
            q.push({x + b, cnt+1});
            visited[x+b] = 1;
        }
        if(x*a <= 100000 && !visited[x*a]){
            q.push({x * a, cnt+1}); 
            visited[x*a] = 1;
        }
        if(x*b <= 100000 && !visited[x*b]){
            q.push({x * b, cnt+1});
            visited[x*b] = 1;
        }
    }
    return 0;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> a >> b >> n >> m;
    cout << go(n);
}