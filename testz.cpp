#include <bits/stdc++.h>
using namespace std;
set<string> s;

int main(){
    string a = "1234";
    string b = "4231";
    string c = "1324";
    s.insert(a);
    s.insert(b);
    s.insert(c);
    cout << s.size();
}