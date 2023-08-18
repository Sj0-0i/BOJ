#include <bits/stdc++.h>
using namespace std;

int n;
int paper[2200][2200]; 
int cnt[3]; // -1, 0, 1 종이 개수

// 종이가 같은 숫자로만 채워졌는지 확인
bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) 
		for (int j = y; j < y + n; j++) 
			if (paper[x][y] != paper[i][j])
				return false;
	
	return true;
}

void solve(int x, int y, int n) {
	if (check(x, y, n)) {
		cnt[paper[x][y] + 1] += 1;
		return;
	}
	int z = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			solve(x + i * z, y + j * z, z);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> paper[i][j];
	
	solve(0, 0, n);

	for (int i = 0; i < 3; i++)
		cout << cnt[i] << '\n';

	return 0;
}