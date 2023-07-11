#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int array[1000000];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    sort(array, array + n); // 0~n-1 범위 정렬
    cout << array[0] << " " << array[n - 1];

    return 0;
}