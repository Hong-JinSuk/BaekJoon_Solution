#include<iostream>

using namespace std;

int n;
int beehouse[20][20];
int number = 0;

void Bee(int start, int cnt, int n) {

	if (n == 1) {
		number++;
		beehouse[cnt][start] = number;
		return;
	}
	number++;
	beehouse[cnt][start] = number;

	int x = cnt, y = start;
	// ������ �Ʒ�
	for (int i = 0; i < n - 1; i++) {
		number++;
		x += 1;
		y += 1;
		beehouse[x][y] = number;
		//cout << "�����ʾƷ�\n";
		//cout << "x: " << x << ", y: " << y << endl;
	}
	// �Ʒ���
	for (int i = 0; i < n - 1; i++) {
		number++;
		x += 2;
		beehouse[x][y] = number;
		//cout << "�Ʒ�\n";
		//cout << "x: " << x << ", y: " << y << endl;
	}
	//���� �Ʒ�
	for (int i = 0; i < n - 1; i++) {
		number++;
		x += 1;
		y -= 1;
		beehouse[x][y] = number;
		//cout << "���ʾƷ�\n";
		//cout << "x: " << x << ", y: " << y << endl;
	}
	//���� ��
	for (int i = 0; i < n - 1; i++) {
		number++;
		x -= 1;
		y -= 1;
		beehouse[x][y] = number;
		//cout << "���� ��\n";
		//cout << "x: " << x << ", y: " << y << endl;
	}
	// ����
	for (int i = 0; i < n - 1; i++) {
		number++;
		x -= 2;
		beehouse[x][y] = number;
		//cout << "��\n";
		//cout << "x: " << x << ", y: " << y << endl;
	}
	// ������ ��
	for (int i = 0; i < n - 2; i++) {
		number++;
		x -= 1;
		y += 1;
		beehouse[x][y] = number;
		//cout << "������ ��\n";
		//cout << "x: " << x << ", y: " << y << endl;
	}
	//cout << "�ٽ� ����\n";
	Bee(start, cnt + 2, n - 1);
}

int main() {

	cin >> n;
	
	int start = n;
	Bee(start-1, 0, n);

	for (int i = 0; i < (n-1)*4+1; i++) {
		for (int j = 0; j < (n-1)*2+1; j++) {
			if (beehouse[i][j])cout << beehouse[i][j];
			else cout << "/";
		}
		cout << endl;
	}
	return 0;
}