#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> b, a;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        b.push_back(str);
    }
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        a.push_back(str);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int idx = find(b.begin(), b.end(), a[i]) - b.begin();
        for(int j=i+1;j<n;j++){
            int k = find(b.begin(), b.end(), a[j]) - b.begin();
            if(idx > k && i < j){
                ans++;
                break;
            }
        }
    }
    cout << ans;
}