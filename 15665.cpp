#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];
vector<bool> chk(10001);

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << num[arr[i]] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		arr[k] = i;
		func(k + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int idx = 0; // 수를 삽입할 index
	while (n--) {
		cin >> num[idx];
		if (chk[num[idx]]) // 이미 이전에 수가 들어온 경우 넘어간다
			continue; 
		chk[num[idx]] = 1; // 그렇지 않으면 수를 num 배열에 추가
		idx++;
	}

	// 현재 num에는 중복되지 않은 수들만 들어가 있다. 길이는 idx
	n = idx;
	sort(num, num + n);
	func(0);

	return 0;
}