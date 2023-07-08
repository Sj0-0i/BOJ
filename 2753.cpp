#include <iostream>
using namespace std;

int main() {
    //4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때
    int year;
    cin >> year;

    if (year % 4 == 0) {
        if (year % 400 == 0)
            cout << 1;
        else if (year % 100 != 0)
            cout << 1;
        else
            cout << 0;
    }
    else
        cout << 0;

    return 0;
}