#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

int n, X;
// �̷����ϸ� ���������� ����~
//priority_queue<int, vector<int>, greater<int>> pos;
priority_queue<int> neg, pos;

int main() {

	cin >> n;
	while (n--) {
		cin >> X;

		// 0 �̾ƴϸ� push
		if (X) {
			// �������� �迭�̶� ������ �־���
			if (X > 0) pos.push(-X);
			else if (X < 0) neg.push(X);
		}
		// 0 �̸�
		else {
			// �迭�� �Ѵ� ���������
			if (pos.empty() && neg.empty()) cout << "0\n";
			// ����ʸ� ���������
			else if (pos.empty()) {
				cout << neg.top() << "\n";
				neg.pop();
			}
			// �����ʸ� ���������
			else if (neg.empty()) {
				cout << abs(pos.top()) << "\n";
				pos.pop();
			}
			// �Ѵ� ������ ũ���
			else {
				if (pos.top() > neg.top()) {
					cout << abs(pos.top()) << "\n";
					pos.pop();
				}
				else {
					cout << neg.top() << "\n";
					neg.pop();
				}
			}
		}
	}

	return 0;
}