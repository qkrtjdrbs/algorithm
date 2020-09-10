#include <iostream>
#define X 1000000000
using namespace std;
long long dp[101][10],ans=0;

int main(){
    int N;
    scanf("%d",&N);
    for(int i=1;i<=9;i++)
        dp[1][i]=1;
    for(int i=2;i<=N;i++){
        for(int j=0;j<=9;j++){
            if(j==0) dp[i][j]=dp[i-1][j+1];
            else if(j==9) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
            dp[i][j] %= X;
        }
    }
    for(int i=0;i<=9;i++)
        ans+=dp[N][i];
    printf("%lld", ans%X);
}