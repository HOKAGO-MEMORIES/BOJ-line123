#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int flatten(int N, vector<int>& boxes) {
	while (N--) {
		vector<int>::iterator max_it = max_element(boxes.begin(), boxes.end());
		vector<int>::iterator min_it = min_element(boxes.begin(), boxes.end());

		if (*max_it - *min_it <= 1)
			return *max_it - *min_it;

		(*max_it)--;
		(*min_it)++;
	}

	return *max_element(boxes.begin(), boxes.end()) - *min_element(boxes.begin(), boxes.end());
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		vector<int> boxes(100);
		for (int i = 0; i < 100; i++)
			cin >> boxes[i];

		int ans = flatten(N, boxes);
		cout << "#" << test_case << " " << ans << '\n';
	}

	return 0;
}
