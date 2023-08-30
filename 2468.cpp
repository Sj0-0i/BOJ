#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, maxcnt, maxh;
int area[102][102];
int rain[102][102]; // �� ��� ����
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
queue<pair<int, int>> q;

void bfs(int i, int j, int limit) {
	rain[i][j] = 1; // �湮
	q.push({ i, j });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) // ���� ���� üũ
				continue;
			if (rain[nx][ny] == 0 && area[nx][ny] > limit) { // �̹湮. ħ�� X
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
			maxh = max(area[i][j], maxh); // ���� �ִ� ����
		}
	}

	for (int h = 0; h <= maxh; h++) {
		for (int i = 0; i < n; i++)
			fill(rain[i], rain[i] + n, 0); // �迭 �ʱ�ȭ

		int cnt = 0; 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (area[i][j] > h && rain[i][j] == 0) { // ħ�� ����, �湮 ����
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