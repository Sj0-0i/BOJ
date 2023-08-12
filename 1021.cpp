#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, ans = 0; // ť�� ũ�� n, �̾Ƴ����� �ϴ� ���� ���� m
	cin >> n >> m;

	deque<int> dq;
	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	while (m--) {
		int num;
		cin >> num;

		int idx = find(dq.begin(), dq.end(), num) - dq.begin(); // num�� �ִ� ��ġ
		
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