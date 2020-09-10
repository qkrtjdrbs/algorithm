#include <iostream>
using namespace std;
int n,a[100001],dp[100001],ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++){
        dp[i]=a[i];
        if(dp[i-1]+a[i] > a[i]){
            dp[i]=dp[i-1]+a[i];
        }
    }
    ans=dp[1];
    for(int i=2;i<=n;i++){
        if(ans<dp[i])
            ans=dp[i];
    }
    cout << ans;
}