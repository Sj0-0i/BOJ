#include <bits/stdc++.h>
using namespace std;

int k;
int arr[15];
int mask[15];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(true) {
		cin >> k;
		if (!k)
			break;

		for (int i = 0; i < k; i++)
			cin >> arr[i];
		for (int i = 6; i < k; i++)
			mask[i] = 1; // ������ �ʾƾ� �� ���� ǥ��

		do {
			for (int i = 0; i < k; i++)
				if (!mask[i])
					cout << arr[i] << ' ';
			cout << '\n';
		} while (next_permutation(mask, mask + k));
		cout << '\n';
	}

	return 0;

	/*
	next_permutation�� ������ ������ ������ �������� �� (�� ������ ��� 1 1 1 ... 1 0 0 0 0 0 0) 
	�ٽ� ù ���� (�� ������ ��� 0 0 0 0 0 0 1 1 ... 1)�� ���ư� �� false�� ��ȯ�ϱ� ������ 
	mask �迭 ���� �� TC�� ���� �� �ڿ������� �� 6ĭ�� 0�� ���־ �ʱ�ȭ�� �ʿ����.
	*/
}