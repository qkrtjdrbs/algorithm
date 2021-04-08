#include <iostream>
#include <tuple>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int T,start,target;
bool check[10000],visit[10000];

int main(){
    for(int i=2;i<10000;i++){
        if(check[i]==false){
            for(int j=i+i;j<10000;j+=i)
                check[j]=true;
        }
    }
    cin >> T;
    while(T--){
        cin >> start >> target;
        memset(visit, false, sizeof(visit));
        queue<pair<int,int>> q;
        q.push({start,0});
        visit[start]=true;
        while(!q.empty()){
            int num, cnt;
            tie(num, cnt)=q.front(); q.pop();
            if(num==target){
                cout << cnt << '\n';
                break;
            }
            string x=to_string(num);
            for(int i=0;i<4;i++){
                for(int j=0;j<10;j++){
                    if(i==0 && j==0) continue;
                    if(x[i]==j) continue;
                    string tmp = x;
                    x[i]=j+'0';
                    int t=stoi(x);
                    if(check[t]==false && visit[t]==false){
                        visit[t]=true;
                        q.push({t,cnt+1});
                    }
                    x = tmp;
                }
            }
        }
        if(visit[target]==false){
            cout << "Impossible" << '\n';
        }
    }
}