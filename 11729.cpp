#include <bits/stdc++.h>
using namespace std;

// n-1개의 원판을 1번 기둥에서 2번 기둥으로
// n번째 원판을 1번 기둥에서 3번 기둥으로
// n-1개의 원판을 2번 기둥에서 3번 기둥으로

// 하노이 탑 최소 이동횟수 -> 2^n - 1

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