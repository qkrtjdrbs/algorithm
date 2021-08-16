#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int width, n;
    while(scanf("%d\n%d", &width, &n) == 2){
        vector<int> piece;
        width *= 10000000;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            piece.push_back(x);
        }
        sort(piece.begin(), piece.end());
        int start = 0, end = n-1;
        while(start < end){
            long long tmp = piece[start] + piece[end];
            if(tmp > width){
                end--;
            } else if(tmp < width){
                start++;
            } else {
                break;
            }
        }
        start >= end ? cout << "danger" : cout << "yes " << piece[start] << " " << piece[end];
        cout << '\n';
    }
}
