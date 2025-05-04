#include <iostream>
#include <vector>
using namespace std;

// 기존의 방법과 다른 빈도 배열 사용
int flatten_2(int N, vector<int>& boxes) {
	int height[101] = {};
	for (int h : boxes) height[h]++;

	int low = 1, high = 100;

	while (N--) {
		while (height[low] == 0) low++;
		while (height[high] == 0) high--;

		if (high - low <= 1)
			break;

		height[high]--;
		height[high - 1]++;

		height[low]--;
		height[low + 1]++;
	}

	while (height[low] == 0) low++;
	while (height[high] == 0) high--;

	return high - low;
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

		int ans = flatten_2(N, boxes);
		cout << "#" << test_case << " " << ans << '\n';
	}

	return 0;
}
