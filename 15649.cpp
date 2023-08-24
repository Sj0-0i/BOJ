#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10]; // 현재 3, 2 채워진 상태면 arr[0]=3, arr[1]=2
bool isused[10]; // issued[1]=false, isused[2]=true, isused[3]=true, isused[4]=false

void func(int k) { // 현재 k개까지 수를 택했음
	if (k == m) { // base condition : m개를 모두 택했으면
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
		cout << '\n';
		return;
	}

	// 아직 쓰이지 않은 수 찾기.
	for (int i = 1; i <= n; i++) { // 1부터 n까지의 수에 대해
		if (!isused[i]) { // 아직 i가 사용되지 않았으면
			arr[k] = i; // k번째 수를 i로 정함.
			isused[i] = 1; // i가 사용되었다고 표시.
			func(k + 1); // 다음 수를 정하러 한 단계 더 들어감.
			isused[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지 않았다고 표시.
		}   // ex) 1 2 3을 완성하여 출력하고, isused[3]은 다시 false가 됨. 그 다음으로 i=4 진행~
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);

	return 0;
}
