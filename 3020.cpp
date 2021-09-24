#include <bits/stdc++.h>
using namespace std;

int n, h, psum[1000001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> h;
    for(int i=1;i<=n;i++){
        int idx;
        cin >> idx;
        if(i % 2 == 0) {
            psum[0]++;
            psum[2*idx]--;
        } else {
            psum[2*h-(2*idx-1)]++;
        }
    }
    for(int i=1;i<=2*h;i++){
        psum[i] += psum[i-1];
    }
    int height = 987654321, cnt = 0;
    for(int i=1;i<=2*h;i+=2){
        if(psum[i] < height) {
            height = psum[i];
            cnt = 1;
        } else if(psum[i] == height) {
            cnt++;
        }
    }
    cout << height << " " << cnt;
}