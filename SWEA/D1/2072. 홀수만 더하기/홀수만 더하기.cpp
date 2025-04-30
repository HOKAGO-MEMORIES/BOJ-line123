#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n = 0, sum = 0, i = 10;
        
        while (i--) {
            cin >> n;
            if (n % 2) sum += n;
        }
        
        cout << '#' << test_case << " " << sum << '\n';
            
	}
	return 0;
}