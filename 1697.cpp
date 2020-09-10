#include <iostream>
#include <queue>
using namespace std;
int n,k,visit[100001],dist[100001];
void bfs(){
    queue<int> q;
    q.push(n);
    visit[n]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(x==k) return;
        if(0<=x-1 && x-1<=100000){
            if(visit[x-1]==0){
                visit[x-1]=1;
                q.push(x-1);
                dist[x-1]=dist[x]+1;
            }
        }
        if(0<=x+1 && x+1<=100000){
            if(visit[x+1]==0){
                visit[x+1]=1;
                q.push(x+1);
                dist[x+1]=dist[x]+1;
            }
        }
        if(0<=x*2 && x*2<=100000){
            if(visit[x*2]==0){
                visit[x*2]=1;
                q.push(x*2);
                dist[x*2]=dist[x]+1;
            }
        }
    }
}

int main(){
    cin >> n >> k;
    bfs();
    cout << dist[k];
}