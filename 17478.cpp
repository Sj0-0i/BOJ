#include <bits/stdc++.h>
using namespace std;

int n;

void bar(const char* str, int s) {
	for (int i = 0; i < s; i++)
		cout << "____";
	cout << str;
}

void solve(int cnt) {
	bar("\"����Լ��� ������?\"\n", cnt);
	if (cnt == n) bar("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n", cnt);
	else {
		bar("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n", cnt);
		bar("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n", cnt);
		bar("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n", cnt);
		solve(cnt + 1);
	}
	bar("��� �亯�Ͽ���.\n", cnt);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";

	solve(0);

	return 0;
}