#include <iostream>
#include "SNode.hpp"

using namespace std;

/*
 * default constructor for a node
 * asks for a rating and the comments, and makes a new node with
 * those values.
 */
SNode::SNode(){
	cout<<"Input a rating."<<endl;
	cin >> this->rating;
	cout<<"Input comments."<<endl;
	cin.clear();
	cin.sync();
	getline(cin,this->comments);
	next = NULL;
}
/*
 * Node constructor with values
 * still makes next = NULL
 */
SNode::SNode(int r, string c){
	rating = r;
	comments = c;
	next = NULL;
}
/*
 * Node destructor
 * we just print that its being deleted, because the only
 * pointer to delete would chain and delete the entire linked list
 * if we do "delete next;"
 */
SNode::~SNode(){
	cout<<"deleting "<<rating<<", "<<comments<<endl;
}
/*
 * prints the rating and comments for the node
 */
void SNode::printNode(){
	cout<<"Rating: "<<rating<<",";
	cout<<"Comments: "<<comments<<endl;
}
