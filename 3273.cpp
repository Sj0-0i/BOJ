#include <bits/stdc++.h>
using namespace std;

int num[100001]; // 수열
bool exist[2000001]; // 각 자연수의 존재 여부를 저장

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
공간복잡도 O(2000000), 시간복잡도 O(n)에 풀이가 가능. 
만약 입력 형식에서 x가 a 배열보다 먼저 주어졌다면 int a[] 배열은 필요가 없었음.
*/