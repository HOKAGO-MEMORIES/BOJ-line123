#include <iostream>
#include <queue>
using namespace std;

void createCode(queue<int>& code) {
	int decrease = 1;
	while (true) {
		int front = code.front();
		code.pop();

		front -= decrease;
		if (front < 0)
			front = 0;
		code.push(front);

		if (front == 0)
			break;

		decrease++;
		if (decrease > 5)
			decrease = 1;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int caseNum;
		cin >> caseNum;

		queue<int> code;
		for (int i = 0; i < 8; i++) {
			int num;
			cin >> num;
			code.push(num);
		}

		createCode(code);
		cout << "#" << caseNum << " ";
		for (int i = 0; i < 8; i++) {
			cout << code.front() << " ";
			code.pop();
		}
			
		cout << '\n';
	}
	return 0;
}
