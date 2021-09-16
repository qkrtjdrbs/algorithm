#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;
int n, k;
int main()
{
    cin >> n >> k;
    vector<pair<int, int>> j(n);
    vector<int> bag(k);
    for (int i = 0; i < n; i++)
    {
        cin >> j[i].first >> j[i].second;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> bag[i];
    }
    sort(j.begin(), j.end());
    sort(bag.begin(), bag.end());
    long long ans = 0;
    priority_queue<int> pq;
    int x = 0;
    for (int i = 0; i < k; i++)
    {
        while (x < n && j[x].first <= bag[i])
        {
            pq.push(j[x++].second);
        }
        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}