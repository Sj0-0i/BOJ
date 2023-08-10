#include <bits/stdc++.h>
using namespace std;

/*
처리를 필요로 하는 수는 cnt. 
cnt 이상인 값 t가 주어지면 그 값을 pop할 수 있게 cnt가 t가 될 때 까지 push를 해야 한다. 
만약 s.top()과 t가 일치하지 않으면 올바르지 않은 수열이다.
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
