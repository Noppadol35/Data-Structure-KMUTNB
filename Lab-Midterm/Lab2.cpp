#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<string> stack;
    string s;
    getline(cin, s);
    int match = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{' || c == '<')
        {
            if (c == '<' && i + 1 < s.length() && s[i + 1] == '<')
            {
                stack.push("<<");
                i++;
            }
            else
            {
                stack.push(string(1, c));
            }
        }
        else if (c == ')' || c == ']' || c == '}' || c == '>')
        {
            if (c == '>' && i + 1 < s.length() && s[i + 1] == '>')
            {
                if (stack.empty() || stack.top() != "<<")
                {
                    cout << "Not match" << endl;
                    cout << match << " match" << endl;
                    return 0;
                }
                stack.pop();
                i++;
                match++;
            }
            else
            {
                if (stack.empty())
                {
                    cout << "Not match" << endl;
                    cout << match << " match" << endl;
                    return 0;
                }
                string v = stack.top();
                stack.pop();
                if ((c == ')' && v != "(") || (c == ']' && v != "[") || (c == '}' && v != "{") || (c == '>' && v != "<"))
                {
                    cout << "Not match" << endl;
                    cout << match << " match" << endl;
                    return 0;
                }
                match++;
            }
        }
    }
    if (stack.empty() && match > 0)
    {
        cout << match << " match" << endl;
    }
    else
    {
        cout << "Not match" << endl;
        cout << match << " match" << endl;
    }

    return 0;
}