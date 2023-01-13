#include<iostream>

using namespace std;

int N;

void printStar(int len, int width, int num) {

	// N=3�ΰ�� (1,1) �� ����� ��ĭ�̱� �����̴�.
	// N=9�ΰ�� (3,{3,4,5}),(4,{3,4,5}),(5,{3,4,5}) �� ��� 3���� ������, ���� 1�̴�.
	// N=27�ΰ�� 9~17 x 9~17�ε�, �� ���� 9�� ���� ��, ���� 1�̴�. ���� ��Ģ�̴�.
	if ((len / num) % 3 == 1 && (width / num) % 3 == 1) cout << ' ';
	
	// �ᱹ N=3�� ���� ���� �Ǿ� �ִµ�, ����� �� ��ĭ�� ������ ����ó���ߴ�.
	else {
		// ����ó���Ǵ� ĭ ����� ��� *�� ��´�.
		if (num / 3 == 0) cout << "*";
		// �ᱹ �� ��͹� ������, N=3�������� ��� �Ͱ�ȴ�.
		else printStar(len, width, num / 3);
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printStar(i, j, N);
		}
		cout << endl;
	}

	return 0;
}