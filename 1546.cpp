#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int num;
    double sum = 0;
    double score[1000] = {};
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> score[i];
    }

    sort(score, score + num); // 0~num-1 ���� �������� ����
    for (int i = 0; i < num; i++) {
        sum = sum + (score[i] / score[num - 1]) * 100;
    }

    cout << sum / num;
}