#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N = 0;
		long long ans = 0;
		cin >> N;
		
		vector<long long> price(N);
		
		for (int i = 0; i < N; i++)
			cin >> price[i];
		long long max_Price = price[N - 1];

		for (int j = N - 1; j > 0; j--) {
			if (max_Price > price[j - 1]) {
				ans += (max_Price - price[j - 1]);
			}
			else {
				max_Price = price[j - 1];
			}
		}

		cout << '#' << test_case << " " << ans << '\n';
	}
	return 0;
}