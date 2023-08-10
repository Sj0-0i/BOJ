#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, ans = 0;
	cin >> k;

	stack<int> s;

	while (k--) {
		int t;
		cin >> t;

		if (t == 0) {
			s.pop();
		}
		else {
			s.push(t);
		}
	}

	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}

	cout << ans;

	return 0;
}