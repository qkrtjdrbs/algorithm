#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int cnt = 0;
    string s;
    getline(cin, s);
    s += '\n';
    stack<char> word;
    for (char a : s)
    {
        if (a == ' ' || a == '\n' || a == '<')
        {
            while (!word.empty())
            {
                cout << word.top();
                word.pop();
            }
            if (cnt == 0)
                cout << a;
        }
        if (a == '<')
        {
            cnt = 1;
        }
        if (a == '>')
        {
            cnt = 0;
            cout << a;
        }
        if (cnt == 0 && a != '>' && a != ' ')
            word.push(a);
        if (cnt == 1 && a != '<')
        {
            cout << a;
        }
    }
}