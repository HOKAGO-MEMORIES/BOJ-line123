#include <iostream>
#include <vector>
using namespace std;

int checkMax(int shortLen, int longLen, vector<int>& shortVector, vector<int>& longVector) {
	int ans = -10e6;
	int top = 0;

	for (int k = 0; k <= longLen - shortLen; k++) {
		int sum = 0;

		for (int i = 0; i < shortLen; i++) {
			int j = i + top;
			sum += shortVector[i] * longVector[j];
		}

		if (sum > ans) ans = sum;
		top++;
	}

	return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		cin >> n >> m;

		vector<int> A(n, 0);
		vector<int> B(m, 0);

		for (int i = 0; i < n; i++) 
			cin >> A[i];

		for (int j = 0; j < m; j++) 
			cin >> B[j];

		int ans = 0;
		if (n > m)
			ans = checkMax(m, n, B, A);
		else
			ans = checkMax(n, m, A, B);

		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}
