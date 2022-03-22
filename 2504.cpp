#include <bits/stdc++.h>
using namespace std;

long long ans;
string str;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> str;
    stack<char> st;
    long long res = 1;
    for(int i=0;i<str.size();i++){
        char x = str[i];
        if(x == '(' || x == '['){
            if(x == '(') res *= 2;
            else res *= 3;
            st.push(x);
        } else if(x == ')') {
            if(st.empty()){
                cout << 0;
                return 0;
            }
            if(st.top() != '('){
                cout << 0;
                return 0;
            } else {
                if(str[i-1] == '(') ans += res;
                res /= 2;
                st.pop();
            }
        } else if(x == ']'){
            if(st.empty()){
                cout << 0;
                return 0;
            }
            if(st.top() != '['){
                cout << 0;
                return 0;
            } else {
                if(str[i-1] == '[') ans += res;
                res /= 3;
                st.pop();
            }
        }
    }
    cout << (st.empty() ? ans : 0);
}