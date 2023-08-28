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
			mask[i] = 1; // 뽑히지 않아야 할 원소 표시

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
	next_permutation은 순서상 마지막 수열에 도달했을 때 (이 문제의 경우 1 1 1 ... 1 0 0 0 0 0 0) 
	다시 첫 수열 (이 문제의 경우 0 0 0 0 0 0 1 1 ... 1)로 돌아간 후 false를 반환하기 때문에 
	mask 배열 또한 각 TC가 끝난 후 자연스럽게 앞 6칸에 0이 들어가있어서 초기화가 필요없다.
	*/
}