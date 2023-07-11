#include <iostream>
using namespace std;

int main() {
    int num, count = 0;
    int remain[42] = {};

    for (int i = 0; i < 10; i++) {
        cin >> num;
        remain[num % 42]++;
    }

    for (int i = 0; i < 42; i++) {
        if (remain[i] != 0)
            count++;
    }

    cout << count;
    return 0;
}