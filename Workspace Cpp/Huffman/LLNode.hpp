#ifndef LLNODE_HPP_
#define LLNODE_HPP_
#include <iostream>
using namespace std;
class LLNode {
	friend class LLPQ;
	friend class LLHuff;
	char c;
	int frequency;
	string code;
	LLNode *left,*right;
	LLNode *next;
public:
	LLNode(char character,string co);
	LLNode(char character, string co,int freq);
	~LLNode();
	void printNode();
	void setFreq(int x);
};

#endif /* LLNODE_HPP_ */
