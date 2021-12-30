#include <iostream>
#define MAX_SIZE 10001
using namespace std;

class Deque {
private:
	int f, r, s;
	int* deque;
public:
	void init_Deque();
	void push_front(int x);
	void push_back(int x);
	int pop_front();
	int pop_back();
	int size();
	int empty();
	int front();
	int back();
	Deque() { init_Deque(); }
};

void Deque::init_Deque() {
	s = 0;
	f = 0;
	r = 1;
	deque = new int[MAX_SIZE];
}

void Deque::push_front(int x) {
	deque[f--] = x;
	s++;
}

void Deque::push_back(int x) {
	deque[r++] = x;
	s++;
}

int Deque::pop_front() {
	if (empty()) {
		return -1;
	}
	else {
		int temp = deque[++f];
		s--;
		return temp;
	}
}

int Deque::pop_back() {
	if (empty()) {
		return -1;
	}
	else {
		int temp = deque[--r];
		s--;
		return temp;
	}
}

int Deque::size() {
	return s;
}

int Deque::empty() {
	if (size() > 0)
		return 0;
	else
		return 1;
}

int Deque::front() {
	if (empty())
		return -1;
	else
		return deque[f + 1];
}

int Deque::back() {
	if (empty())
		return -1;
	else
		return deque[r - 1];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	Deque d;

	string order;
	for (int i = 0; i < N; i++) {
		cin >> order;

		if (order == "push_front") {
			int n;
			cin >> n;
			d.push_front(n);
		} 
		else if (order == "push_back") {
			int n;
			cin >> n;
			d.push_back(n);
		}
		else if (order == "pop_front") {
			cout << d.pop_front() << '\n';
		}
		else if (order == "pop_back") {
			cout << d.pop_back() << '\n';
		}
		else if (order == "size") {
			cout << d.size() << '\n';
		}
		else if (order == "empty") {
			cout << d.empty() << '\n';
		}
		else if (order == "front") {
			cout << d.front() << '\n';
		}
		else if (order == "back") {
			cout << d.back() << '\n';
		}
	}

	return 0;
}