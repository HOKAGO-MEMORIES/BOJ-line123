#include <iostream>
using namespace std;

int arr[100001];
int n = 0;

void swap(int l, int k) {
	int temp = arr[k];
	arr[k] = arr[l];
	arr[l] = temp;
}

void up(int m) {
	int half = m / 2;
	if (arr[m] < arr[half]) {
		swap(m, half);
		up(half);
	}
}

void down(int m) {
	int left = m * 2;
	int right = left + 1;

	if (left > n)
		return;

	if (n >= right) {
		
		if (arr[left] <= arr[right]) {
			if (arr[m] > arr[left]) {
				swap(m, left);
				down(left);
			}
		}

		if(arr[left] > arr[right]) {
			if (arr[m] > arr[right]) {
				swap(m, right);
				down(right);
			}
		}
	}
	else {
		if (arr[m] > arr[left]) {
			swap(m, left);
			down(left);
		}
	}
}

void push(int x) {
	arr[++n] = x;
	up(n);
}

int pop() {
	int ans = arr[1];
	arr[1] = arr[n--];
	down(1);
	return ans;
}

void solve() {
	int N, x, answer;
	cin >> N;

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