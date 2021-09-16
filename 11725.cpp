#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int n,parent[100001];
bool visit[100001];
vector<int> V[100001];
void bfs(){
    queue<int> q;
    q.push(1);
    visit[1]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int y : V[x]){
            if(!visit[y]){
                visit[y]=true;
                parent[y]=x;
                q.push(y);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    bfs();
    for(int i=2;i<=n;i++){
        cout << parent[i] << '\n';
    }
}