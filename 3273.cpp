#include <bits/stdc++.h>
using namespace std;

int num[100001]; // ����
bool exist[2000001]; // �� �ڿ����� ���� ���θ� ����

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	cin >> x;

	for (int i = 0; i < n; i++) {
		if (x - num[i] > 0 && exist[x - num[i]])
			ans++;
		exist[num[i]] = true;
	}

	cout << ans;

	return 0;
}

/*
�������⵵ O(2000000), �ð����⵵ O(n)�� Ǯ�̰� ����. 
���� �Է� ���Ŀ��� x�� a �迭���� ���� �־����ٸ� int a[] �迭�� �ʿ䰡 ������.
*/