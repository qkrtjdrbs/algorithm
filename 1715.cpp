#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, x, ans;

int main()
{
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pq.push(x);
    }
    while (pq.size() != 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans = ans + a + b;
        pq.push(a + b);
    }
    cout << ans;
}