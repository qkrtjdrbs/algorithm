#include <iostream>
#include <queue>
using namespace std;
int n,k,visit[100001],dist[100001];
void bfs(){
    queue<int> q1;
    queue<int> q2;
    q1.push(n);
    visit[n]=1;
    while(!q1.empty()){
        int x=q1.front();
        q1.pop();
        if(0<=x*2 && x*2<=100000){
            if(visit[x*2]==0){
                visit[x*2]=1;
                q1.push(x*2);
                dist[x*2]=dist[x];
            }
        }
        if(0<=x-1 && x-1<=100000){
            if(visit[x-1]==0){
                visit[x-1]=1;
                q2.push(x-1);
                dist[x-1]=dist[x]+1;
            }
        }
        if(0<=x+1 && x+1<=100000){
            if(visit[x+1]==0){
                visit[x+1]=1;
                q2.push(x+1);
                dist[x+1]=dist[x]+1;
            }
        }
        if(q1.empty()){
            q1=q2;
            q2=queue<int> ();
        }
    }
}

int main(){
    cin >> n >> k;
    bfs();
    cout << dist[k] << '\n';
}