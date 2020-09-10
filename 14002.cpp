#include <iostream>
#include <algorithm>
using namespace std;
int a[1001], d[1001], v[1001], ans, max_i=0;
void go(int x){
    if(x==0) return;
    go(v[x]);
    cout << a[x] << ' ';
}
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        d[i] = 1;
        for (int j=1; j<i; j++) {
            if (a[j] < a[i] && d[j]+1 > d[i]) {
                d[i] = d[j]+1;
                v[i] = j;
            }
        }
    }
    ans=d[0];
    for(int i=1;i<=n;i++){
        if(ans < d[i]){
            ans=d[i];
            max_i=i;
        }
    }
    cout << ans << '\n';
    go(max_i);
}