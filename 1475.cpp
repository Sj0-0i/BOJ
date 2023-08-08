#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n;
	cin >> n;

	int cnt[10] = {};
	int m = 0;

	while (n > 0) {
		cnt[n % 10]++;
		n /= 10;
	}

	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) continue;
		m = max(m, cnt[i]);
	}

	m = max(m, (cnt[6] + cnt[9] + 1) / 2);

	cout << m;

	return 0;
}