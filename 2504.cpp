#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	stack<char> st;

	int sum = 0; // ´©Àû
	int num = 1; // °öÇØÁú °ª

	/*
	(()[[]])([]) = 22 + 6 = 28

	()[[]] 2 + 3 * 3 = 11
	(()[[]]) 2 * 11 = 22
	([]) 2 * 3 = 6
	*/

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			num *= 2;
			st.push(s[i]);
		}
		else if (s[i] == '[') {
			num *= 3;
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			if (st.empty() || st.top() != '(') {
				cout << 0;
				return 0;
			}
			
			if (s[i - 1] == '(')
				sum += num;
			st.pop();
			num /= 2; // ¼Ò°ıÈ£ ½ÖÀÌ »ç¶óÁü.
		}
		else { // ']'
			if (st.empty() || st.top() != '[') {
				cout << 0;
				return 0;
			}

			if (s[i - 1] == '[')
				sum += num;
			st.pop();
			num /= 3; // ´ë°ıÈ£ ½ÖÀÌ »ç¶óÁü.
		}
	}
	if (st.empty())
		cout << sum;
	else 
		cout << 0;

	return 0;
}