#include <iostream>
using namespace std;

/*
¦����° ������ ��쿡�� 1/i, 2/(i-1),3/(i-2), ..., i/1������ ������ �ǰ�
Ȧ����° ������ ��쿡�� i/1, (i-1)/2, (i-2)/3, ..., 1/i������ ������ �ȴ�.
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