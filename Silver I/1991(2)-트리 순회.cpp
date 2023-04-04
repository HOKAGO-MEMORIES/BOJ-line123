//클래스를 사용하지 않은 짧은 코드
#include <iostream>
using namespace std;

const int MAX = 27;
char tree[MAX][2];

void preorder(char node) {
	if (node != '.') {
		cout << node;
		preorder(tree[node - 'A'][0]);
		preorder(tree[node - 'A'][1]);
	}
}

void inorder(char node) {
	if (node != '.') {
		inorder(tree[node - 'A'][0]);
		cout << node;
		inorder(tree[node - 'A'][1]);
	}
}

void postorder(char node) {
	if (node != '.') {
		postorder(tree[node - 'A'][0]);
		postorder(tree[node - 'A'][1]);
		cout << node;
	}
}

void solve() {

	char x, y, z;
	int n;
	cin >> n;

	while (n--) {
		cin >> x >> y >> z;
		tree[x - 'A'][0] = y;
		tree[x - 'A'][1] = z;
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}