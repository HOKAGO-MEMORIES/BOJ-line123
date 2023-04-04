#include <iostream>
using namespace std;

class TreeNode {
private:
	string data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(string data) {
		this->data = data;
	}
	void setLeft(TreeNode* left) { this->left = left; }
	void setRight(TreeNode* right) { this->right = right; }
	TreeNode* getLeft() { return left; }
	TreeNode* getRight() { return right; }
	string getData() { return data; }
};

class Tree {
private:
	TreeNode* root;
public:
	Tree() { root = nullptr; }

	TreeNode* getRoot() { return root; }
	void setRoot(string data) { root = new TreeNode(data); }

	TreeNode* find(string data) {
		return findHelper(getRoot(), data);
	}

	TreeNode* findHelper(TreeNode* node, string data) {
		if (node == nullptr) return nullptr;
		if (node->getData() == data) return node;
		TreeNode* found = findHelper(node->getLeft(), data);
		if (found == nullptr) found = findHelper(node->getRight(), data);
		if (found == nullptr) return nullptr;
		return found;
	}

	void insert(string data, string left, string right) {
		TreeNode* node = find(data);
		if (node != nullptr) {
			if (node->getLeft() == nullptr && left != ".")
				node->setLeft(new TreeNode(left));
			if (node->getRight() == nullptr && right != ".")
				node->setRight(new TreeNode(right));
		}
		else {
			setRoot(data);
			getRoot()->setLeft(new TreeNode(left));
			getRoot()->setRight(new TreeNode(right));
		}
	}

	void preorder(TreeNode* node) {
		if (node != nullptr && node->getData() != ".") {
			cout << node->getData();
			preorder(node->getLeft());
			preorder(node->getRight());
		}
	};

	void inorder(TreeNode* node) {
		if (node != nullptr && node->getData() != ".") {
			inorder(node->getLeft());
			cout << node->getData();
			inorder(node->getRight());
		}
	};

	void postorder(TreeNode* node) {
		if (node != nullptr && node->getData() != ".") {
			postorder(node->getLeft());
			postorder(node->getRight());
			cout << node->getData();
		}
	};
};

void solve() {

	string x, y, z;
	Tree T;
	int n;
	cin >> n;

	while (n--) {
		cin >> x >> y >> z;
		T.insert(x, y, z);
	}

	T.preorder(T.getRoot());
	cout << '\n';
	T.inorder(T.getRoot());
	cout << '\n';
	T.postorder(T.getRoot());
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}