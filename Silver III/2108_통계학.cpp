#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[500000];
int num[8001] = {};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	int n;
	double sum = 0;

	for (int i = 0; i < N; i++) {
		cin >> n;
		arr[i] = n;
		sum += n;
		num[n + 4000]++;
	}

	sort(arr, arr + N);

	double average = round(sum / N);
	if(average == -0) average = 0;
	int middle = arr[N / 2];
	int range = arr[N - 1] - arr[0];

	int max = 0, at = 0;
	for (int j = 0; j < 8001; j++) {
		if (num[j] > max) {
			max = num[j];
			at = j;
		}
	}
		
	for (int k = at + 1; k < 8001; k++) {
		if (num[k] == max) {
			at = k;
			break;
		}
	}

	int mode = at - 4000;

	cout << average << '\n';
	cout << middle << '\n';
	cout << mode << '\n';
	cout << range << '\n';

	return 0;
}