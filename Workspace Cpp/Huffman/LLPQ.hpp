/*
 * LLPQ.hpp
 *
 *  Created on: Oct 10, 2018
 *      Author: Derek Baum
 */

#ifndef LLPQ_HPP_
#define LLPQ_HPP_

#include <stdlib.h>
#include <iostream>

#include "LLNode.hpp"
using namespace std;

class LLPQ{
	LLNode *first, *last;
	int size;
public:
	LLPQ();
	~LLPQ();
	void printLLPQ();
	//prints out the linked list/priority queue

	void addFirst(char x, string co="-1");
	// adds the very first character node to the linked list, along
	// with an original default vode value set to -1.

	void addAtFirst(char x, string co="-1");
	//add a new node to the beginning of the linked list (modifying the first
	//pointer and the size, and setting the vode field to co, (default = -1).

	LLNode *remFirst();
	//removes the first node from the list (to be used in creating
	//the huffman code

	string findCode(char k);
	/*goes through the llinked list, finds the character k, and returns
	 * the code associated with that node - used to translate a file
	 * once you have the code (Note that if we had studied
	 * hash tables/maps, this would be so much easier using them.
	 */

	void sortLL();
	/* sorts your linked list, based on the counts in the nodes
	 * (so the character that occurred the least frequently will
	 * be at the beginning of the list, and the character that
	 * occurred the most frequently will be at the end of the list.
	 */

	void insertUnique(char c);
	/* Inserts only unique characters into the linked list. If the
	 * character is already in the linked list, it increases the
	 * count of that character
	 */

	void insertInOrder(LLNode *n);
	/* inserts the node n into the linked list in order of its
	 * count value - this will be used in the creation of the huffman
	 * code.
	 */


};





#endif /* LLPQ_HPP_ */
