#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector <int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int cnt=0;
    for(int i=1;i<n;i++){
        if(a[i-1]<a[i]){
            cnt+=1;
        }
    }
    if(cnt==n-1){
        cout << "-1";
        return 0;
    }
    prev_permutation(a.begin(), a.end());
    for(int i=0;i<n;i++){
        cout << a[i] << ' ';
    }
}