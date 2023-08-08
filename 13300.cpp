#include <bits/stdc++.h>
using namespace std;

int s[2][7]; // 성별/반별 학생 수 저장. 여0 남1

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, ans = 0;
	cin >> n >> k;

	while (n--) {
		int a, b;
		cin >> a >> b;
		s[a][b]++;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 7; j++) {
			ans += s[i][j] / k;
			// 학생이 남으면 방 한 개 추가
			if (s[i][j] % k)
				ans++;
		}
	}

	cout << ans;

	return 0;
}