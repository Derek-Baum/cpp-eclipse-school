#ifndef LLNODE_HPP_
#define LLNODE_HPP_
#include <iostream>
using namespace std;
class LLNode {
	friend class LLPQ;
	char c;
	int frequency;
	string code;
	LLNode *left,*right;
public:
	LLNode(char character,string co);
	~LLNode();
	void printNode();
};

#endif /* LLNODE_HPP_ */
