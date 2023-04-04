#include <iostream>
using namespace std;

int arr[5];

void bubbleSort() {

	int temp = 0;

	for (int i = 4; i > 0; i--) {
		for (int j = 0; j < i; j++) {

			if(arr[j] > arr[j + 1]) { 
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void solve() {

	int avg = 0;

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		avg += arr[i];
	}

	bubbleSort();
	avg /= 5;

	cout << avg << '\n' << arr[2] << '\n';
		
		
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}