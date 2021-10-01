#include <bits/stdc++.h>
using namespace std;

int n, snow[601];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> snow[i];
    }
    sort(snow, snow+n);
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int elsa = snow[i] + snow[j], l=0, r=n-1;
            while(l < r){
                while(l == i || l == j) l++;
                while(r == i || r == j) r--;
                if(l >= r) break;
                int anna = snow[l] + snow[r];
                ans = min(ans, abs(elsa-anna));
                if(anna > elsa) r--;
                else if(anna < elsa) l++;
                else break;
            }
        }
    }
    
    cout << ans;
}