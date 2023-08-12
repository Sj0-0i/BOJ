#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// i - l + 1 ~ i 구간에서의 최솟값
	int n, l;
	cin >> n >> l;

	deque<pair<int, int>> dq;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		// dq는 오름차순, 가장 작은 값은 항상 dq의 front
		while (!dq.empty() && dq.back().second >= num)
			dq.pop_back();

		// 새로운 수 삽입	
		dq.push_back({ i, num });

		if (dq.front().first <= i - l)
			dq.pop_front();

		cout << dq.front().second << " ";
	}

	return 0;
}

// 해설 : https://yabmoons.tistory.com/630