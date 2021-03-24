#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int ans = 987654321;
string a, b;

void recur(string a, string cur, int cnt){
    if(cur == a){
        ans = min(ans, cnt);
        return;
    }
    if(stoi(a) > stoi(cur)){
        ans = -1;
        return;
    }
    int len = cur.length();
    if(cur[len-1] == '1'){
        cur.pop_back();
        recur(a, cur, cnt+1);
    } else {
        int tmp = stoi(cur);
        if(tmp % 2 == 0){
            tmp /= 2;
            recur(a, to_string(tmp), cnt+1);
        } else {
            ans = -1;
            return;
        }
    }
}

int main(){
    cin >> a >> b;
    recur(a, b, 0);
    ans == -1 ? ans : ans += 1;
    cout << ans;
}