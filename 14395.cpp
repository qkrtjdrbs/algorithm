#include <bits/stdc++.h>
#define MAX 1000000000
using namespace std;

int s, t;
set<int> visited;
vector<string> ans;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> s >> t;
    if(s == t){
        cout << 0;
        return 0;
    }
    queue<pair<int, string>> q;
    q.push({s, ""});
    visited.insert(s);
    while(!q.empty()){
        int cur; string res;
        tie(cur, res) = q.front();
        q.pop();

        if(cur == t) ans.push_back(res);

        if(cur <= sqrt((double)MAX) && visited.find(cur*cur) == visited.end()){
            q.push({cur*cur, res+"*"});
            visited.insert(cur*cur);
        }
        if(cur <= MAX / 2 && visited.find(2*cur) == visited.end()){
            q.push({2*cur, res+"+"});
            visited.insert(2*cur);
        }
        if(visited.find(0) == visited.end()){
            q.push({0, res+"-"});
            visited.insert(0);
        }
        if(cur != 0 && visited.find(1) == visited.end()){
            q.push({1, res+"/"});
            visited.insert(1);
        }
    } 
    sort(ans.begin(), ans.end());
    ans.size() ? cout << ans[0] : cout << -1;
}