#include <iostream>
#include <string>
using namespace std;

bool checkString(string s) {
    if (s[0] == 'F' || s[0] == 'B')
        return false;
    return true;
}

string checkFizzBuzz(int n) {
    if (n % 3 == 0 && n % 5 == 0)   return "FizzBuzz";
    if (n % 3 == 0) return "Fizz";
    if (n % 5 == 0) return "Buzz";
    return to_string(n);
}

void solve() {
    int num = 0;
    string s = "";
    
    for (int i = 0; i < 3; i++) {
        cin >> s;
        if (checkString(s)) 
            num = (stoi(s) + 3 - i);
    }
    cout << checkFizzBuzz(num) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
