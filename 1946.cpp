#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
int t, n, ans;
struct cmp1
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first > b.first;
    };
};
struct cmp2
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first < b.first;
    };
};
bool check(priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> &tq, int f, int s)
{
    int vf, vs;
    tie(vf, vs) = tq.top();
    if (f > vf && s > vs)
        return false;
    return true;
}
int main()
{
    cin >> t;
    while (t--)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> tq;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int f, s;
            cin >> f >> s;
            pq.push({f, s});
        }
        while (!pq.empty())
        {
            int f, s;
            tie(f, s) = pq.top();
            pq.pop();
            if (tq.empty())
            {
                tq.push({f, s});
            }
            else
            {
                bool c = check(tq, f, s);
                if (c)
                {
                    tq.push({f, s});
                }
            }
        }
        cout << tq.size() << '\n';
    }
}