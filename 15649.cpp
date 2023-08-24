#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10]; // ���� 3, 2 ä���� ���¸� arr[0]=3, arr[1]=2
bool isused[10]; // issued[1]=false, isused[2]=true, isused[3]=true, isused[4]=false

void func(int k) { // ���� k������ ���� ������
	if (k == m) { // base condition : m���� ��� ��������
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' '; // arr�� ����ص� ���� ���
		cout << '\n';
		return;
	}

	// ���� ������ ���� �� ã��.
	for (int i = 1; i <= n; i++) { // 1���� n������ ���� ����
		if (!isused[i]) { // ���� i�� ������ �ʾ�����
			arr[k] = i; // k��° ���� i�� ����.
			isused[i] = 1; // i�� ���Ǿ��ٰ� ǥ��.
			func(k + 1); // ���� ���� ���Ϸ� �� �ܰ� �� ��.
			isused[i] = 0; // k��° ���� i�� ���� ��� ��쿡 ���� �� Ȯ�������� i�� ���� ������ �ʾҴٰ� ǥ��.
		}   // ex) 1 2 3�� �ϼ��Ͽ� ����ϰ�, isused[3]�� �ٽ� false�� ��. �� �������� i=4 ����~
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);

	return 0;
}
