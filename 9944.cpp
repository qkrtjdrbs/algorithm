#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[31][31];
vector<pair<int, int>> start;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j] == '.'){
                start.push_back({i, j});
                k++;
            }
        }
    }
    
}