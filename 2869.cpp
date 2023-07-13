#include <iostream>
using namespace std;

/*
정상에 오르면 미끄러지지 않으므로 V-A까지 오르면 다음 날 정상에 도달
V-A까지의 기간 : (V-A)/(A-B)
기간의 나머지가 0일 경우에는 다음 날 정상 도달,
0이 아닐 경우에는 거리가 조금 부족한 것이므로 하루를 더해주면 된다
*/

int main() {
    int a, b, v;
    int day = 1;

    cin >> a >> b >> v;

    day += (v - a) / (a - b);

    if ((v - a) % (a - b) != 0)
        day++;
    if (a >= v)
        cout << "1";
    else
        cout << day;

    return 0;
}