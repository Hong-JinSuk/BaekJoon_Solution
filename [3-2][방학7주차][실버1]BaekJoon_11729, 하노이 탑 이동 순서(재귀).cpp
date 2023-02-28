#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

int n;
int cnt = 0;

vector<pair<int, int>> answer;

// start ���� mid�� ���ļ� end�� ������ �����Ѵ�.
void hanoi(int n, int start, int mid, int end) {
	cnt++;
	// �ϳ��ۿ� �ȳ������� �׳� �ű��.
	if (n == 1) {
		answer.push_back({ start,end });
		return;
	}

	// n-1���� mid�� �ű��
	hanoi(n - 1, start, end, mid);
	// ���� ���ſ� 1���� end�� �Ű��ش�.
	answer.push_back({ start,end });
	// �׸��� n-1���� end�� �ű�� ��� �Ű�����.
	hanoi(n - 1, mid, start, end);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	hanoi(n, 1, 2, 3);
	cout << cnt << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].first << " " << answer[i].second << "\n";
	}

	return 0;
}