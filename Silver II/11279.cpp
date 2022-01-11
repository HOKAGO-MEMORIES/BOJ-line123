#include <iostream>
using namespace std;

int arr[100001];
int n = 0;

void swap(int m, int p) {
	int temp = arr[m];
	arr[m] = arr[p];
	arr[p] = temp;
}

void downheapify(int m) {
	int left = m * 2;
	if (left > n)
		return;

	int right = left + 1;

	if (n >= right) {
		if (arr[m] > arr[left] && arr[m] > arr[right])
			return;

		if (arr[left] > arr[m] && arr[left] >= arr[right]) {
			swap(m, left);
			downheapify(left);
		}

		if (arr[right] > arr[m] && arr[right] > arr[left]) {
			swap(m, right);
			downheapify(right);
		}

	}
	else {
		if (arr[left] > arr[m]) {
			swap(left, m);
			return;
		}
	}

}

void upheapify(int m) {
	if (m == 1)
		return;

	if (arr[m] > arr[m / 2]) {
		swap(m, m / 2);
		upheapify(m / 2);
	}
}


void push(int x) {
	arr[++n] = x;
	upheapify(n);
}

int pop() {
	int root = arr[1];
	arr[1] = arr[n--];
	downheapify(1);

	return root;
}

void solve() {
	int N;
	cin >> N;

	int x, answer;
	while (N--) {
		cin >> x;
		if (x == 0) {
			answer = 0;
			if (n > 0)
				answer = pop();
			cout << answer << '\n';
		}
		else
			push(x);
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}