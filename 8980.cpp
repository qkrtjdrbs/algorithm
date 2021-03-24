#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int n, c, m, ans;

struct cmp
{
    bool operator()(tuple<int, int, int> a, tuple<int, int, int> b)
    {
        if (get<1>(a) == get<1>(b))
        {
            return get<0>(a) > get<0>(b);
        }
        return get<1>(a) > get<1>(b);
    }
};

int main()
{
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> truck;
    cin >> n >> c >> m;
    int currC = c;
    for (int i = 0; i < m; i++)
    {
        int f, s, t;
        cin >> f >> s >> t;
        truck.push({f, s, t});
    }
    for (int vil = 1; vil <= n; vil++)
    {
        while (!truck.empty())
        {
            int tf, ts, tt;
            tie(tf, ts, tt) = truck.top();
            if (ts == vil)
            {
                truck.pop();
                currC += tt;
                ans += tt;
            }
            else
            {
                break;
            }
        }
    }
    cout << ans;
}