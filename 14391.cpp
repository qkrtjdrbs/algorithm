#include <iostream>
#include <algorithm>
using namespace std;
int n,m,paper[4][4],ans=0;

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            scanf("%1d",&paper[i][j]);
    }
    int ans=0;
    for(int i=0;i<(1 << n*m);i++){
        int sum=0;
        for(int j=0;j<n;j++){
            int cur=0;
            for(int k=0;k<m;k++){
                int x=j*m+k;
                if((i&(1<<x))==0){
                    cur=10*cur+paper[j][k];
                }
                else{
                    sum+=cur;
                    cur=0;
                }
            }
            sum+=cur;
        }
        for(int j=0;j<m;j++){
            int cur=0;
            for(int k=0;k<n;k++){
                int x=k*m+j;
                if((i&(1 << x))){
                    cur=10*cur+paper[k][j];
                }
                else{
                    sum+=cur;
                    cur=0;
                }
            }
            sum+=cur;
        }
        ans=max(ans,sum);
    }
    printf("%d",ans);
}