#include <bits/stdc++.h>
using namespace std;

int s[2][7]; // ����/�ݺ� �л� �� ����. ��0 ��1

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
			// �л��� ������ �� �� �� �߰�
			if (s[i][j] % k)
				ans++;
		}
	}

	cout << ans;

	return 0;
}