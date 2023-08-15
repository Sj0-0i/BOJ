// BFS, 시작점이 여러 개
// 익은 토마토의 개수가 여러 개일 수 있다
// 각 익은 토마토들에 대해 해당 위치를 시작점으로 하는 BFS를 한 번씩 다 돌리는 방법
// -> BFS의 시간복잡도 O(NM), 토마토 최대 NM개 있으므로 -> O(N^2M^2).. 

// 시작점이 여러 개인 BFS!! -> 모든 시작점을 큐에 넣고 BFS
// 익은 토마토를 큐에 넣고 BFS를 돌리면 된다. 
// dist에서 익은 토마토나 빈칸은 0 익지 않은 토마토는 -1

// BFS를 돌 때 큐에 쌓이는 순서는 거리 순

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002];
int dist[1002][1002];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;
    queue<pair<int, int> > Q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1)
                Q.push({ i,j }); // 시작점이 여러 개
            if (board[i][j] == 0) // 익지 않은 토마토
                dist[i][j] = -1;
        }
    }

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] >= 0) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({ nx,ny });
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == -1) { // 익지 않은 토마토가 아직도 있으면
                cout << -1; // 그 토마토는 평생 익지 못해
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
    return 0;
}