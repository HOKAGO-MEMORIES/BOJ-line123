#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N = 0; 
		cin >> N;

		vector<int> heights(N);

		for (int i = 0; i < N; i++)
			cin >> heights[i];

		int cnt = 0;

		for (int i = 2; i < N - 2; i++) {
			int left = max(heights[i - 2], heights[i - 1]);
			int right = max(heights[i + 1], heights[i + 2]);
			int maxHeight = max(left, right);

			if (heights[i] > maxHeight)
				cnt += (heights[i] - maxHeight);
		}

		cout << '#' << test_case << " " << cnt << '\n';
	}
	return 0;
}