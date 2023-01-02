#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    col--;
    priority_queue<tuple<int, int, int>> pq;
    for(int i=0;i<data.size();i++){
        pq.push({-data[i][col], data[i][0], i});
    }

    vector<vector<int>> tmp;
    while(!pq.empty()){
        auto [x, k, idx] = pq.top();
        x = -x;
        tmp.push_back(data[idx]);
        pq.pop();
    }
    data = tmp;

    vector<int> sums;
    for(int i=row_begin-1;i<row_end;i++){
        int res = 0;
        for(int j=0;j<data[i].size();j++){
            res += (data[i][j] % (i+1));
        }
        sums.push_back(res);
    }

    int ans = sums[0];
    for(int i=1;i<sums.size();i++){
        ans ^= sums[i];
    }
    return ans;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cout << solution({{2, 2, 6}, {1, 5, 10}, {4, 2, 9}, {3, 8, 3}}, 2, 2, 3);
}