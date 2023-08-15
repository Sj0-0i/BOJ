#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char board[101][101];
int vis[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

void bfs(int x, int y, int n) {
	vis[x][y] = 1;
	q.push({ x, y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny]) continue;

			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);



	return 0;
}
