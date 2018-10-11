/*
 * book.cpp
 *
 *  Created on: Sep 29, 2018
 *      Author: Derek
 */
#include <iostream>
#include "Book.hpp"

using namespace std;
/*
 * Default Constructor for creating a book
 * (we need this to make an array of bokos on the heap)
 */
Book::Book(){
	fname = "";
	lname = "";
	bname = "";
	year = 0;
	ratings = new int[10] {0};
}
/*
 * Constructor #2 that makes 0 ratings.
 */
Book::Book(std::string f, std::string l, std::string b,int yr){
	fname = f;
	lname = l;
	bname = b;
	year = yr;
	ratings = new int[10] {0};
}
/*
 * constructor #3 with the ratings as a parameter
 */
Book::Book(std::string f, std::string l, std::string b,int yr, int *rates){
	fname = f;
	lname = l;
	bname = b;
	year = yr;
	ratings = rates;
}
/*
 * destructor deletes ratings
 */
Book::~Book(){
	delete ratings;
}
/*
 * gets the average rating by looping through the ratings
 */
double Book::avgRating(){
	double x = 0;
	for(int i = 0; i < 10; i++){
		x+=ratings[i];
	}
	return x/10.0;
}
/*
 * Prints the avg rating of the book,
 * if there are no ratings, it prints that,
 * otherwise it prints the avg rating.
 */
void Book::printRating(){
	double x = avgRating();
	if(x == 0){
		cout<<"No ratings yet."<<endl;
	}else{
		cout<<"Average rating: "<<x<<endl;
	}
}
/*
 * prints all the info of the book
 */
void Book::printInfo(){
	cout<<bname<<", authored by: "<<fname<<" "<<lname<<endl<<"Published in the year "<<year<<"."<<endl<<"Average rating of: "<<avgRating()<<"."<<endl;
}
/*
 * operator overload. returns true if this objects avg
 * rating is > the one we are given.
 */
bool Book::operator >(Book &b1){
	return this->avgRating() > b1.avgRating();
}
