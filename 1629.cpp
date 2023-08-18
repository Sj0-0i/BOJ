#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ū ���� �ŵ�����
// b�� ¦���̸� a^b = a^(b/2) * a^(b/2)
// b�� Ȧ���̸� a^b = a^(b/2) * a^(b/2 + 1)

ll POW(ll a, ll b, ll c) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a % c;

	ll val = POW(a, b / 2, c);
	val = val * val % c;

	if (b % 2 == 0)  // ¦���� ��
		return val;

	return val * a / c; // Ȧ���� ��
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a, b, c;
	cin >> a >> b >> c;
	cout << POW(a, b, c);
	
	return 0;
}