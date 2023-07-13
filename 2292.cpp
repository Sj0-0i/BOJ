#include <iostream>
using namespace std;

int main() {
    /*
    2~7까지는 2번만에 이동이 가능하고,
    8~19까지는 3번만에 이동이 가능하고,
    20~38까지는 4번만에 이동이 가능하다.
    바깥층으로 나갈 때 마다, 6,12,18,24,30,36식으로 6*Layer식으로 범위가 늘어난다.
    이를 활용하여, 6*i의 등비수열의 합을 구하고, 그 합이 입력된 주소보다 크게끔 하는 i를 찾아서 출력해주면 된다.
    */

    int num;
    int i = 0;
    
    cin >> num;
    
    for (int sum = 2; sum <= num; i++)
        sum += 6 * i;
    
    if (num == 1)
        i = 1;
    
    cout << i;

    return 0;
}