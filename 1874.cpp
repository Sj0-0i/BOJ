#include <bits/stdc++.h>
using namespace std;

/*
ó���� �ʿ�� �ϴ� ���� cnt. 
cnt �̻��� �� t�� �־����� �� ���� pop�� �� �ְ� cnt�� t�� �� �� ���� push�� �ؾ� �Ѵ�. 
���� s.top()�� t�� ��ġ���� ������ �ùٸ��� ���� �����̴�.
*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> s;
    string ans;
    int cnt = 1;

    while (n--) {
        int t;
        cin >> t;

        while (cnt <= t) {
            s.push(cnt++);
            ans += "+\n";
        }
        if (s.top() != t) {
            cout << "NO\n";
            return 0;
        }

        s.pop();
        ans += "-\n";
    }

    cout << ans;

    return 0;
}
