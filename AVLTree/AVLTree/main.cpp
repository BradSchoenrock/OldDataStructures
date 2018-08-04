#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "AVLTree.cpp"
#include "linkedlist.cpp"

using namespace std;

#define ITERATIONS 1000
#define RANGE 1000

bool looksGood(LinkedList<int> *list, AVLTree<int, int> *tree) {
	if (!tree->isbalanced()) {
		cout << "Problem. Tree not balanced." << endl;
		return false;
	}
	for(int j = 0; j < RANGE; j++) {
		if (tree->exists(j) != list->search(j)) {
			cout << "Problem. " << j << "tree says " << tree->exists(j) << " while list says " << list->search(j) << endl;
			list->printTheList();
			tree->print();
			return false;
		}
	}
	return true;
}

void main() {
	LinkedList<int> *list=new LinkedList<int>(-98765);
	AVLTree<int, int> *tree=new AVLTree<int,int>();

	//lots of random insert and delete operations.
	for(int i = 0; i < ITERATIONS; i++) {
		int value = rand() % RANGE;

		if (!tree->exists(value)) {
			list->addInOrder(value);
			tree->insert(value, value);
		}
		else if (tree->exists(value)) {
			list->remove(value);
			tree->remove(value);
		}
		if (!looksGood(list, tree)) return;
	}

	//remove whatever is left.
	for(int j = 0; j < RANGE; j++) {
		if (tree->exists(j)) {
			list->remove(j);
			tree->remove(j);
		}
	}

	if (!looksGood(list, tree)) return;

}