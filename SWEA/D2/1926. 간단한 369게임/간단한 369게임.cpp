#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int N;
	cin >> N;

	for (int num = 1; num <= N; num++) {
		int cnt = 0;
		string num_Str = to_string(num);

		for (char digit : num_Str) {
			if (digit == '3' || digit == '6' || digit == '9')
				cnt++;
		}

		if (cnt > 0) {
			string clap = "";
			for (int j = 0; j < cnt; j++)
				clap.append("-");
			cout << clap << " ";
		}
		else {
			cout << num << " ";
		}
	}

	return 0;
}