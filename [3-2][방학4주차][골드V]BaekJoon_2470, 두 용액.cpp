#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int N;
int Min = 1000000001;

int main() {

	cin >> N;
	int* Arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> Arr[i];
	}	

	sort(Arr, Arr + N);
	
	// �� ������ ���̴� ����
	int Left = 0, Right = N - 1;

	//������ �����ص� �迭
	int ans[2];
	//ans[0] = Arr[Left];
	//ans[1] = Arr[Right];

	while (Left < Right) {

		int Sum = Arr[Left] + Arr[Right];

		// 0���� Best�� ����.
		if (Sum == 0) {
			ans[0] = Arr[Left];
			ans[1] = Arr[Right];
			break;
		}

		// ���� ������
		else if (Sum < 0) {
			// ���� ���밪�� Min���� ������
			if (abs(Sum) < Min) {
				//Min�� �ٲ��ְ� ��������
				Min = abs(Sum);
				ans[0] = Arr[Left];
				ans[1] = Arr[Right];
			}
			// ������ �ٿ��ش�.
			Left++;
		}
		// ���� �����
		else {
			// ���� ���밪�� Min���� ������
			if (abs(Sum) < Min) {
				//Min�� �ٲ��ְ� ��������
				Min = abs(Sum);
				ans[0] = Arr[Left];
				ans[1] = Arr[Right];
			}
			// ����� �ٿ��ش�.
			Right--;
		}
	}

	cout << ans[0] << " " << ans[1];

	return 0;
}