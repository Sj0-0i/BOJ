#include <bits/stdc++.h>
using namespace std;

int num[201]; // 음수 저장할 공간

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, v;
	cin >> n;

	while (n--) {
		int s;
		cin >> s;
		num[s + 100]++; // 음수 표시 위해 + 100
	}

	cin >> v;
	cout << num[v + 100];

	return 0;
}