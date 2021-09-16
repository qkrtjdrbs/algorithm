#include <iostream>
using namespace std;
int k,s[14],ans[6];
void go(int index, int cnt){
    if(cnt==6){
        for(int i=0;i<6;i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    if(index==k) return;
    ans[cnt]=s[index];
    go(index+1, cnt+1);
    go(index+1, cnt);
}

int main(){
    while(1){
        cin >> k;
        if(k==0) return 0;
        for(int i=0;i<k;i++)
            cin >> s[i];
        go(0,0);
        cout << '\n';
    }
}