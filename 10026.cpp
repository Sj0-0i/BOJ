#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char board[101][101];
int vis[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n;

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	vis[i][j] = 1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;
			
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

int search() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j]) {
				cnt++;
				bfs(i, j);
			}
		}
	}

	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}

	int not_ = search(); // 적록색약 아님

	// 적록색약인 사람 구하려고 배열 초기화
	for (int i = 0; i < n; i++)
		fill(vis[i], vis[i] + n, 0);

	// 적록색약 초록을 빨강으로
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}

	int t = search();
	cout << not_ << " " << t;

	return 0;
}
