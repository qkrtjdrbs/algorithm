#include <bits/stdc++.h>
using namespace std;

int t, n;
string op = "+- ";
vector<string> ans;

void go(int cnt, string ops){
    if(cnt == n-1){
        ops += to_string(n);
        string res = "";
        for(auto x : ops){
            if(x != ' ') res += x;
        }
        vector<int> num;
        vector<char> oper;
        string tmp = "";
        for(auto x : res){
            if(isdigit(x)){
                tmp += x;
            } else {
                num.push_back(stoi(tmp));
                oper.push_back(x);
                tmp = "";
            }
        }
        num.push_back(stoi(tmp));
        int sum = num[0];
        for(int i=0;i<oper.size();i++){
            if(oper[i] == '+'){
                sum += num[i+1];
            } else if(oper[i] == '-'){
                sum -= num[i+1];
            }
        }
        if(sum == 0) ans.push_back(ops);
        return;
    }
    go(cnt+1, ops + to_string(cnt+1) + op[0]);
    go(cnt+1, ops + to_string(cnt+1) + op[1]);
    go(cnt+1, ops + to_string(cnt+1) + op[2]);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        ans.clear();
        cin >> n;
        go(0, "");
        sort(ans.begin(), ans.end());
        for(auto x : ans) cout << x << '\n';
        cout << '\n';
    }
}