#include"stdafx.h"
#include <iostream>
#include <cstdlib>
#include "TemplatedLinkedList.cpp"
#include "LinkyList.cpp"

#define STUDENT_LL LinkedList<double>
#define STUDENT_ADD addBack
#define STUDENT_ADD_IN_ORDER addInOrder
#define STUDENT_SEARCH search
#define STUDENT_REMOVE remove
#define STUDENT_COUNT count
#define STUDENT_SORT bubbleSort
#define STUDENT_PRINT printTheList

void test2();
void test1();
void test0();

void main() {
	test1();
}

void test0() {
	STUDENT_LL *list2 = new STUDENT_LL();
	list2->STUDENT_ADD_IN_ORDER(3);
	list2->STUDENT_ADD_IN_ORDER(2);
	list2->STUDENT_ADD_IN_ORDER(7);
	list2->STUDENT_ADD_IN_ORDER(6);
	list2->STUDENT_ADD_IN_ORDER(5);
	list2->STUDENT_ADD_IN_ORDER(8);
	list2->STUDENT_ADD_IN_ORDER(1);
	list2->STUDENT_ADD_IN_ORDER(4);
	list2->STUDENT_ADD_IN_ORDER(9);
	list2->STUDENT_PRINT();
	delete(list2);
}

void test2() {
	STUDENT_LL *list2 = new STUDENT_LL();
	list2->STUDENT_ADD(1);
	list2->STUDENT_ADD(2);
	list2->STUDENT_ADD(3);
	list2->STUDENT_ADD(4);
	list2->STUDENT_ADD(5);
	list2->STUDENT_ADD(6);
	list2->STUDENT_ADD(7);
	list2->STUDENT_ADD(8);
	list2->STUDENT_ADD(9);
	list2->STUDENT_PRINT();
	delete(list2);
}

void test1() {
	const int TEST_SIZE = 30000;
	srand(0);

	LinkedListTest *list1 = new LinkedListTest();
	STUDENT_LL *list2 = new STUDENT_LL();
	
	for(int i = 0; i < TEST_SIZE; i++) {
		int r = rand();
		list1->add(r);
		list2->STUDENT_ADD(r);
		if (list1->getHead() != list2->getHead()) {
			std::cout << "Problem with add" << std::endl;
		}
		if (list1->getCount() != list2->STUDENT_COUNT()) {
			std::cout << "Problem with count when using add" << std::endl;
		}
	}

	for(int i = 0; i < TEST_SIZE; i++) {
		int r = rand();
		list1->remove(list1->getHead());
		list2->STUDENT_REMOVE(list2->getHead());
		if (list1->getHead() != list2->getHead()) {
			std::cout << "Problem with add or remove" << std::endl;
		}
		if (list1->getCount() != list2->STUDENT_COUNT()) {
			std::cout << "Problem with count when using remove" << std::endl;
		}
	}

	delete(list1);
	delete(list2);

	list1 = new LinkedListTest();
	list2 = new STUDENT_LL();
	
	for(int i = 0; i < TEST_SIZE; i++) {
		int r = rand();
		list1->addInOrder(r);
		list2->STUDENT_ADD_IN_ORDER(r);
		if (list1->getHead() != list2->getHead()) {
			std::cout << "Problem with addInOrder" << std::endl;
			list1->print();
			std::cout << std::endl;
			list2->STUDENT_PRINT();
			return;
		}
		if (list1->getCount() != list2->STUDENT_COUNT()) {
			std::cout << "Problem with count when using addInOrder" << std::endl;
		}
	}

	for(int i = 0; i < TEST_SIZE; i++) {
		int r = rand();
		list1->remove(list1->getHead());
		list2->STUDENT_REMOVE(list2->getHead());
		if (list1->getHead() != list2->getHead()) {
			std::cout << "Problem with addInOrder or remove" << std::endl;
		}
		if (list1->getCount() != list2->STUDENT_COUNT()) {
			std::cout << "Problem with count when using remove" << std::endl;
		}
	}

	delete(list1);
	delete(list2);

	list1 = new LinkedListTest();
	list2 = new STUDENT_LL();
	
	for(int i = 0; i < TEST_SIZE; i++) {
		int r = rand();
		list1->addInOrder(r);
		list2->STUDENT_ADD_IN_ORDER(r);
		if (list1->getHead() != list2->getHead()) {
			std::cout << "Problem with addInOrder" << std::endl;
		}
		if (list1->getCount() != list2->STUDENT_COUNT()) {
			std::cout << "Problem with count when using addInOrder" << std::endl;
		}
	}

	for(int i = 0; i < TEST_SIZE; i++) {
		if (list1->search(i) != list2->STUDENT_SEARCH(i)) {
			std::cout << "Problem with search" << std::endl;
		}
	}

	list1->bubbleSort();
	list2->STUDENT_SORT();

	for(int i = 0; i < TEST_SIZE; i++) {
		int r = rand();
		list1->remove(list1->getHead());
		list2->STUDENT_REMOVE(list2->getHead());
		if (list1->getHead() != list2->getHead()) {
			std::cout << "Problem with addInOrder or remove when sorting involved" << std::endl;
		}
		if (list1->getCount() != list2->STUDENT_COUNT()) {
			std::cout << "Problem with count when using remove when sorting involved" << std::endl;
		}
	}

	delete(list1);
	delete(list2);

}