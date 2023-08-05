#include <bits/stdc++.h>
using namespace std;

int num[9];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> num[i];
		sum += num[i];
	}
	
	sort(num, num + 9);

	// 9명 키 모두 더한 값에서 2명의 키를 빼줌. 
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - num[i] - num[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j)
						cout << num[k] << '\n';
				}
				return 0; // 이것을 잊지 말기
			}
		}
	}

	return 0;
}