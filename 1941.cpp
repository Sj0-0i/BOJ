#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool mask[25];
string board[5];
int ans;
// S: 이다솜파, Y: 임도연파

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
		cin >> board[i];
	fill(mask + 7, mask + 25, true);

	do {
		queue<pair<int, int>> q;
		int S = 0, adj = 0; // 이다솜파의 수, 가로세로로 인접한 사람 수
		bool is[5][5] = {};
		bool vis[5][5] = {};

		for (int i = 0; i < 25; i++) {
			if (!mask[i]) {
				int x = i / 5, y = i % 5;
				is[x][y] = true;
				if (q.empty()) {
					q.push({ x, y });
					vis[x][y] = true;
				}
			}
		}
		while (!q.empty()) {
			int x, y;
			tie(x, y) = q.front();
			q.pop();
			adj++;
			S += board[x][y] == 'S';

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j], ny = y + dy[j];
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vis[nx][ny] || !is[nx][ny])
					continue;
				q.push({ nx, ny });
				vis[nx][ny] = true;
			}
		}
		ans += (adj >= 7 && S >= 4);
	} while (next_permutation(mask, mask + 25));
	cout << ans;

	return 0;
}