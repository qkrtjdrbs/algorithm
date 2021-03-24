#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;
int n,d,p;
bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    return a.second > b.second;
}
int main(){
    cin >> n;
    vector<pair<int,int>> univ(n);
    for(int i=0;i<n;i++){
        cin >> univ[i].first >> univ[i].second;
    }
    sort(univ.begin(), univ.end(), cmp);
    long long ans = 0;
    priority_queue<int> pq;
    int x = 0;
    for(int i=10000; i>=1; i--){
        while(x < n && univ[x].second >= i){
            pq.push(univ[x++].first);
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}