#include <iostream>
#include <string>
using namespace std;

//배열에서 값이 시작되는 지점(top)과 배열에 값이 들어간 마지막 지점(back)을 이용
int arr[100001];
int top = 0;
int back = 0;

//배열을 직접 바꿀 필요는 없음, R 함수에서 top과 back의 값을 바꿔줘서 뒤집는 효과를 줌
void R() {

	int temp = back;
	back = top;
	top = temp;
}

//is_reverse가 true인 경우 역방향
bool D(bool is_reverse) {

	if (is_reverse) {
		if (top < back)
			return true;
		else {
			top--;
			return false;
		}
	}
	else {
		if (top > back)
			return true;
		else {
			top++;
			return false;
		}
	}
}

void solve() {
	int t, n;
	cin >> t;

	char c;
	string p, s = "";
	bool is_error, is_reverse;

	while (t--) {
		cin >> p >> n;
		top = 0;
		back = n - 1;

		//n에 0값이 들어온다면 n을 1 증가시켜 뒤의 for문을 돌아 빈 값 '[]'를 입력받도록 함
		if (!n)
			n++;

		for (int i = 0; i < n;) {
			cin >> c;
			if (c == ',' || c == ']') {
				//만약 빈 값 '[]'이라면 stoi 함수를 사용하지 않도록 함
				if(s != "")
					arr[i] = stoi(s);
				i++;
				s = "";
			}
			else {
				if (c != '[') 
					s += to_string(c - '0');
			}
		}

		int size = (int)p.size();
		//배열이 비어 있는데 D 함수를 호출한 경우 is_error = true
		is_error = false;
		//R 함수를 호출하여 역방향으로 바뀌었다면 is_reverse = true
		is_reverse = false;

		for (int j = 0; j < size; j++) {
			switch (p[j]) {
			case 'R':
				R();
				is_reverse = !is_reverse;
				break;

			case 'D':
				is_error = D(is_reverse);
				break;
			}

			if (is_error) {
				break;
			}
		}

		//is_error의 값에 따라 배열을 출력할지 error를 출력할지 결정
		if (!is_error) {
			cout << "[";
			//정방향인지 역방향인지에 따라 for문 결정
			if (is_reverse) {
				for (int k = top; k >= back; k--) {
					cout << arr[k];
					if (k != back)
						cout << ",";
				}
			}
			else {
				for (int k = top; k <= back; k++) {
					cout << arr[k];
					if (k != back)
						cout << ",";
				}
			}
			cout << "]" << '\n';
		}
		else {
			cout << "error" << '\n';
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}