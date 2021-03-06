/*
 * LLHuff.cpp
 *
 *  Created on: Oct 16, 2018
 *      Author: Derek Baum
 */
#include <iostream>
#include "LLHuff.hpp"
#include "LLNode.hpp"
#include "LLPQ.hpp"
#include <fstream>

using namespace std;

LLHuff::LLHuff(string f){
	file = f;
	root = NULL;
	size = 0;
	pq = new LLPQ;
	ascii = NULL;
}
LLHuff::~LLHuff(){
	delete root;
	delete pq;
	delete ascii;
}
void LLHuff::helper(){
	LLNode *parent = new LLNode('*',"",0);
	parent->left = pq->remFirst();
	parent->right = pq->remFirst();
	parent->frequency = parent->left->frequency + parent->right->frequency;
	pq->insertInOrder(parent);
}
void LLHuff::MakeHuff(){
	while(true){
		helper();
		if(pq->size == 1 && pq->first->c == '*')
			break;
	}
	cout<<"ending on"<<endl;
	pq->printLLPQ();
	root = pq->first;
}
void LLHuff::setCodes(LLNode *top){
	if(top == NULL){
		return;
	}else{
		top->left->code=top->code + "0";
		top->right->code=top->code + "1";
		setCodes(top->left);
		setCodes(top->right);
	}
}
void LLHuff::printAllChars(LLNode *top){
	if(top == NULL){
		return;
	}else if(top->c=='*'){
		printAllChars(top->left);
		printAllChars(top->right);
	}else{
		cout<<top->c<<" ";
	}
}
LLNode* LLHuff::FindCode(LLNode *top, char ch){
	if(top == NULL)
		return NULL;
	else if(top->c == ch)
		return top;
	else{
		LLNode *output;
		output = FindCode(top->left,ch);
		if(output == NULL)
			output = FindCode(top->right,ch);
	return output;
	}
}
int LLHuff::height(LLNode *top){
	if(top == NULL)
		return 0;
	else{
		int l = height(top->left);
		int r = height(top->right);

		if(l > r)
			return l+1;
		return r + 1;
	}
}
void LLHuff::printLevel(LLNode *top, int level){
	if(top == NULL){
		return;
	}else if(level == 1){
		cout<<top->c<<" ";
	}else if(level > 1){
		printLevel(top->left,level-1);
		printLevel(top->right,level-1);
	}
}
void LLHuff::printTree(){
	printTree(root);
}
void LLHuff::printTree(LLNode *top){
	int h = height(top);
	for(int i = 0; i < h+2;i++){
		printLevel(top,i);
		cout<<endl;
	}
}
void LLHuff::ReadFile(){
	ifstream infile(file.c_str(),ios::in);
	char ch;
	while(infile.get(ch)){
		pq->insertUnique(ch);
	}
	infile.close();
}
void LLHuff::compressFile(){
	ifstream infile(file.c_str(),ios::in);
	char ch;
	ofstream outfile("compressed.txt",ios::out);
	cout<<"we find this THING: "<<root->right->right->right->left->left->right->right->c<<endl;
	cout<<"printing all chars"<<endl;
	printAllChars(root);
	cout<<endl;
	while(infile.get(ch)){
//		cout<<ch<<endl;
		outfile<<FindCode(root,ch)->code<<" ";
	}
	infile.close();
	outfile.close();

}
void LLHuff::ReadAscii(){
	cout << file << endl;
	ifstream infile("asciitable.txt",ios::in); // open file
	char ch;
	string asciicode;
	if (!infile.is_open()) {
	return;
	}
	infile >> asciicode;
	pq->addFirst(' ',asciicode);
	infile >> asciicode;
	while (infile>>ch) { // loop getting single characters
	cout << ch;
	infile>>asciicode; // gets entire word (code)
	cout << asciicode << endl;
	pq->addAtFirst(ch,asciicode,0);
	}
	cout << endl;
	infile.close();
	/////////////////////////////////////
	ifstream infile2(file.c_str(),ios::in); // open file for reading
	ofstream outfile("asciivsn.txt",ios::out);
	char k;
	string comp;
	while (infile2.get(k)) { // loop getting single characters
	cout << k;
	comp = pq->findCode(k);
	if (comp == "") {
	cout << "ERROR WITH " << k << endl;
	}
	else {
	cout << k << ":" << comp << endl;
	outfile << comp << " ";
	}
	}
	cout << endl;
	infile2.close();
	outfile.close();

}
