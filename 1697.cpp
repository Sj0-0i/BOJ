// BFS, 1���������� BFS
// 2������ �����¿�� �̵�, 1������ x���� x-1, x+1, 2x�� �̵�

// n�� k�� ������ 0 �̻� 100000 ����������, x + 1, 2x�� �ֱ� ������ 200000���� ����

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dist[100002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	fill(dist, dist + 100001, -1);

	dist[n] = 0;
	queue<int> Q;
	Q.push(n);

	while (dist[k] == -1) {
		int cur = Q.front(); Q.pop();

		for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
			if (nxt < 0 || nxt > 100000)
				continue;
			if (dist[nxt] != -1)
				continue;
			dist[nxt] = dist[cur] + 1;
			Q.push(nxt);
		}
	}
	cout << dist[k];
	return 0;
}