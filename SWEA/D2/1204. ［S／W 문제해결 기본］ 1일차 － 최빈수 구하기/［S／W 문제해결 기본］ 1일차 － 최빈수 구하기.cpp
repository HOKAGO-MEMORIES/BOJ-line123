#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int case_num = 0;
		cin >> case_num;

		int cnt[101] = { 0 };
		for (int i = 0; i < 1000; i++) {
			int num;
			cin >> num;
			cnt[num]++;
		}

		int ans = 0, max_cnt = 0;
		for (int i = 100; i >= 0; i--) {
			if (cnt[i] > max_cnt) {
				max_cnt = cnt[i];
				ans = i;
			}
		}

		cout << '#' << case_num << " " << ans << '\n';
	}

	return 0;
}
