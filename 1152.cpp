#include <iostream>
#include <string>

using namespace std;
int main()
{
	int result = 0;
	bool flag = false;
	string str;
	getline(cin, str);

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ' ')
			flag = false;
		else if (!flag) {
			flag = true;
			++result;
		}
	}

	cout << result;
}