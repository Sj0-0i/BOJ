#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[1002][1002];
int visS[1002][1002];
int visF[1002][1002];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int tnum, w, h;

// . : 빈 공간
// # : 벽
// @ : 상근이의 시작 위치
// * : 불

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tnum;

	for (int t = 0; t < tnum; t++) {
		bool yes = false;
		queue<pair<int, int>> qf = {}, qs = {};
		cin >> h >> w;

		for (int i = 0; i < w; i++) {
			fill(visF[i], visF[i] + h, 0);
			fill(visS[i], visS[i] + h, 0);
		}

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				char c;
				cin >> c;

				if (c == '#')
					board[i][j] = -1;
				else {
					if (c == '@') {
						qs.push({ i, j });
						visS[i][j] = 1;
					}
					else if (c == '*') {
						qf.push({ i, j });
						visF[i][j] = 1;
					}
					board[i][j] = 0;
				}
			}
		}

		while (!qf.empty()) {
			auto cur = qf.front(); qf.pop();

			for (int k = 0; k < 4; k++) {
				int nx = cur.X + dx[k];
				int ny = cur.Y + dy[k];

				if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
				if (board[nx][ny] == -1) continue;
				if (visF[nx][ny]) continue;

				visF[nx][ny] = visF[cur.X][cur.Y] + 1;
				qf.push({ nx, ny });
			}
		}

		while (!qs.empty() && (!yes)) {
			auto cur = qs.front(); qs.pop();

			for (int k = 0; k < 4; k++) {
				int nx = cur.X + dx[k];
				int ny = cur.Y + dy[k];

				if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
					cout << visS[cur.X][cur.Y] << '\n';
					yes = true;
					break;
				}
				if (board[nx][ny] == -1) continue;
				if (visS[nx][ny]) continue;
				if (visF[nx][ny] != 0 && visF[nx][ny] <= visS[cur.X][cur.Y] + 1) continue;

				visS[nx][ny] = visS[cur.X][cur.Y] + 1;
				qs.push({ nx, ny });
			}
		}

		if (!yes)
			cout << "IMPOSSIBLE" << '\n';
	}
	
	return 0;
}
