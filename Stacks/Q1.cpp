#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    if (s.size() & 1)
    {
        return false;
    }
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty() || s[i] == '}' && st.top() != '{' || s[i] == ']' && st.top() != '[' || s[i] == ')' && st.top() != '(')
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    return false;
}