#include <bits/stdc++.h>
using namespace std;
const int MX = 31;
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 };
int l, r, c;
// l: 층, R: 행, C: 열
// #: 지나갈 수 없음.
// .: 비어있음
// S: 시작지점
// E: 탈출 출구

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> l >> r >> c;

        if (l == 0 && r == 0 && c == 0) 
            break;

        queue<tuple<int, int, int>> q;
        char board[MX][MX][MX];
        int dist[MX][MX][MX];
        bool escape = false;

        for (int i = 0; i < l; i++)
            for (int j = 0; j < r; j++) 
                fill(dist[i][j], dist[i][j] + c, 0);

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    cin >> board[i][j][k];
                    if (board[i][j][k] == 'S') {
                        q.push({ i, j, k });
                        dist[i][j][k] = 0;
                    }
                    else if (board[i][j][k] == '.') 
                        dist[i][j][k] = -1;
                }
            }
        }

        while (!q.empty()) {
            if (escape) break;
            auto cur = q.front(); q.pop();

            int curH, curX, curY;
            tie(curH, curX, curY) = cur;

            for (int dir = 0; dir < 6; dir++) {
                int nh = curH + dh[dir];
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c || nh < 0 || nh >= l) continue;
                if (board[nh][nx][ny] == '#' || dist[nh][nx][ny] > 0) continue;

                dist[nh][nx][ny] = dist[curH][curX][curY] + 1;
                if (board[nh][nx][ny] == 'E') {
                    cout << "Escaped in " << dist[nh][nx][ny] << " minute(s).\n";
                    escape = true;
                    break;
                }
                q.push({ nh,nx,ny });
            }
        }
        while (!q.empty()) 
            q.pop();
        if (!escape) 
            cout << "Trapped!" << "\n";
    }

    return 0;
}