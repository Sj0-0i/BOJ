#include <bits/stdc++.h>
using namespace std;

// n-1���� ������ 1�� ��տ��� 2�� �������
// n��° ������ 1�� ��տ��� 3�� �������
// n-1���� ������ 2�� ��տ��� 3�� �������

// �ϳ��� ž �ּ� �̵�Ƚ�� -> 2^n - 1

void hanoi(int start, int mid, int end, int n) {
	if (n == 1)
		cout << start << " " << end << '\n';
	else {
		hanoi(start, end, mid, n - 1);
		cout << start << " " << end << '\n';
		hanoi(mid, start, end, n - 1);
	}
	
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cout << (int)pow(2, n) - 1 << '\n';
	hanoi(1, 2, 3, n);

	return 0;
}