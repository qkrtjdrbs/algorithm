#include <iostream>
using namespace std;
int T, x, y, M, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> M >> N >> x >> y;
        x-=1; y-=1;
        int i=x;
        for (i=x;i<=M*N;i+=M) {
            if ((i%N)==y) {
                cout << i+1 << '\n';
                break;
            }
        }
        if (i>M*N)
            cout << "-1" << '\n';
    }
}
