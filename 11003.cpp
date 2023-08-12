#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// i - l + 1 ~ i ���������� �ּڰ�
	int n, l;
	cin >> n >> l;

	deque<pair<int, int>> dq;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		// dq�� ��������, ���� ���� ���� �׻� dq�� front
		while (!dq.empty() && dq.back().second >= num)
			dq.pop_back();

		// ���ο� �� ����	
		dq.push_back({ i, num });

		if (dq.front().first <= i - l)
			dq.pop_front();

		cout << dq.front().second << " ";
	}

	return 0;
}

// �ؼ� : https://yabmoons.tistory.com/630