#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    stack<string> stack;
    string s;

    getline(cin, s);
    bool match = false;
    int unmatched = 0;
    int num = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{' || c == '<')
        {
            stack.push(string(1, c));
        }

        if (c == '>' || c == ')' || c == '}' || c == ']')
        {
            if (!stack.empty())
            {
                string v = stack.top();
                if (c == ')' && v == "(")
                {
                    stack.pop();
                    num++;
                }
                if (c == '}' && v == "{")
                {
                    stack.pop();
                    num++;
                }
                if (c == ']' && v == "[")
                {
                    stack.pop();
                    num++;
                }
                if (c == '>' && s[i + 1] == '>' && v == "<<")
                {
                    stack.pop();
                    i++;
                    num++;
                }
                else if (c == '>' && v == "<")
                {
                    stack.pop();
                    num++;
                }
                else
                {
                    match = false;
                    unmatched++;
                }
            }
            else
            {
                match = false;
                unmatched++;
            }
        }
    }
    unmatched += stack.size();

    if (stack.empty())
    {
        match = true;
    }
    if (unmatched == 0 )
    {
        cout << num << " matched";
    }
    else
    {
        cout << unmatched << " unmatched" << endl;
        cout << num << " matched" << endl;
    }
    return 0;
}