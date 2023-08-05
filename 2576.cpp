#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num, sum = 0, odd = 0, min = 100;

	for (int i = 0; i < 7; i++) {
		cin >> num;

		if (num % 2) {
			odd += 1;
			sum += num;

			if (num < min) min = num;
		}
		
	}
		
	if(odd) {
		cout << sum << '\n';
		cout << min << '\n';
	} else cout << "-1";

	return 0;
}