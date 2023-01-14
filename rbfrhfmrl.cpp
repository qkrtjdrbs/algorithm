#include <bits/stdc++.h>
using namespace std;

int cnt[10000001];

int solution(int k, vector<int> tang) {
    int ans=0, res=0;
    for(auto i : tang) cnt[i]++;
    
    priority_queue<int> pq;
    for(int i=1;i<=10000000;i++){
        if(cnt[i]){
            pq.push(cnt[i]);
        }
    }

    while(!pq.empty()){
        if(res >= k) break;
        int x = pq.top();
        pq.pop();
        ans++;
        res += x;
    }

    return ans;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cout << solution(6, {1, 3, 2, 5, 4, 5, 2, 3}) << '\n';
    // cout << solution(4, {1, 3, 2, 5, 4, 5, 2, 3}) << '\n';
    // cout << solution(2, {1,1,1,1,2,2,2,3}) << '\n';
}