#include <bits/stdc++.h>
using namespace std;

int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int board[103][103][103];
int dist[103][103][103];
queue<tuple<int, int, int>> q;

// 1 - 익음, 0 - 익지 않음, -1 - 토마토가 없음

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, h;
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int num;
				cin >> num;
				board[j][k][i] = num;
				if (num == 1) q.push({ j, k, i });
				if (num == 0) dist[j][k][i] = -1;
			}
		}
	}
	
	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur;

		for (int dir = 0; dir < 6; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (dist[nx][ny][nz] >= 0) continue;

			dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
			q.push({ nx, ny, nz });
		}
	}

	int ans = 0;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[j][k][i] == -1) {
					cout << -1 << "\n";
					return 0;
				}
				ans = max(ans, dist[j][k][i]);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}