/*
 * SLL.cpp
 *
 *  Created on: Oct 2, 2018
 *      Author: Derek Baum
 */
#include <iostream>
#include "SLL.hpp"

using namespace std;
/*
 * constructor for linked list
 * initializes first and last to NULL,
 * and the size to 0
 */
SLL::SLL(){
	first = NULL;
	last = NULL;
	size = 0;
}
/*
 * linked list destructor
 * deletes every node with a while lope.
 */
SLL::~SLL(){
	SNode *tmp = first;
	while(tmp != NULL){
		SNode *next = tmp->next;
		tmp->~SNode();
		tmp = next;
	}
	cout<<"deleted each node in ll"<<endl;
}
/*
 * calls printNode on every node in the linked list
 */
void SLL::printSLL(){
	SNode *tmp = first;
	while(tmp != NULL){
		tmp->printNode();
		tmp = tmp->next;
	}
	cout<<endl;
}
/*
 * inserts a new node with the given data in ascending order
 * onto our current list
 * so given list with ratings, 4 5 6 8, and new node with rating 7
 * we will end with the list as 4 5 6 7 8
 */
void SLL::insertInOrder(int r, string c){
	if(first == NULL){
		addFirst(r,c);
	}else if(first->rating > r){
		addAtFront(r,c);
	}else if(r > last->rating){
		push(r,c);
	}else{
		SNode *tmp = first;
		while(tmp->next->rating < r){
			tmp = tmp->next;
		}
		//4 8 9
		//4 5 8 9
		SNode *tmp2 = tmp->next;
		tmp->next = new SNode(r,c);
		tmp->next->next = tmp2;
		size++;
	}
}
/*
 * pushes a new node with the given data onto the
 * end of the linked list
 */
void SLL::push(int r, string c){
	SNode *tmp = new SNode(r,c);
	last->next = tmp;
	size++;
	last = tmp;
}
/*
 * addes a new node with the given data to the beginning
 * of the list
 */
void SLL::addAtFront(int r, string c){
	SNode *tmp = new SNode(r,c);
	tmp->next = first;
	first = tmp;
	size++;
}
/*
 * adds the very first node with the given data
 * to an empty list
 */
void SLL::addFirst(int r, string c){
	first = new SNode(r,c);
	last = first;
	size++;
}
/*
 * removes the last node from the linked list,
 * and returns the rating from the node removed.
 */
int SLL::pop(){
	int rat = last->rating;
	cout<<"removing "<<rat<<", "<<last->comments<<endl;
	SNode *tmp = first;
	while(tmp->next->next!=NULL){
		tmp = tmp->next;
	}
	last = tmp;
	last->next->~SNode();
	last->next = NULL;
	size--;
	return rat;
}
/*
 * calculates the average rating (by traversing the list)
 * and then returns the average rating.
 */
double SLL::getAve(){
	double sum = 0;
	SNode *tmp = first;
	while(tmp != NULL){
		sum+=tmp->rating;
		tmp=tmp->next;
	}
	return sum/((double)size);
}
