#include<iostream>
#include<algorithm>
#include<sstream>
#include<queue>
#include<deque>
#include<vector>
using namespace std;

int T, n;
deque<int> num;
bool re;
bool isError;
vector<string> answer;

// ,�� �����ؼ� ���� split �ϴ� �Լ�
deque<string> split(string str, char Delimiter) {
	istringstream iss(str);
	string buffer;

	deque<string> result;

	while (getline(iss, buffer, Delimiter)) {
		result.push_back(buffer);
	}

	return result;
}
int main() {

	cin >> T;
	
	for (int i = 0; i < T; i++) {

		// ��ɾ� �Է�
		string Order;
		cin >> Order;
		queue<char> order;
		for (int i = 0; i < Order.size(); i++) {
			order.push(Order[i]);
		}
		
	    //�迭�� ����ִ� �� ���� �Է�
		cin >> n;

		// �� �Է�
		string str;
		cin >> str;
		str.erase(remove(str.begin(), str.end(), '['));
		str.erase(remove(str.begin(), str.end(), ']'));
		deque<string> num = split(str, ',');

		// ��ɾ� ����
		int orderSize = order.size();
		for (int i = 0; i < orderSize; i++) {

			// ���� ���ڰ� �ְų�, ��� R�� ���� ������ �����ϴ�.
			if (num.size() > 0 || order.front() == 'R') {
				// order�� R�̸� �������ٰ� �ν����ְ�, order�� ������.
				if (order.front() == 'R') {
					// re �� true�� false��, false�� true�� ���ش�.
					if (re) re = false;
					else re = true;
					order.pop();
				}
				// �������ٸ� �ڿ��� ���ְ�, �ƴϸ� �տ��� ���ش�.
				else {
					order.pop();
					if (re) num.pop_back();
					else num.pop_front();
				}
			}
			// ���ڰ� ���µ� ��ɾ �������� ������.
			else isError = true;
		}

		if (isError) answer.push_back("error");
		else {
			answer.push_back("[");
			if (re) {
				for (int i = num.size() - 1; i > -1; i--) {
					answer.push_back(num[i]);
					if (i > 0) answer.push_back(",");
				}
				answer.push_back("]");
			}
			else {
				for (int i = 0; i < num.size(); i++) {
					answer.push_back(num[i]);
					if (i < num.size() - 1) answer.push_back(",");
				}
				answer.push_back("]");
			}
		}

		num.clear();
		isError = false;
		re = false;
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
		if (answer[i] == "error" || answer[i] == "]") cout << endl;
	}
	
	return 0;
}