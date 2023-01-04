#include <bits/stdc++.h>
using namespace std;

vector<int> enemies;

bool check(int mid, int n, int k){
    vector<int> tmp;
    for(int i=0;i<=mid;i++){
        tmp.push_back(enemies[i]);
    }
    sort(tmp.begin(), tmp.end());
    reverse(tmp.begin(), tmp.end());

    long long res = 0;
    for(int i=k;i<tmp.size();i++){
        res += tmp[i];
    }
    if(res <= n) return true;
    return false;
}

int solution(int n, int k, vector<int> e) {
    enemies = e;
    int l=0, r=enemies.size()-1, ans=0;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid, n, k)){
            l = mid+1;
            ans = max(ans, mid);
        } else {
            r = mid-1;
        }
    }
    return ++ans;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cout << solution(7, 3, {4, 2, 4, 5, 3, 3, 1}) << '\n';
    cout << solution(2, 4, {3, 3, 3, 3}) << '\n';
}