#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<string> logs[7];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> q;
    for(int i=0;i<n;i++){
        string ymd, tmp, t, conv = "";
        cin >> ymd >> tmp;
        t = tmp.substr(0, 8);
        int idx = stoi(tmp.substr(9));
        for(int i=1;i<=idx;i++) logs[i].push_back(ymd + t);
    }
    for(int i=1;i<=6;i++) sort(logs[i].begin(), logs[i].end());
    for(int i=0;i<q;i++){
        string startL = "", endL = "", f, m, l;
        cin >> f >> m >> l;
        startL += (f + m.substr(0, 8));
        endL += (m.substr(9) + l.substr(0, 8));
        int idx = stoi(l.substr(9));
        auto left = lower_bound(logs[idx].begin(), logs[idx].end(), startL);
        auto right = upper_bound(logs[idx].begin(), logs[idx].end(), endL);
        cout << right - left << '\n';
    }
}