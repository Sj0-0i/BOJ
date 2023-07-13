#include <iostream>
using namespace std;

/*
짝수번째 패턴의 경우에는 1/i, 2/(i-1),3/(i-2), ..., i/1식으로 진행이 되고
홀수번째 패턴의 경우에는 i/1, (i-1)/2, (i-2)/3, ..., 1/i식으로 진행이 된다.
*/

int main() {
	int N;
	cin >> N;

	int i = 1;

	while (N > i) {
		N -= i;
		i++;
	}

	if (i % 2 == 1)
		cout << i + 1 - N << '/' << N << "\n";
	else
		cout << N << '/' << i + 1 - N << "\n";
}