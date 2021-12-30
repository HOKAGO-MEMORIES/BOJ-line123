#include <iostream>
#define MAX_SIZE 10001
using namespace std;

class Queue {
private:
	int f, r, s;
	int* queue;
public:
	void init_Queue();
	void push(int x);
	int pop();
	int size();
	int empty();
	int front();
	int back();
	Queue() { init_Queue(); }
};

void Queue::init_Queue() {
	s = 0;
	f = 0;
	r = 0;
	queue = new int[MAX_SIZE];
}

void Queue::push(int x) {
	queue[r++] = x;
	s++;
}

int Queue::pop() {
	if (empty()) {
		return -1;
	}
	else {
		int temp = queue[f++];
		s--;
		return temp;
	}
}

int Queue::size() {
	return s;
}

int Queue::empty() {
	if (size() > 0)
		return 0;
	else
		return 1;
}

int Queue::front() {
	if (empty())
		return -1;
	else
		return queue[f];
}

int Queue::back() {
	if (empty())
		return -1;
	else
		return queue[r - 1];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	Queue q;

	string order;
	for (int i = 0; i < N; i++) {
		cin >> order;

		if (order == "push") {
			int n;
			cin >> n;
			q.push(n);
		}
		else if (order == "pop") {
			cout << q.pop() << '\n';
		}
		else if (order == "size") {
			cout << q.size() << '\n';
		}
		else if (order == "empty") {
			cout << q.empty() << '\n';
		}
		else if (order == "front") {
			cout << q.front() << '\n';
		}
		else if (order == "back") {
			cout << q.back() << '\n';
		}
	}

	return 0;
}