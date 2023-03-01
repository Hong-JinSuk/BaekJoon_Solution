#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, c, x;
vector<int> house;

// dis �� �Ÿ��� ��ġ�� �ϸ� ��ġ�� �� �� �ֳ�??
bool Install(int dis) {

	int cnt = 1, start = house[0];

	for (int i = 1; i < n; i++) {

		// ��ġ�� �Ǵ� �Ÿ��� ��ġ�ϰ� ��ġ�� �� ������ �ٽ� ����.
		if (house[i] - start >= dis) {
			cnt++;
			start=house[i];
		}

	}

	// ��ġ�� �Ǹ� true �ƴϸ� false ��ȯ
	if (cnt >= c) return true;
	else return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> x;
		house.push_back(x);
	}

	sort(house.begin(), house.end());

	// ��ġ�� �� �� �ִ� �ּ�, �ִ� �Ÿ�
	int Min = 1, Max = house[n - 1] - house[0];
	int ans = 0;


	while (Min <= Max) {

		// �̺� Ž��
		int mid = (Min + Max) / 2;
		
		// mid�� ��ġ�� �� �ִ� �Ÿ����
		if (Install(mid)) {
			// ans �ʱ�ȭ ���ְ�
			ans = max(ans, mid);
			// �ּҰ��� �ι�� �÷��� �÷��� �ٽ����ش�.
			Min = mid + 1;
		}
		// ��ġ�� �� ���� �Ÿ���� �ִ밪�� ������ �ٿ��� �ٽ� ���ش�.
		else Max = mid - 1;

	}

	cout << ans;

	return 0;
}