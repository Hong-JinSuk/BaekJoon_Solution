#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N;
vector<int> Sosu;

int main() {

	cin >> N;

	vector<bool> Num(N + 1);
	Num[1] = true;

	for (int i = 2; i < sqrt(N) + 1; i++) {
		if (!Num[i]) {
			for (int j = i + i; j < N + 1; j += i) Num[j] = true;
		}
	}

	// �����佺 �׳׽��� ü�� �̿��ؼ� �Ҽ��� ����
	int sum = 0;
	Sosu.push_back(0);
	for (int i = 2; i < N + 1; i++) {
		// �Ҽ����� ����ؼ� ���ؼ� �־��ش�.
		if (!Num[i]) {
			sum += i;
			Sosu.push_back(sum);
		}
	}

	int Left = 0, Right = 0, answer = 0;

	while (Left <= Right && Right < Sosu.size()) {
		if (Sosu[Right] - Sosu[Left] < N) Right++;
		else if (Sosu[Right] - Sosu[Left] > N) Left++;
		// Right-Left = N
		else {
			answer++;
			Right++;
			Left++;
		}
	}

	cout << answer;

	return 0;
}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//
//int N;
//int answer = 0;
//vector<int> Sosu;
//
//int main() {
//
//	cin >> N;
//
//	vector<bool> Num(N + 1);
//	Num[1] = true;
//
//	for (int i = 2; i < sqrt(N) + 1; i++) {
//		if (!Num[i]) {
//			for (int j = i + i; j < N + 1; j += i) Num[j] = true;
//		}
//	}
//
//	// �����佺 �׳׽��� ü�� �̿��ؼ� �Ҽ��� ����
//	for (int i = 2; i < N + 1; i++) {
//		if (!Num[i]) {
//			Sosu.push_back(i);
//		}
//	}
//
//	// �ڱ��ڽ��� �Ҽ��� 1�� �����ش�.
//	if (Sosu.back() == N) {
//		answer++;
//	}
//
//	// N/2 ���� ���� �Ҽ��� �����ָ鼭 ���ϸ� �ȴ�.
//	for (int i = 0; i < Sosu.size(); i++) {
//		if (Sosu[i] > (N / 2 + 1)) {
//			Sosu.erase(Sosu.begin() + i, Sosu.end());
//			break;
//		}
//	}
//
//	sort(Sosu.begin(), Sosu.end(), greater<int>());
//
//	// ���ϴ°� 2������
//	int check = 2;
//	int sosu = 0;
//
//	while (check <= Sosu.size()) {
//
//		// check���� �����ش�.
//		for (int j = 0; j < Sosu.size() - check + 1; j++) {
//			for (int i = j; i < check + j; i++) {
//				sosu += Sosu[i];
//			}
//			if (sosu == N) {
//				answer++;
//			}
//			// �̹� N���� ���� ������ �� ���絵 N�� �� ���� ����.
//			if (sosu < N) {
//				sosu = 0;
//				break;
//			}
//			sosu = 0;
//		}
//
//		// ���ϴ� ������ �Ѱ� �÷��ش�.
//		check++;
//	}
//
//	cout << answer;
//
//	return 0;
//}