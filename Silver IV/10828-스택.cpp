#include <iostream>
#define MAX_SIZE 10001
using namespace std;

class Stack {
private:
	int t, s;
	int* stack;
public:
	void init_Stack();
	void push(int x);
	int pop();
	int size();
	int empty();
	int top();
	Stack() { init_Stack(); }
};

void Stack::init_Stack() {
	s = 0;
	t = -1;
	stack = new int[MAX_SIZE];
}

void Stack::push(int x) {
	stack[++t] = x;
	s++;
}

int Stack::pop() {
	if (empty()) {
		return -1;
	}
	else {
		int temp = stack[t--];
		s--;
		return temp;
	}
}

int Stack::size() {
	return s;
}

int Stack::empty() {
	if (size() > 0)
		return 0;
	else
		return 1;
}

int Stack::top() {
	if (empty()) {
		return -1;
	}
	else {
		return stack[t];
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	Stack s;

	string order;
	for (int i = 0; i < N; i++) {
		cin >> order;

		if (order == "push") {
			int n;
			cin >> n;
			s.push(n);
		}
		else if (order == "pop") {
			cout << s.pop() << '\n';
		}
		else if (order == "size") {
			cout << s.size() << '\n';
		}
		else if (order == "empty") {
			cout << s.empty() << '\n';
		}
		else if (order == "top") {
			cout << s.top() << '\n';
		}
	}

	return 0;
}