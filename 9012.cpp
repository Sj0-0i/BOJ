#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        stack<char> st;
        bool yes = true;

        for (auto c : s) {
            if (c == '(')
                st.push(c);
            else { 
                if (st.empty() || st.top() != '(') {
                    yes = false;
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty()) 
            yes = false;

        if (yes) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }

    return 0;
}