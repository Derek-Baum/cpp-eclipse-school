/*
 * LLPQ.cpp
 *
 *  Created on: Oct 10, 2018
 *      Author: Derek Baum
 */
#include <iostream>
#include "LLPQ.hpp"

using namespace std;

LLPQ::LLPQ(){
	first = NULL;
	last = NULL;
	size = 0;
}
LLPQ::~LLPQ(){
	LLNode *tmp = first;
	while(tmp!= NULL){
		LLNode *next = tmp->next;
		tmp->~LLNode();
		tmp = next;
	}
	cout<<"Deleted each node in ll"<<endl;
}
void LLPQ::printLLPQ(){
	LLNode *tmp = first;
	while(tmp!=NULL){
		tmp->printNode();
		tmp = tmp->next;
	}
	cout<<endl;
}
void LLPQ::addFirst(char x, string co,int freq){
	first = new LLNode(x,co,freq);
	size++;
	last=first;
}
void LLPQ::addAtFirst(char x, string co, int freq){
	LLNode *tmp = new LLNode(x,co,freq);
	tmp->next = first;
	first = tmp;
	size++;
}

LLNode* LLPQ::remFirst(){
	LLNode *ret = first;
	first = first->next;
	size--;

	return ret;
}
string LLPQ::findCode(char k){
	LLNode *tmp = first;
	while(tmp->c != k && tmp != NULL){
		tmp = tmp->next;
	}
	return tmp->code;
}
void LLPQ::sortLL(){
	LLPQ newList;
	LLNode *tmp = first;
	LLNode *minNode = tmp;
	tmp=tmp->next;
	while(tmp!=NULL){
		if(tmp->frequency > minNode->frequency){
			minNode = tmp;
		}
		tmp = tmp->next;
	}
	newList.addFirst(minNode->c,minNode->code,minNode->frequency);


	tmp = first;
	while(minNode->frequency != -2){
		minNode->frequency = -2;
		tmp = first;
		minNode = tmp;
		while(tmp!= NULL){
			if(tmp->frequency > minNode ->frequency)
				minNode = tmp;
			tmp=tmp->next;
		}
		if(minNode->frequency == -2)
			break;
		newList.addAtFirst(minNode->c,minNode->code,minNode->frequency);
	}
	first = newList.first;
	last = newList.last;

}

void LLPQ::insertUnique(char c){
	if(first == NULL){
		addFirst(c,"-1",1);
		return;
	}
	LLNode *tmp = first;
	while(tmp != NULL){
		if(tmp->c == c){
			tmp->frequency++;
			return;
		}
		tmp = tmp->next;
	}
	addAtFirst(c,"-1",1);

}
void LLPQ::insertInOrder(LLNode *n){
	if(size == 0){
		first = n;
		last = first;
		size++;
		return;
	}
	if(first->frequency >= n->frequency){
		addAtFirst(n->c,n->code,n->frequency);
	}else if(last->frequency <= n->frequency){
		last->next = n;
		size++;
		last = n;
	}else{
		LLNode *tmp = first;
		while(tmp->next->frequency < n->frequency){
			tmp = tmp->next;
		}
		LLNode *tmp2 = tmp->next;
		tmp->next = n;
		tmp->next->next = tmp2;
		size++;
	}
}
int LLPQ::getSize(){
	return size;
}
