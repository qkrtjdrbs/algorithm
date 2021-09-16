#include <iostream>
#include <string>
using namespace std;
int n,sign[10][10],ans[10];
string s;
bool check(int index){
    int sum=0;
    for(int i=index;i>=0;i--){
        sum += ans[i];
        if(sign[i][index]==-1){
            if(sum >= 0) return false;
        }else if(sign[i][index]==1){
            if(sum <= 0) return false;
        }else if(sign[i][index]==0){
            if(sum != 0) return false;
        }
    }
    return true;
}
bool go(int index){
    if(index==n) return true;
    for(int i=0;i<=10;i++){
        ans[index]=sign[index][index]*i;
        if(check(index) && go(index+1)) return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> s;
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++){
            if(s[cnt]=='+'){
                sign[i][j]=1;
            }else if(s[cnt]=='-'){
                sign[i][j]=-1;
            }else{
                sign[i][j]=0;
            }
            cnt+=1;
        }
    }
    go(0);
    for(int i=0;i<n;i++)
        cout << ans[i] << ' ';
}