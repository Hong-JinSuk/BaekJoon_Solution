#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, k;
bool visited[100001];
int acc[100001] = { 0, };
int check[100001];
vector<int> path;
queue<int> q;

int Search() { //bfs����

	q.push(n);
	visited[n] = true;
	int a = 1;
	while (!q.empty()) {

		int n = q.front(); // queue���� �Ǿտ� �ִ°� ������
		q.pop(); // �����°� �ĳ�

		int Next[3] = { n - 1,n + 1,n * 2 }; // �̵��� 3���� ���

		for (int i = 0; i < 3; i++) {

			// ���� ��ΰ� 0�̻� 100000���� �湮 x�� ���
			if (Next[i] >= 0 && Next[i] <= 100000 && !visited[Next[i]]) {
				q.push(Next[i]); // queue�� �־��ֿ��
				visited[Next[i]] = true; // �湮 ǥ��
				acc[Next[i]] = acc[n] + 1; // ������
				check[Next[i]] = n; // ���������� ������� ����
			}

			if (Next[i] == k) {
				return acc[Next[i]];
			}
		}
	}
}

int main() {

	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}
	int answer = Search();
	cout << answer << endl;

	// ������������ �ϳ��� �ڷ� �����ص� ��η� ã�� ���°�
	path.push_back(k);
	for (int i = 0; i < answer; i++) {
		path.push_back(check[k]);
		k = check[k];
	}
	for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";

	return 0;
}