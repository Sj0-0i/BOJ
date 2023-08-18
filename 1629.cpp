#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Å« ¼öÀÇ °ÅµìÁ¦°ö
// b°¡ Â¦¼öÀÌ¸é a^b = a^(b/2) * a^(b/2)
// b°¡ È¦¼öÀÌ¸é a^b = a^(b/2) * a^(b/2 + 1)

ll POW(ll a, ll b, ll c) {
	if (b == 1)
		return a % c;

	ll val = POW(a, b / 2, c);
	val = val * val % c;

	if (b % 2 == 0)  // Â¦¼öÀÏ ¶§
		return val;

	return val * a % c; // È¦¼öÀÏ ¶§
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a, b, c;
	cin >> a >> b >> c;
	cout << POW(a, b, c);
	
	return 0;
}