#include <iostream>
#include <algorithm>
using namespace std;
int n,w[11][11],per[11],ans=987654321;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin >> w[i][j];
    }
    for(int i=1;i<=n;i++)
        per[i]=i;
    do
    {
        int sum=0;
        bool flag=true;
        for(int i=1;i<n;i++){
            if(!w[per[i]][per[i+1]]) flag=false;
            else{
                sum+=w[per[i]][per[i+1]];
            }
        }
        if(flag && w[per[n]][per[1]]){
            ans=min(ans, sum+w[per[n]][per[1]]);
        }
    } while (next_permutation(per, per+n));
    cout << ans;
}