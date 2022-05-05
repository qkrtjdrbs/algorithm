#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        string str, endstr;
        cin >> str;
        endstr = str;
        sort(endstr.begin(), endstr.end());
        reverse(endstr.begin(), endstr.end());
        if(str == endstr){
            cout << str << '\n';
            continue;
        }
        int cnt=0;
        do{
            if(cnt == 1){
                cout << str << '\n';
                break;
            }
            cnt++;
        }while(next_permutation(str.begin(), str.end()));
    }
}