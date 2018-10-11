/*
 * Derek Baum
 * Lab 02
 */
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctime>

using namespace std;
void nextProblem();
void printAddress();
void addFour(int x);
int randomInt();
void cubeValue(int &x);
void addRandVal(int *x);
void problemSix(int *x, int *y);
void scramble(char &a, char b, char *c);
bool swap(int &x, int &y);
void swapLoop();
void arrayThing(int length,int &min);
void reverseArray(int length);
void randomArray(int length,int maxVal);
int *stackVar();
void printArray(int a[], int length);
void randomArray(int a[]);
int *randomStuffArray(int *a,int *b, int *c);

int main(){

	//problem 1
	printAddress();

	nextProblem();
	//start problem 2

	int x = 10;
	cout << x << endl;
	cout << &x << endl;
	addFour(x); // this is call by value, it creates local x and adds four

	nextProblem();
	//start problem 3

	int y = randomInt();
	cout << y << endl;
	cout << &y << endl;

	nextProblem();
	//start problem 4

	int val = 3;
	cout << "Val is " << val << endl;
	cout << "Vals address is " << &val << endl;
	cubeValue(val);
	cout << "Val is " << val << endl;
	cout << "Vals address is " << &val << endl;
	//this is call by reference

	nextProblem();
	//start problem 5

	int z = 5;
	cout << "z is "<<z<<endl;
	cout << "z's address is "<<&z<<endl;
	addRandVal(&z);
	cout << "z is now "<<z<<endl;
	cout << "z's address is "<<&z<<endl;

	nextProblem();
	//start problem 6

	x = 10;
	y = 20;
	problemSix(&x,&y);
	cout << "x is now "<< x << endl;
	cout << "y is now "<< y << endl;

	nextProblem();
	//start problem 7

	char k = 'k';
	char o = 'o';
	char l = 'l';
	char a = 'a';
	char i = 'i';
	char d = 'd';
	cout <<k<<o<<o<<l<<a<<i<<d<<endl;
	scramble(k,a,&d);
	cout <<a<<l<<k<<o<<d<<o<<l<<endl;

	nextProblem();
	//start problem 8a

	x = 15;
	y = 10;
	cout<<"x is "<<x<<", and y is "<<y<<endl;
	cout<<"now swapping only if x is > y"<<endl;
	swap(x,y);
	cout<<"x is "<<x<<", and y is "<<y<<endl;

	nextProblem();
	// start problem 8b

	swapLoop();

	nextProblem();
	//start problem 8

	int min = -1;
	arrayThing(10,min);
	cout<<"our min is now "<<min<<endl;

	nextProblem();
	//start problem 9

	reverseArray(10); //testing odd length
	reverseArray(11); //testing even length

	nextProblem();
	//start problem 10

	randomArray(10,50);

	nextProblem();
	//start problem 11

	int *num = stackVar();
	cout<<"our variable in main is: "<<num<<", and its address is: "<<&num<<endl;
	//no this doesn't work because the local variable is deleted
	//from the stack after the function returns.

	nextProblem();
	//start problem 12

	int b[25];
	randomArray(b);
	printArray(b,25);


	nextProblem();
	//start problem 13

	int len,high,low;
	int *array = randomStuffArray(&len,&high,&low);
	printArray(array,len);

	return 0;
}

void nextProblem(){
	cout << "" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@NEXT@@PROBLEM@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "" << endl;
}
 // #1
void printAddress(){
	int x = 3;
	cout << x << endl;
	cout << &x << endl;
}
//#2
void addFour(int x){
	x+=4;
	cout << x << endl;
	cout << &x << endl;
}
//#3
int randomInt(){

	srand((int) time(0));
	int x =	rand() % 50;
	cout << x << endl;
	cout << &x << endl;
	return x;
}
//#4
void cubeValue(int &x){
	x*=x * x;
	cout << x << endl;
	cout << &x << endl;

}
//#5
void addRandVal(int *x){
	srand((int) time(NULL));
	int y = rand() % 10;
	*x += y;
	cout << "random number is "<<y<<endl;
	cout << "our new number is " <<x<<endl;
	cout << "the address of the input is"<<&x<<endl;
}
//#6
void problemSix(int *x, int *y){
	int *z = x;
	*z = 32;
	z = y;
	*z = 42;
}
//#7
void scramble(char &a, char b, char *c){
	a = 'c';
	b = 'x';
	*c = 'h';
}
//8a
bool swap(int &x, int &y){
	if(x > y){
		int z = x;
		x=y;
		y=z;
		return true;
	}
	return false;
}
//8b
void swapLoop(){
	srand((int) time(NULL));
	int x,y;
	for(int i = 0; i < 20; i++){
		x = rand()%26;
		y = rand()%26;
		cout<<"X is: "<<x<<", and Y is: "<<y<<endl;
		if(swap(x,y)){
			cout<<"After swapping, X is: "<<x<<", and Y is: "<<y<<endl;
		}else{
			cout<<"The numbers didn't swap"<<endl;
		}

	}
}
//#8
void arrayThing(int length,int &min){
	int a[length];
	min = 51;
	srand((int) time(NULL));
	for(int i = 0; i < length; i++){
		a[i] = (rand()%50) + 1;
		cout <<a[i]<<((i == length-1) ? "" : ", ");
		if(a[i] < min)
			min = a[i];
	}
	cout<<endl;
}
//#9
void reverseArray(int length){
	int a[length];
	srand((int) time(0));
	cout <<"First Array"<<endl;
	for(int i = 0; i < length; i++){
		a[i] = rand()%51;
		cout <<a[i]<<((i == length-1) ? "" : ", ");
	}
	cout << endl;
	int x;
	//reverses the array
	for(int i = 0; i < length/2; i++){
		x = a[i];
		a[i] = a[length-i-1];
		a[length-i-1] = x;
	}
	cout << "Reversed Array"<<endl;

	for(int i = 0; i < length; i++){
		cout <<a[i]<<((i == length-1) ? "" : ", ");
	}
	cout <<endl;
}
//#10
void randomArray(int length,int maxVal){
	int a[length];
	srand((int) time(NULL));

	for(int i = 0;i<length;i++){
		a[i] = rand()%maxVal;
	}

	//i really hate how inefficient this is, but
	//im just following the instructions...
	cout <<"printing the sorted array ... "<<endl;
	bool complete = false;
	int min = maxVal+1;
	int index;
	while(!complete){
		for(int i = 0;i<length;i++){
			if(a[i] < min){
				min = a[i];
				index = i;
			}
		}
		if(min == (maxVal+1)){
			complete = true;
		}
		a[index] = maxVal+1;
		cout<<min<<((complete) ? "" : ", ");
		min = maxVal+1;
	}
	cout<<endl;

}
//#11
int *stackVar(){
	int x = 3;
	cout <<"Value is: "<<x<<", and address is: "<<&x<<endl;
	return &x;
}
//#12
void printArray(int a[], int length){
	for(int i = 0;i < length;i++){
		cout<<a[i]<<(i==(length-1) ? "" : ", ");
	}
	cout<<endl;
}
//#12b
void randomArray(int a[]){
	srand((int) time(NULL));
	for(int i = 0; i < 25; i++){
		a[i] = (rand()%10) +1;
	}
}
//#13
int *randomStuffArray(int *a, int *b, int *c){
	srand((int) time(NULL));
	int length = (rand()%25)+25;
	int *arr = new int[length];
	int high = (rand()%5)+5;
	int low = (rand()%5)-10;
	for(int i = 0;i < length;i++){
		arr[i] = (rand()%(high-low))+low;
	}
	*a=length;
	*b=high;
	*c=low;
	return arr;
}
