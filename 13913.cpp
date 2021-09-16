#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int n,k,visit[100001],dist[100001],from[100001];
stack<int> ans;
void bfs(){
    queue<int> q;
    q.push(n);
    visit[n]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(x==k) {
            cout << dist[k] << '\n';
            for(int i=k;i!=n;i=from[i]){
                ans.push(i);
            }
            ans.push(n);
            while(!ans.empty()){
                cout << ans.top() << ' ';
                ans.pop();
            }
        }
        if(0<=x-1 && x-1<=100000){
            if(visit[x-1]==0){
                visit[x-1]=1;
                q.push(x-1);
                dist[x-1]=dist[x]+1;
                from[x-1]=x;
            }
        }
        if(0<=x+1 && x+1<=100000){
            if(visit[x+1]==0){
                visit[x+1]=1;
                q.push(x+1);
                dist[x+1]=dist[x]+1;
                from[x+1]=x;
            }
        }
        if(0<=x*2 && x*2<=100000){
            if(visit[x*2]==0){
                visit[x*2]=1;
                q.push(x*2);
                dist[x*2]=dist[x]+1;
                from[x*2]=x;
            }
        }
    }
}

int main(){
    cin >> n >> k;
    bfs();
}