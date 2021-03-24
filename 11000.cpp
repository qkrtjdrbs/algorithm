#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int n, ans;
struct cmp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first > b.first;
    };
};
int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    priority_queue<int, vector<int>, greater<int>> alloc_pq;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        pq.push({s, t});
    }
    while (!pq.empty())
    {
        int f, s;
        tie(f, s) = pq.top();
        if (alloc_pq.empty())
        {
            alloc_pq.push(s);
            ans += 1;
        }
        else
        {
            int alloc_s = alloc_pq.top();
            if (alloc_s <= f)
            {
                alloc_pq.pop();
                alloc_pq.push(s);
            }
            else
            {
                alloc_pq.push(s);
            }
        }
        pq.pop();
    }
    cout << alloc_pq.size();
}