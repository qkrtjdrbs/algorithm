#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int t,dist[10000],from[10000],A,B;
char com[10000];
void print(int a, int b){
    if(a==b) return;
    else{
        print(A, from[b]);
        cout << com[b];
    }
}
void bfs(){
    queue<int> q;
    q.push(A);
    dist[A]=0;
    while(!q.empty()){
        int x=q.front(); q.pop();
        int result=2*x;
        if(result>9999){
            result%=10000;
        }
        if(dist[result]==-1){
            q.push(result);
            dist[result]=dist[x]+1;
            from[result]=x;
            com[result]='D';
            if(result==B){
                print(A,B);
            }
        }
        
        result=x-1;
        if(result==-1){
            result=9999;
        }
        if(dist[result]==-1){
            q.push(result);
            dist[result]=dist[x]+1;
            from[result]=x;
            com[result]='S';
            if(result==B){
                print(A,B);
            }
        }

        result=(x%1000)*10+(x/1000);
        if(dist[result]==-1){
            q.push(result);
            dist[result]=dist[x]+1;
            from[result]=x;
            com[result]='L';
            if(result==B){
                print(A,B);
            }
        }

        result=(x%10)*1000+(x/10);
        if(dist[result]==-1){
            q.push(result);
            dist[result]=dist[x]+1;
            from[result]=x;
            com[result]='R';
            if(result==B){
                print(A,B);
            }
        }
    }
}
int main(){
    cin >> t;
    while(t--){
        memset(dist, -1, sizeof(dist));
        for(int i=0;i<10000;i++){
            com[i]=' ';
        }
        cin >> A >> B;
        bfs();
        cout << '\n';
    }
}