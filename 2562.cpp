#include <iostream>
using namespace std;

int main() {
    int array[9];
    int max = -1;
    int maxIndex = 0;

    for (int i = 0; i < 9; i++) {
        cin >> array[i];
    }

    for (int j = 0; j < 9; j++) {
        if (array[j] > max) {
            max = array[j];
            maxIndex = j;
        }
    }

    cout << max << "\n";
    cout << maxIndex + 1;
}