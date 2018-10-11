/*
 * main.cpp
 *
 *  Created on: Sep 29, 2018
 *      Author: Derek
 */
#include "book.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctime>

using namespace std;

void greatestBook(Book *books, int length);

int main(){
	//A part 1::
	int r1[] = {0,1,2,3,4,5,6,7,8,8};
	int r2[] = {0,1,2,9,9,9,6,9,8,9};
	int r3[] = {0,1,2,6,9,5,6,7,8,2};
	int r4[] = {0,1,2,4,4,5,6,7,8,3};
	int r5[] = {0,1,2,3,4,5,6,8,8,9};
	Book b1("Fname1", "Lname1", "Bname1", 1999,r1);
	Book b2("Fname2", "Lname2", "Bname2", 2000,r2);
	Book b3("Fname3", "Lname3", "Bname3", 1998,r3);
	Book b4("Fname4", "Lname4", "Bname4", 1997,r4);
	Book b5("Fname5", "Lname5", "Bname5", 1996,r5);

	Book books[] = {b1,b2,b3,b4,b5};
	greatestBook(books, 5);

	//A part 2::

	Book *heapBook = new Book("Derek", "Baum", "Autobiography", 2018, r2);
	heapBook->printInfo();

	//A part 3::
	Book *heapBook2 = new Book("Joe", "Schmoe", "I learn how to row", 2017, r1);

	Book *books2 = new Book[2];
	books2[0] = *heapBook;
	books2[1] = *heapBook2;

	books2[0].printInfo();
	books2[1].printInfo();

	return 0;
}
//A part 1
/*
 * function that prints the greatest books info in the given
 * book array.
 */
void greatestBook(Book *books, int length){
	Book greatest = books[0];
	for(int i = 1; i < length;i++){
		if(books[i] > greatest){
			greatest = books[i];
		}
	}
	cout<<"this is the greatest books info"<<endl;
	greatest.printInfo();
}



