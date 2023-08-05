#include <bits/stdc++.h>
using namespace std;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int code[4] = {};
	char re;

	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 4; i++) {
			cin >> code[i];
		}

		int cnt = count(code, code + 4, 0);

		if (cnt == 0)
			re = 'E';
		else if (cnt == 1)
			re = 'A';
		else if (cnt == 2)
			re = 'B';
		else if (cnt == 3)
			re = 'C';
		else re = 'D';

		cout << re << '\n';
	}

	return 0;
}