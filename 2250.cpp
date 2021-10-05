#include <bits/stdc++.h>
using namespace std;

int n, tree[10001][2], refer[10001], x=1;

vector<int> width[10001];

void inorder(int idx, int y){
    if(tree[idx][0] != -1) inorder(tree[idx][0], y+1);
    width[y].push_back(x++);
    if(tree[idx][1] != -1) inorder(tree[idx][1], y+1);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int num, l, r;
        cin >> num >> l >> r;
        refer[num]++; refer[l]++; refer[r]++;
        tree[num][0] = l;
        tree[num][1] = r;
    }
    int root;
    for(int i=1;i<=10000;i++){
        if(refer[i] == 1) {
            root = i;
            break;
        }
    }
    inorder(root, 1);
    for(int i=1;i<=10000;i++) sort(width[i].begin(), width[i].end());
    int lv = 1, ans = 1;
    for(int i=2;i<=10000;i++) {
        if(width[i].size()){
            int w = width[i][width[i].size()-1] - width[i][0] + 1;
            if(w > ans){
                lv = i;
                ans = w;
            }
        }
    }
    cout << lv << " " << ans;
}