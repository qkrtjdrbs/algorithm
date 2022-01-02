#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> ball;
vector<int> vol, psum, volByColor[200001], psumByColor[200001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    vol.push_back(0); psum.push_back(0);
    ball.push_back({0, 0});
    for(int i=1;i<=n;i++){
        int x, y;
        cin >> x >> y;
        ball.push_back({x, y});
        vol.push_back(y);
        volByColor[x].push_back(y);
    }
    sort(vol.begin(), vol.end());
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum += vol[i];
        psum.push_back(sum);
    }
    for(int i=1;i<=n;i++){
        volByColor[i].push_back(0);
        sort(volByColor[i].begin(), volByColor[i].end());
        int sum = 0;
        for(int j=0;j<volByColor[i].size();j++){
            sum += volByColor[i][j];
            psumByColor[i].push_back(sum);
        }
    }
    for(int i=1;i<=n;i++){
        int x, y;
        tie(x, y) = ball[i];
        int all = lower_bound(vol.begin(), vol.end(), y) - vol.begin();
        int sameBall = lower_bound(volByColor[x].begin(), volByColor[x].end(), y) - volByColor[x].begin();
        cout << psum[all-1] - psumByColor[x][sameBall-1] << '\n';
    }
}