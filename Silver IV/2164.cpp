#include <iostream>
#include <queue>
using namespace std;


int main() {

	int N;
	cin >> N;

	queue<int> card;
	for (int i = 1; i < N + 1; i++) {
		card.push(i);
	}

	while (card.size() > 1) {
		card.pop();
		card.push(card.front());
		card.pop();
	}

	cout << card.front() << '\n';

	return 0;
}