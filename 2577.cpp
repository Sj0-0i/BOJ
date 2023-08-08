#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	int mul = a * b * c;
	int result[10] = {};
	// 17037300
	// 0123456789
	// 3102000200

	while (mul > 0) {
		result[mul % 10]++;
		mul /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << result[i] << '\n';

	return 0;
}