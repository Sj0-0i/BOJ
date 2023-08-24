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

	int start = 1; // ����. k=0�� �� start=1
	if (k != 0) // k != 0�� ��
		start = arr[k - 1] + 1;

	for (int i = start; i <= n; i++) {
		if (!isused[i]) { // ���� i�� ������ �ʾ�����
			arr[k] = i; // k��° ���� i�� ����.
			isused[i] = 1; // ����ߴٰ� ǥ��.
			func(k + 1); // ���� �� ���Ϸ�
			isused[i] = 0; // k��° ���� i�� ���� ��� ��쿡 ���� �� Ȯ�� -> i�� �ٽ� ������� �ʾҴٰ� ǥ��.
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