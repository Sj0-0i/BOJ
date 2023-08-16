#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dist[301][301];
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int t, l, x, y, xx, yy;
queue<pair<int, int>> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> l;
		for (int i = 0; i < l; i++)
			fill(dist[i], dist[i] + l, -1);
		
		cin >> x >> y;
		dist[x][y] = 0;
		q.push({ x, y });
		cin >> xx >> yy;
		
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= l || ny < 0 || ny >= l)
					continue;
				if (dist[nx][ny] >= 0) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q.push({ nx, ny });
			}
		}
		cout << dist[xx][yy] << '\n';
	}

	return 0;
}