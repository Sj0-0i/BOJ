#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int idx;
	string arr[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	for (int i = 0; i < 8; ++i) {
		while (true) {
			idx = str.find(arr[i]);
			if (idx == string::npos)
				break;
			str.replace(idx, arr[i].length(), "a");
		}
	}

	cout << str.length();
}