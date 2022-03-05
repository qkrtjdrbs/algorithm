#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1000000000;

int n, num[10001];
vector<string> ops;

bool opsInput(){
    while(1){
        string s;
        cin >> s;
        if(s == "NUM"){
            string x;
            cin >> x;
            s += " " + x;
        }
        ops.push_back(s);
        if(s == "END"){
            break;
        } else if(s == "QUIT"){
            return false;
        }
    }
    return true;
}

void numInput(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> num[i];
    string next;
    getline(cin, next);
}

void operation(){
    for(int i=0;i<n;i++){
        stack<ll> st;
        st.push(num[i]);
        bool e = false;
        for(auto op : ops){
            string c = op.substr(0, 3);
            if(c == "NUM"){
                ll x = stoi(op.substr(4));
                if(abs(x) > INF){
                    e = true;
                    break;
                }
                st.push(x);
            } else if(c == "POP") {
                if(st.empty()){
                    e = true;
                    break;
                }
                st.pop();
            } else if(c == "INV") {
                if(st.empty()){
                    e = true;
                    break;
                }
                int x = st.top();
                st.pop();
                st.push(-x);
            } else if(c == "DUP") {
                if(st.empty()){
                    e = true;
                    break;
                }
                st.push(st.top());
            } else if(c == "SWP") {
                if(st.empty()){
                    e = true;
                    break;
                }
                int a = st.top(); st.pop();
                if(st.empty()){
                    e = true;
                    break;
                }
                int b = st.top(); st.pop();
                st.push(a); st.push(b);
            } else if(c == "ADD") {
                if(st.empty()){
                    e = true;
                    break;
                }
                int a = st.top(); st.pop();
                if(st.empty()){
                    e = true;
                    break;
                }
                int b = st.top(); st.pop();
                int c = a + b;
                if(abs(c) > INF){
                    e = true;
                    break;
                }
                st.push(c);
            } else if(c == "SUB") {
                if(st.empty()){
                    e = true;
                    break;
                }
                int a = st.top(); st.pop();
                if(st.empty()){
                    e = true;
                    break;
                }
                int b = st.top(); st.pop();
                ll c = b - a;
                if(abs(c) > INF){
                    e = true;
                    break;
                }
                st.push(c);
            } else if(c == "MUL") {
                if(st.empty()){
                    e = true;
                    break;
                }
                ll a = st.top(); st.pop();
                if(st.empty()){
                    e = true;
                    break;
                }
                ll b = st.top(); st.pop();
                ll c = a * b;
                if(abs(c) > INF){
                    e = true;
                    break;
                }
                st.push(c);
            } else if(c == "DIV") {
                if(st.empty()){
                    e = true;
                    break;
                }
                int a = st.top(); st.pop();
                if(st.empty()){
                    e = true;
                    break;
                }
                int b = st.top(); st.pop();
                if(!a){
                    e = true;
                    break;
                }
                int c = abs(b) / abs(a);
                if((b < 0 && a > 0) || (b > 0 && a < 0)){
                    c = -c;
                }
                st.push(c);
            } else if(c == "MOD") {
                if(st.empty()){
                    e = true;
                    break;
                }
                int a = st.top(); st.pop();
                if(st.empty()){
                    e = true;
                    break;
                }
                int b = st.top(); st.pop();
                if(!a){
                    e = true;
                    break;
                }
                int c = abs(b) % abs(a);
                if(b < 0){
                    c = -c;
                }
                st.push(c);
            }
        }
        if(e || st.size() != 1){
            cout << "ERROR\n";
            continue;
        }
        if(st.size() == 1){
            cout << st.top() << '\n';
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    while(1){
        memset(num, 0, sizeof(num));
        ops.clear();
        if(!opsInput()) break;
        numInput();
        operation();
        cout << '\n';
    }
}