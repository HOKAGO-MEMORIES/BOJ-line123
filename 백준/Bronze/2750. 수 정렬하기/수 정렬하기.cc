#include <iostream>
using namespace std;

int arr[1000];

void insertionSort(int n) {
	
	int key, i, j;

	for (i = 1; i < n; i++) {
		
		key = arr[i];

		for(j = i - 1; j >= 0 && key < arr[j]; j--) 
			arr[j + 1] = arr[j];

		arr[j + 1] = key;
	}
}

void solve() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	insertionSort(n);

	for (int j = 0; j < n; j++)
		cout << arr[j] << '\n';	
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}