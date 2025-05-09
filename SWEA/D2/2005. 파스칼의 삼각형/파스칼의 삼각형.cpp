#include <iostream>
#include <vector>
using namespace std;

void generatePascal(int n, vector<vector<int>>& pascalTriangle) {
	for (int i = 0; i < n; i++) {
		pascalTriangle[i][0] = 1;
		pascalTriangle[i][i] = 1;

		for (int j = 1; j < i; j++) {
			pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
		}
	}
}

void printPascal(int n) {
	vector<vector<int>> pascalTriangle(n, vector<int>(n, 0));
	generatePascal(n, pascalTriangle);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << pascalTriangle[i][j];
			if (j != i) cout << " ";
		}
		cout << '\n';
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{	
		int n = 0;
		cin >> n;
		
		cout << "#" << test_case << '\n';
		printPascal(n);
	}
	return 0;
}
