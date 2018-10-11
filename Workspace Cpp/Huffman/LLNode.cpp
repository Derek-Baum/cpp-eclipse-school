/*
 * SNode.cpp
 *
 *  Created on: Oct 10, 2018
 *      Author: Derek Baum
 */
#include "LLNode.hpp"

#include <iostream>

using namespace std;
LLNode::LLNode(char character, string co){
	c = character;
	frequency = 1;
	code = co;
	left=right=NULL;
}
LLNode::~LLNode(){
	cout<<"Deleting "<<c<<endl;
}
void LLNode::printNode(){
	cout<<"Character "<<c<<endl<<"Frequency: "<<frequency<<endl<<"Code: "<<code<<endl;
}
