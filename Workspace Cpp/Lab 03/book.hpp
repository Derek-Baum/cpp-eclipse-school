/*
 * book.hpp
 *
 *  Created on: Sep 29, 2018
 *      Author: Derek
 */
#include <string>
#ifndef BOOK_HPP_
#define BOOK_HPP_

class Book{
	std::string fname; //first name of the author
	std::string lname; //last name of the author
	int *ratings; //ratings array
	std::string bname; //name of the book
	int year; //year the book was published.
public:
	Book(); // default constructor
	Book(std::string f, std::string l,std::string b,int yr); // constructor w/o ratings
	Book(std::string f, std::string l,std::string b,int yr, int *rates);// constructor w/ everything
	~Book();//destructor
	double avgRating();//returns the avg rating by looping through the ratings array
	void printRating();//prints the avg rating, however, if it is empty, it prints that it is empty.
	void printInfo();//prints all book info
	bool operator >(Book &b1);// > operator overload using avgrating.
};




#endif /* BOOK_HPP_ */
