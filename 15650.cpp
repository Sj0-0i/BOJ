#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	int start = 1; // 시작. k=0일 때 start=1
	if (k != 0) // k != 0일 때
		start = arr[k - 1] + 1;

	for (int i = start; i <= n; i++) {
		if (!isused[i]) { // 아직 i가 사용되지 않았으면
			arr[k] = i; // k번째 수를 i로 정함.
			isused[i] = 1; // 사용했다고 표시.
			func(k + 1); // 다음 수 정하러
			isused[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인 -> i를 다시 사용하지 않았다고 표시.
		}
		
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);

	return 0;
}