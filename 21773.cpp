#include <bits/stdc++.h>
using namespace std;
int t, n;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t >> n;
    priority_queue<tuple<int, int, int>> pq;
    for(int i=0;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c, -a, b});
    }
    while(t-- && !pq.empty()){
        int prior, pid, time;
        tie(prior, pid, time) = pq.top();
        pq.pop(); pid = -pid;
        
        cout << pid << '\n';
        
        prior--;
        time--;
        if(time != 0){
            pq.push({prior, -pid, time});
        }
    }
}