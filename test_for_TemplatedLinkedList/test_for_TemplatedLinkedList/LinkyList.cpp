//This class is not a linked list, but rather a "surely" to test the LinkedList against.

#include <iostream>



class LinkedListTest {
private:
	int listLength;
	int* data;
	bool isSorted;

public:
	LinkedListTest() {
		listLength = 0;
		data = new int[0];
		isSorted = true;
	}

	int getHead() {
		return (listLength > 0) ? data[0] : -9876.5432;
	}

	void add(int d) {
		//resize array
		int* tempData = new int[listLength + 1];
		for(int i = 0; i < listLength; i++) {
			tempData[i] = data[i];
		}
		//put it in the last spot
		tempData[listLength] = d;
		delete [] data;
		data = tempData;

		//adjust listLength
		listLength++;

		//update isSorted
		if (isSorted && listLength >= 2) {
			isSorted = (data[listLength-1] >= data[listLength-2]);
		}
	}

	void addInOrder(int d) {
		if (!isSorted) {
			add(d);
		}
		else {
			add(d);
			for(int i = listLength - 1; i >= 1 && data[i] < data[i-1]; i--) {
				int temp = data[i];
				data[i] = data[i-1];
				data[i-1] = temp;
			}
			isSorted = true;
		}
	}

	int getCount() {
		return listLength;
	}

	bool search(int d) {
		for(int i = 0; i < listLength; i++) {
			if (data[i] == d) return true;
		}
		return false;
	}

	void remove(int d) {
		int index;
		for(index = 0; index < listLength && data[index] != d; index++);
		if (index == listLength) return; //didn't find it.
		for(; index < listLength - 1; index++) {
			data[index] = data[index+1];
		}
		listLength--;
	}

	void bubbleSort() {
		for(int i = 0; i < listLength; i++) {
			for(int j = 0; j < listLength - 1; j++) {
				if (data[j] > data[j+1]) {
					int temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	}

	void print() {
		for(int i = 0; i < listLength; i++) {
			std::cout << data[i] << std::endl;
		}
	}

	~LinkedListTest() {
		delete [] data;
	}

};