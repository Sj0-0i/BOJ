#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];
bool isused[10];

void func(int k, int start) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	int temp = 0;
	for (int i = start; i < n; i++) {
		if (temp != num[i]) {
			arr[k] = num[i];
			temp = arr[k];
			func(k + 1, i + 1);
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
	func(0, 0);

	return 0;
}