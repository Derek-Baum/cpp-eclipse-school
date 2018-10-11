/*
 * mainll.cpp
 *
 *  Created on: Oct 2, 2018
 *      Author: Derek Baum
 */

#include <iostream>
#include "SNode.hpp"
#include "SLL.hpp"

using namespace std;

int main() {

	/* me testing
	 SLL list;

	 list.addFirst(10,"10");
	 list.push(11,"11");
	 list.addAtFront(9,"9");
	 list.addAtFront(7,"7");
	 list.addAtFront(6,"6");

	 list.insertInOrder(8,"8");


	 list.printSLL();
	 cout<<"the average rating is "<<list.getAve()<<endl;

	 cout<<list.pop()<<endl;
	 list.printSLL();
	 */
	int r[10] = { 9, 8, 4, 5, 11, 10, 3, 6, 8, 2 };
	string s[10] = { "really good!", "loved it", "mediocre", "okay, not great",
			"best book ever!", "awesome!", "boring", "not bad",
			"definitely worth reading", "terrible!" };
	SLL *list = new SLL();
	for (int i = 0; i < 10; i++) {
		list->insertInOrder(r[i], s[i]);
		list->printSLL();
	}
	cout << "Ave: " << list->getAve() << endl;
	cout << "Popping "<<endl<< list->pop() << endl;
	list->printSLL();
	cout << "Popping " << list->pop() << endl;
	list->printSLL();
	delete list;

	return 0;
}

