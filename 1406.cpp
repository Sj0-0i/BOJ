#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	list<char> L;
	for (auto c : s)
		L.push_back(c);
	auto cursor = L.end();

	int m;
	cin >> m;

	while (m--) {
		char op;
		cin >> op;

		if (op == 'L') {
			if (cursor != L.begin())
				cursor--;
		}
		else if (op == 'D') {
			if (cursor != L.end())
				cursor++;
		}
		else if (op == 'B') {
			if (cursor != L.begin()) {
				cursor--;
				cursor = L.erase(cursor);
			}
		}
		else { // 'P'
			char ins;
			cin >> ins;
			L.insert(cursor, ins);
		}
	}

	for (auto c : L)
		cout << c;

	return 0;
}