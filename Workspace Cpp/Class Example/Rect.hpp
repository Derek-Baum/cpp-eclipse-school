/*
 * Rect.hpp
 *
 *  Created on: Sep 18, 2018
 *      Author: mexib
 */

#ifndef RECT_HPP_
#define RECT_HPP_

class Rect{
	int length;
	int width;
	int area;
public:
	Rect(int x, int y);
	void setLen(int x);
	void setWid(int x);
	int getLen();
	int getWid();
	int getArea();
};





#endif /* RECT_HPP_ */
