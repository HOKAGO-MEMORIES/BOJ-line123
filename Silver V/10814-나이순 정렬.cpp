#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class user {
public:
	int age;
	int priority;
	string name;
	user(int age, int priority, string name) : age(age), priority(priority), name(name) { }
};

bool compare(user a, user b) {
	if (a.age == b.age)
		return a.priority < b.priority;
	else
		return a.age < b.age;
}

int main() {

	int N;
	cin >> N;

	int a;
	string n;
	vector<user> user_vector;

	for (int i = 0; i < N; i++) {
		cin >> a >> n;
		user_vector.push_back(user(a, i, n));
	}

	sort(user_vector.begin(), user_vector.end(), compare);

	for (int j = 0; j < user_vector.size(); j++)
		cout << user_vector[j].age << " " << user_vector[j].name << '\n';
	
	return 0;
}