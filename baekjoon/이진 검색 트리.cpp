#include <iostream>
#include <malloc.h>
using namespace std;

int arr[100000];

struct no {
	int value;
	no* left;
	no* right;
};
no* root;

no* newnode(int v) {
	no* i =(no*)malloc(sizeof(no)*1); i->value = v;
	i->left = NULL;
	i->right = NULL;
	return i;
}

void insert(int v,no* p) {
	if (v > p->value) {
		if (p->right != NULL)
			insert(v,p->right);
		else {
			p->right = newnode(v);
		}
	}
	else {
		if (p->left != NULL) {
			insert(v, p->left);
		}
		else {
			p->left = newnode(v);
		}
	}
}

void outit(no* p) {
	if (p->left != NULL) {
		outit(p->left);
	}
	if (p->right != NULL) {
		outit(p->right);
	}
	cout << p->value << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i = 0;
	while (cin >> arr[i++]) {
		if (cin.eof())
			break;
	}
	root = newnode(arr[0]);

	for (i = 1; arr[i] != 0; i++) {
		insert(arr[i],root);
	}
	outit(root);
	return 0;
}