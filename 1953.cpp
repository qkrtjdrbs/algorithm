#include <bits/stdc++.h>
using namespace std;

int n, visited[101];
bool dislike[101][101];
vector<int> red, blue;

void go(int x, int team){
    visited[x] = team;
    for(int i=1;i<=n;i++){
        if(dislike[i][x] && !visited[i]){
            go(i, team * (-1));
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int len;
        cin >> len;
        for(int j=0;j<len;j++){
            int x;
            cin >> x;
            dislike[i][x] = dislike[x][i] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            go(i, 1);
        }
    }
    for(int i=1;i<=n;i++){
        if(visited[i] == 1) red.push_back(i);
        else blue.push_back(i);
    }
    cout << blue.size() << '\n';
    for(auto b : blue) cout << b << " ";
    cout << '\n';
    cout << red.size() << '\n';
    for(auto r : red) cout << r << " ";
    cout << '\n';
}