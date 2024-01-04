#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s)
{
    int n = s.length();
    stack<char> st;
    vector<bool> exist(26, false);
    int count[26] = {};
    for (auto c : s)
        count[c - 'a']++;

    for (auto c : s)
    {
        count[c - 'a']--;
        if (exist[c - 'a'])
            continue;

        while (!st.empty() && c < st.top() && count[st.top() - 'a'] > 0)
        {
            char rem = st.top();
            exist[rem - 'a'] = false;
            st.pop();
        }
        exist[c - 'a'] = true;
        st.push(c);
    }
    string res = "";
    while (!st.empty())
    {
        res = st.top() + res;
        st.pop();
    }
    return res;
}