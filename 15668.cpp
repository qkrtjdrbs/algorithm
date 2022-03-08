#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> s;
    n = stoi(s);
    int len = s.size();
    for(int i=1;i<=min(98765, n/2);i++){
        bool visited[10], flag=true;
        memset(visited, 0, sizeof(visited));
        string a = to_string(i), b = to_string(n - i);
        for(auto x : a){
            int idx = x - '0';
            if(visited[idx]){
                flag = false;
                break;
            }
            visited[idx] = 1; 
        }
        for(auto x : b){
            int idx = x - '0';
            if(visited[idx]){
                flag = false;
                break;
            }
            visited[idx] = 1; 
        }
        if(flag){
            cout << a << " + " << b;
            return 0;
        }
    }
    cout << -1;
}