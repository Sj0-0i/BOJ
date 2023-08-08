#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);


	string input;
	cin >> input;

	for (auto c : input)
		cnt[c - 'a']++;
	for (int i = 0; i < 26; i++)
		cout << cnt[i] << ' ';

	return 0;
}