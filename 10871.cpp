#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, X, num;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num < X) {
			cout << num << " ";
		}
	}

	return 0;
}