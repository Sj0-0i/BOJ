#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> tower; // index, height

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	tower.push({ 100000001, 0 });

	for(int i = 1; i <= n; i++) {
		int height;
		cin >> height;

		while (tower.top().first < height)
			tower.pop();

		cout << tower.top().second << " ";
		tower.push({ height, i });
	}

	return 0;
}