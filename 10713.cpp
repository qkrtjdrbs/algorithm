#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n, m;
long long psum[MAX];
vector<int> order;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        order.push_back(x);
    }
    for(int i=0;i<m-1;i++){
        int minX, maxX;
        minX = min(order[i], order[i+1]);
        maxX = max(order[i], order[i+1]);
        psum[minX]++; psum[maxX]--;
    }
    for(int i=1;i<=n;i++){
        psum[i] += psum[i-1];
    }
    long long ans = 0;
    for(int i=1;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a * psum[i] > c + b * psum[i]){
            ans += (c + b * psum[i]);
        } else {
            ans += a * psum[i];
        }
    }
    cout << ans;
}