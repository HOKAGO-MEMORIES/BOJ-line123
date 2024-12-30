#include <iostream>
#include <set>
using namespace std;

void solve() {

	int n;
	cin >> n;
	set<string, greater<string>> st;

	while (n--) {
		string name, state;
		cin >> name >> state;
		
		if (state == "enter") 
			st.insert(name);
		else 	
			st.erase(name);
	}
	
	set<string>::iterator i;

	for (i = st.begin(); i != st.end(); i++)
		cout << *i << '\n';
	
}

int main() {
    
    ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}