#include <bits/stdc++.h>
using namespace std;

int n, k, area;
vector<pair<int, int>> points;
vector<tuple<int, int, int>> holes;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    cin >> k;
    for(int i=0;i<k;i++){
        int a, b, c;
        cin >> a >> b >> c >> b;
   
    }
    cout << area;
}