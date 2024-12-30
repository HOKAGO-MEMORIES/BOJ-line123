#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Time {
public:
	int start;
	int end;
};

int N;

bool compare(Time t1, Time t2) {
	if (t1.end == t2.end) {
		return t1.start < t2.start;
	}
	else {
		return t1.end < t2.end;
	}
}

int solve(vector<Time> vec) {
	
	int answer = 0, next = 0;

	for (int i = 0; i < N; i++)  {
		if (vec[i].start >= next) {
			next = vec[i].end;
			answer++;
		}
		
	}

	return answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<Time> vec(N);

	for (int i = 0; i < N; i++) 
		cin >> vec[i].start >> vec[i].end;
		
	sort(vec.begin(), vec.end(), compare);

	int answer = solve(vec);

	cout << answer << '\n';

	return 0;
}