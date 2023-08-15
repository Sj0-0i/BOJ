// BFS, 시작점이 두 종류
// 종류별로 BFS를 각각 돌리기
// 불에 대한 BFS를 돌리고, 지훈이에 대한 BFS를 돌림
// 지훈이가 특정 칸에 x의 시간에 최초로 방문 가능한데, x시간이나 그 이전에 불이 붙는다면 그 칸에는 못 가는 것
// vis[nx][ny] = 1 또는 dist[nx][ny] >= 0일 때, 해당 칸에 불이 붙은 시간을 확인하여 추가로 continue

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 이동 시간
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		fill(dist1[i], dist1[i] + m, -1);
		fill(dist2[i], dist2[i] + m, -1);
	}
	for (int i = 0; i < n; i++)
		cin >> board[i];

	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F') {
				Q1.push({ i, j });
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				Q2.push({ i, j });
				dist2[i][j] = 0;
			}
		}
	}

	// # : 벽
	// . : 지나갈 수 있는 공간
	// J : 지훈이의 미로에서의 초기 위치 (지나갈 수 있는 공간)
	// F : 불이 난 공간

	// 불 BFS
	while (!Q1.empty()) {
		auto cur = Q1.front(); Q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;

			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			Q1.push({ nx, ny });
		}
	}

	// 지훈이 BFS
	while (!Q2.empty()) {
		auto cur = Q2.front(); Q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				// 범위를 벗어난 것 -> 탈출에 성공!
				// 큐에 거리 순으로 들어가므로 최초에 탈출한 시간을 출력
				cout << dist2[cur.X][cur.Y] + 1;
				return 0;
			}

			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)
				continue; // 불의 전파 시간을 조건에 추가

			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			Q2.push({ nx, ny });
		}
	}

	cout << "IMPOSSIBLE";
}