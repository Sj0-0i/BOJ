#include <bits/stdc++.h>
using namespace std;

int n, Y = 0, M = 0, phone[10000];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n; // n <= 20, m <= 10000
	for (int i = 0; i < n; i++)
		cin >> phone[i];

	for (int i = 0; i < n; i++)
		Y += ((phone[i] / 30) + 1) * 10;
	
	for (int i = 0; i < n; i++)
		M += ((phone[i] / 60) + 1) * 15;

	if (Y > M) cout << "M " << M;
	else if (Y == M) cout << "Y " << "M " << Y;
	else cout << "Y " << Y;

	return 0;
}