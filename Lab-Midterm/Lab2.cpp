#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> stack;
    string input;
    getline(cin, input);
    int match = 0;

    for (int i = 0; i < input.length(); i++)
    {
        char open = input[i];
        if (open == '(' || open == '[' || open == '{' || open == '<')
        {
            // <<
            if (open == '<' && input[i + 1] == '<')
            {
                stack.push("<<");
                i++;
            }
            else
            {
                stack.push(string(1, open));
            }
        }
        else if (open == ')' || open == ']' || open == '}' || open == '>')
        {
            if (open == '>' && input[i + 1] == '>')
            {
                if (stack.empty() || stack.top() != "<<")
                {
                    cout << "Not matched" << endl;
                    cout << match << " match" << endl;
                }
                stack.pop();
                i++;
                match++;
            }
            else
            {
                if (stack.empty())
                {
                    cout << "Not matched" << endl;
                    cout << match << " match" << endl;
                }
                string close = stack.top();
                stack.pop();
                if (open == '(' && close == ")" || open == '[' && close == "]" || open == '{' && close == "}" || open == '<' && close == ">")
                {
                    cout << "Not matched" << endl;
                    cout << match << " match" << endl;
                }
                match++;
            }
        }
    }
    if (stack.empty() && match > 0)
    {
        cout << match << " matched" << endl;
    }
    else
    {
        cout << "Not matched" << endl;
        cout << match << " match" << endl;
    }

    return 0;
}
