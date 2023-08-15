// 1. �����¿�� ����� �׸��� ũ�⸦ �˾Ƴ���
// 2. ��ȭ���� �ִ� ��� �׸��� ã�Ƴ���

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

    int num = 0; // �׸��� ��
    int mx = 0; // �׸��� �ִ�

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { // (i, j) ������
            if (board[i][j] == 0 || vis[i][j])
                continue; // ��ĥ�� �ȵ� �κ�(0)�̰ų� �̹� �湮���� ��� �Ѿ
            // (i,j)�� ���ο� �׸��� �����ִ� ������

            num++;
            queue<pair<int, int> > Q;
            vis[i][j] = 1; // (i,j) �湮 ǥ��
            Q.push({ i,j });

            int area = 0; // �׸��� ����

            while (!Q.empty()) {
                area++; // ť�� ����ִ� ���Ҹ� �ϳ� �� �� ���� ���̸� 1 ������Ŵ
                pair<int, int> cur = Q.front(); Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue; // ���� ���� ��� �Ѿ
                    if (vis[nx][ny] || board[nx][ny] != 1)
                        continue; // �̹� �湮�� ĭ�̰ų� �Ķ� ĭ�� �ƴ� ���

                    vis[nx][ny] = 1; // (nx, ny) �湮 ǥ��
                    Q.push({ nx,ny });
                }
            }
            // (i, j)�� ���������� �ϴ� BFS�� �����
            mx = max(mx, area);
        }
    }
    cout << num << '\n' << mx;

    return 0;
}