#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<char> s;
    string answer = "";
    string mid;
    cin >> mid;
    for (int i = 0; i < mid.length(); i++)
    {
        if (mid[i] >= 'A' && mid[i] <= 'Z')
        {
            answer += mid[i];
            continue;
        }
        else if (s.empty())
        {
            s.push(mid[i]);
        }
        else if (mid[i] == '(')
        {
            s.push(mid[i]);
        }
        else if(mid[i] == '*' || mid[i] == '/'){
            while(!s.empty() && (s.top() == '*' || s.top() == '/')){
                answer += s.top();
                s.pop();
            }
            s.push(mid[i]);
            continue;
        }
        else if(mid[i] == '+' || mid[i] == '-'){
            while(!s.empty() && s.top() != '('){
                answer += s.top();
                s.pop();
            }
            s.push(mid[i]);
            continue;
        }

        else if (mid[i] == ')')
        {
            while (s.top() != '(')
            {
                answer += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while (!s.empty())
    {
        answer += s.top();
        s.pop();
    }
    cout << answer;
}