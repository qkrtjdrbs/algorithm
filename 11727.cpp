#include <iostream>
#define X 10007
using namespace std;

int n, dp[1001];

int main(){
    cin >> n;
    dp[1]=1; dp[2]=3;
    for(int i=3;i<=n;i++){
        if((2*dp[i-2]%X + dp[i-1]%X) >= X)
            dp[i]=(2*dp[i-2]%X + dp[i-1]%X)-X;
        else
            dp[i]=(2*dp[i-2]%X + dp[i-1]%X);
    }
    cout << dp[n];
}