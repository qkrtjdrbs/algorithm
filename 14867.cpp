#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
set<pair<int, int>> visited;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> a >> b >> c >> d;
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    visited.insert({0, 0});
    while(!q.empty()){
        int ca, cb, cnt;
        tie(ca, cb, cnt) = q.front();
        q.pop();
        if(ca == c && cb == d){
            cout << cnt;
            return 0;
        }
        //fill
        if(visited.find({a, cb}) == visited.end()) {
            visited.insert({a, cb});
            q.push({a, cb, cnt+1});
        }
        if(visited.find({ca, b}) == visited.end()) {
            visited.insert({ca, b});
            q.push({ca, b, cnt+1});
        }
        //empty
        if(visited.find({0, cb}) == visited.end()) {
            visited.insert({0, cb});
            q.push({0, cb, cnt+1});
        }
        if(visited.find({ca, 0}) == visited.end()) {
            visited.insert({ca, 0});
            q.push({ca, 0, cnt+1});
        }
        //move
        if(ca > b - cb){
            if(visited.find({ca-(b-cb), b}) == visited.end()) {
                visited.insert({ca-(b-cb), b});
                q.push({ca-(b-cb), b, cnt+1});
            }
        } else {
            if(visited.find({0, cb+ca}) == visited.end()) {
                visited.insert({0, cb+ca});
                q.push({0, cb+ca, cnt+1});
            }
        }
        if(cb > a - ca){
            if(visited.find({a, cb-(a-ca)}) == visited.end()) {
                visited.insert({a, cb-(a-ca)});
                q.push({a, cb-(a-ca), cnt+1});
            }
        } else {
            if(visited.find({ca+cb, 0}) == visited.end()) {
                visited.insert({ca+cb, 0});
                q.push({ca+cb, 0, cnt+1});
            }
        }
    }
    cout << -1;
}