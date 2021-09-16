#include <iostream>
#include <deque>
#include <string>
using namespace std;
int n, k;
string input;

int main()
{
    deque<char> dq;
    cin >> n >> k >> input;
    int len = input.size();
    for (int i = 0; i < len; i++)
    {
        while (!dq.empty() && k && dq.back() < input[i])
        {
            dq.pop_back();
            k -= 1;
        }
        dq.push_back(input[i]);
    }
    while (k--)
    {
        dq.pop_back();
    }
    while (!dq.empty())
    {
        cout << dq.front();
        dq.pop_front();
    }
}