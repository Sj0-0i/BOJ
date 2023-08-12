#include <bits/stdc++.h>
using namespace std;

void parse(string& s, deque<int>& d) {
	int cur = 0;

	for (int i = 1; i + 1 < s.size(); i++) {
		if (s[i] == ',') {
			d.push_back(cur);
			cur = 0;
		}
		else 
			cur = 10 * cur + (s[i] - '0');
	}

	if (cur != 0)
		d.push_back(cur);
}

void print_result(deque<int>& dq) {
	cout << '[';
	for (int i = 0; i < dq.size(); i++) {
		cout << dq[i];
		if (i + 1 != dq.size())
			cout << ',';
	}
	cout << "]\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		deque<int> dq;
		int rev = 0, n;
		bool error = false;

		string q, s;
		cin >> q;
		cin >> n;
		cin >> s;

		parse(s, dq);
		
		for (char c : q) {
			if (c == 'R')
				rev = 1 - rev;
			else {
				if (dq.empty()) {
					error = true;
					break;
				}
				if (!rev) 
					dq.pop_front();
				else 
					dq.pop_back();
			}
		}

		if (error)
			cout << "error\n";
		else {
			if (rev) 
				reverse(dq.begin(), dq.end());
			print_result(dq);
		}
	}

	return 0;
}