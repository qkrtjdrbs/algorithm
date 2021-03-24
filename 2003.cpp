#include <bits/stdc++.h>
using namespace std;
int n, m, a[10001], ans;

void go(){
    int start=0, end=0, sum=0;
    while(start!=n){
        if(end >= n){
            sum = 0;
            start += 1;
            end = start;
        }
        if(start==end){
            if(a[start]<m){
                sum += a[start];
                end += 1;
            } else if(a[start]>m){
                sum = 0;
                start += 1;
                end += 1;
            } else {
                sum = 0;
                start += 1;
                end += 1;
                ans += 1;
            }
        } else {
            sum += a[end];
            if(sum < m){
                end += 1;
            } else if(sum > m){
                sum = 0;
                start += 1;
                end = start;
            } else {
                sum = 0;
                start += 1;
                end = start;
                ans += 1;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    go();
    cout << ans;
}