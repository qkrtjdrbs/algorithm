#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> v;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> s;
    string tmp = "";
    for(char i=0;i<s.size();i++){
        if(s[i] == ':'){
            if(tmp != "") v.push_back(tmp);
            tmp = "";
            if(s[i+1] == ':'){
                v.push_back("zero");
                i++;
            }
        } else {
            tmp += s[i];
        }
    }
    if(tmp != "") v.push_back(tmp);
    for(int i=0;i<v.size();i++){
        if(0 < i && i < v.size()) cout << ":";
        if(v[i] == "zero"){
            for(int j=0;j<9-v.size();j++){
                cout << "0000";
                if(j != 8-v.size()) cout << ":";
            }
        } else {
            string z = "0000";
            string res = z.substr(0, 4-v[i].size()) + v[i];
            cout << res;
        }
    }
}