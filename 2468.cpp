#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, maxcnt, maxh;
int area[102][102];
int rain[102][102]; // 비에 잠긴 영역
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
queue<pair<int, int>> q;

void bfs(int i, int j, int limit) {
	rain[i][j] = 1; // 방문
	q.push({ i, j });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) // 정상 범위 체크
				continue;
			if (rain[nx][ny] == 0 && area[nx][ny] > limit) { // 미방문. 침수 X
				rain[nx][ny] = 1;
				q.push({ nx, ny }); 
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> area[i][j];
			maxh = max(area[i][j], maxh); // 잠기는 최대 높이
		}
	}

	for (int h = 0; h <= maxh; h++) {
		for (int i = 0; i < n; i++)
			fill(rain[i], rain[i] + n, 0); // 배열 초기화

		int cnt = 0; 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (area[i][j] > h && rain[i][j] == 0) { // 침수 여부, 방문 여부
					bfs(i, j, h);
					cnt++;
				}
			}
		}
		maxcnt = max(cnt, maxcnt);
	}
	cout << maxcnt;

	return 0;
}