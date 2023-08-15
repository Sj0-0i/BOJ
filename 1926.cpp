// 1. 상하좌우로 연결된 그림의 크기를 알아내기
// 2. 도화지에 있는 모든 그림을 찾아내기

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second 
int board[502][502];
bool vis[502][502];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    int num = 0; // 그림의 수
    int mx = 0; // 그림의 최댓값

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { // (i, j) 시작점
            if (board[i][j] == 0 || vis[i][j])
                continue; // 색칠이 안된 부분(0)이거나 이미 방문했을 경우 넘어감
            // (i,j)는 새로운 그림에 속해있는 시작점

            num++;
            queue<pair<int, int> > Q;
            vis[i][j] = 1; // (i,j) 방문 표시
            Q.push({ i,j });

            int area = 0; // 그림의 넓이

            while (!Q.empty()) {
                area++; // 큐에 들어있는 원소를 하나 뺄 때 마다 넓이를 1 증가시킴
                pair<int, int> cur = Q.front(); Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue; // 범위 밖일 경우 넘어감
                    if (vis[nx][ny] || board[nx][ny] != 1)
                        continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우

                    vis[nx][ny] = 1; // (nx, ny) 방문 표시
                    Q.push({ nx,ny });
                }
            }
            // (i, j)를 시작점으로 하는 BFS가 종료됨
            mx = max(mx, area);
        }
    }
    cout << num << '\n' << mx;

    return 0;
}