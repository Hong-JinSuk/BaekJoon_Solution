#include<iostream>
#include<cmath>
using namespace std;

int n, k;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	// B[k]�� k���� �۰ų� �����Ƿ� Max=k�� �����ߴ�.
	int Min = 1, Max = k;
	int ans = 0;

	while (Min <= Max) {

		// Find = ���� ã������ �� (��)
		int Find = (Min + Max) / 2;
		int cnt = 0;

		// i*j / i = j��. ���� cnt�� ���� ã������ ���ں���
		// �۰ų� ���� ���ڵ��� ������ �ȴ�.
		// https://kbw1101.tistory.com/29 �˰��� ���� ������.
		for (int i = 1; i <= n; i++) {
			cnt += min(n, Find / i);
		}

		// ���� ������ ���ٸ�, ���� ã������ ���� ���� �亸��
		// ū ���̹Ƿ� �ٿ��ش�.
		if (cnt >= k) {
			ans = Find;
			Max = Find - 1;
		}
		else Min = Find + 1;

	}

	cout << ans;

}