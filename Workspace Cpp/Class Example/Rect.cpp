#include "Rect.hpp"

Rect::Rect(int x, int y){
	length = x;
	width = y;
	area = length * width;
}
void Rect::setLen(int x){
	length = x;
	area = length * width;
}
void Rect::setWid(int x){
	width = x;
	area = length * width;
}
int Rect::getLen(){
	return length;
}
int Rect::getWid(){
	return width;
}
int Rect::getArea(){
	return area;
}
