#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[51][51];
int vis[51][51];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue <pair<int, int>> q;

void bfs(int x, int y, int n, int m) {
	vis[x][y] = 1;
	q.push({ x, y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;
			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}
		
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1 && !vis[i][j]) {
					// 배추가 심어져 있고, 방문한 적 없으면 BFS 진행
					cnt++;
					bfs(i, j, n, m);
				}
			}
		}

		cout << cnt << '\n';
		for (int i = 0; i < n; i++) { // 다음 test case를 위해 초기화
			fill(board[i], board[i] + m, 0);
			fill(vis[i], vis[i] + m, false);
		}
	}

	return 0;
}