/*
 * LLHuff.hpp
 *
 *  Created on: Oct 16, 2018
 *      Author: Derek Baum
 */
#include <iostream>
#include <stdlib.h>
#include "LLPQ.hpp"
using namespace std;
#ifndef LLHUFF_HPP_
#define LLHUFF_HPP_

class LLHuff {
	string file;
	LLNode *root;
	int size;
public:
	LLPQ *pq;//pri queue list of char nodes, made in first part
	LLPQ *ascii;//linked list of chars and their ascii codes
	LLHuff(string f); //f is the name of the file you make the code for
	~LLHuff();
	void MakeHuff();
	/*
	 * takes the priority queue and makes the huffman tree out of
	 * it as shown above, setting the root to the last remaining node
	 * created.
	 */
	LLNode* FindCode(LLNode *top, char ch);
	/*
	 * Finds the code for each leaf node in the tree. A few notes about
	 * this one: first, the path starts at 1, and is multiplied by 10
	 * each iteration through to get an accurate integer representation
	 * of the path. I wrote this function as a recursive one, and I
	 * STRONGLY recommend you do as well. All codes for every leaf can
	 * be found in one pass of the tree with recursion.
	 * One final note: I made a new linked list (assigned to pq, since
	 * I was done with the old pq, with each leaf node and its code bein
	 * added to the linkde list. This linked list of characters and codes
	 * will be used to create the compressed version of the file, in
	 * which each character is replaced with its corresponding code. This
	 * would be alot easier with a hash table/map, but we haven't worked
	 * with them yet. If you want to make a new field and create a hash
	 * table for this part, I am fine with that.
	 */
	void ReadFile();
	/*
	 * opens, reads in a file char by char, and creates the priority
	 * queue
	 */
	void compressFile();
	/*
	 * opens the original file for reading and a new, compressed file for
	 * writing. Looks up each character read in from the original file and
	 * writes out its corresponding code in the compressed file
	 */
	void ReadAscii();
		/*
		 * reads in the ascii code from the asciitable.txt file, and then
		 * takes the regular file and converts it to the ascii code and saves
		 * that file.
		 */
	void setCodes(LLNode *top);
	void printTree(LLNode *top);
	void printLevel(LLNode *top, int level);
	int height(LLNode *top);
	void printTree();
	void printAllChars(LLNode *top);
	void helper();
};






#endif /* LLHUFF_HPP_ */
