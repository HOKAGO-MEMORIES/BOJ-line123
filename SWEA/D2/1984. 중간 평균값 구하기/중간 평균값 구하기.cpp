#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int max = 0, min = 10e6, num;
		double avg = 0, sum = 0;

		for (int i = 0; i < 10; i++) {
			cin >> num;
			max = (num > max) ? num : max;
			min = (num > min) ? min : num;
			sum += (double)num;
		}

		sum -= (double)(max + min);
		avg = floor(sum / 8 + 0.5);

		cout << "#" << test_case << " " << avg << '\n';
	}
	return 0;
}
