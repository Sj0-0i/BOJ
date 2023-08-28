#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];
bool isused[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i ++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	int temp = 0; // 중복 수열 확인 위한 임시 변수
	for (int i = 0; i < n; i++) {
		if (!isused[i] && temp != num[i]) { // 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열이다.
			isused[i] = 1;
			arr[k] = num[i];
			temp = arr[k];
			func(k + 1);
			isused[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);
	func(0);

	return 0;
}