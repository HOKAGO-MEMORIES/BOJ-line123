//나중에 시간 되면 이거 잘 고쳐보기 
//다시 보면 기막힌 코딩에 아마 환장할듯
//1시간 59분 걸림
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int t;
	cin >> t;

	int a[201];
	int n, ai;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> ai;
			a[j] = ai;
		}

		sort(a, a + n);

		int answer = 0;
		bool is_zero = false;
		bool check[201] = {};
		bool appear[201] = {};
		int num = 0, num1 = 0, num2 = 0;

		for (int k = 0; k < n; k++) {

			if (a[k] < 0) {
				num1 = a[k] - (a[k] * 2) - 1;
				num2 = a[k] + 200;

				num = num2;
			}
			else {
				num1 = a[k] - 1;
				num2 = 200 - a[k];

				num = num1;
			}

				if (a[k] == 0 && !is_zero) {
					answer++;
					is_zero = true;
				}
				else if (a[k] != 0 && !check[num]){

					if (a[k] < 0) {
						answer++;
						check[num] = true;
						appear[num] = true;
					}
					else {
						if (!appear[num2] && !check[num2]) {
							answer++;
							check[num] = true;
						}
						else if (check[num2]){
							answer++;
							check[num] = true;
						}
					}

				}
				else if (a[k] != 0){
					if (a[k] < 0 && check[num] && !check[num1]) {
						answer++;
						check[num1] = true;
					}
					else if (a[k] > 0 && !check[num2] && check[num]) {
						answer++;
						check[num2] = true;
					}
				}

			}

		cout << answer << '\n';
	}

	return 0;
}