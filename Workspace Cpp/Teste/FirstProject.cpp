//============================================================================
// Name        : FirstProject.cpp
// Authors     : Derek Brad Bryan
// Date        : Aug 30
// Contents    : Lab 1
//============================================================================
#include <iostream>
#include <math.h>
using namespace std;


void two(); //Prints a line of stars
bool isPrime(int x); //Checks if a number is prime
int sum(); //Calculates 1+2+3+...+300
int termCount(); //Counts the number of terms needed to add 1+2+3+... until the sum is over 100K
void multTables(int x); //Multiplies a number by 1 through 12
void allMultTables(); //The multiple tables for 1 to 12
int collatz(); //Calculates the steps for the collatz conjecture of a given number
void printLeapYears(int startYear, int endYear); //Calculates which years are leap years for a given range
void drawX(int x); //Prints out a big ol' X of a given size
void collatzTester(int min, int max); //Tests the collatz conjecture for ints bewtween two numbers
bool recursivePrime(int x); //isPrime but implemented recursively
void recursiveTable(int x); //Times tables but implemented recursively




//main()
int main() {
	cout << "askjdnfasdfg" << endl;
	cout << boolalpha << endl;
	cout << isPrime(7) << endl;
	cout << sum() << endl;
	cout << termCount() << endl;
	two();
	multTables(2);
	two();
	allMultTables();
	two();
	cout << collatz() << endl;
	two();
	printLeapYears(2018, 2418);
	drawX(5);
	drawX(11);
	drawX(20);
	collatzTester(3,100);
	cout << boolalpha;
	cout << recursivePrime(4) << endl;
	recursiveTable(5);
	return 0;
}


//Not inputs or parameters
//Prints a line of stars
//Used for organization of the main function
void two() {
	cout << "********************************************" << endl;
}


//Take input of a number to check primality
//Checks if numbers from 2 to sqrt(x) are factors of the number
//Returns true if it is a prime, returns false elsewise
bool isPrime(int x) {
	two();
	int i = 1;

	while(++i <= sqrt(x)){
		if(x % i == 0)
			return false;
	}
	return true;
}


//No inputs or parameters
//Adds up 1+2+3+...+300. Prints out the current sum ever 20 numbers
//Returns the sum.
int sum(){
	two();
	int i = 0;
	int sum = 0;
	while(i <= 300){
		sum+=i;
		if(i % 20 == 0)
			cout << sum << endl;
		i++;
	}
	return sum;
}


//No inputs or parameters
//Counts the number of terms needed to add 1+2+3+... until the sum is over 100K
//Returns how many terms it took
int termCount(){
	two();
	int i = 1;
	int sum = 0;
	while(sum < 100000){
		sum+= i;
		i++;
	}

	return i-1;
}


//Input is one number to calculate the multiple tables for
//Prints the multiple tables of 1 to 12 multiplied by x.
//Does not return anything
void multTables(int x){
	for(int i = 1; i <= 12; i++){
		cout << x*i;
		cout << " ";
	}
	cout << "" << endl;
}

//No inputs or parameters
//Prints the multiple tables up to 12 for 1 through 12.
//Does not return anything
void allMultTables(){

	for(int i = 1; i <= 12; i++){
		multTables(i);
		cout << "" << endl;
	}

}


//No parameters, but takes an integer as user input when run
//Calculates the steps the Collatz Conjecture takes for a given input
//Returns the number of steps it took ato converge to 0
int collatz(){
	int x;
	cout << "Type an integer." << endl;

	cin >> x;

	int count = 0;
	while(x!=1){
		if(x%2==0){
			x/=2;
		}else{
			x = x*3 + 1;
		}
		count++;
	}
	cout << "Your number converged to 0 after ";
	cout << count;
	cout << " loops." << endl;

	return count;
}

//Takes a range of years as an input
//Prints out every year in between those two years hat will be a leap year.
//A little more than required but we assumed going above and beyond is encouraged
///Does not return anything
void printLeapYears(int startYear, int endYear){
	while(startYear < endYear){
		if(startYear % 4 == 0){
			if(startYear % 100 == 0){
				if(startYear % 400 == 0){
					cout << startYear << endl;
					startYear+=4;
				}else{
					startYear+=4;
				}
			}else{
				cout << startYear << endl;
				startYear+=4;
			}
		}else{
			startYear++;
		}
	}
}

//Takes an integer as an input, represents the size of the X to be printed
//Prints out a big ol' X
//Does not return anything
void drawX(int x){
	if(x%2==0)
		x++;
	for(int i = 1; i < x*2; i++){
		for(int j = 0; j < x*2; j++){
			if(j == i || j == (x*2 - i)){
				cout << "*";
			}else{
				cout << " ";
			}
		}
		cout << "" << endl;
	}

}

//Takes a range of inputs for min to max as input
//Checks to see whether the collatz conjecture hold true for each number between the two numbers.
//Does not return anything
void collatzTester(int min, int max){
	for(int i = min;i <= max;i++){
		int x = i;
		cout << x;
		while(x!=1){
			if(x%2==0){
				x/=2;
			}else{
				x = x*3 + 1;
			}
		}
		cout << " .... We got 1, so the Collatz Conjecture is still working." << endl;
	}
}



//First input is the number to check the primality of
//Second input is how far along we have checked up to this point
//Checks if a number is prime, but does it recursively
//Returns whether or not the given number is a prime
bool recursivePrime(int x, int div){
	if(x < 3){
		return x==2;
	}else if(div > sqrt(x)){
		return true;
	}else if(x%div == 0){
		return false;
	}else{
		return recursivePrime(x, div+1);
	}
}


//Starts checking factors of given number starting at 2 and going up recursively
//The intended way to call recursiveTable() on an input
//Returns whether or not the given number is a prime
bool recursivePrime(int x){
	return recursivePrime(x, 2);
}

//Prints out the times tables for a given input, uses two inputs to track current number
//Does not return anything
void recursiveTable(int x,int i){
	if(i > 12)
		return;
	cout << x*i;
	cout << " ";
	recursiveTable(x, i+1);
}
//The intended way to call recursiveTable()
//Does not return anything
void recursiveTable(int x){
	recursiveTable(x,1);
}

