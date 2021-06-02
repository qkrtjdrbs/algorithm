#include <bits/stdc++.h>
using namespace std;
int n, s, a[100001];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    for(int i=0;i<n;i++)
        cin >> a[i];
    int len = 987654321, cnt = 1;
    int i = 0, j = 1, sum = a[0];
    while(i < j && j <= n){
        if(sum >= s){
            len = min(cnt, len);
            sum -= a[i++];
            cnt--;
        } else if(sum < s){
            sum += a[j++];
            cnt++;
        }
    }
    if(len == 987654321) cout << 0;
    else cout << len;
}