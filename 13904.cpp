#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int n, parent[1001], visit[1001], ans;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
};

int main(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    cin >> n;
    for(int i=0;i<n;i++){
        int d, w;
        cin >> d >> w;
        pq.push({d, w});
    }
    for(int i=0;i<n;i++){
        int d, w, alloc;
        tie(d, w) = pq.top();
        pq.pop();
        for(int j=d;j>0;j--){
            if(!visit[j]){
                visit[j]=1;
                ans += w;
                break;
            }
        }
    }
    cout << ans;
}

