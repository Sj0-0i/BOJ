#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, ans = 0; // 큐의 크기 n, 뽑아내려고 하는 수의 개수 m
	cin >> n >> m;

	deque<int> dq;
	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	while (m--) {
		int num;
		cin >> num;

		int idx = find(dq.begin(), dq.end(), num) - dq.begin(); // num이 있는 위치
		
		while (dq.front() != num) {
			if (idx < dq.size() - idx) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			ans++;
		}
		dq.pop_front();
	}
	cout << ans;

	return 0;
}